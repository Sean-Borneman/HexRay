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
    int round;
    int digit_index;
    int input_index;
    int user_input;
    int calibration_sequence[6];
    
    total_sum = 0;
    while (total_sum == 0) {
        for (digit_index = 0; digit_index < 5; digit_index++) {
            random_value = rand();
            calibration_sequence[digit_index] = random_value % 9;
            total_sum += calibration_sequence[digit_index];
        }
    }
    
    round = 0;
    do {
        if (round > 4) {
            puts(":Calibration success");
            puts("!");
            fflush(stdout);
            total_sum += 12; // Add bonus to sum
            return total_sum;
        }
        
        printf(":Calibrating (%d/5)...\n", round + 1);
        putchar('>');
        
        for (digit_index = 0; digit_index <= round; digit_index++) {
            putchar(calibration_sequence[digit_index] + '1');
        }
        putchar('\n');
        fflush(stdout);
        
        for (input_index = 0; input_index <= round; input_index++) {
            user_input = getchar();
            if (user_input == EOF) {
                exit(0);
            }
            if ((user_input - '1') != calibration_sequence[input_index]) {
                puts(":Calibration failure");
                fflush(stdout);
                total_sum = 0;
                return total_sum;
            }
        }
        
        round++;
    } while (true);
}

// Main game phase - number guessing game with secret sequence
int run_game(unsigned int target_sum)
{
    int user_input;
    unsigned int computer_guess;
    long random_val;
    char *flag_env;
    int shift_index;
    unsigned int remaining_sum;
    char input_buffer[7];
    
    // Initialize input buffer
    for (shift_index = 0; shift_index < 7; shift_index++) {
        input_buffer[shift_index] = '\0';
    }
    
    // Wait for secret sequence: 5,8,8,2,3,0,0
    do {
        // Shift buffer left
        for (shift_index = 0; shift_index < 6; shift_index++) {
            input_buffer[shift_index] = input_buffer[shift_index + 1];
        }
        
        user_input = getchar();
        if (user_input == EOF) {
            exit(0);
        }
        input_buffer[6] = (char)(user_input - '1');
        
    } while (!(input_buffer[0] == 5 && input_buffer[1] == 8 && 
               input_buffer[2] == 8 && input_buffer[3] == 2 && 
               input_buffer[4] == 3 && input_buffer[5] == 0 && 
               input_buffer[6] == 0));
    
    remaining_sum = target_sum;
    
    // Main game loop
    do {
        if ((int)remaining_sum < 10) {
            printf(">%d\n", remaining_sum);
            fflush(stdout);
            return 1; // Game continues
        }
        
        random_val = random();
        computer_guess = (unsigned int)((int)random_val + (int)(random_val / 9) * -9 + 1);
        printf(">%d\n", computer_guess);
        fflush(stdout);
        
        remaining_sum -= computer_guess;
        
        user_input = getchar();
        if (user_input == EOF) {
            exit(0);
        }
        
        user_input = user_input - '0';
        
    } while ((user_input < 1) || (user_input > 9) || 
             (remaining_sum -= user_input, remaining_sum != 0));
    
    // Player won - show flag
    flag_env = getenv("FLAG");
    printf(":%s\n", flag_env);
    fflush(stdout);
    
    return 0; // Game ends
}
