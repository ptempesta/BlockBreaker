#include <time.h>
#include "Graphics.h"
#include "Bar.h"
#include "Block.h"
#include "Ball.h"
#include "Background.h"
#include "FileIO.h"


Bar bar(250, 15, {1, 1, 1}, 0, 0);
Ball ball(15, {1, 1, 1}, 500, 300);
Ball ball2(35, {1, 0, 1}, 500, 300);
vector<RegBlock> blocks(30);


FileIO fio;
string file = "saveState.txt";
int score = 0;
int level = 0;

GLdouble width, height;
int wd;
enum menu {
    menuEnum, inGameEnum, GameOverEnum, inMenuEnum
};
menu gameMenu;
Background beginMenu;
Background newGButton;
Background loadGButton;
Background exitGButton;
Background mainMButton;

//Restets blocks when called
void resetBlocks() {
    //Random setting of hardness
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < blocks.size(); ++i) {
        blocks[i].setHardness(rand() % 3 + 1);
        blocks[i].setHeight(20);
        blocks[i].setWidth(50);
    }

    // First Row of 10 Blocks
    blocks[0].setX(200);
    blocks[0].setY(100);
    blocks[1].setX(260);
    blocks[1].setY(100);
    blocks[2].setX(320);
    blocks[2].setY(100);
    blocks[3].setX(380);
    blocks[3].setY(100);
    blocks[4].setX(440);
    blocks[4].setY(100);
    blocks[5].setX(500);
    blocks[5].setY(100);
    blocks[6].setX(560);
    blocks[6].setY(100);
    blocks[7].setX(620);
    blocks[7].setY(100);
    blocks[8].setX(680);
    blocks[8].setY(100);
    blocks[9].setX(740);
    blocks[9].setY(100);

    // Second Row of 10 Blocks
    blocks[10].setX(200);
    blocks[10].setY(130);
    blocks[11].setX(260);
    blocks[11].setY(130);
    blocks[12].setX(320);
    blocks[12].setY(130);
    blocks[13].setX(380);
    blocks[13].setY(130);
    blocks[14].setX(440);
    blocks[14].setY(130);
    blocks[15].setX(500);
    blocks[15].setY(130);
    blocks[16].setX(560);
    blocks[16].setY(130);
    blocks[17].setX(620);
    blocks[17].setY(130);
    blocks[18].setX(680);
    blocks[18].setY(130);
    blocks[19].setX(740);
    blocks[19].setY(130);

    // Third Row of 10 Blocks
    blocks[20].setX(200);
    blocks[20].setY(160);
    blocks[21].setX(260);
    blocks[21].setY(160);
    blocks[22].setX(320);
    blocks[22].setY(160);
    blocks[23].setX(380);
    blocks[23].setY(160);
    blocks[24].setX(440);
    blocks[24].setY(160);
    blocks[25].setX(500);
    blocks[25].setY(160);
    blocks[26].setX(560);
    blocks[26].setY(160);
    blocks[27].setX(620);
    blocks[27].setY(160);
    blocks[28].setX(680);
    blocks[28].setY(160);
    blocks[29].setX(740);
    blocks[29].setY(160);
}

void init() {
    width = 1000;
    height = 500;

    bar.setX((width / 2) - (bar.getWidth() / 2));
    bar.setY(height - bar.getHeight() - 100);
    bar.setWidth(width / 5);

    resetBlocks();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

//Creates Game over menu when user loses game
void GameOverMenu() {
    beginMenu.draw(height, width, {0, 0, 0}, 0, 0);
    string message = "GAME OVER :( Save File Has been deleted!! :O What would you like to do next?";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 - 450, 20);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    if (gameMenu == GameOverEnum) {

        string messageScore = "Score: " + to_string(score);
        glColor3f(1, 1, 1);
        glRasterPos2i(width / 2, height - 100);
        for (int j = 0; j < messageScore.length(); ++j) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, messageScore[j]);
        }
    }
    mainMButton.draw(50, 150, {1, 0, 0}, width / 2 - 400, 50);
    string message1 = "Main Menu";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 - 383, 75);
    for (int i = 0; i < message1.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message1[i]);
    }
    exitGButton.draw(50, 150, {1, 0, 0}, width / 2 - 100, 50);
    string message2 = "Exit Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 - 83, 75);
    for (int i = 0; i < message2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
    }
}
//Displays the main menu of the game
void displayMenu() {
    gameMenu = inMenuEnum;
    beginMenu.draw(height, width, {0, 0, 0}, 0, 0);
    string message = "Welcome to Block Breaker! Select an Option!";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 - 250, 20);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    newGButton.draw(50, 150, {1, 0, 0}, width / 2 - 400, 200);
    string message1 = "New Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 - 383, 235);
    for (int i = 0; i < message1.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message1[i]);
    }
    loadGButton.draw(50, 150, {1, 0, 0}, width / 2 - 100, 200);
    string message2 = "Load Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 - 83, 235);
    for (int i = 0; i < message2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
    }
    exitGButton.draw(50, 150, {1, 0, 0}, width / 2 + 200, 200);
    string message3 = "Exit Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(width / 2 + 217, 235);
    for (int i = 0; i < message3.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message3[i]);
    }
    displayBall();

}

/*
 * This is collision for the ball, and it is defined below in another area. To gain a greater insight into collision and
 * movement for the ball, simply scroll down to the first point where collision is indicated via comments.
 *
 * Well, this ball collision detection is for the menu screen purple ball. It is the same premise, though.
 */
void displayBall() {
    ball2.draw();
    for (int i = 0; i < blocks.size(); ++i) {
        blocks[i].draw();
        resetBlocks();
    }
    if (ball2.getY() + ball2.getRadius() >= height && ball2.getCollisionFlagY() == 1) { //bottom of the screen
        ball2.reverseYVel();
        ball2.flipCollisionFlagY();

    } else if (ball2.getY() - ball2.getRadius() <= 0 && ball2.getCollisionFlagY() == 0) { //top of the screen
        ball2.reverseYVel();
        ball2.flipCollisionFlagY();
    } else if (ball2.getX() + ball2.getRadius() >= width && ball2.getCollisionFlagX() == 1) { //right of the screen
        ball2.reverseXVel();
        ball2.flipCollisionFlagX();
    } else if (ball2.getX() - ball2.getRadius() <= 0 && ball2.getCollisionFlagX() == 0) { //left of the screen
        ball2.reverseXVel();
        ball2.flipCollisionFlagX();


    } else {
        for (int i = 0; i < blocks.size(); ++i) {

            if (ball2.getY() + ball2.getRadius() >= blocks[i].getY() &&
                ball2.getY() + ball2.getRadius() <= (blocks[i].getY() + blocks[i].getHeight())
                && ball2.getCollisionFlagY() == 1
                && (ball2.getX() + ball2.getRadius() >= blocks[i].getX() &&
                    ball2.getX() - ball2.getRadius() <= (blocks[i].getX() + blocks[i].getWidth()))) { // top of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball2.reverseYVel();
                ball2.flipCollisionFlagY();
            } else if (ball2.getY() - ball2.getRadius() <= blocks[i].getY() + blocks[i].getHeight() &&
                       ball2.getY() - ball2.getRadius() >= (blocks[i].getY())
                       && ball2.getCollisionFlagY() == 0
                       && (ball2.getX() + ball2.getRadius() >= blocks[i].getX() && ball2.getX() - ball2.getRadius() <=
                                                                                   (blocks[i].getX() +
                                                                                    blocks[i].getWidth()))) { // bottom of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball2.reverseYVel();
                ball2.flipCollisionFlagY();
            } else if (ball2.getY() + ball2.getRadius() >= blocks[i].getY() &&
                       ball2.getY() - ball2.getRadius() <= (blocks[i].getY() + blocks[i].getHeight()) &&
                       ball2.getX() - ball.getRadius() <= blocks[i].getX() + blocks[i].getWidth() &&
                       ball2.getX() >= blocks[i].getX() + blocks[i].getWidth() &&
                       ball2.getCollisionFlagX() == 0) { // right of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball2.reverseXVel();
                ball2.flipCollisionFlagX();

            } else if (ball2.getY() + ball2.getRadius() >= blocks[i].getY() &&
                       ball2.getY() - ball2.getRadius() <= (blocks[i].getY() + blocks[i].getHeight()) &&
                       ball2.getX() + ball2.getRadius() >= blocks[i].getX() &&
                       ball2.getX() - ball2.getRadius() <= blocks[i].getX() &&
                       ball2.getCollisionFlagX() == 1) { // left of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball2.reverseXVel();
                ball2.flipCollisionFlagX();

            }
        }
    }
    ball2.move();
}
//Displays the main game when called
void displayGame() {
    score = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].getX() == -90) {
            score++;
        }
    }
    //Saves and Displays Score
    score += level * 30;
    fio.writeToFile("score.txt", to_string(score));
    string messageScore = "Score: " + to_string(score);
    glColor3f(1, 1, 1);
    glRasterPos2i((width / 2) + 300, height - 450);
    for (int j = 0; j < messageScore.length(); ++j) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, messageScore[j]);
    }
    string messageNote = ("Press the 'S' Button to Save!");
    glColor3f(1, 1, 1);
    glRasterPos2i((width / 2) + 150, height - 75);
    for (int j = 0; j < messageNote.length(); ++j) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, messageNote[j]);
    }
    string messageNote2 = ("Press 'M' Button to Return to Main Menu!");
    glColor3f(1, 1, 1);
    glRasterPos2i((width / 2) + 150, height - 50);
    for (int j = 0; j < messageNote2.length(); ++j) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, messageNote2[j]);
    }
    string messageNote3 = ("Use the Left & Right Arrow Keys to Move!");
    glColor3f(1, 1, 1);
    glRasterPos2i((width / 2) + 150, height -25);
    for (int j = 0; j < messageNote3.length(); ++j) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, messageNote3[j]);
    }
    bar.draw();
    ball.draw();
    for (int i = 0; i < blocks.size(); ++i) {
        blocks[i].draw();

    }

    //handling the moving ball
    /*
     * This rather lengthy section of code deals with the collision detection for the ball when it strikes a block, a
     * wall, or the bar. Whenever the ball strikes one of the side walls or the side of a block, the x velocity of the
     * ball is reversed and the corresponding x velocity flag is flipped so that the ball is not stuck reversing its x
     * velocity infinitely many times. Likewise, whenever the ball strikes either the top wall, a top or bottom of a
     * block, or the bar, the y velocity is reversed and the corresponding y velocity flag is flipped for the same
     * reason.
     */
    if (ball.getY() + ball.getRadius() >= height && ball.getCollisionFlagY() == 1) { //bottom of the screen

        // Game over (since the ball hit the bottom!)
        gameMenu = GameOverEnum;

        bar.setX((width / 2) - (bar.getWidth() / 2));
        bar.setY(height - bar.getHeight() - 100);
        ball.setX(bar.getX() + (bar.getWidth() / 2));
        ball.setY((bar.getY() - bar.getHeight()) - ball.getRadius());
        fio.writeToFile(file, "");
    } else if (ball.getY() - ball.getRadius() <= 0 && ball.getCollisionFlagY() == 0) { //top of the screen
        ball.reverseYVel();
        ball.flipCollisionFlagY();
    } else if (ball.getX() + ball.getRadius() >= width && ball.getCollisionFlagX() == 1) { //right of the screen
        ball.reverseXVel();
        ball.flipCollisionFlagX();
    } else if (ball.getX() - ball.getRadius() <= 0 && ball.getCollisionFlagX() == 0) { //left of the screen
        ball.reverseXVel();
        ball.flipCollisionFlagX();
    } else if (ball.getY() + ball.getRadius() >= bar.getY() &&
               ball.getY() + ball.getRadius() <= (bar.getY() + bar.getHeight()) // bar
               && ball.getCollisionFlagY() == 1
               && (ball.getX() + ball.getRadius() >= bar.getX() &&
                   ball.getX() - ball.getRadius() <= (bar.getX() + bar.getWidth()))) {
        ball.reverseYVel();
        ball.flipCollisionFlagY();
        /*
         * This if statement structure eals with whenever the ball hits a certain portion of the bar. If the ball hits
         * the edges of the bar, its x velocity is amplified and its y velocity is dampened. Likewise, if the ball hits
         * the center of the bar, its y velocity is amplified and its x velocity is dampened. There is a check so that
         * this amplification and dampening is not extreme (IE, does not amplify or demand to a ridiculous degree.)
         */
        if (ball.getX() <= bar.getX() + bar.getWidth() / 3 // left portion of bar strike
            && ball.getXVel() <= 5 && ball.getXVel() >= -5) {
            ball.setXVel(ball.getXVel() * 2);
            ball.setYVel(ball.getYVel() / 2);
            if (ball.getXVel() >= 0) {
                ball.reverseXVel();
                ball.flipCollisionFlagX();
            }
        } else if (ball.getX() >= bar.getX() + bar.getWidth() / 3 + bar.getWidth() / 3
                   && ball.getXVel() <= 5 && ball.getXVel() >= -5) { // right portion of bar strike
            ball.setXVel(ball.getXVel() * 2);
            ball.setYVel(ball.getYVel() / 2);
            if (ball.getXVel() <= 0) {
                ball.reverseXVel();
                ball.flipCollisionFlagX();
            }
        } else if (ball.getYVel() <= 7 && ball.getYVel() >= -7) { // center portion of bar strike
            ball.setXVel(ball.getXVel() / 2);
            ball.setYVel(ball.getYVel() * 2);
        }
    } else {
        for (int i = 0; i < blocks.size(); ++i) {

            if (ball.getY() + ball.getRadius() >= blocks[i].getY() &&
                ball.getY() + ball.getRadius() <= (blocks[i].getY() + blocks[i].getHeight())
                && ball.getCollisionFlagY() == 1
                && (ball.getX() + ball.getRadius() >= blocks[i].getX() &&
                    ball.getX() - ball.getRadius() <= (blocks[i].getX() + blocks[i].getWidth()))) { // top of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball.reverseYVel();
                ball.flipCollisionFlagY();
            } else if (ball.getY() - ball.getRadius() <= blocks[i].getY() + blocks[i].getHeight() &&
                       ball.getY() - ball.getRadius() >= (blocks[i].getY())
                       && ball.getCollisionFlagY() == 0
                       && (ball.getX() + ball.getRadius() >= blocks[i].getX() && ball.getX() - ball.getRadius() <=
                                                                                 (blocks[i].getX() +
                                                                                  blocks[i].getWidth()))) { // bottom of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball.reverseYVel();
                ball.flipCollisionFlagY();
            } else if (ball.getY() + ball.getRadius() >= blocks[i].getY() &&
                       ball.getY() - ball.getRadius() <= (blocks[i].getY() + blocks[i].getHeight()) &&
                       ball.getX() - ball.getRadius() <= blocks[i].getX() + blocks[i].getWidth() &&
                       ball.getX() >= blocks[i].getX() + blocks[i].getWidth() &&
                       ball.getCollisionFlagX() == 0) { // right of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball.reverseXVel();
                ball.flipCollisionFlagX();

            } else if (ball.getY() + ball.getRadius() >= blocks[i].getY() &&
                       ball.getY() - ball.getRadius() <= (blocks[i].getY() + blocks[i].getHeight()) &&
                       ball.getX() + ball.getRadius() >= blocks[i].getX() &&
                       ball.getX() - ball.getRadius() <= blocks[i].getX() &&
                       ball.getCollisionFlagX() == 1) { // left of block
                blocks[i].setHardness(blocks[i].getHardness() - 1);
                ball.reverseXVel();
                ball.flipCollisionFlagX();

            }
        }
    }
    ball.move();

    //resetting the board when all blocks are destroyed
    int blockCount = 0;
    for (int j = 0; j < blocks.size(); ++j) {
        if (blocks[j].getX() == -90) {
            blockCount++;
        }
    }
    if (blockCount == 30) {
        level++;
        ball.setX(bar.getX() + (bar.getWidth() / 2));
        ball.setY((bar.getY() - bar.getHeight()) - ball.getRadius());
        resetBlocks();
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    switch (gameMenu) {
        case menuEnum:
            displayMenu();
            break;
        case inGameEnum:
            displayGame();
            break;
        case GameOverEnum:
            GameOverMenu();
            break;
        case inMenuEnum:
            displayMenu();
            break;
    }
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    //go back to menu from in-game
    if (gameMenu == inGameEnum) {
        if (key == 109) {
            bar.setX((width / 2) - (bar.getWidth() / 2));
            bar.setY(height - bar.getHeight() - 100);
            ball.setX(bar.getX() + (bar.getWidth() / 2));
            ball.setY((bar.getY() - bar.getHeight()) - ball.getRadius());
            gameMenu = inMenuEnum;
        }
    }
//Saves the game when the 's" key is pressed
    if (gameMenu == inGameEnum) {
        if (key == 115) {
            string message = "Saving!";
            glColor3f(1, 1, 1);
            glRasterPos2i(width / 2 - 250, height / 2 - 24);
            for (int i = 0; i < message.length(); ++i) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
            }
            fio.writeToFile(file, "");
            for (int i = 0; i < blocks.size(); ++i) {
                for (int j = 0; j < 2; ++j) {
                    fio.appendToFile(file, blocks[i].toString()[j]);
                }
            }
        }
    }
    return;
}

void kbdS(int key, int x, int y) {
    if (gameMenu == inGameEnum) {
        switch (key) {
            case GLUT_KEY_DOWN:
                break;
            case GLUT_KEY_LEFT:
                if (bar.getX() > 5) {
                    bar.move(-20);
                }
                break;
            case GLUT_KEY_RIGHT:
                if (bar.getX() + bar.getWidth() < width - 5) {
                    bar.move(20);
                }
                break;
            case GLUT_KEY_UP:
                break;
        }
    }
//    glutPostRedisplay();
    return;
}
void cursor(int x, int y) {
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON &&
        state == GLUT_DOWN &&
        gameMenu == menuEnum || gameMenu == inMenuEnum &&
                                (x >= newGButton.getX() &&
                                 x < newGButton.getX() + newGButton.getWidth()) &&
                                (y >= newGButton.getY() &&
                                 y < newGButton.getY() + newGButton.getHeight())) {

        //if in menu and in the confines of the new game button
        level = 0;
        resetBlocks();
        gameMenu = inGameEnum; //begin the game

    } else if (button == GLUT_LEFT_BUTTON &&
               state == GLUT_DOWN &&
               gameMenu == menuEnum || gameMenu == inMenuEnum &&
                                       (x >= loadGButton.getX() &&
                                        x < loadGButton.getX() + loadGButton.getWidth()) &&
                                       (y >= loadGButton.getY() &&
                                        y < loadGButton.getY() + loadGButton.getHeight())) {

        //if in menu and in the confines of the load game button
        int c = 0;
        int num = 30;
        string fileInfo;
        vector<RegBlock> inBlocks(num);
        vector<string> strSplice;
        inBlocks.resize(num);
        strSplice.resize(num);

        fileInfo = fio.readFromFile(file);

        if (fileInfo.size() == num * 10) {
            for (int i = 0; i < strSplice.size(); ++i) {
                strSplice[i] = fileInfo.substr(c, 10);
                c += 10;
            }

            for (int j = 0; j < inBlocks.size(); ++j) {
                inBlocks[j].setHardness(stoi(strSplice[j].substr(0, 1)));
                inBlocks[j].setX(stoi(strSplice[j].substr(2, 3)));
                inBlocks[j].setY(stoi(strSplice[j].substr(6, 3)));
            }

            for (int k = 0; k < blocks.size(); ++k) {
                blocks[k] = inBlocks[k];
            }

            score = stoi(fio.readFromFile("score.txt"));
            gameMenu = inGameEnum; //begin game
        }
    } else if (button == GLUT_LEFT_BUTTON &&
               state == GLUT_DOWN &&
               gameMenu == menuEnum || gameMenu == inMenuEnum &&
                                       (x >= exitGButton.getX() &&
                                        x < exitGButton.getX() + exitGButton.getWidth()) &&
                                       (y >= exitGButton.getY() &&
                                        y < exitGButton.getY() + exitGButton.getHeight())) {

        //if in menu and in the confines of the exit game button
        glutDestroyWindow(wd);
        exit(0);
    } else if (button == GLUT_LEFT_BUTTON &&
               state == GLUT_DOWN &&
               gameMenu == GameOverEnum &&
               (x >= mainMButton.getX() &&
                x < mainMButton.getX() + mainMButton.getWidth()) &&
               (y >= mainMButton.getY() &&
                y < mainMButton.getY() + mainMButton.getHeight())) {

        resetBlocks();
        gameMenu = inMenuEnum;

    } else if (button == GLUT_LEFT_BUTTON &&
               state == GLUT_DOWN &&
               gameMenu == GameOverEnum &&
               (x >= exitGButton.getX() &&
                x < exitGButton.getX() + exitGButton.getWidth()) &&
               (y >= exitGButton.getY() &&
                y < exitGButton.getY() + exitGButton.getHeight())) {

        //if in menu and in the confines of the exit game button
        glutDestroyWindow(wd);
        exit(0);
    }
    glutPostRedisplay();
}

void timer(int extra) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char **argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int) width, (int) height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Block Breaker" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}