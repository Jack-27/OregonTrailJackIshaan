#include <string>
#ifndef MILESTONE_H
#define MILESTONE_H
using namespace std;

class milestone {
    private:
        string name;
        string type;
        int mile;
    public:
        milestone(string nameI, string typeI, int mileI) {
            name = nameI;
            type = typeI;
            mile = mileI;
        } 
        string getName() {
            return name;
        }
        string getType() {
            return type;
        }
        int getMile() {
            return mile;
        }
        milestone() {
            name = "";
        }
        
};


#endif