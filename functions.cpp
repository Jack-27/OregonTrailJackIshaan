#include "storage.h"
#include "store.h"
#include "party.h"
#include "people.h"
#include <iostream>
#include <string>
using namespace std;

void turn() {

    computeDistanceTraveled();
    statusUpdate();
    milestone();
    eventCalc();

}
void init() {
//initializes game by doing the following steps
// Load in milestone array
// Load new party
// Ask for name of player
// Ask for names of companians
// Choose start date
//all give a little bit of story

}

void statusUpdate() {
    // this is where the status update will be printed
}

void computeDistanceTraveled() {
    //This will figure out how far the player has traveled based on oxen and rng
    //This will then round down to the next milestone if applicable
}

int distToNextMilestone() {
    //returns how many miles away the next milestone is
}

void milestone() {
    //gives the player options based on what kind of milestone (if any) they are at
}
void eventCalc() {
    //runs through probabities of events launching 
}
void misfortune() {
    //chooses and executes a misfortune
}
void fortune() {
    //chooses and executes a fortune
}
