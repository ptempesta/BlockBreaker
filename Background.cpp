

#include "Background.h"
#include "Graphics.h"

void Background::draw(int Dheight, int Dwidth, vector<double> colorC, int xPos, int yPos) {

    x = xPos;
    y = yPos;
    height = Dheight;
    width = Dwidth;
    color = colorC;

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);
    glVertex2i(xPos, yPos);
    glVertex2i(xPos + width, yPos);
    glVertex2i(xPos + width, yPos + height);
    glVertex2i(xPos, yPos + height);
    glEnd();
}

int Background::getX() const {
    return x;
}

int Background::getY() const {
    return y;
}

int Background::getHeight() const {
    return height;
}

int Background::getWidth() const {
    return width;
}

vector<double> Background::getColor() const {
    return color;
}

void Background::setColor(vector<double> colorM) {
    color = colorM;
}
