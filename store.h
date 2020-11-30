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
        int option;
        bool oxenBought;
    public:
        int run(double money) {
            if (timesVisited == 0) {
                readFile("store_info.txt");
                oxenBought == 0;
            }
            while (option != 5) {
                readFile("storeMenu.txt");
                cin >> option;
                switch (option)
                {
                case 1:
                    oxen();
                    break;
                case 2:
                    food();
                    break;
                case 3:
                    bullets();
                    break;
                case 4:
                    miscItems();
                    break;
                case 5:
                    if (!oxenBought) {
                        cout << "You need to buy oxen first." << endl;
                        option = 0;
                    }
                    break;
                default:
                    cout << "Invalid option, please hit 1-5." << endl;
                    break;
                }
            }
        }
        
        //each of these functions will print what buying them does, let the player buy them, and return a double to be added to the bill
        double oxen() {
            int choice;
            double price = 40 * (1 + .25 * timesVisited);
            if (timesVisited == 0) {
                cout << "You buy oxen in pairs, you must buy 3-5 pairs of oxen if its your first time." << endl;
            } else {
                cout << "You buy oxen in pairs, more than 5 pairs seems to help less and less though." << endl;
            }
            cout << "The price per pair of Oxen is " << price << ", how many would you like?" << endl;
            cin >> choice;
            if (choice < 2 || choice > 5 && timesVisited == 0) {
                cout << "You must buy 3-5 pairs of oxen" << endl;
                return oxen();
            } 
            if (choice >= 1) {
                return choice * price;
            }
            
            
        }
        double food() {

        }
        double bullets() {

        }
        double miscItems() {

        }
        
 
};

#endif
