// Ishann Wenger and Jack Franklin

#include "storage.h"
#include "store.h"
#include "party.h"
#include "people.h"
#include "milestone.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <vector>
using namespace std;


vector <milestone> milestones;
party mainParty;

//This is where all the functions that deal with file IO will go
void readFile(string file) {
    fstream text;
    text.open("textFiles/" + file);
    string line = "";
    while( getline(text, line)) {
        cout << line << endl;
    }

}

void store() {
    double money = mainParty.getMoney();
    double bill= 0;
    int timesVisited = mainParty.storeVisits;
    double priceModifier = 1 + .25 * timesVisited;
    bool running;
    bool oxenBought = true;
    int option;


    if (timesVisited == 0) {
        readFile("store_info.txt");
        oxenBought = false;
    }
    while (option != 5) {
        readFile("storeMenu.txt");
        cin >> option;
        if (!option) {
            option = 0;
        }
        switch (option)
        {
        case 1:
            running = true;
            while (running == true){
                if (money < 40 * priceModifier) {
                    cout << "You don't have enough money to buy any oxen." << endl;
                    running = false;
                }
                int choice;
                if (timesVisited == 0) {
                    cout << "You buy oxen in pairs, you must buy 3-5 pairs of oxen if its your first time." << endl;
                } else {
                    cout << "You buy oxen in pairs, oxen help you travel futhur." << endl;
                }
                cout << "The price per pair of Oxen is " << 40 * priceModifier << ", how many would you like?" << endl;
                cin >> choice;
                if (choice < 2 || choice > 5 && timesVisited == 0) {
                    cout << "You must buy 3-5 pairs of oxen" << endl;
                } else if (choice >= 1) {
                    if (choice * 40 * priceModifier > money) {
                        cout << "Not enough money to buy this much." << endl;
                    } else {
                        mainParty.items.addOxen(choice * 2);
                        bill += choice * 40 * priceModifier;
                        cout << "The current bill is " << bill << "." << endl;
                        running = false;
                        oxenBought = true;
                    }
                } else {
                    cout << "Invalid input." << endl;
                }
            }
            break;
        case 2:
            running = true;
            while (running == true){
                if (money < .5 * priceModifier) {
                    cout << "You don't have enough money to buy any food." << endl;
                    running = false;
                }
                int choice;
                cout << "You should proabably buy 200 pounds of food per person. The price is " << .5 * priceModifier;
                cout << " dollars per pound, how many pounds would you like?" << endl;
                cin >> choice;
                if (choice >= 1) {
                    if (choice * .5 * priceModifier > money) {
                        cout << "Not enough money to buy this much." << endl;
                    } else {
                        mainParty.items.addFood(choice);
                        bill += choice * .5 * priceModifier;
                        cout << "The current bill is " << bill << "." << endl;
                        running = false;
                    }
                } else {
                    cout << "Invalid input." << endl;
                }

            }
            break;
        case 3:
            running = true;
            while (running == true){
                if (money < 2 * priceModifier) {
                    cout << "You don't have enough money to buy any bullets." << endl;
                    running = false;
                }
                int choice;
                cout << "You will need bullets to hunt for food and fend off raiders. The price is " << .5 * priceModifier;
                cout << " dollars per 20 bullets, how many boxes of bullets would you like?" << endl;
                cin >> choice;
                if (choice >= 1) {
                    if (choice * 2 * priceModifier > money) {
                        cout << "Not enough money to buy this much." << endl;
                    } else {
                        mainParty.items.addBullets(choice * 20);
                        bill += choice * 2 * priceModifier;
                        cout << "The current bill is " << bill << "." << endl;
                        running = false;
                    }
                } else {
                    cout << "Invalid input." << endl;
                }

            }
            break;
        case 4:
            running = true;
            while (running == true){
                if (money < 25 * priceModifier) {
                    cout << "You don't have enough money to buy any medical kits." << endl;
                    running = false;
                }
                int choice;
                cout << "You need medical aid kits to heal sick party membaers. The price is " << 25 * priceModifier;
                cout << " dollars per kit, how many kits would you like?" << endl;
                cin >> choice;
                if (choice >= 1) {
                    if (choice * .5 * priceModifier > money) {
                        cout << "Not enough money to buy this much." << endl;
                    } else {
                        mainParty.items.addMedKits(choice);
                        bill += choice * 25 * priceModifier;
                        cout << "The current bill is " << bill << "." << endl;
                        running = false;
                    }
                } else {
                    cout << "Invalid input." << endl;
                }

            }
            running = true;
            while (running == true){
                if (money < 20 * priceModifier) {
                    cout << "You don't have enough money to buy any wagonparts." << endl;
                    running = false;
                }
                int choice;
                cout << "You need wagon parts to fix your wagon. The price is " << 20 * priceModifier;
                cout << " dollars per part, how many parts would you like?" << endl;
                cin >> choice;
                if (choice >= 1) {
                    if (choice * .5 * priceModifier > money) {
                        cout << "Not enough money to buy this much." << endl;
                    } else {
                        mainParty.items.addWagonParts(choice);
                        bill += choice * 20 * priceModifier;
                        cout << "The current bill is " << bill << "." << endl;
                        running = false;
                    }
                } else {
                    cout << "Invalid input." << endl;
                }

            }
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
    mainParty.addMoney(bill * -1.0);
    mainParty.storeVisits++;
    cout << "Your remaining money is " << mainParty.getMoney() << endl << endl;
}

int checkMatch(string stringone, string substring) {
    int countt = 0;
    for (int i = 0; i < stringone.length(); i++) {
        for (int j = stringone.length() - i ; j > 0; j--) {
            if (substring == stringone.substr(i, j)) {
                countt++;
            }
        }
    }
    return countt;
}

void readMilestones(string file) {
    fstream text;
    string type;
    string name;
    int miless;
    int counter = 0;
    text.open("textFiles/" + file);
    string line = "";
    while( getline(text, line)) {
        if (counter == 0) {
            name = line;
            if (checkMatch(line, "Fort") == 1) {
                type = "fort";
            } else if (checkMatch(line, "River")) {
                type = "river";
            } else {
                type = "landmark";
            }
            counter++;
        } else {
            miless = stoi(line, nullptr); 
            milestones.push_back(milestone(name, type, miless));
            counter--;
        }
    }


}

void initStartDate() {
    string choice;
    bool chose = true;
    cout << "YOU ARE PLANNED TO SET OUT ON 03/28/1847, WOULD YOU LIKE TO CHANGE THIS?" << endl << "Y / N: ";
    while (chose) {
        cin >> choice;
        cout << endl;
        if (choice == "Y" || choice == "y") {
            chose = false;
            bool chose2 = true;
            string date;
            int day;
            int month;
            while(chose2) {
                cout << "Enter a new date between 03/01/1847 and 05/01/1847" << endl << "(mm/dd/yyyy): ";
                cin >> date;
                if (date.size() == 10 && date[2] == '/' && date[5] == '/') {
                    month = stoi(date.substr(0, 2), nullptr);
                    day = stoi(date.substr(3, 2), nullptr);
                    cout << month << endl << day << endl;
                    if (month >= 3 && month <= 5) {
                        if (month == 5) {
                            if (day == 1) {
                                chose2 = false;
                            } else {
                                cout << "Invalid date." << endl;
                            }

                        } else if (day >= 1 && day <= mainParty.daysInMonth(month) && month != 5) {
                            chose2 = false;
                        } else {
                            cout << "Invalid date." << endl;
                        }
                        
                    } else {
                        cout << "Invalid date." << endl;
                    }

                } else {
                    cout << "Invalid input" << endl;
                }
            }
            cout << "You are set to leave on " << month << "/" << day << "/1847" << endl;
            cout << "You must reach the oregon city by 11/30/1847" << endl;
            mainParty.setDate(day, month);
        } else if (choice == "N" || choice == "n") {
            chose = false;
            mainParty.setDate(28, 3);
            cout << "You are set to leave on 3/28/1847" << endl;
            cout << "You must reach the oregon city by 11/30/1847" << endl;
        } else {
            cout << "Invalid input please try again." << endl << "Y / N: ";
        }
    }


}

void initParty() {
    string name;
    cout << "What is your name? ";
    cin >> name;
    mainParty.characters[0] = people(name, true);
    cout << endl << "Enter your four companions names:" << endl << "1. ";
    cin >> name;
    mainParty.characters[1] = people(name, false);
    cout << endl << "2. ";
    cin >> name;
    mainParty.characters[2] = people(name, false);
    cout << endl << "3. ";
    cin >> name;
    mainParty.characters[3] = people(name, false);
    cout << endl << "4. ";
    cin >> name;
    mainParty.characters[4] = people(name, false);
}

void statusUpdate() {
    int choice;
    cout << mainParty.getDate() << endl;    // this is where the status update will be printed
    cout << endl;
    cout << "TOTAL MILEAGE IS " << mainParty.getMiles() << endl;
    cout << "FOOD       BULLETS       OXEN       WAGON PARTS       MEDKIT       CASH" << endl;
    cout << mainParty.items.getFood() << "          " << mainParty.items.getBullets() << "            " << mainParty.items.getOxen() << "             " << mainParty.items.getWagonParts() << "              " << mainParty.items.getMedKits() << "          " << mainParty.getMoney() << endl; 
}

bool milestoneCheck(int miles, int dist) {
    milestone mile;
    for (int i = 0; i < milestones.size(); i++) {
        if (milestones.at(i).getMile() > miles &&  milestones.at(i).getMile() < miles + dist) {
            mile = milestones.at(i);
            int opt;
            cout << "You are passing by " << mile.getName() << " you could still probably go " << miles + dist - mile.getMile() << " more miles. Stop or continue on?" << endl;
            cout << "1. Stop   2. Continue" << endl;
            cin >> opt;
            while (opt <= 0 && opt >= 3) {
                cin >> opt;
            }
            if (opt == 1) {
                cout << "You have arrived at " << mile.getName() << ". You have traveled " << mile.getMile() - miles << " miles!" << endl;
                mainParty.addMiles(mile.getMile() - miles);
                mainParty.mileStone(mile);
                return true;
            }
            if (opt == 2 ) {
                return false;
            }
        }
    }
    return false;

}

void computeDistanceTraveled() {
    //This will figure out how far the player has traveled based on oxen and rng
    //This will then round down to the next milestone if applicable
    //It also gets rid of food and checks if anything is at 0
    int distance = mainParty.getMiles();
    srand(time(0));
    int ran;
    int newdistance;
    if(mainParty.items.getOxen() > 7)
    {
        ran = rand() % 14;
        newdistance = 140 - ran;
    }
    if((mainParty.items.getOxen() > 5) && (mainParty.items.getOxen() < 8))
    {
        ran = rand() % 14;
        newdistance = 126 - ran;
    }
    if((mainParty.items.getOxen() > 2) && (mainParty.items.getOxen() < 6))
    {
        ran = rand() % 14;
        newdistance = 112 - ran;
    }
    if((mainParty.items.getOxen() > 0) && (mainParty.items.getOxen() < 3))
    {
        ran = rand() % 14;
        newdistance = 84 - ran;
    }
    if (!milestoneCheck(distance, newdistance)) {
        cout << "YOU HAVE TRAVELED " << newdistance << "MILES!" << endl;
        
        mainParty.addMiles(newdistance);
    }
    
}

int randomAlive()
{
    srand(time(0));
    int i = 0;
    int ran;
    while(i < 5)
    {
        ran = rand() % 5;
        if(mainParty.checkChar(i) == true && i == ran)
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

void hunting()
{
    srand(time(0));
    int ran;
    int choice;
    int i = 0;
    int alive;
    int consumed;
    int k = 0;
    cout << "YOU HAVE DECIDED TO GO HUNTING!" << endl;

    ran = rand() % 2;

    if(ran == 0)
    {
        k++;
        cout << "YOU GOT LUCKY AND HAVE ENCOUNTERD A RABBIT! DO YOU WANT TO HUNT: YES(1) OR NO(2)?" << endl;
        cin >> choice;
        if(mainParty.items.getBullets() > 10)
        {
            cout << "YOU MUST SOLVE A PUZZLE IN ORDER TO BE SUCCESSFULL IN THE HUNT!" << endl;
            srand(time(0));
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
                cout << "YOU HAVE SUCCESSFULLY KILLED A RABBIT! YOU HAVE INCREASED YOUR MEAT SUPPLY BY 5LBS BUT USED 10 BULLETS!" << endl;
                mainParty.items.addFood(5);
                mainParty.items.addBullets(-10);
            }
            if(choice != ran)
            {
                cout << "You missed the rabbit and it escaped..." << endl;
            }
            
        }
        else
        {
            cout << "YOU HAD AN INSUFFICENT NUMBER OF BULLETS TO BE SUCCESSFUL IN THE HUNT." << endl;
        }
    }
    srand(time(0));
    ran = rand() % 4;
    i = 0;
    choice = 0;
    if(ran == 0)
    {
        k++;
        cout << "YOU GOT LUCKY AND HAVE ENCOUNTERD A FOX! DO YOU WANT TO HUNT: YES(1) OR NO(2)?" << endl;
        cin >> choice;
        if(mainParty.items.getBullets() > 10)
        {
            cout << "YOU MUST SOLVE A PUZZLE IN ORDER TO BE SUCCESSFULL IN THE HUNT!" << endl;
            srand(time(0));
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
                cout << "YOU HAVE SUCCESSFULLY KILLED A FOX! YOU HAVE INCREASED YOUR MEAT SUPPLY BY 10LBS BUT USED 8 BULLETS!" << endl;
                mainParty.items.addFood(10);
                mainParty.items.addBullets(-8);
            }
             if(choice != ran)
            {
                cout << "You missed the fox and it escaped..." << endl;
            }
        }
        else
        {
            cout << "YOU HAD AN INSUFFICENT NUMBER OF BULLETS TO BE SUCCESSFUL IN THE HUNT." << endl;
        }
    }
    srand(time(0));
    ran = rand() % 100;
    i = 0;
    choice = 0;
    if(ran < 15)
    {
        k++;
        cout << "YOU GOT LUCKY AND HAVE ENCOUNTERD A DEER! DO YOU WANT TO HUNT: YES(1) OR NO(2)?" << endl;
        cin >> choice;
        if(mainParty.items.getBullets() > 10)
        {
            cout << "YOU MUST SOLVE A PUZZLE IN ORDER TO BE SUCCESSFULL IN THE HUNT!" << endl;
            srand(time(0));
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
                cout << "YOU HAVE SUCCESSFULLY KILLED A DEER! YOU HAVE INCREASED YOUR MEAT SUPPLY BY 60LBS BUT USED 5 BULLETS!" << endl;
                mainParty.items.addFood(60);
                mainParty.items.addBullets(-5);
            }
            if(choice != ran)
            {
                cout << "You missed the deer and it escaped..." << endl;
            }
        }
        else
        {
            cout << "YOU HAD AN INSUFFICENT NUMBER OF BULLETS TO BE SUCCESSFUL IN THE HUNT." << endl;
        }
    }
    srand(time(0));
    ran = rand() % 100;
    i = 0;
    choice = 0;
    if(ran < 7)
    {
        k++;
        cout << "YOU GOT LUCKY AND HAVE ENCOUNTERD A BEAR! DO YOU WANT TO HUNT: YES(1) OR NO(2)?" << endl;
        cin >> choice;
        if(mainParty.items.getBullets() > 10)
        {
            cout << "YOU MUST SOLVE A PUZZLE IN ORDER TO BE SUCCESSFULL IN THE HUNT!" << endl;
            srand(time(0));
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
                cout << "YOU HAVE SUCCESSFULLY KILLED A BEAR! YOU HAVE INCREASED YOUR MEAT SUPPLY BY 200LBS BUT USED 10 BULLETS!" << endl;
                mainParty.items.addFood(200);
                mainParty.items.addBullets(-10);
            }
            if(choice != ran)
            {
                cout << "You missed the bear and it escaped..." << endl;
            }
        }
        else
        {
            cout << "YOU HAD AN INSUFFICENT NUMBER OF BULLETS TO BE SUCCESSFUL IN THE HUNT." << endl;
        }
    }
        
    srand(time(0));
    ran = rand() % 20;
    i = 0;
    choice = 0;
    if(ran == 0)
    {
        k++;
        cout << "YOU GOT LUCKY AND HAVE ENCOUNTERD A MOOSE! DO YOU WANT TO HUNT: YES(1) OR NO(2)?" << endl;
        cin >> choice;
        if(mainParty.items.getBullets() > 10)
        {
            cout << "YOU MUST SOLVE A PUZZLE IN ORDER TO BE SUCCESSFULL IN THE HUNT!" << endl;
            srand(time(0));
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
                cout << "YOU HAVE SUCCESSFULLY KILLED A MOOSE! YOU HAVE INCREASED YOUR MEAT SUPPLY BY 500LBS BUT USED 12 BULLETS!" << endl;
                mainParty.items.addFood(500);
                mainParty.items.addBullets(-12);
            }
            if(choice != ran)
            {
                cout << "You missed the moose and it escaped..." << endl;
            }
        }
        else
        {
            cout << "YOU HAD AN INSUFFICENT NUMBER OF BULLETS TO BE SUCCESSFUL IN THE HUNT." << endl;
        }
    }
    if(k == 0)
    {
        cout << "You didn't come across any animals..." << endl;
    }
    cout << "HOW WELL WOULD YOU LIKE TO FEED EVERYONE?\nPOORLY(1): 2LBS OF FOOD, PER PERSON.\nMODERATELY(2): 3LBS OF FOOD, PER PERSON. \n WELL(3): 5 LBS OF FOOD, PER PERSON." << endl;
    cin >> choice;

    alive = mainParty.numCharAlive();
    switch(choice)
    {
        case 1:
            consumed = alive * 2;
        break;

        case 2:
            consumed = alive * 3;
        break;

        case 3: 
            consumed = alive * 5;
        break;
    }
    mainParty.items.addFood(-consumed);

    if(mainParty.items.getFood() > 1000)
    {
        cout << "THE WAGON IS ONLY ABLE TO CARRY 1000 POUNDS...YOU HAD TO LEAVE THE EXTRA MEAT BEHIND!" << endl;
    }
    
}

void raiders()
{
    srand(time(0));
    int ran;
    int choice = 0;
    int i = 0;
    int loss;
    bool check = false;
    cout << "RAIDERS AHDEAD! THEY LOOK HOSTILE!" << endl;

        cout << "WOULD YOU LIKE TO RUN(1), ATTACK(2), OR SURRENDER(3)?" << endl;
        cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "YOU MANAGED TO ESCAPE, BUT IN YOUR HURRY TO FLEE YOU HAVE LOST 1 OX, 10LBS OF FOOD, AND 1 WAGON PART!" << endl;
            mainParty.items.addOxen(-1);
            mainParty.items.addFood(-10);
            mainParty.items.addWagonParts(-1);
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
            mainParty.items.addBullets(50);
            mainParty.items.addFood(50);
        }
        if(choice != ran)
        {
            cout << "YOU HAVE LOST THE BATTLE AND MUST FLEE! 50 BULLESTS WERE USED DURING THE BATTLE! AS YOU'RE FLEEING YOU DROP A QUARTER OF YOUR CASH SUPPLY!" << endl;
            loss = mainParty.getMoney();
            loss = loss / 4;
            mainParty.addMoney(-loss);
            mainParty.items.addBullets(-50);
        }
        break;

        case 3:
            cout << "YOU HAVE CHOSEN TO SURRENDER AND THE RAIDERS TAKE A QUARTER OF YOUR CASH SUPPLY!" << endl;
            mainParty.addMoney(-loss);
            break;
    }
}

void misfortune() {
    srand(time(0));
    int ran;  //chooses and executes a misfortune
    string sick;
    int i = randomAlive();
    string name = mainParty.characters[i].getName();
    ran = rand() % 3;

    switch(ran)
    {
        
        case 0:
            srand(time(0));
            ran = rand() % 6;
            switch(ran)
            {
                case 0:
                cout << "Oh no! " << name << " has typhoid" << endl;
                sick = "Typhoid";
                break;

                case 1:
                cout << "Oh no! " << name << " has Cholera" << endl;
                sick = "Cholera";
                break;

                case 2:
                cout << "Oh no! " << name << " has diarrhea" << endl;
                sick = "diarrhea";
                break;

                case 3:
                cout << "Oh no! " << name << " has the Measles" << endl;
                sick = "The Measles";
                break;

                case 4:
                cout << "Oh no! " << name << " has dysentary" << endl;
                sick = "dysentary";
                break;

                case 5:
                cout << "Oh no! " << name << " has the fever" << endl;
                sick = "The Fever";
                break;   
            }
            if(mainParty.items.getMedKits() > 0)
            {
                srand(time(0));
                ran = rand() % 2;
                if(ran == 0)
                {
                    cout << name << " Died of " << sick << endl;
                    mainParty.killChar(i);
                }
                else
                {
                    cout << name << " has survived " << sick << endl;
                }
                cout << "Medkit Supply -1." << endl;
                mainParty.items.addMedKits(-1);
            }
            else
            {
                cout << "Would you like to rest(1) in an attempt to heal " << name << " , or press on(2)?" << endl;
                cin >> i;

                if(i == 1)
                {
                    srand(time(0));
                    ran = rand() % 10;
                    if(ran > 2)
                    {
                        cout << name << " has survived " << sick << endl;
                    }
                    else
                    {
                    cout << name << " died of " << sick << endl;
                    mainParty.killChar(i);
                    }
                }
                else
                {
                    srand(time(0));
                    ran = rand() % 10;
                    if(ran > 2)
                    {
                        cout << name << " died of " << sick << endl;
                        mainParty.killChar(i);
                    }
                    else
                    {
                    cout << name << " has survived" << sick << endl;
                    }
                }
                
                
            }
            if(mainParty.characters[0].isAlive() == false) //leader dies game ends
            {
                cout << "The leader of the party has died!" << endl;
                mainParty.endGame();
            }
        break;

        case 1:
            mainParty.items.addOxen(-1);

            cout << "Oh no! One of the oxen has died! You have " << mainParty.items.getOxen() << " left." << endl;

            if(mainParty.items.getOxen() < 1)
            {
                cout << "You are unable to continue due to losing all your oxen.";
                mainParty.endGame();
            }
            else
            {
                cout << "You are still able to continue and parts of the oxen are harvested for food." << endl;
                mainParty.items.addFood(100);
            }
        
        break;

        case 2:
        string part;
        srand(time(0));
        ran = rand() % 3;
        if(ran == 0)
        {
            part = "Wheels";
        }
        if(ran == 1)
        {
            part = "Axles";
        }
        if(ran == 2)
        {
            part = "Tongues";
        }
        
        cout << "Oh no! On of your " << part << " is broken!" << endl;

        if(mainParty.items.getWagonParts() > 0)
        {
            cout << "You have to use one of your spare wagon parts to fix the break.." << endl;
            mainParty.items.addWagonParts(-1);
        }
        else
        {
            cout << "Due to your broken wagon, you are unable to continue your trip across the U.S.!" << endl;
            mainParty.endGame();
        }
        break;
    }
}

void fortune() {
    srand(time(0));
    int ran = rand() % 5;

    if(ran == 0)
    {
        srand(time(0));
        ran = rand() % 10;
        {
            if (ran < 4)
            {
                cout << "While going to the bathroom you notice the corner of a chest sticking out of the dirt." << endl;
                cout << "You dig it up and find $300 and a bag of 25 bullets!" << endl;
                mainParty.items.addBullets(10);
                mainParty.addMoney(100);
            }
            if (ran > 3 && ran < 7)
            {
                cout << "You came across an abandoned wagon with 20 pounds of beans and 10 pounds of dried fruit. " << endl;
                mainParty.items.addFood(30);
            }
            if(ran > 6 && ran < 9)
            {
                cout << "You meet a Native American tribe and they gift you 1 wagon part, 100 pounds of food, and $300 worth of supplies that you will trade for money when passing the next fort." << endl;
                mainParty.items.addWagonParts(1);
                mainParty.items.addFood(100);
                mainParty.addMoney(300);
            }
            else
            {
                cout << "You spot something shining a few hundred yards off the tail...\nupon closer inspection you realize it isn't from our world. Its a alien space craft! \nyou enter the space craft and there are instructions detailing how to fly the aircraft. You no longer care about your journey and fly where ever you want." << endl;
                mainParty.endGame();
            }
            
        }
    }

}

void eventCalc() {
    //runs through probabities of events launching 
    srand(time(0));         //chance of raiders
    double ran = 0;
    double prob;
    ran = rand() % 3;
    if(ran == 0)
    {
        raiders();
    }
    srand(time(0));
    ran = rand() % 10;  //chooses and executes a misfortune
    if(ran < 4)
    {
        misfortune();
    } else if (ran > 8) {
        fortune();
    }


}

bool checkIfDead() {
    if (mainParty.getMiles() >= 2040) {
        cout << "You have reached oregon trail, great job!" << endl;
        return true;
    }
    if (mainParty.items.getOxen() <= 0) {
        cout << "You have run out of oxen and thus cannot continue." << endl;
        return true;
    }
    if (mainParty.characters[0].isAlive() == false) {
        cout << "You have died and thus cannot continue." << endl;
        return true;
    }
    if (mainParty.items.getFood() <= 0) {
        cout << "You have ran out of food and starved and thus cannot continue." << endl;
        return true;
    }
}

void turn() {

    int choice;
    int gameOver = 0;
    statusUpdate();
    cout << "What would you like to do?" << endl;
    if (mainParty.checkMileStone()) {
        if (mainParty.mile.getType() == "fort") {
            cout << "1. Continue On   2. Hunt   3. Rest   4. Quit   5. Store" << endl;
            cin >> choice;
            if (choice == 5) {
                store();
                mainParty.storeVisits++;
            }
            mainParty.mile = milestone();
            mainParty.noMileStone();
        } else if (mainParty.mile.getType() == "river") {
            cout << "1. Cross river and continue on   2. Hunt   3. Rest   4. Quit" << endl;
            cin >> choice;
            mainParty.mile = milestone();
            mainParty.noMileStone();
        } else {
            cout << "1. Continue On   2. Hunt   3. Rest   4. Quit" << endl;
            cin >> choice;
            mainParty.noMileStone();
            mainParty.mile = milestone();
        }
    } else {
        cout << "1. Continue On   2. Hunt   3. Rest   4. Quit" << endl;
        cin >> choice;
    }
    if (choice == 2) {
        hunting();
        mainParty.addDays(5);
        mainParty.items.addFood(mainParty.numCharAlive() * -15);
    }
    if (choice == 3) {
        mainParty.addDays(3);
        mainParty.items.addFood(mainParty.numCharAlive() * -9);
    }
    if (choice == 4 || checkIfDead()) {
        if (choice == 4){
            cout << "All of your party seems to die from a mysterious source, perhaps the cruel will of some far god." << endl;
        }
        mainParty.endGame();
        gameOver = 1;
    }
    if (gameOver == 0) {
        eventCalc();
        if (choice == 1) {
            computeDistanceTraveled();
            mainParty.addDays(14);
            mainParty.items.addFood(mainParty.numCharAlive() * -3 * 14);
        }
    }
}

void game(){
    readMilestones("milestones.txt");
    initParty();
    initStartDate();
    store();
    while (mainParty.isOver() == false) {
        turn();
    }
    // Score stuff goes here

}

void postGame() {
    string opt;
    bool exe = true;
    cout << endl << "Do you want to record your score? Y/N" << endl;
    while (exe) {
        cin >> opt;
        if (opt == "Y" || opt == "y") {
            string name;
            exe = false;
            cout << "Enter three letter name for highscore: ";
            cin >> name;
            ofstream score("textFiles/highscores.txt", ios::app);
            score << name.substr(0, 3) << mainParty.getMiles() + mainParty.getMoney() * mainParty.numCharAlive();
            score.close();
        } else if (opt == "N" || opt == "n") {
            exe = false;
        } else {
            cout << "Invalid option, use Y/N" << endl;
        }
    }
    mainParty = party();


}

void viewHighScores() {
    //This is our sorting algorithim, it sorts the top ten high scores
    vector <int> order(10, -1);
    vector <int> numbers;
    vector <string> names;
    fstream score;
    bool used;
    int biggestNum = 0;
    int biggestNumPos = 0;
    score.open("textFiles/highscores.txt");
    string line = "";
    while( getline(score, line)) {
        names.push_back(line.substr(0, 3));
        numbers.push_back(stoi(line.substr(3), nullptr));
    }
    for (int i = 0; i < 10; i++) {
            biggestNum = -1;
            biggestNumPos = -1;
        for (int j = 0; j < numbers.size(); j++) {
            
            used = false;
            for (int n = 0; n < order.size(); n++) {
                
                if (order.at(n) == j) {
                    used = true;
                }
                
            }
            if (used == false && numbers.at(j) > biggestNum) {
                    biggestNum = numbers.at(j);
                    biggestNumPos = j;
                }
            
        }
        order.push_back(biggestNumPos);
    }
    for (int i = 0; i < order.size(); i++) {
        if (order.at(i) != -1) {
            cout << names.at(order.at(i)) << ": " << numbers.at(order.at(i)) << endl;
        }
    }

}

int main() {
    int opt;
    while (opt != 3) {
        cout << "===OREGON TRAIL===" << endl << "1. Play   2. View Highscores    3. Quit" << endl;
        cin >> opt;
        if (opt == 1) {
            game();
            postGame();
        } else if (opt == 2) {
            viewHighScores();
        } else if (opt == 3) {
            cout << "Goodbye!";
        } else {
            cout << "Invalid option." << endl;
        }
    }
    

}