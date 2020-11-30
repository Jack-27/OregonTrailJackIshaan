#include "storage.h"
#include "store.h"
#include "milestone.h"
#include "party.h"
#include "people.h"
#include "functions.h"
#include "fileFunctions.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <vector>
using namespace std;

void game(){
    
    party mainParty;
    initParty(mainParty);
    initStartDate(mainParty);
    store mainStore;
    mainStore.run(mainParty.getMoney(), mainParty);
    while (mainParty.isOver() == true) {
        turn(mainParty);
    }
    // Score stuff goes here

}

int main() {
    game();

}
