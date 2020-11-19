#include <fstream>
#include <iostream>
#ifndef STORE_H
#define STORE_H
using namespace std;

class store {
    private:
        ifstream shopText;
        int timesVisited;
        int bill;
    public:
        int main(int money) {
            if (timesVisited == 0) {
                readFile();
            }
            // This is where a menu for the store is going to go, with each options funtions down below, 
            // The funtions are seperate because I plan to add a travelling shop event that only lets the player buy one thingx.
        }
        void readFile() {
            shopText.open("store_info.txt");
            string line = "";
            while( getline(shopText, line)) {
                cout << line << endl;
            }

        }
        //each of these functions will print what buying them does, let the player buy them, and return a double to be added to the bill
        double oxen() {

        }
        double food() {

        }
        double bullets() {

        }
        double miscItems() {

        }
 
};

#endif
