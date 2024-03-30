/*
#include <pdcurses.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICLES 50
#define DELAY 50

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
} Particle;

void initialize_particles(Particle particles[], int num_particles) {
    for (int i = 0; i < num_particles; ++i) {
        particles[i].x = rand() % COLS;
        particles[i].y = rand() % LINES;
        particles[i].dx = (rand() % 3) - 1; // Random value between -1 and 1
        particles[i].dy = (rand() % 3) - 1;
    }
}

void update_particles(Particle particles[], int num_particles) {
    for (int i = 0; i < num_particles; ++i) {
        particles[i].x += particles[i].dx;
        particles[i].y += particles[i].dy;

        // Bounce off the walls
        if (particles[i].x <= 0 || particles[i].x >= COLS - 1) {
            particles[i].dx = -particles[i].dx;
        }

        if (particles[i].y <= 0 || particles[i].y >= LINES - 1) {
            particles[i].dy = -particles[i].dy;
        }
    }
}

void draw_particles(Particle particles[], int num_particles) {
    for (int i = 0; i < num_particles; ++i) {
        mvprintw(particles[i].y, particles[i].x, "*");
    }
}

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0); // Non-blocking input

    srand(time(NULL));

    int num_particles = MAX_PARTICLES;
    Particle particles[MAX_PARTICLES];

    initialize_particles(particles, num_particles);

    while (1) {
        clear();

        update_particles(particles, num_particles);
        draw_particles(particles, num_particles);

        refresh();
        timeout(DELAY);

        int ch = getch();
        if (ch != ERR) {
            break; // Exit the loop if a key is pressed
        }
    }

    endwin();
    return 0;
}
*/

#include <pdcurses.h>
//#include <unistd.h>

#define WIDTH 60
#define HEIGHT 30
#define DELAY 100 // Microseconds

void initialize_grid(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j] = ' ';
        }
    }
}

void set_cell(char grid[HEIGHT][WIDTH], int x, int y) {
    grid[y][x] = 'X';
}

void clear_cell(char grid[HEIGHT][WIDTH], int x, int y) {
    grid[y][x] = ' ';
}

void draw_grid(char grid[HEIGHT][WIDTH]) {
    clear();
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            mvprintw(i, j * 2, "%c ", grid[i][j]);
        }
    }
    refresh();
}

int count_neighbors(char grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue; // Skip the center cell (current cell)
            }

            int nx = (x + j + WIDTH) % WIDTH;
            int ny = (y + i + HEIGHT) % HEIGHT;

            if (grid[ny][nx] == 'X') {
                ++count;
            }
        }
    }
    return count;
}

void update_grid(char grid[HEIGHT][WIDTH]) {
    char new_grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int neighbors = count_neighbors(grid, j, i);

            if (grid[i][j] == 'X') {
                // Cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    // Rule 1 and 3: Die due to underpopulation or overpopulation
                    new_grid[i][j] = ' ';
                } else {
                    // Rule 2: Stay alive
                    new_grid[i][j] = 'X';
                }
            } else {
                // Cell is dead
                if (neighbors == 3) {
                    // Rule 4: Become alive due to reproduction
                    new_grid[i][j] = 'X';
                } else {
                    new_grid[i][j] = ' ';
                }
            }
        }
    }
    // Copy the new grid back to the original grid
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0); // Non-blocking input

    char grid[HEIGHT][WIDTH];
    initialize_grid(grid);

    // Glider pattern example
    set_cell(grid, 1, 0);
    set_cell(grid, 2, 1);
    set_cell(grid, 0, 2);
    set_cell(grid, 1, 2);
    set_cell(grid, 2, 2);

    while (1) {
        draw_grid(grid);
        Sleep(DELAY);

        int ch = getch();
        if (ch != ERR) {
            break; // Exit the loop if a key is pressed
        }

        update_grid(grid);
    }

    endwin();
    return 0;
}
