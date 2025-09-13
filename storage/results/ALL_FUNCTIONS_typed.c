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

// Calibration phase - user must repeat sequences of digits
int run_calibration(void)
{
    int random_value;
    int total_sum;
    int round;
    int digit_index;
    int input_index;
    int input_char;
    int digit_sequence[6];
    
    total_sum = 0;
    while (total_sum == 0) {
        for (digit_index = 0; digit_index < 5; digit_index++) {
            random_value = rand();
            digit_sequence[digit_index] = random_value % 9;
            total_sum += digit_sequence[digit_index];
        }
    }
    
    round = 0;
    do {
        if (round > 4) {
            puts(":Calibration success");
            puts("!");
            fflush(stdout);
            total_sum += 12;  // Add bonus to sum
            return total_sum;
        }
        
        printf(":Calibrating (%d/5)...\n", round + 1);
        putchar('>');
        
        // Display sequence up to current round
        for (digit_index = 0; digit_index <= round; digit_index++) {
            putchar(digit_sequence[digit_index] + '1');
        }
        putchar('\n');
        fflush(stdout);
        
        // Check user input matches sequence
        for (input_index = 0; input_index <= round; input_index++) {
            input_char = getchar();
            if (input_char == EOF) {
                exit(0);
            }
            if ((input_char - '1') != digit_sequence[input_index]) {
                puts(":Calibration failure");
                fflush(stdout);
                total_sum = 0;
                return total_sum;
            }
        }
        
        round++;
    } while (true);
}

// Main game - subtract random numbers until reaching zero
int run_game(unsigned int starting_value)
{
    int input_char;
    unsigned int computer_move;
    long random_val;
    unsigned int remaining_value;
    int user_input;
    int shift_index;
    char input_buffer[7];
    const char target_sequence[7] = {5, 8, 8, 2, 3, 0, 0};
    char *flag_value;
    
    // Initialize input buffer
    for (shift_index = 0; shift_index < 7; shift_index++) {
        input_buffer[shift_index] = 0;
    }
    
    // Wait for specific input sequence to start game
    do {
        // Shift buffer left
        for (shift_index = 0; shift_index < 6; shift_index++) {
            input_buffer[shift_index] = input_buffer[shift_index + 1];
        }
        
        input_char = getchar();
        if (input_char == EOF) {
            exit(0);
        }
        input_buffer[6] = input_char - '1';
        
    } while (memcmp(input_buffer, target_sequence, 7) != 0);
    
    remaining_value = starting_value;
    
    do {
        if (remaining_value < 10) {
            printf(">%d\n", remaining_value);
            fflush(stdout);
            return 1;  // Game continues
        }
        
        // Computer makes random move (1-9)
        random_val = random();
        computer_move = (random_val % 9) + 1;
        printf(">%d\n", computer_move);
        fflush(stdout);
        
        remaining_value -= computer_move;
        
        // Get user input
        input_char = getchar();
        if (input_char == EOF) {
            exit(0);
        }
        
        user_input = input_char - '0';
        if (user_input < 1 || user_input > 9) {
            continue;  // Invalid input, try again
        }
        
        remaining_value -= user_input;
        
    } while (remaining_value != 0);
    
    // Player won - display flag
    flag_value = getenv("FLAG");
    printf(":%s\n", flag_value);
    fflush(stdout);
    
    return 0;  // Game ends
}
