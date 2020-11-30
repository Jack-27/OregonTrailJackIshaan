#include <fstream>
#include <iostream>
#ifndef STORE_H
#define STORE_H
using namespace std;

class store {
    private:
        ifstream shopText;
        int timesVisited;
        double bill;
        int option;
        bool oxenBought;
        
    public:
        int run(double money, party main) {
            bill = 0;
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
                    int tempNum = oxen();
                    if (bill + tempNum > money) {
                        cout << "Not enough money to buy this item." << endl;

                    } else {
                        main.items.addOxen(tempNum / (40 * (1 + .25 * timesVisited)));
                        bill += tempNum;
                        cout << "The current bill is " << bill << ".";
                        oxenBought = true;
                    }
                    break;
                case 2:
                    int tempNum = food();
                    if (bill + tempNum > money) {
                        cout << "Not enough money to buy this item." << endl;

                    } else {
                        main.items.addFood(tempNum / (0.5 * (1 + .25 * timesVisited)));
                        bill += tempNum;
                        cout << "The current bill is " << bill << ".";
                    }
                    break;
                case 3:
                    int tempNum = bullets();
                    if (bill + tempNum > money) {
                        cout << "Not enough money to buy this item." << endl;

                    } else {
                        main.items.addBullets((tempNum / (2 * (1 + .25 * timesVisited))) * 20);
                        bill += tempNum;
                        cout << "The current bill is " << bill << ".";
                    }
                    break;
                case 4:
                    miscItems(money, main);
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
            main.addMoney(bill * -1.0);
            cout << "Your remaining money is " << main.getMoney() << endl;
            timesVisited++;
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
            } else {
                cout << "Invalid input." << endl;
                return oxen();
            }
            
            
        }
        double food() {
            int choice;
            double price = 0.5 * (1 + .25 * timesVisited);
            cout << "You should proabably buy 200 pounds of food per person. The price is " << price ;
            cout << " per pound, how many pounds would you like?" << endl;
            cin >> choice;
            if (choice >= 1) {
                return choice * price;
            } else {
                cout << "Invalid input." << endl;
                return food();
            }

        }
        double bullets() {
            int choice;
            double price = 2 * (1 + .25 * timesVisited);
            cout << "You will need bullets to hunt for food and fend off raiders. The price is " << price ;
            cout << " per 20 bullets, how many boxes of bullets would you like?" << endl;
            cin >> choice;
            if (choice >= 1) {
                return choice * price;
            } else {
                cout << "Invalid input." << endl;
                return bullets();
            }

        }
        double miscItems(int money, party mparty) {
            int choice;
            int wagonParts;
            double price = 20 * (1 + .25 * timesVisited);
            cout << "You will need wagon parts to fix your wagon. The price is " << price ;
            cout << " per wagon part, how many parts would you like?" << endl;
            cin >> wagonParts;
            if (wagonParts >= 1) {
                cout << "You will need medical aid kits to help heal party members a kit costs " << 25 * (1 + .25 * timesVisited);
                cout << " , how many do you want?" << endl;
                cin >> choice;
                if (choice >= 1) {
                    if (wagonParts * price + choice * (25 * (1 + .25 * timesVisited)) + bill < money) {
                        mparty.items.addWagonParts(wagonParts);
                        mparty.items.addMedKits(choice);
                        bill += wagonParts * price + choice * (25 * (1 + .25 * timesVisited));
                        cout << "Your current bill is " << bill << endl;
                        return 0.1;
                    } else {
                        cout << "Not enough money." << endl;
                        return 0.1;
                    }
                    
                } else {
                    cout << "Invalid input." << endl;
                    return miscItems(money, mparty);
                }

            } else {
                cout << "Invalid input." << endl;
                return miscItems(money, mparty);
            }
        }
        
 
};

#endif
