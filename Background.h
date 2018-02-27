#ifndef BLOCKBREAKER_BACKGROUND_H
#define BLOCKBREAKER_BACKGROUND_H

#include <vector>

using namespace std;

class Background {
public:
    /*
     * R: Dheight, Dwidth, color, xPos, yPos
     * M: background
     * E: draws the background
     */
    void draw(int Dheight, int Dwidth, vector<double> color, int xPos, int yPos);

    int getX() const;

    int getY() const;

    int getWidth() const;

    int getHeight() const;

    vector<double> getColor() const;

    void setColor(vector<double> colorM);

private:
    int x;
    int y;
    int width;
    int height;
    vector<double> color;
};


#endif //BLOCKBREAKER_BACKGROUND_H
