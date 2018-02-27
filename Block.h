#ifndef BLOCKBREAKER_BLOCK_H
#define BLOCKBREAKER_BLOCK_H

#include <vector>
#include <iostream>

using namespace std;

//pure abstract
class Block {
public:
    Block();

    Block(int hardnessC, vector<double> colorC, int xC, int yC);

    //gets called when hardness <= 0
    /*
     * R: nothing
     * M: removes a block
     * E: height, width, x, y
     */
    virtual void destroySelf();

    /*
     * R: nothing
     * M: itself
     * E: returns the fields as a vector of strings
     */
    virtual vector<string> toString() const = 0;

    /*
     * R: nothing
     * M: itself
     * E: draws and colors the block
     */
    void draw() const;

    //setters
    virtual void setHardness(int hardnessM);

    void setColor(vector<double> colorM);

    void setX(int xM);

    void setY(int yM);

    void setWidth(int widthM);

    void setHeight(int heightM);

    //getters
    int getHardness() const;

    vector<double> getColor() const;

    int getWidth() const;

    int getHeight() const;

    int getX() const;

    int getY() const;

protected:
    int width = 50; //x
    int height = 20; //y
    int hardness;
    vector<double> color;
    int x;
    int y;
private:
};

class RegBlock : public Block {
public:
    RegBlock();

    RegBlock(int hardnessC, vector<double> colorC, int xC, int yC);

    /*
     * R: int
     * M: hardness
     * E: modifies hardness of a block
     */
    void setHardness(int hardnessM) override;

    /*
     * R: nothing
     * M: removes a block
     * E: height, width, x, y
     */
    void destroySelf() override;

    /*
     * R: nothing
     * M: nothing
     * E: parses data about the block into string format
     */
    vector<string> toString() const override;
};

#endif //BLOCKBREAKER_BLOCK_H
