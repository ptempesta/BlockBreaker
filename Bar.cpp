#include "Bar.h"
#include "Graphics.h"
//Sets initial instance of a bar
Bar::Bar() {
    setX(0);
    setY(0);
    setHeight(10);
    setWidth(400);
    setColor({1.0, 1.0, 1.0});
}
//Sets all values for the bar
Bar::Bar(int widthC, int heightC, vector<double> colorC, int xC, int yC) {
    setX(xC);
    setY(yC);
    setWidth(widthC);
    setHeight(heightC);
    setColor(colorC);
}

//Moves bar
void Bar::move(int deltax) {
    setX(getX() + deltax);
}
//Draws the bar
void Bar::draw() const {
    glBegin(GL_QUADS);
    glColor3d(getColor()[0], getColor()[1], getColor()[2]);
    glVertex2i(x, y);
    glVertex2i(x + getWidth(), y);
    glVertex2i(x + getWidth(), y + getHeight());
    glVertex2i(x, y + getHeight());
    glEnd();
}
//Sets the bars's color
void Bar::setColor(vector<double> colorM) {
    color = colorM;
}
//sets x value
void Bar::setX(int xM) {
    x = xM;
}
//sets the y value
void Bar::setY(int yM) {
    y = yM;
}
//sets the width
void Bar::setWidth(int widthM) {
    width = widthM;
}
//sets the height
void Bar::setHeight(int heightM) {
    height = heightM;
}

vector<double> Bar::getColor() const {
    return color;
}

int Bar::getHeight() const {
    return height;
}

int Bar::getWidth() const {
    return width;
}

int Bar::getX() const {
    return x;
}

int Bar::getY() const {
    return y;
}