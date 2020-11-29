#include "people.h"
#include "storage.h"
#ifndef PARTY_H
#define PARTY_H


class party {

    private:
        people characters[5];
        int miles;
        int day;
        int month;
        double money;
        bool over;
        
    public:
        storage items;
        double getMoney() {
            return money;
        }
        string getDate() {
            return to_string(month) + "/" + to_string(day) + "/1947";
        }
        void addChar(people person, int at) {
            characters[at] = person;
        }
        int addMoney(int cash) {
            money += cash;
        }
        void setDate(int dayI, int monthI) {
            day = dayI;
            month = monthI;
        }
        int getMiles() {
            return miles;
        }
        void addMiles(int input) {
            miles += input;
        }
        int getMilesLeft() {
            return 2040 - miles;
        }
        void killChar(int at) {
            characters[at].kill();
        }
        bool checkChar(int at) {
            return characters[at].isAlive();
        }
        bool isOver() {
            return over;
        }
        void endGame() {
            over = true;
        }
        party() {
            over = false;
        }
};

#endif