```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <evntprov.h>

// ETW callback function for event registration
void ETW_Callback(LPCGUID SourceId, ULONG ControlCode, UCHAR Level, 
                  ULONGLONG MatchAnyKeyword, ULONGLONG MatchAllKeyword, 
                  PEVENT_FILTER_DESCRIPTOR FilterData, PVOID CallbackContext)
{
    void (*callback_func)(void);
    int *context = (int *)CallbackContext;
    
    if (context != NULL) {
        if (ControlCode == 0) {
            *context = 0;
        }
        else if (ControlCode == 1) {
            context[5] = (int)FilterData;
            int size = 0x100;
            if (Level != 0) {
                size = (Level & 0xff) + 1;
            }
            *context = size;
            context[2] = (int)MatchAnyKeyword;
            context[3] = (int)MatchAllKeyword;
            context[4] = (int)FilterData;
        }
        
        callback_func = (void (*)(void))context[8];
        if (callback_func != NULL) {
            // Guard check for indirect call
            callback_func();
        }
    }
}

// Initialize ETW event registration
void Initialize_ETW(void)
{
    GUID provider_guid;
    ULONG result;
    
    // Load provider GUID from data section
    provider_guid.Data1 = *(ULONG *)(0x403004 - 0x10);
    provider_guid.Data2 = *(USHORT *)(0x403004 - 0xc);
    provider_guid.Data3 = *(USHORT *)(0x403004 - 0xa);
    memcpy(provider_guid.Data4, (void *)(0x403004 - 8), 8);
    
    // Register ETW provider
    result = EventRegister(&provider_guid, ETW_Callback, (PVOID)0x403000, (PREGHANDLE)0x403018);
    
    if (result == 0) {
        EventSetInformation(*(REGHANDLE *)0x403018, *(REGHANDLE *)0x40301c, 2, 
                          (PVOID)0x403004, *(USHORT *)0x403004);
    }
}

// Write ETW event
void Write_ETW_Event(int context_ptr, BYTE *event_data, LPCGUID activity_id, 
                     LPCGUID related_activity_id, ULONG user_data_count, 
                     PEVENT_DATA_DESCRIPTOR user_data)
{
    EVENT_DESCRIPTOR event_desc;
    USHORT data_size;
    
    // Build event descriptor from event data
    event_desc.Id = *event_data;
    event_desc.Version = *(USHORT *)(event_data + 1);
    event_desc.Channel = *(BYTE *)(event_data + 3);
    event_desc.Level = *(BYTE *)(event_data + 4);
    event_desc.Opcode = *(BYTE *)(event_data + 5);
    event_desc.Task = *(USHORT *)(event_data + 6);
    event_desc.Keyword = *(ULONGLONG *)(event_data + 8);
    
    // Set up user data descriptors
    user_data[0].Ptr = (ULONGLONG)*(void **)(context_ptr + 4);
    user_data[0].Size = **(USHORT **)(context_ptr + 4);
    user_data[0].Reserved = 2;
    
    data_size = *(USHORT *)(event_data + 0xb);
    user_data[1].Ptr = (ULONGLONG)(event_data + 0xb);
    user_data[1].Size = data_size;
    user_data[1].Reserved = 1;
    
    EventWriteTransfer(*(REGHANDLE *)(context_ptr + 0x18), &event_desc, 
                      activity_id, related_activity_id, user_data_count, user_data);
}

// Main calculator launcher function
void Launch_Calculator(void)
{
    EVENT_DATA_DESCRIPTOR event_data[2];
    const char *event_name = "CalculatorStarted";
    
    Initialize_ETW();
    
    // Check ETW conditions and log event if appropriate
    if ((*(int *)0x403000 > 5) && ((*(int *)0x40300c & 0x20000) != 0)) {
        if ((*(int *)0x403010 == 0) && ((*(int *)0x403014 & 0x20000) == *(int *)0x403014)) {
            Write_ETW_Event(0x403000, (BYTE *)0x401259, NULL, NULL, 3, event_data);
        }
    }
    
    // Launch Windows Calculator using ms-calculator protocol
    ShellExecuteW(NULL, NULL, L"ms-calculator:", NULL, NULL, SW_SHOWNORMAL);
}

// Security cookie initialization
void Initialize_Security_Cookie(void)
{
    FILETIME file_time;
    LARGE_INTEGER perf_counter;
    DWORD process_id, thread_id, tick_count;
    UINT cookie = 0;
    
    if ((*(UINT *)0x403028 == 0) || (*(UINT *)0x403028 == 0xbb40e64e)) {
        GetSystemTimeAsFileTime(&file_time);
        cookie = file_time.dwHighDateTime ^ file_time.dwLowDateTime;
        
        process_id = GetCurrentProcessId();
        cookie ^= process_id;
        
        thread_id = GetCurrentThreadId();
        cookie ^= thread_id;
        
        tick_count = GetTickCount();
        cookie ^= tick_count;
        
        QueryPerformanceCounter(&perf_counter);
        cookie ^= perf_counter.HighPart ^ perf_counter.LowPart;
        
        *(UINT *)0x403028 = (cookie != 0) ? cookie : 0xbb40e64e;
    }
    
    *(UINT *)0x40302c = ~*(UINT *)0x403028;
}

// C runtime initialization
int Initialize_CRT(void)
{
    int app_type;
    int *mode_ptr;
    
    app_type = 2; // GUI application
    __set_app_type(app_type);
    
    // Set file mode
    mode_ptr = (int *)__p__fmode();
    *mode_ptr = *(int *)0x403388;
    
    // Set COM mode
    mode_ptr = (int *)__p__commode();
    *mode_ptr = *(int *)0x40337c;
    
    // Set math error handler
    if (*(int *)0x403030 == 0) {
        __setusermatherr((int (*)(struct _exception *))0x401e40);
    }
    
    // Set floating point control
    _controlfp(0x10000, 0x30000);
    
    return 0;
}

// Main entry point
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    STARTUPINFOW startup_info;
    WCHAR *cmd_line;
    WCHAR ch;
    BOOL in_quotes = FALSE;
    
    GetStartupInfoW(&startup_info);
    
    // Initialize C runtime
    Initialize_CRT();
    
    // Parse command line
    cmd_line = *(WCHAR **)_wcmdln;
    if (cmd_line != NULL) {
        while (*cmd_line != 0) {
            ch = *cmd_line;
            if (ch < 0x21) {
                if (ch == 0) break;
                if (!in_quotes) {
                    while (*cmd_line != 0 && *cmd_line < 0x21) {
                        cmd_line++;
                    }
                    break;
                }
            }
            if (ch == L'"') {
                in_quotes = !in_quotes;
            }
            cmd_line++;
        }
    }
    
    // Launch calculator
    Launch_Calculator();
    
    return 0;
}

// Program entry point
void entry(void)
{
    Initialize_Security_Cookie();
    WinMain(NULL, NULL, NULL, 0);
}

// Exception handler
LONG WINAPI Exception_Handler(EXCEPTION_POINTERS *exception_info)
{
    EXCEPTION_RECORD *record = exception_info->ExceptionRecord;
    
    if ((record->ExceptionCode == 0xe06d7363) && (record->NumberParameters == 3)) {
        DWORD param = record->ExceptionInformation[2];
        if (param == 0x19930520 || param == 0x19930521 || 
            param == 0x19930522 || param == 0x1994000) {
            terminate();
        }
    }
    
    return EXCEPTION_CONTINUE_SEARCH;
}

// Set up exception handling
int Setup_Exception_Handler(void)
{
    SetUnhandledExceptionFilter(Exception_Handler);
    return 0;
}
```
