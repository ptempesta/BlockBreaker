#include "Block.h"
#include "Graphics.h"

Block::Block() {
    setX(0);
    setY(0);
    setHardness(1);
    setColor({1.0, 0.0, 1.0});
}

Block::Block(int hardnessC, vector<double> colorC, int xC, int yC) {
    setX(xC);
    setY(yC);
    setHardness(hardnessC);
    setColor(colorC);
}

void Block::destroySelf() {}

void Block::draw() const {
    glBegin(GL_QUADS);
    glColor3d(getColor()[0], getColor()[1], getColor()[2]);
    glVertex2i(x, y);
    glVertex2i(x + getWidth(), y);
    glVertex2i(x + getWidth(), y + getHeight());
    glVertex2i(x, y + getHeight());
    glEnd();
}

void Block::setHardness(int hardnessM) {
    if (hardnessM <= 0) {
        destroySelf();
    } else {
        hardness = hardnessM;
    }
}

void Block::setColor(vector<double> colorM) {
    color = colorM;
}

void Block::setX(int xM) {
    x = xM;
}

void Block::setY(int yM) {
    y = yM;
}

int Block::getHardness() const {
    return hardness;
}

vector<double> Block::getColor() const {
    return color;
}

int Block::getX() const {
    return x;
}

int Block::getY() const {
    return y;
}

int Block::getWidth() const {
    return width;
}

int Block::getHeight() const {
    return height;
}

void Block::setWidth(int widthM) {
    width = widthM;
}

void Block::setHeight(int heightM) {
    height = heightM;
}

RegBlock::RegBlock() = default;

RegBlock::RegBlock(int hardnessC, vector<double> colorC, int xC, int yC) {
    setX(0);
    setY(0);
    setHardness(1);
    setColor({1.0, 1.0, 1.0});
}


void RegBlock::destroySelf() {
    height = 0;
    width = 0;
    x = -90;
    y = -90;
}

void RegBlock::setHardness(int hardnessM) {
    if (hardnessM <= 0) {
        vector<double> temp;
        temp = {0, 0, 0};
        setColor(temp);
        destroySelf();
    } else if (hardnessM == 1) {
        vector<double> temp;
        temp = {0, 1, 0};
        setColor(temp);
        hardness = hardnessM;
    } else if (hardnessM == 2) {
        vector<double> temp;
        temp = {1, 1, 0};
        setColor(temp);
        hardness = hardnessM;
    } else if (hardnessM >= 3) {
        vector<double> temp;
        temp = {1, 0, 0};
        setColor(temp);
        hardness = hardnessM;
    }
}

vector<string> RegBlock::toString() const {
    string strHard = to_string(getHardness());
    string strPos = ("{" + to_string(getX()) + "," + to_string(getY()) + "}");

    return {strHard, strPos};
}