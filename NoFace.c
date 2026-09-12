#include <stdio.h>  // For printf() function
#include <stdlib.h> // For system() function
#include <unistd.h> // For usleep() function
#include <conio.h>  // For kbhit() and getch() functions


#define WIDTH 40 // board width in cells
#define HEIGHT 20 // board height in cells

int main(void) {
    // No Face's head position starting in the middle of the board
    int head_x = WIDTH / 2;
    int head_y = HEIGHT / 2;

    // remember which way No Face is heading
    // Start him moving to the right
    char direction = 'd';

    // The game loop
    while (1) {

        // Clear the screen
        system("cls");

        // Draw the board
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {

                if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
                    printf("#"); // Draw a wall
                } else if (x == head_x && y == head_y) {
                    printf("O"); // Draw No Face's head
                } else {
                    printf(" "); // Draw empty space
                }
            }
            printf("\n");
        }

        // Check for key press without freezing the program
        if (kbhit()) {                        // Check if a key has been pressed
            char key = getch();               // Get the pressed key
            if (key == 'w') direction = 'w'; // Move up
            else if (key == 's') direction = 's'; // Move down
            else if (key == 'a') direction = 'a'; // Move left
            else if (key == 'd') direction = 'd'; // Move right
        }
        
        switch (direction) {
            case 'd': head_x = head_x + 1; break; // Move right
            case 'a': head_x = head_x - 1; break; // Move left
            case 's': head_y = head_y + 1; break; // Move down
            case 'w': head_y = head_y - 1; break; // Move up
        }

        // Sleep for a short duration to control the speed of movement
        usleep(200000); // Sleep for 0.2 seconds
    }

    return 0;

}