#include "storage.h"
#include "store.h"
#include "party.h"
#include "people.h"
#include "milestone.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <vector>
using namespace std;


int main() {
    

}
void game(){
    vector <milestone> milestones;
    readMilestones("textFiles/milestones.txt", milestones);
    party mainParty;
    initParty(mainParty);
    initStartDate(mainParty);
    store mainStore;
    mainStore.run(mainParty.getMoney(), mainParty);
    while (mainParty.isOver() == true) {
        turn();
    }
    // Score stuff goes here

}