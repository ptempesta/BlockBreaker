#ifndef graphics_h
#define graphics_h

#include <stdlib.h>

#ifdef _WIN32

#include <windows.h>

#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include "C:\Program Files\Common Files\freeglut\include\GL\glut.h"

#endif

#include <iostream>
#include <cmath>

using namespace std;

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL BlockBreaker
void InitGL(void);

// Callback functions for GLUT */

// Draw the window - this is where all the GL actions are
void display(void);

//Menu functions

/*
 * R: nothing
 * M: beginMenu, newGButton, loadGButton, exitGButton
 * E: displays the main menu
 */
void displayMenu();

/*
 * R: nothing
 * M: bar, ball, blocks[]
 * E: displays the game and handles all move logic
 */
void displayGame();

/*
 * R: nothing
 * M: beginGOverMenu, fio, mainMButton, exitGButton
 * E: displays the game over menu
 */
void GameOverMenu();

/*
 * R: nothing
 * M: blocks[]
 * E: resets all blocks on screen
 */
void resetBlocks();

/*
 * R: nothing
 * M: beginGOverMenu, saveButton, leaveButton
 * E: displays the save menu screen
 */
void displayBall();

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int extra);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

int graphicsPlay(int argc, char *argv[]);

#endif /* graphics_h */