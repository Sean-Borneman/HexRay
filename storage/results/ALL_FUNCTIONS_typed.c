#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Main entry point - sets up calibration and game
int main(void)
{
    time_t current_time;
    int calibration_sum;
    int game_result;
    
    current_time = time(NULL);
    srand((unsigned int)current_time);
    
    calibration_sum = 0;
    while (calibration_sum == 0) {
        calibration_sum = run_calibration();
    }
    
    game_result = 1;
    while (game_result != 0) {
        game_result = run_game(calibration_sum);
    }
    
    return 0;
}

// Calibration phase - generates random sequences for user to repeat
int run_calibration(void)
{
    int random_value;
    int total_sum;
    int stage;
    int digit_index;
    int input_index;
    int input_char;
    int calibration_sequence[6];
    
    total_sum = 0;
    while (total_sum == 0) {
        for (digit_index = 0; digit_index < 5; digit_index++) {
            random_value = rand();
            calibration_sequence[digit_index] = random_value % 9;
            total_sum += calibration_sequence[digit_index];
        }
    }
    
    stage = 0;
    do {
        if (stage > 4) {
            puts(":Calibration success");
            puts("!");
            fflush(stdout);
            total_sum += 12; // Add bonus to sum
            return total_sum;
        }
        
        printf(":Calibrating (%d/5)...\n", stage + 1);
        putchar('>');
        
        for (digit_index = 0; digit_index <= stage; digit_index++) {
            putchar(calibration_sequence[digit_index] + '1');
        }
        putchar('\n');
        fflush(stdout);
        
        for (input_index = 0; input_index <= stage; input_index++) {
            input_char = getchar();
            if (input_char == EOF) {
                exit(0);
            }
            if ((input_char - '1') != calibration_sequence[input_index]) {
                puts(":Calibration failure");
                fflush(stdout);
                total_sum = 0;
                return total_sum;
            }
        }
        
        stage++;
    } while (true);
}

// Main game phase - number guessing game with special sequence trigger
int run_game(unsigned int target_sum)
{
    int input_char;
    unsigned int random_number;
    long random_value;
    int user_guess;
    char sequence_buffer[7];
    int buffer_index;
    char *flag_value;
    
    // Initialize sequence buffer
    for (buffer_index = 0; buffer_index < 7; buffer_index++) {
        sequence_buffer[buffer_index] = '\0';
    }
    
    // Wait for magic sequence: 5,8,8,2,3,0,0 (converted from '6','9','9','3','4','1','1')
    do {
        // Shift buffer left
        for (buffer_index = 0; buffer_index < 6; buffer_index++) {
            sequence_buffer[buffer_index] = sequence_buffer[buffer_index + 1];
        }
        
        input_char = getchar();
        if (input_char == EOF) {
            exit(0);
        }
        sequence_buffer[6] = input_char - '1'; // Convert to 0-based
        
    } while (!(sequence_buffer[0] == 5 && sequence_buffer[1] == 8 && 
               sequence_buffer[2] == 8 && sequence_buffer[3] == 2 && 
               sequence_buffer[4] == 3 && sequence_buffer[5] == 0 && 
               sequence_buffer[6] == 0));
    
    // Number guessing game
    do {
        if ((int)target_sum < 10) {
            printf(">%d\n", target_sum);
            fflush(stdout);
            return 1; // Game continues
        }
        
        random_value = random();
        random_number = (int)random_value + (int)(random_value / 9) * -9 + 1;
        printf(">%d\n", random_number);
        fflush(stdout);
        
        target_sum -= random_number;
        
        input_char = getchar();
        if (input_char == EOF) {
            exit(0);
        }
        
        user_guess = input_char - '0';
        
    } while ((user_guess < 1) || (user_guess > 9) || 
             (target_sum -= user_guess, target_sum != 0));
    
    // Player won - show flag
    flag_value = getenv("FLAG");
    printf(":%s\n", flag_value);
    fflush(stdout);
    
    return 0; // Game ends
}
