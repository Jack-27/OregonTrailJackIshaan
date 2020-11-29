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
        int run(int money) {
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

        }
        double food() {

        }
        double bullets() {

        }
        double miscItems() {

        }
 
};

#endif
