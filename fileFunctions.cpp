#include <fstream>
#include <iostream>
using namespace std;


//This is where all the functions that deal with file IO will go
void readFile(string file) {
            fstream text;
            text.open("textFiles/" + file);
            string line = "";
            while( getline(text, line)) {
                cout << line << endl;
            }

        }
