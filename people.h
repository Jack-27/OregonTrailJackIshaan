#include <string>
#ifndef PEOPLE_H
#define PEOPLE_H
using namespace std;

class people {
    public:
        string getName() {
            return name;
        }
        bool isPlayer() {
            return player;
        }
        people(string nameI, bool playerI) {
            name = nameI;
            player = playerI;
            alive = true;
        }
        bool isAlive() {
            return alive;
        }
        void kill() {
            alive = false;
        }
        people() {
            name = "";
        }
    private:
        string name;
        bool player;
        bool alive;
};

#endif