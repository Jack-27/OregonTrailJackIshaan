// CS1300 Fall 2020
// Author: Jack Franklin
// Recitation: 330 – Chris Gavin
// Homework 4 - Problem # 4

#include <iostream>
using namespace std;
string stringone, substringone;
int countt = 0;
int main() {
    cout << "Enter the search string:" << endl;
    cin >> stringone;
    cout << "Enter the substring to be searched:" << endl;
    cin >> substringone;
    for (int i = 0; i < stringone.length(); i++) {
        for (int j = stringone.length() - i ; j > 0; j--) {
            if (substringone == stringone.substr(i, j)) {
                countt++;
            }
        }
    }
    cout << "Number of occurences: " << countt;
    return 0;
}