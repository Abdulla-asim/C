/*#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Moving Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect square;
    square.x = square.y = 0;
    square.w = square.h = 50;

    int speed = 5;

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        square.x += speed;
        if (square.x > (800 - 50) || square.x < 0) {
            speed = -speed;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &square);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
*/



/*
#define PDC_WIDE
#include <stdio.h>
#include <pdcurses.h>

int main() {
    // Initialize PDCurses
    initscr();
    timeout(0);  // Non-blocking input
    keypad(stdscr, TRUE);

    // Your animation loop
    while (1) {
        // Update your animation logic here

        // Clear the screen
        clear();

        // Draw your animation elements
        mvprintw(10, 10, "X");  // Example: Draw a character at position (10, 10)

        // Refresh the screen
        refresh();

        // Introduce a delay (adjust as needed)
        napms(100);  // 100 milliseconds delay

        // Break the loop based on some condition (e.g., user input)
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    // Close PDCurses
    endwin();
    return 0;
}
*/



// animation word animation
#include <pdcurses.h>
#include <unistd.h>

#define DELAY 30

int main()
{
    int x = 0;
    int y = 0; 
    
    int max_X = 0;
    int max_Y = 0;

    int next_x = 0;

    int direction = 1;

    initscr();
    noecho();
    curs_set(FALSE);

    timeout(0);

    getmaxyx(stdscr, max_Y, max_X);

    x = max_X / 2;
    y = max_Y / 2;
    
    while(1)
    {
        getmaxyx(stdscr, max_Y, max_X);
        y = max_Y / 2; 
        clear();
        
        mvprintw(y , x, "Animation");
        refresh();

        napms(DELAY);

        next_x = x + direction;

        if(next_x >= max_X - 10 || next_x < 0)
        {
            direction*= -1;
        }
        else 
        {
            x += direction;
        }
    }
endwin();
}
