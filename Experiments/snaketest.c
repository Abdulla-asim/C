#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pdcurses.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15

// Direction constants
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Game elements
struct Point {
    int x, y;
};

struct Snake {
    struct Point head;
    int length;
    int direction;
    struct Point body[100];
};

struct PowerUp {
    struct Point position;
    int active;
};

struct Obstacle {
    struct Point position;
    int active;
};

// Function prototypes
void initGame();
void draw();
void getInput();
void moveSnake();
void checkCollision();
//void generatePowerUp();
//void generateObstacle();
//void checkPowerUpCollision();
//void checkObstacleCollision();

// Global variables
struct Snake snake;
struct PowerUp powerUp;
struct Obstacle obstacles[5];

int main() {
    // Initialize NCurses and create the main window
    initscr();
    WINDOW *mainwin = newwin(HEIGHT + 2, WIDTH + 2, 0, 0);

    // Additional NCurses setup (timeout, keypad, cursor visibility)
    timeout(0);
    keypad(mainwin, TRUE);
    curs_set(0);

    initGame();

    while (1) {
        getInput();
        moveSnake();
        checkCollision();
        /*checkPowerUpCollision();
        checkObstacleCollision();
        generatePowerUp();
        generateObstacle();*/
        draw();
        napms(70); // Adjust the speed of the game
    }

    endwin(); // Close NCurses window
    return 0;
}

/*void initGame() {
    initscr(); // Initialize NCurses
    timeout(0); // Non-blocking input
    keypad(stdscr, TRUE); // Enable special keys
    curs_set(0); // Hide cursor

    // Initialize snake
    snake.head.x = WIDTH / 2;
    snake.head.y = HEIGHT / 2;
    snake.length = 1;
    snake.direction = RIGHT;

    // Initialize power-up
    powerUp.active = 0;

    // Initialize obstacles
    for (int i = 0; i < 5; ++i) {
        obstacles[i].active = 0;
    }

    // Seed random number generator
    srand(time(NULL));
}*/
void initGame() {
    // Initialize NCurses
    initscr();
    timeout(0); 
    keypad(stdscr, TRUE);
    curs_set(0);

    // Initialize snake
    snake.head.x = WIDTH / 2;
    snake.head.y = HEIGHT / 2;
    snake.length = 1;
    snake.direction = RIGHT;

    // Initialize the first segment of the snake's body
    snake.body[0] = snake.head;

    // Initialize power-up
    powerUp.active = 0;

    // Initialize obstacles
    for (int i = 0; i < 5; ++i) {
        obstacles[i].active = 0;
    }

    // Seed random number generator
    srand(time(NULL));
}


void draw() {
    clear(); // Clear the screen

    // Draw snake
    for (int i = 0; i < snake.length; ++i) {
        mvprintw(snake.body[i].y, snake.body[i].x, "O");
    }

    // Draw power-up
    if (powerUp.active) {
        mvprintw(powerUp.position.y, powerUp.position.x, "P");
    }

    // Draw obstacles
    for (int i = 0; i < 5; ++i) {
        if (obstacles[i].active) {
            mvprintw(obstacles[i].position.y, obstacles[i].position.x, "X");
        }
    }

    // Draw borders
    for (int i = 0; i <= WIDTH + 1; ++i) {
        mvprintw(0, i, "#");
        mvprintw(HEIGHT + 1, i, "#");
    }

    for (int i = 0; i <= HEIGHT + 1; ++i) {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH + 1, "#");
    }

    refresh(); // Refresh the screen
}

void getInput() {
    int ch = getch();

    switch (ch) {
        case KEY_UP:
            snake.direction = UP;
            break;
        case KEY_DOWN:
            snake.direction = DOWN;
            break;
        case KEY_LEFT:
            snake.direction = LEFT;
            break;
        case KEY_RIGHT:
            snake.direction = RIGHT;
            break;
        case 'q':
            endwin(); // Close NCurses window before quitting
            exit(0);
    }
}

void moveSnake() {
    // Save the current position of the head
    struct Point prevHead = snake.head;

    // Move the head
    switch (snake.direction) {
        case UP:
            --snake.head.y;
            break;
        case DOWN:
            ++snake.head.y;
            break;
        case LEFT:
            --snake.head.x;
            break;
        case RIGHT:
            ++snake.head.x;
            break;
    }

    // Move the body
    for (int i = snake.length - 1; i > 0; --i) {
        snake.body[i] = snake.body[i - 1];
    }

    // Update the body with the new head position
    snake.body[0] = prevHead;
}

void checkCollision() {
    // Check collision with walls
    if (snake.head.x <= 0 || snake.head.x >= WIDTH + 1 || snake.head.y <= 0 || snake.head.y >= HEIGHT + 1) {
        exit(0);
    }
}
