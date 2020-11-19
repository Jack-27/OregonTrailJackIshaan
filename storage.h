#ifndef STORAGE_H
#define STORAGE_H

// This is where all of the items are tracked.
class storage {

    private:
        int oxen;
        int wagonParts;
        int medKits;
        int bullets;
        int food;
    public:
        void setOxen(int input) {
            oxen = input;
        }
        void setWagonParts(int input) {
            wagonParts = input;
        }
        void setMedKits(int input) {
            medKits = input;
        }
        void setBullets(int input) {
            bullets = input;
        }
        void setFood(int input) {
            food = input;
        }
        int getOxen() {
            return oxen;
        }
        int getWagonParts() {
            return wagonParts;
        }
        int getMedKits() {
            return medKits;
        }
        int getBullets() {
            return bullets;
        }
        int getFood() {
            return food;
        }
        void addOxen(int input) {
            oxen += input;
        }
        void addWagonParts(int input) {
            wagonParts += input;
        }
        void addMedKits(int input) {
            medKits += input;
        }
        void addBullets(int input) {
            bullets += input;
        }
        void addFood(int input) {
            food += input;
        }
        storage() {
            oxen = 0;
            wagonParts = 0;
            medKits = 0;
            bullets = 0;
            food = 0;
        }
        
};

#endif