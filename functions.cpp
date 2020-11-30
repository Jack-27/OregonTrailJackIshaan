#include "storage.h"
#include "store.h"
#include "party.h"
#include "people.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <vector>
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
    int choice;
    cout << party::getDate << endl;    // this is where the status update will be printed
    cout << endl;
    cout << "TOTAL MILEAGE IS " << computeDistanceTraveled << endl;
    cout << "FOOD       BULLETS       OXEN       WAGON PARTS       MEDKIT       CASH" << endl;
    cout << storage::getFood() << "          " << storage::getBullets() << "            " << storage::getOxen() << "             " << storage::getWagonParts() << "              " << storage::getMedKits() << "          " << party::getMoney() << endl; 
}

void computeDistanceTraveled(int distance) {
    //This will figure out how far the player has traveled based on oxen and rng
    //This will then round down to the next milestone if applicable
    srand(time(0));
    int ran;
    int newdistance;
    if(storage::getOxen() > 8)
    {
        ran = rand() % 14;
        newdistance = 140 - ran;
    }
    if(storage::getOxen() > 6) && (storage::getOxen() < 9)
    {
        ran = rand() % 14;
        newdistance = 126 - ran;
    }
    if(storage::getOxen() > 4) && (storage::getOxen() < 7)
    {
        ran = rand() % 14;
        newdistance = 112 - ran;
    }
    if(storage::getOxen() > 2) && (storage::getOxen() < 5)
    {
        ran = rand() % 14;
        newdistance = 98 - ran;
    }
    if(storage::getOxen() > 0) && (storage::getOxen() < 3)
    {
        ran = rand() % 14;
        newdistance = 84 - ran;
    }
    cout << "YOU HAVE TRAVELED " << newdistance + distance << "MILES!" << endl;
}
int randomAlive()
{
    srand(time(0));
    int i = 0;
    int ran;
    while(i < 5)
    {
        ran = rand() % 5;
        if(party::checkChar(i) = true && i == ran)
        {
            return i;
        }

        i++;

    }

    return 0;
}

int distToNextMilestone() {
    //returns how many miles away the next milestone is
}

void milestone() {
    //gives the player options based on what kind of milestone (if any) they are at

}
void eventCalc() {
    //runs through probabities of events launching 
    srand(time(0));         //chance of raiders
    double ran;
    double prob;
    prob = pow(party::getMiles() / 100 - 4,2) + 72;
    prob = prob / pow(party::getMiles() / 100 - 4, 2) + 12;
    prob = prob - 1;
    prob = prob / 0.10;
    prob =100 - prob;
    ran = rand() % 100;
    if(ran > prob)
    {
        raiders();
    }

    int ran = rand() % 10;  //chooses and executes a misfortune
    if(ran > 4)
    {
        misfortune();
    }


}
void raiders()
{
    srand(time(0));
    int ran;
    int choice;
    int i = 0;
    int loss;
    cout << "RAIDERS AHDEAD! THEY LOOK HOSTILE!" << endl;
    while(choice > 3 && choice < 1)
    {
        cout << "WOULD YOU LIKE TO RUN(1), ATTACK(2), OR SURRENDER(3)?" << endl;
        cin >> choice;
    }

    switch(choice)
    {
        case 1:
        cout << "YOU MANAGED TO ESCAPE, BUT IN YOUR HURRY TO FLEE YOU HAVE LOST 1 OX, 10LBS OF FOOD, AND 1 WAGON PART!" << endl;
        storage::addOxen(-1);
        storage::addFood(-10);
        storage::addWagonParts(-1);
        break;

        case 2:
        cout << "YOU HAVE DECIDED TO FIGHT!" << endl;
        cout << "YOU MUST COMPLETE A PUZZLE IN ORDER TO WIN!" << endl;

        ran = rand() % 10;

        cout << "YOU HAVE THREE TRIES TO GUESS A NUMBER 0-9!" << endl;

        while((choice != ran) && (i < 3))
        {
            cout << "GUESS #" << i + 1 << "!" << endl;
            cin >> choice;
            i++;
        }
        if(choice == ran)
        {
            cout << "YOU HAVE GUESS THE CORRECT NUMBER! YOU HAVE SCARED AWAY THE RAIDERS AND AS THEY WERE RUNNING, THEY DROPPED 50LBS OF FOOD AND 50 BULLETS!" << endl;
            storage::addBullets(50);
            storage::addBullets(50);
        }
        if(choice != ran)
        {
            cout << "YOU HAVE LOST THE BATTLE AND MUST FLEE! 50 BULLESTS WERE USED DURING THE BATTLE! AS YOU'RE FLEEING YOU DROP A QUARTER OF YOUR CASH SUPPLY!" << endl;
            loss = party::getMoney();
            loss = loss / 4;
            party::addMoney(-loss);
            storage::addBullets(-50);
        }
        break;

        case 3:
        cout << "YOU HAVE CHOSEN TO SURRENDER AND THE RAIDERS TAKE A QUARTER OF YOUR CASH SUPPLY!" << endl;
        party::addMoney(-loss);
        break;
    }
}


void misfortune() {
    srand(time(0));
    int ran;  //chooses and executes a misfortune
    string sick;
    int i;
    int i = randomAlive();
    string name = people::getName(i);
    ran = rand() % 3;

    switch(ran)
    {
        
        case 0:
            ran = rand() % 6;
            switch(ran)
            {
                case 0:
                cout << "OH NO! " << << "HAS THE TYPHOID" << endl;
                sick = "TYPHOID";
                break;

                case 1:
                cout << "OH NO! " << << "HAS THE CHOLERA" << endl;
                sick = "CHOLERA";
                break;

                case 2:
                cout << "OH NO! " << << "HAS THE THE DIARRHEA" << endl;
                sick = "DIARRHEA";
                break;

                case 3:
                cout << "OH NO! " << << "HAS THE THE MEASLES" << endl;
                sick = "THE MEASLES";
                break;

                case 4:
                cout << "OH NO! " << << "HAS THE THE DYSENTERY" << endl;
                sick = "DYSENTARY";
                break;

                case 5:
                cout << "OH NO! " << << "HAS THE THE FEVER" << endl;
                sick = "THE FEVER";
                break;   
            }
            if(storage::getMedKits() > 0)
            {
                ran = rand() % 2;
                if(ran = 0)
                {
                    cout << << " DIED OF " << sick << endl;
                    party::killChar(i);
                }
                else
                {
                    cout << << "HAS SURVIVED " << sick << endl;
                }
                cout << "MEDKIT SUPPLY -1." << endl;
                storage::addMedKits(-1);
            }
            else
            {
                cout << "WOULD YOU LIKE TO REST(1) IN AN ATTEMPT TO HEAL " << << " , OR PRESS ON(2)?" << endl;
                cin >> i;

                if(i == 1)
                {
                    ran = rand() % 10;
                    if(ran > 2)
                    {
                        cout << << "HAS SURVIVED " << sick << endl;
                    }
                    else
                    {
                    cout << << " DIED OF " << sick << endl;
                    party::killChar(i);
                    }
                }
                else
                {
                    ran = rand() % 10;
                    if(ran > 2)
                    {
                        cout << << " DIED OF " << sick << endl;
                        party::killChar(i);
                    }
                    else
                    {
                    cout << << "HAS SURVIVED " << sick << endl;
                    }
                }
                
                
            }
            if(party::characters[0].isAlive() == false) //leader dies game ends
            {
                cout << "THE LEADER OF THE PARTY HAS DIED."
                party::endGame();
            }
        break;

        case 1:
        storage::addOxen(-1);

        cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << storage::getOxen() << " LEFT." << endl;

        if(storage::getOxen() < 1)
        {
            cout << "YOU ARE UNABLE TO CONTINUE DUE TO LOOSING ALL YOUR OXEN."
            party::endGame();
        }
        else
        {
            cout << "YOU ARE STILL ABLE TO CONTINUE AND PARTS OF THE OXEN ARE ABLE TO BE HARVEST FOR FOOD." << endl;
            storage::addFood(100);
        }
        
        break;

        case 2:
        string part;
        ran = rand() % 3;
        if(ran = 0)
        {
            part = "WHEELS";
        }
        if(ran = 1)
        {
            part = "AXLES";
        }
        if(ran = 2)
        {
            part = "TONGUES";
        }
        
        cout << "OH NO! ONE OF YOUR " << part << " IS BROKEN!" << endl;

        if(storage::getWagonParts > 0)
        {
            cout << "YOU USE ONE OF YOUR SPARE WAGON PARTS TO FIX THE BREAK." << endl;
            storage::addWagonParts(-1);
        }
        else
        {
            cout << "DUE TO YOUR BROKEN WAGON, YOU ARE UNABLE TO CONTINUE ON YOUR TREK ACROSS THE U.S.!" << endl;
            party::endGame();
        }
        break;
    }

    int ran = rand() % 10;  //chooses and executes a misfortune
    string sick;
    int i;
    if(ran < 4)
    {
        cout << "No Misfortunes" << endl;
    }
    else
    {
        ran = rand() % 3;
    
        switch(ran)
        {
            case 0:
                if()//need to select random person thats alive
                {

                } 
                ran = rand() % 6;
                switch(ran)
                {
                    case 0:
                    cout << "OH NO! " << << "HAS THE TYPHOID" << endl;
                    sick = "TYPHOID";
                    break;

                    case 1:
                    cout << "OH NO! " << << "HAS THE CHOLERA" << endl;
                    sick = "CHOLERA";
                    break;

                    case 2:
                    cout << "OH NO! " << << "HAS THE THE DIARRHEA" << endl;
                    sick = "DIARRHEA";
                    break;

                    case 3:
                    cout << "OH NO! " << << "HAS THE THE MEASLES" << endl;
                    sick = "THE MEASLES";
                    break;

                    case 4:
                    cout << "OH NO! " << << "HAS THE THE DYSENTERY" << endl;
                    sick = "DYSENTARY";
                    break;

                    case 5:
                    cout << "OH NO! " << << "HAS THE THE FEVER" << endl;
                    sick = "THE FEVER";
                    break;   
                }
                if(storage::getMedKits() > 0)
                {
                    ran = rand() % 2;
                    if(ran = 0)
                    {
                        cout << << " DIED OF " << sick << endl;
                        party::killChar(x);
                    }
                    else
                    {
                        cout << << "HAS SURVIVED " << sick << endl;
                    }
                    cout << "MEDKIT SUPPLY -1." << endl;
                    storage::addMedKits(-1);
                }
                else
                {
                    cout << "WOULD YOU LIKE TO REST(1) IN AN ATTEMPT TO HEAL " << << " , OR PRESS ON(2)?" << endl;
                    cin >> i;

                    if(i == 1)
                    {
                        ran = rand() % 10;
                        if(ran > 2)
                        {
                            cout << << "HAS SURVIVED " << sick << endl;
                        }
                        else
                        {
                        cout << << " DIED OF " << sick << endl;
                        party::killChar(x);
                        }
                    }
                    else
                    {
                        ran = rand() % 10;
                        if(ran > 2)
                        {
                            cout << << " DIED OF " << sick << endl;
                            party::killChar(x);
                        }
                        else
                        {
                        cout << << "HAS SURVIVED " << sick << endl;
                        }
                    }
                    
                    
                }
                if(party::characters[0].isAlive() == false) //leader dies game ends
                {
                    cout << "THE LEADER OF THE PARTY HAS DIED."
                    party::endGame();
                }
            break;

            case 1:
            storage::addOxen(-1);

            cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << storage::getOxen() << " LEFT." << endl;

            if(storage::getOxen() < 1)
            {
                cout << "YOU ARE UNABLE TO CONTINUE DUE TO LOOSING ALL YOUR OXEN."
                party::endGame();
            }
            else
            {
                cout << "YOU ARE STILL ABLE TO CONTINUE AND PARTS OF THE OXEN ARE ABLE TO BE HARVEST FOR FOOD." << endl;
                storage::addFood(100);
            }
            
            break;

            case 2:
            string part;
            ran = rand() % 3;
            if(ran = 0)
            {
                part = "WHEELS";
            }
            if(ran = 1)
            {
                part = "AXLES";
            }
            if(ran = 2)
            {
                part = "TONGUES";
            }
            
            cout << "OH NO! ONE OF YOUR " << part << " IS BROKEN!" << endl;

            if(storage::getWagonParts > 0)
            {
                cout << "YOU USE ONE OF YOUR SPARE WAGON PARTS TO FIX THE BREAK." << endl;
                storage::addWagonParts(-1);
            }
            else
            {
                cout << "DUE TO YOUR BROKEN WAGON, YOU ARE UNABLE TO CONTINUE ON YOUR TREK ACROSS THE U.S.!" << endl;
                party::endGame();
            }
            break;
        }

    }
    
    
}

void fortune() {
    srand(time(0));
    int ran = rand() % 5;

    if(ran == 0)
    {
        ran = rand() % 10;
        {
            if (ran < 4)
            {
                cout << "WHILE GOING TO THE BATHROOM YOU NOTICE THE CORNER OF A CHEST STICKING OUT OF THE DIRT." << endl;
                cout << "YOU DIG IT UP AND FIND $300 AND A BAG OF 25 BULLETS!" << endl;
                storage::addBullets(10);
                party::addMoney(100);
            }
            if (ran > 3 && ran < 7)
            {
                cout << "YOU CAME ACROSS AN ABANDONED WAGON WITH 20 POUNDS OF BEANS AND 10 POUNDS OF DRIED FRUIT. " << endl;
                storage::addFood(30);
            }
            if(ran > 6 && ran < 9)
            {
                cout << "YOU MEET A NATIVE AMERICAN TRIBE AND THEY GIFT YOU 1 WAGON PART, 100 POUNDS OF FOOD, AND $300 WORTH OF SUPPLIES THAT YOU WILL TRADE FOR MONEY WHEN PASSING THE NEXT FORT." << endl;
                storage::addWagonParts(1);
                storage::addFood(100);
                party::addMoney(300)
            }
            else
            {
                cout << "YOU SPOT SOMETHING SHINING A FEW HUNDRED YARDS OFF THE TAIL...\nUPON CLOSER INSPECTION YOU REALIZE IT ISN'T FROM OUR WORLD. ITS A ALIEN SPACE CRAFT! \nYOU ENTER THE SPACE CRAFT AND THERE ARE INSTRUCTIONS DETAILING HOW TO FLY THE AIRCRAFT. YOU NO LONGER CARE ABOUT YOUR JOURNY AND FLY WHERE EVER YOU WANT." << endl;
                party::endGame();
            }
            
        }
    }

}
