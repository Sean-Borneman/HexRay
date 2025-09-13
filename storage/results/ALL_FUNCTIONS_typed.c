```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <evntprov.h>

// ETW Event callback function
void ETW_EventCallback(LPCGUID SourceId, ULONG ControlCode, UCHAR Level, 
                      ULONGLONG MatchAnyKeyword, ULONGLONG MatchAllKeyword, 
                      PEVENT_FILTER_DESCRIPTOR FilterData, PVOID CallbackContext)
{
    typedef void (*CallbackFunc)(void);
    CallbackFunc callback;
    int *context = (int *)CallbackContext;
    int bufferSize;
    
    if (context != NULL) {
        if (ControlCode == 0) {
            *context = 0;
        }
        else if (ControlCode == 1) {
            context[5] = (int)FilterData;
            bufferSize = 0x100;
            if (Level != 0) {
                bufferSize = (Level & 0xff) + 1;
            }
            *context = bufferSize;
            context[2] = (int)MatchAnyKeyword;
            context[3] = (int)MatchAllKeyword;
            context[4] = (int)FilterData;
        }
        
        callback = (CallbackFunc)context[8];
        if (callback != NULL) {
            // Guard check for indirect call
            callback();
        }
    }
}

// Initialize ETW provider
void InitializeETWProvider(void)
{
    GUID providerGuid;
    ULONG result;
    
    // Load provider GUID from data section
    providerGuid.Data1 = *(ULONG *)(0x00403004 - 0x10);
    providerGuid.Data2 = *(USHORT *)(0x00403004 - 0xc);
    providerGuid.Data3 = *(USHORT *)(0x00403004 - 0xa);
    memcpy(providerGuid.Data4, (void *)(0x00403004 - 8), 8);
    
    // Register ETW provider
    result = EventRegister(&providerGuid, ETW_EventCallback, 
                          (PVOID)0x403000, (PREGHANDLE)0x403018);
    
    if (result == ERROR_SUCCESS) {
        EventSetInformation(*(REGHANDLE *)0x403018, *(ULONG *)0x40301c, 
                           2, (PVOID)0x403004, *(USHORT *)0x403004);
    }
}

// Write ETW event
void WriteETWEvent(int contextAddr, UCHAR *eventData, LPCGUID activityId, 
                  LPCGUID relatedActivityId, ULONG userDataCount, 
                  PEVENT_DATA_DESCRIPTOR userDataDescriptors)
{
    EVENT_DESCRIPTOR eventDescriptor;
    USHORT stringLength;
    
    // Build event descriptor from event data
    eventDescriptor.Id = *eventData;
    eventDescriptor.Version = *(USHORT *)(eventData + 1);
    eventDescriptor.Channel = *(UCHAR *)(eventData + 3);
    eventDescriptor.Level = *(UCHAR *)(eventData + 4);
    eventDescriptor.Opcode = *(UCHAR *)(eventData + 5);
    eventDescriptor.Task = *(USHORT *)(eventData + 6);
    eventDescriptor.Keyword = *(ULONGLONG *)(eventData + 8);
    
    // Set up user data descriptors
    userDataDescriptors[0].Ptr = (ULONGLONG)*(void **)(contextAddr + 4);
    userDataDescriptors[0].Size = **(USHORT **)(contextAddr + 4);
    userDataDescriptors[0].Reserved = 2;
    
    userDataDescriptors[1].Ptr = (ULONGLONG)(eventData + 0xb);
    stringLength = *(USHORT *)(eventData + 0xb);
    userDataDescriptors[1].Size = stringLength;
    userDataDescriptors[1].Reserved = 1;
    
    EventWriteTransfer(*(REGHANDLE *)(contextAddr + 0x18), &eventDescriptor,
                      activityId, relatedActivityId, userDataCount, 
                      userDataDescriptors);
}

// Main calculator launcher function
void LaunchCalculator(void)
{
    EVENT_DATA_DESCRIPTOR eventDescriptors[2];
    const char *eventName = "CalculatorStarted";
    
    InitializeETWProvider();
    
    // Check if ETW logging is enabled and write event
    if ((*(ULONG *)0x403000 > 5) && ((*(ULONG *)0x40300c & 0x20000) != 0)) {
        if ((*(ULONG *)0x403010 == 0) && 
            ((*(ULONG *)0x403014 & 0x20000) == *(ULONG *)0x403014)) {
            WriteETWEvent(0x403000, (UCHAR *)0x401259, NULL, NULL, 3, eventDescriptors);
        }
    }
    
    // Launch Windows Calculator using ms-calculator protocol
    ShellExecuteW(NULL, NULL, L"ms-calculator:", NULL, NULL, SW_SHOWNORMAL);
}

// Security cookie initialization
void InitializeSecurityCookie(void)
{
    FILETIME fileTime;
    LARGE_INTEGER perfCounter;
    DWORD processId, threadId, tickCount;
    UINT cookie = 0;
    
    if ((*(UINT *)0x403028 == 0) || (*(UINT *)0x403028 == 0xbb40e64e)) {
        GetSystemTimeAsFileTime(&fileTime);
        cookie = fileTime.dwHighDateTime ^ fileTime.dwLowDateTime;
        
        processId = GetCurrentProcessId();
        cookie ^= processId;
        
        threadId = GetCurrentThreadId();
        cookie ^= threadId;
        
        tickCount = GetTickCount();
        cookie ^= tickCount;
        
        QueryPerformanceCounter(&perfCounter);
        cookie ^= perfCounter.HighPart ^ perfCounter.LowPart;
        
        *(UINT *)0x403028 = (cookie != 0) ? cookie : 0xbb40e64e;
    }
    
    *(UINT *)0x40302c = ~*(UINT *)0x403028;
}

// Runtime initialization
int RuntimeInit(void)
{
    int appType;
    int *modePtr;
    
    appType = 2; // Console application type
    __set_app_type(appType);
    
    // Set file and COM modes
    modePtr = (int *)__p__fmode();
    *modePtr = *(int *)0x403388;
    
    modePtr = (int *)__p__commode();
    *modePtr = *(int *)0x40337c;
    
    // Set math error handler if not already set
    if (*(void **)0x403030 == NULL) {
        __setusermatherr((int (*)(struct _exception *))0x401e40);
    }
    
    // Set floating point control
    _controlfp(0x10000, 0x30000);
    
    return 0;
}

// Main entry point
int main(void)
{
    STARTUPINFOW startupInfo;
    wchar_t *cmdLine;
    wchar_t ch;
    int inQuotes = 0;
    int exitCode;
    
    InitializeSecurityCookie();
    RuntimeInit();
    
    // Get startup info and command line
    GetStartupInfoW(&startupInfo);
    cmdLine = *(wchar_t **)_wcmdln_exref;
    
    if (cmdLine == NULL) {
        return 0xff;
    }
    
    // Parse command line (skip program name)
    do {
        ch = *cmdLine;
        if (ch < 0x21) {
            if (ch == 0) break;
            if (inQuotes == 0) {
                while ((ch != 0) && (ch < 0x21)) {
                    cmdLine++;
                    ch = *cmdLine;
                }
                break;
            }
        }
        if (ch == L'"') {
            inQuotes = (inQuotes == 0) ? 1 : 0;
        }
        cmdLine++;
    } while (true);
    
    // Launch calculator
    exitCode = LaunchCalculator();
    
    // Clean exit
    if (*(int *)0x403374 == 0) {
        exit(exitCode);
    } else {
        _cexit();
        return exitCode;
    }
}

// Exception handler for security failures
LONG WINAPI SecurityExceptionHandler(EXCEPTION_POINTERS *exceptionInfo)
{
    EXCEPTION_RECORD *record = exceptionInfo->ExceptionRecord;
    
    if ((record->ExceptionCode == 0xE06D7363) && 
        (record->NumberParameters == 3) &&
        ((record->ExceptionInformation[2] == 0x19930520) ||
         (record->ExceptionInformation[2] == 0x19930521) ||
         (record->ExceptionInformation[2] == 0x19930522) ||
         (record->ExceptionInformation[2] == 0x1994000))) {
        terminate();
    }
    
    return EXCEPTION_CONTINUE_SEARCH;
}

// Security initialization
int InitializeSecurity(void)
{
    SetUnhandledExceptionFilter(SecurityExceptionHandler);
    return 0;
}

// Program entry point
void entry(void)
{
    InitializeSecurityCookie();
    main();
}
```
