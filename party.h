#include "people.h"
#include "storage.h"
#ifndef PARTY_H
#define PARTY_H


class party {

    private:
        int miles;
        int day;
        int month;
        double money;
        bool over;
        
    public:
        people characters[5];
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
        int numCharAlive()
        {
            int j = 0;
            for(int i = 0; i < 5; i++)
            {
                if(characters[i].isAlive() == true)
                {
                    j++;
                }
            }
            return j;
        }
        bool isOver() {
            return over;
        }
        void endGame() {
            over = true;
        }
        party() {
            over = false;
            money = 1600;
        }
        void addDays(int days) {
            for(int i = 0; i < days; i++) {
                if (day == daysInMonth(month)) {
                    month++;
                } else {
                    day++;
                }
            }
        }

        int daysInMonth( int month) {
            int year = 1947;
            if (month > 0 && month < 13) {
                if (month != 2) {
                    switch (month % 2)
                    {
                    case 1:
                        if (month < 7) {
                            return 31;
                        } else {
                            return 30;
                        }
                        break;
                    case 0:
                        if (month > 7) {
                            return 31;
                        } else {
                            return 30;
                        }
                    default:
                        break;
                    }
                } else {
                    if (year > 1582) {
                        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                            return 29;
                        } else {
                            return 28;
                        }
                    } else {
                        if (year % 4 == 0) {
                            return 29;
                        } else {
                            return 28;
                        }
                    }
                }
            } 

        }
};


#endif