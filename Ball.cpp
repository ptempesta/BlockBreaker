#include "Graphics.h"
#include "Ball.h"
#include <windows.h>

Ball::Ball() {
    setRadius(25);
    setColor({1.0, 0.0, 0.0});
    setX(250);
    setY(250);
    xvel = -3;
    yvel = -4;
    collisionFlagX = 0;
    collisionFlagY = 0;
}
//Sets the ball's values
Ball::Ball(int radiusC, vector<double> colorC, int xC, int yC) {
    setRadius(radiusC);
    setColor(colorC);
    setX(xC);
    setY(yC);
    xvel = -3;
    yvel = -4;
    collisionFlagX = 0;
    collisionFlagY = 0;
}
//Moves the ball
void Ball::move() {

    setX(x += xvel);
    setY(y += yvel);

}
//Reverses x velocity
void Ball::reverseXVel() {
    xvel *= -1;

}
//Reverses y velocity
void Ball::reverseYVel() {
    yvel *= -1;

}
//Draws ball
void Ball::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(getColor()[0], getColor()[1], getColor()[2]);
    glVertex2i(getX(), getY());
    for (double i = 0; i <= 2.0 * PI + 0.05; i += 2.0 * PI / 360.0) {
        glVertex2i(getX() + getRadius() * cos(i), getY() + getRadius() * sin(i));
    }
    glEnd();
}
//sets radius
void Ball::setRadius(int radiusM) {
    radius = radiusM;
}
//Sets color for ball
void Ball::setColor(vector<double> colorM) {
    color = colorM;
}
//Sets x position
void Ball::setX(int xM) {
    x = xM;
}
//Sets y position
void Ball::setY(int yM) {
    y = yM;
}
//Sets x velocity
void Ball::setXVel(double xV) {
    xvel = xV;
}
//Sets y velocity
void Ball::setYVel(double yV) {
    yvel = yV;
}

int Ball::getRadius() const {
    return radius;
}

vector<double> Ball::getColor() const {
    return color;
}

int Ball::getX() const {
    return x;
}

int Ball::getY() const {
    return y;
}

int Ball::getCollisionFlagX() const {
    return collisionFlagX;
}

int Ball::getCollisionFlagY() const {
    return collisionFlagY;
}

double Ball::getXVel() const {
    return xvel;
}

double Ball::getYVel() const {
    return yvel;
}
//Flips collision flag so ball can no longer get stuck
void Ball::flipCollisionFlagX() {
    if (collisionFlagX == 0) {
        collisionFlagX = 1;
    } else if (collisionFlagX == 1) {
        collisionFlagX = 0;
    }
}
//Flips collision flag so ball can no longer get stuck
void Ball::flipCollisionFlagY() {
    if (collisionFlagY == 0) {
        collisionFlagY = 1;
    } else if (collisionFlagY == 1) {
        collisionFlagY = 0;
    }
}