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



void initStartDate(party main) {
    string choice;
    bool chose = true;
    cout << "You are planned to set out on 03/28/1847, would you like to change this?" << endl << "Y / N: ";
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

                        } else if (day >= 1 && day <= main.daysInMonth(month) && month != 5) {
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
            main.setDate(day, month);
        } else if (choice == "N" || choice == "n") {
            chose = false;
            main.setDate(28, 3);
            cout << "You are set to leave on 3/28/1847" << endl;
            cout << "You must reach the oregon city by 11/30/1847" << endl;
        } else {
            cout << "Invalid input please try again." << endl << "Y / N: ";
        }
    }


}

void initParty(party main) {
    string name;
    cout << "What is your name? ";
    cin >> name;
    main.characters[0] = people(name, true);
    cout << endl << "Enter your four companions names:" << endl << "1. ";
    cin >> name;
    main.characters[1] = people(name, false);
    cout << endl << "2. ";
    cin >> name;
    main.characters[2] = people(name, false);
    cout << endl << "3. ";
    cin >> name;
    main.characters[3] = people(name, false);
    cout << endl << "4. ";
    cin >> name;
    main.characters[4] = people(name, false);
}

void statusUpdate(party main) {
    int choice;
    cout << main.getDate() << endl;    // this is where the status update will be printed
    cout << endl;
    cout << "Total mileage is: " << main.getMiles() << endl;
    cout << "Food       Bullets       Oxen       Wagon Parts       Medkits       Cash" << endl;
    cout << main.items.getFood() << "          " << main.items.getBullets() << "            " << main.items.getOxen() << "             " << main.items.getWagonParts() << "              " << main.items.getMedKits() << "          " << main.getMoney() << endl; 
}

void computeDistanceTraveled(int distance, party main) {
    //This will figure out how far the player has traveled based on oxen and rng
    //This will then round down to the next milestone if applicable
    srand(time(0));
    int ran;
    int newdistance;
    if(main.items.getOxen() > 8)
    {
        ran = rand() % 14;
        newdistance = 140 - ran;
    }
    if((main.items.getOxen() > 6) && (main.items.getOxen() < 9))
    {
        ran = rand() % 14;
        newdistance = 126 - ran;
    }
    if((main.items.getOxen() > 4) && (main.items.getOxen() < 7))
    {
        ran = rand() % 14;
        newdistance = 112 - ran;
    }
    if((main.items.getOxen() > 2) && (main.items.getOxen() < 5))
    {
        ran = rand() % 14;
        newdistance = 98 - ran;
    }
    if((main.items.getOxen() > 0) && (main.items.getOxen() < 3))
    {
        ran = rand() % 14;
        newdistance = 84 - ran;
    }
    cout << "You have traveled: " << newdistance + distance << "miles!" << endl;
    main.addMiles(newdistance);
}

int randomAlive(party main)
{
    
    int i = 0;
    int ran;
    while(i < 5)
    {
        srand(time(0));
        ran = rand() % 5;
        if(main.checkChar(ran) == true)
        {
            return ran;
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

void hunting(party main)
{
    srand(time(0));
    int ran;
    int choice;
    int i = 0;
    int alive;
    int consumed;
    cout << "You have decided to go hunting!" << endl;

    ran = rand() % 2;

    if(ran == 0)
    {
        cout << "You got lucky and have encounterd a rabbit! Do you want to hunt: Yes(1) or No(2)?" << endl;
        cin >> choice;
        if(main.items.getBullets() >= 10 && choice == 1)
        {
            cout << "You must solve a puzzle in order to be successful in the hunt!" << endl;
            srand(time(0));
            ran = rand() % 10;

            cout << "You have three tries to Guess a number 0-9!" << endl;

            while((choice != ran) && (i < 3))
            {
                cout << "Guess #" << i + 1 << "!" << endl;
                cin >> choice;
                i++;
            }
            if(choice == ran)
            {
                cout << "You have successfully killed a rabbit! You have increased your meat supply by 5lbs but used 10 bullets!" << endl;
                main.items.addFood(5);
                main.items.addBullets(-10);
            }
            else
            {
                cout << "Unfortunately you have not guess the correct number! The rabbit escapes." << endl;
            }
            
        }
        else if(main.items.getBullets() < 10 && choice == 1)
        {
            cout << "You had an insufficient number of bullets to be successful in the hunt." << endl;
        }
        else if(choice == 2)
        {
            cout << "You have decided to not go after the rabbit." << endl;
        }
        
    }
    srand(time(0));
    ran = rand() % 4;
    i = 0;
    if(ran == 0)
    {
        cout << "You got lucky and have encountered a fox! Do you want to hunt: Yes(1) or No(2)?" << endl;
        cin >> choice;
        if(main.items.getBullets() >= 10 && choice == 1)
        {
            cout << "You must solve a puzzle in order to be successful in the hunt!" << endl;
            srand(time(0));
            ran = rand() % 10;

            cout << "You have three tries to Guess a number 0-9!" << endl;

            while((choice != ran) && (i < 3))
            {
                cout << "Guess #" << i + 1 << "!" << endl;
                cin >> choice;
                i++;
            }
            if(choice == ran)
            {
                cout << "You have successfully killed a fox! You have increased your meat supply by 10lbs but used 8 bullets!" << endl;
                main.items.addFood(10);
                main.items.addBullets(-8);
            }
        }
        else if(choice == 1 && main.items.getBullets() < 10)
        {
            cout << "You had an insufficient number of bullets to be successful in the hunt." << endl;
        }
        else if(choice == 2)
        {
            cout << "You have decided to not go after the fox." << endl;
        }
    }
    srand(time(0));
    ran = rand() % 100;
    i = 0;
    if(ran < 15)
    {
        cout << "You got lucky and have encounterd a deer! Do you want to hunt: yes(1) or no(2)?" << endl;
        cin >> choice;
        if(main.items.getBullets() >= 10 && choice == 1)
        {
            cout << "You must solve a puzzle in order to be successful in the hunt!" << endl;
            srand(time(0));
            ran = rand() % 10;

            cout << "You have three tries to Guess a number 0-9!" << endl;

            while((choice != ran) && (i < 3))
            {
                cout << "Guess #" << i + 1 << "!" << endl;
                cin >> choice;
                i++;
            }
            if(choice == ran)
            {
                cout << "You have successfully killed a deer! You have increased your meat supply by 60lbs but used 5 bullets!" << endl;
                main.items.addFood(60);
                main.items.addBullets(-5);
            }
        }
        else if(choice == 1 && main.items.getBullets() < 10)
        {
            cout << "You had an insufficient number of bullets to be successful in the hunt." << endl;
        }
        else if(choice == 2)
        {
            cout << "You have decided to not go after the deer." << endl;
        }
    }
    srand(time(0));
    ran = rand() % 100;
    i = 0;
    if(ran < 7)
    {
        cout << "You got lucky and have encounterd a bear! Do you want to hunt: yes(1) or no(2)?" << endl;
        cin >> choice;
        if(main.items.getBullets() >= 10 && choice == 1)
        {
            cout << "You must solve a puzzle in order to be successful in the hunt!" << endl;
            srand(time(0));
            ran = rand() % 10;

            cout << "You have three tries to Guess a number 0-9!" << endl;

            while((choice != ran) && (i < 3))
            {
                cout << "Guess #" << i + 1 << "!" << endl;
                cin >> choice;
                i++;
            }
            if(choice == ran)
            {
                cout << "You have successfully killed a bear! You have increased your meat supply by 200lbs but used 10 bullets!" << endl;
                main.items.addFood(200);
                main.items.addBullets(-10);
            }
        }
        else if(choice == 1 && main.items.getBullets() < 10)
        {
            cout << "You had an insufficient number of bullets to be successful in the hunt." << endl;
        }
        else if(choice == 2)
        {
            cout << "You have decided to not go after the bear." << endl;
        }
    }
    srand(time(0));
    ran = rand() % 20;
    i = 0;
    if(ran == 0)
    {
        cout << "You got lucky and have encountered a moose! Do you want to hunt: yes(1) or no(2)?" << endl;
        cin >> choice;
        if(main.items.getBullets() >= 10 && choice == 1)
        {
            cout << "You must solve a puzzle in order to be successful in the hunt!" << endl;
            srand(time(0));
            ran = rand() % 10;

            cout << "You have three tries to Guess a number 0-9!" << endl;

            while((choice != ran) && (i < 3))
            {
                cout << "Guess #" << i + 1 << "!" << endl;
                cin >> choice;
                i++;
            }
            if(choice == ran)
            {
                cout << "You have successfully killed a moose! You have increased your meat supply by 500lbs but used 12 bullets!" << endl;
                main.items.addFood(500);
                main.items.addBullets(-12);
            }
        }
        else if(choice == 1 && main.items.getBullets() < 10)
        {
            cout << "You had an insufficient number of bullets to be successful in the hunt." << endl;
        }
        else if(choice == 2)
        {
            cout << "You have decided to not go after the moose." << endl;
        }
    }
    cout << "How well would you like to feed everyone?\nPoorly(1): 2lbs of food, per person.\nModerately(2): 3lbs of food, per person. \nWell(3): 5 lbs of food, per person." << endl;
    cin >> choice;

    alive = main.numCharAlive();
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
    main.items.addFood(-consumed);

    if(main.items.getFood() > 1000)
    {
        cout << "The wagon is only able to carry 1000 pounds...You had to leave the extra meat behind!" << endl;
        main.items.setFood(1000);
    }
}

void raiders(party main)
{
    srand(time(0));
    int ran;
    int choice;
    int i = 0;
    int loss;
    cout << "Raiders ahead! They look hostile!" << endl;
    while(choice > 3 && choice < 1)
    {
        cout << "Would you like to run(1), attack(2), or surrender(3)?" << endl;
        cin >> choice;
    }

    switch(choice)
    {
        case 1:
        cout << "You managed to escape, but in your hurry to flee you have lost 1 ox, 10lbs of food, and 1 wagon part!" << endl;
        main.items.addOxen(-1);
        main.items.addFood(-10);
        main.items.addWagonParts(-1);
        break;

        case 2:
        cout << "You have decided to fight!" << endl;
        cout << "You must complete a puzzle in order to win!" << endl;

        ran = rand() % 10;

        cout << "You have three tries to guess a number 0-9!" << endl;

        while((choice != ran) && (i < 3))
        {
            cout << "Guess #" << i + 1 << "!" << endl;
            cin >> choice;
            i++;
        }
        if(choice == ran)
        {
            cout << "You have guessed the correct number! You have scared away the raiders and as they were running, they dropped 50lbs of food and 50 bullets!" << endl;
            main.items.addBullets(50);
            main.items.addBullets(50);
        }
        if(choice != ran)
        {
            cout << "You have lost the battle and must flee! 50 bullets were used during the battle! As you're fleeing you drop a quarter of your cash supply!" << endl;
            loss = main.getMoney();
            loss = loss / 4;
            main.addMoney(-loss);
            main.items.addBullets(-50);
        }
        break;

        case 3:
        cout << "You have chosen to surrender and the raiders take a quarter of your cash supply!" << endl;
        main.addMoney(-loss);
        break;
    }
}

void misfortune(party main) {
    srand(time(0));
    int ran;  //chooses and executes a misfortune
    string sick;
    int i = randomAlive(main);
    string name = main.characters[i].getName();
    ran = rand() % 3;

    switch(ran)
    {
        
        case 0:
            srand(time(0));
            ran = rand() % 6;
            switch(ran)
            {
                case 0:
                cout << "Oh no! " << name << "has Typhoid" << endl;
                sick = "Typhoid.";
                break;

                case 1:
                cout << "Oh no! " << name << "has Cholera" << endl;
                sick = "Cholera.";
                break;

                case 2:
                cout << "Oh no! " << name << "has Diarrhea" << endl;
                sick = "Diarrhea.";
                break;

                case 3:
                cout << "Oh no! " << name << "has the Measels" << endl;
                sick = "the Measels.";
                break;

                case 4:
                cout << "Oh no! " << name << "has Dysentery" << endl;
                sick = "Dysentery.";
                break;

                case 5:
                cout << "Oh no! " << name << "has the Fever" << endl;
                sick = "the Fever.";
                break;   
            }
            if(main.items.getMedKits() > 0)
            {
                srand(time(0));
                ran = rand() % 2;
                if(ran == 0)
                {
                    cout << name << " died of " << sick << endl;
                    main.killChar(i);
                }
                else
                {
                    cout << name << "has survived " << sick << endl;
                }
                cout << "MEDKIT SUPPLY -1." << endl;
                main.items.addMedKits(-1);
            }
            else
            {
                cout << "Would you like to rest(1) in an attempt to heal " << name << ", or press on(2)?" << endl;
                cin >> i;

                if(i == 1)
                {
                    srand(time(0));
                    ran = rand() % 10;
                    if(ran > 2)
                    {
                        cout << name << "has survived " << sick << endl;
                    }
                    else
                    {
                    cout << name << " died of " << sick << endl;
                    main.killChar(i);
                    }
                }
                else
                {
                    srand(time(0));
                    ran = rand() % 10;
                    if(ran > 2)
                    {
                        cout << name << " died of " << sick << endl;
                        main.killChar(i);
                    }
                    else
                    {
                    cout << name << "has survived " << sick << endl;
                    }
                }
                
                
            }
            if(main.characters[0].isAlive() == false) //leader dies game ends
            {
                cout << "The leader of the party has died." << endl;
                main.endGame();
            }
        break;

        case 1:
            main.items.addOxen(-1);

            cout << "Oh no! One of the oxen has died! You have " << main.items.getOxen() << " left." << endl;

            if(main.items.getOxen() < 1)
            {
                cout << "You are unable to continue due to loosing all your oxen.";
                main.endGame();
            }
            else
            {
                cout << "You are still able to continue and parts of the oxen are able to be harvest for food." << endl;
                main.items.addFood(100);
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
        
        cout << "Oh no! One of your " << part << " is broken!" << endl;

        if(main.items.getWagonParts() > 0)
        {
            cout << "You use one of your spare wagon parts to fix the break." << endl;
            main.items.addWagonParts(-1);
        }
        else
        {
            cout << "Due to your broken wagon, you are unable to continue on your trek across the U.S.!" << endl;
            main.endGame();
        }
        break;
    }
}

void fortune(party main) {
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
                main.items.addBullets(10);
                main.addMoney(100);
            }
            if (ran > 3 && ran < 7)
            {
                cout << "You came across an abandoned wagon with 20 pounds of beans and 10 pounds of dried fruit. " << endl;
                main.items.addFood(30);
            }
            if(ran > 6 && ran < 9)
            {
                cout << "You meet a Native American tribe and they gift you 1 wagon part, 100 pounds of food, and $300 worth of supplies that you will trade for money when passing the next fort." << endl;
                main.items.addWagonParts(1);
                main.items.addFood(100);
                main.addMoney(300);
            }
            else
            {
                cout << "You spot something shining a few hundred yards off the tail...\nupon closer inspection you realize it isn't from our world. Its a alien space craft! \nyou enter the space craft and there are instructions detailing how to fly the aircraft. You no longer care about your journey and fly where ever you want." << endl;
                main.endGame();
            }
            
        }
    }

}

void eventCalc(party main) {
    //runs through probabities of events launching 
    srand(time(0));         //chance of raiders
    double ran;
    double prob;
    prob = pow(main.getMiles() / 100 - 4,2) + 72;
    prob = prob / pow(main.getMiles() / 100 - 4, 2) + 12;
    prob = prob - 1;
    prob = prob / 0.10;
    prob = 100 - prob;
    ran = rand() % 100;
    if(ran > prob)
    {
        raiders(main);
    }
    srand(time(0));
    ran = rand() % 10;  //chooses and executes a misfortune
    if(ran > 4)
    {
        misfortune(main);
    }


}
void turn(party main) {

    computeDistanceTraveled(main.getMiles(), main);
    statusUpdate(main);
    milestone();
    eventCalc(main);

}