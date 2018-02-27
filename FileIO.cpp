#include "FileIO.h"

FileIO::FileIO() {

}
//Writes to file
void FileIO::writeToFile(string fileName, string text) {
    ofstream f_out;
    string file = fileName;
    f_out.open(file);
    if (f_out) {
        f_out << text;
    }
    f_out.close();
}
//Appends to file
void FileIO::appendToFile(string fileName, string text) {
    ofstream f_out;
    string file = fileName;
    f_out.open(file, ios::out | ios::app);
    if (f_out) {
        f_out << text;
    }
    f_out.close();
}
//Reads to file
string FileIO::readFromFile(string fileName) {
    ifstream f_in;

    f_in.open(fileName);
    string first_line;
    if (f_in) {
        getline(f_in, first_line);

    }

    f_in.close();
    return first_line;
}