```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables
extern char target[449];  // Pre-defined target pattern of '<', '>', '=' characters

int main(void)
{
    char user_input[80];
    char generated_pattern[520];
    int pattern_index = 0;
    int input_index = 0;
    int low, high, mid;
    unsigned int i;
    
    printf("Enter flag: ");
    scanf("%s", user_input);
    
    size_t input_length = strlen(user_input);
    if (input_length >= 0x47) {  // Input too long
        puts("Nope");
        return 0;
    }
    
    // Process each character in the input
    while (input_index < (int)strlen(user_input)) {
        low = 0;
        high = 0xff;  // Binary search range 0-255
        
        // Binary search to find the current character
        while (1) {
            mid = (low + high) / 2;
            if (mid == (int)user_input[input_index]) {
                // Found the character, record '=' and move to next
                generated_pattern[pattern_index] = '=';
                pattern_index++;
                break;
            } else if (mid < (int)user_input[input_index]) {
                // Mid is too small, record '>' and search upper half
                generated_pattern[pattern_index] = '>';
                low = mid + 1;
                pattern_index++;
            } else {
                // Mid is too large, record '<' and search lower half
                generated_pattern[pattern_index] = '<';
                high = mid - 1;
                pattern_index++;
            }
        }
        input_index++;
    }
    
    // Check if the generated pattern matches the expected length and content
    if (pattern_index == 0x1c0) {  // Expected pattern length is 448 (0x1c0)
        for (i = 0; i < 0x1c0; i++) {
            if (generated_pattern[i] != target[i]) {
                puts("Nope");
                return 0;
            }
        }
        puts("Correct!");
    } else {
        puts("Nope");
    }
    
    return 0;
}
```
