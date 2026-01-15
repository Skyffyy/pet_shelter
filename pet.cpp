#include <string>
#include <cstdlib>

using namespace std;

class Pet {
private:
    string name;
    int happines;
    int hunger;
    int attractivenes;
    bool isAlive = true;

public:
    Pet() {
        this->happines = rand() % 1001;
        this->hunger = 10 + rand() % 91;
        this->attractivenes = rand() % 1001;
    }

    Pet(int attractivenes, int hunger, int happines) {
        this->happines = happines;
        this->hunger = hunger;
        this->attractivenes = attractivenes;
        if (hunger >= 100) this->isAlive = false;
    }

    void name_pet(string name) {
        this->name = name;
    }

    void increase_happines(int amount) {
        this->happines += amount;
        if (this->happines > 1000) {
            this->happines = 1000;
        }
    }

    void update_happines() {
        if (!isAlive) return;
        this->happines--;
        if (this->happines < 0) {
            this->happines = 0;
        }
    }

    void feed(int amount) {
        if (!isAlive) return;
        this->hunger -= amount;
        if (this->hunger < 0) {
            this->hunger = 0;
        }
    }

    void update_hunger() {
        if (!isAlive) return;
        this->hunger++;
        if (this->hunger >= 100) {
            this->isAlive = false;
        }
    }

    void update_attractivenes() {
        if (!isAlive) return;
        this->attractivenes--;
        if (this->attractivenes < 0) {
            this->attractivenes = 0;
        }
    }

    void groom() { 
        if (!isAlive) return;
        this->attractivenes = 1000; 
    }
    
    int get_attractivenes() { 
        return this->attractivenes; 
    }
    
    int get_hunger() { 
        return this->hunger; 
    }
    
    int get_happines() { 
        return this->happines; 
    }
    
    bool is_alive() {
        return this->isAlive;
    }
};