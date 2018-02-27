#ifndef BLOCKBREAKER_BAR_H
#define BLOCKBREAKER_BAR_H


#include <vector>

using namespace std;


class Bar {
public:
    Bar();

    Bar(int widthC, int heightC, vector<double> colorC, int xC, int yC);

    /*
     * R: nothing
     * M: x and y
     * E: moves the Bar
     */
    void move(int deltax);


    /*
     * R: nothing
     * M: nothing
     * E: draws the bar on screen
     */
    void draw() const;

    //setters
    void setHeight(int heightM);

    void setWidth(int widthM);

    void setColor(vector<double> colorM);

    void setX(int xM);

    void setY(int yM);

    //getters
    vector<double> getColor() const;

    int getHeight() const;

    int getWidth() const;

    int getX() const;

    int getY() const;

private:
    int height;
    int width;
    vector<double> color;
    int x;
    int y;
};

#endif //BLOCKBREAKER_BAR_H
