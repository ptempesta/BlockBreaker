#ifndef BLOCKBREAKER_FILEIO_H
#define BLOCKBREAKER_FILEIO_H

#include<iostream>
#include <fstream>
#include <string>

using namespace std;


class FileIO {
public:
    FileIO();

    /*
     * R: nothing
     * M: nothing
     * E: writes to a file, overwrites content already there
     */
    void writeToFile(string fileName, string text);

    /*
     * R: nothing
     * M: nothing
     * E: writes to a file, appending text to the file
     */
    void appendToFile(string fileName, string text);

    /*
     * R: nothing
     * M: nothing
     * E: returns all of the content of the file
     */
    string readFromFile(string fileName);

};


#endif //BLOCKBREAKER_FILEIO_H
