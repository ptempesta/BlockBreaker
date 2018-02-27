#ifndef BLOCKBREAKER_BALL_H
#define BLOCKBREAKER_BALL_H

#include <vector>
#include <cmath>

using namespace std;


class Ball {
public:
    Ball();

    Ball(int radiusC, vector<double> colorC, int xC, int yC);

    /*
     * R: nothing
     * M: x and y
     * E: moves the ball, calculates if it hits the edge of the window and
     *    handles dealing damage to the blocks, as well as bouncing off them
     */
    void move();

    /*
     * R: nothing
     * M: xvel
     * E: flips the sign of xvel
     */
    void reverseXVel();

    /*
     * R: nothing
     * M: yvel
     * E: flips the sign of yvel
     */
    void reverseYVel();

    /*
     * R: nothing
     * M: collisionFlagX
     * E: 0 => 1 or 1 => 0
     */
    void flipCollisionFlagX();

    /*
     * R: nothing
     * M: collisionFlagY
     * E: 0 => 1 or 1 => 0
     */
    void flipCollisionFlagY();

    /*
     * R: nothing
     * M: nothing
     * E: draws the ball on screen
     */
    void draw() const;

    //setters
    void setRadius(int radiusM);

    void setColor(vector<double> colorM);

    void setX(int xM);

    void setY(int yM);

    void setXVel(double xV);

    void setYVel(double yV);

    //getters
    int getRadius() const;

    vector<double> getColor() const;

    int getX() const;

    int getY() const;

    int getCollisionFlagX() const;

    int getCollisionFlagY() const;

    double getXVel() const;

    double getYVel() const;

private:
    double PI = 3.141569265358979323;
    int radius;
    vector<double> color;
    int x;
    int y;
    double xvel;
    double yvel;

    int collisionFlagX;
    int collisionFlagY;
};


#endif //BLOCKBREAKER_BALL_H
