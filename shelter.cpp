#include <vector>
#include "pet.cpp"
#include "employee.cpp"
#include <ctime>
#include <iostream>

using namespace std;

class Shelter {
private:
    vector<Pet*> pets;
    vector<Employee*> employees;
    time_t prev_time;
    time_t current_time;
    
public:
    Shelter(time_t prev_time, time_t current_time) {
        this->prev_time = prev_time;
        this->current_time = current_time;
    }
    
    void addPet(Pet* pet) {
        pets.push_back(pet);
    }
    
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    bool giveTask(int taskType, int petIndex, int empIndex) {
        if (empIndex < 0 || empIndex >= employees.size()) {
            cout << "Error: no such employee!" << endl;
            return false;
        }
        
        if (petIndex < 0 || petIndex >= pets.size()) {
            cout << "Error: no such pet!" << endl;
            return false;
        }
        
        Employee* emp = employees[empIndex];
        Pet* pet = pets[petIndex];
        
        if (!pet->is_alive()) {
            cout << "Error: pet is dead!" << endl;
            return false;
        }
        
        if (!emp->get_isFree()) {
            cout << "Employee " << emp->get_name() << " is busy!" << endl;
            return false;
        }
        
        emp->doTask(taskType);
        
        if (taskType == 0) {
            pet->groom();
            cout << "Pet #" << petIndex+1 << " groomed!" << endl;
        } else if (taskType == 1) {
            pet->increase_happines(emp->get_marketing_skill() * 10);
            cout << "Pet #" << petIndex+1 << " advertised!" << endl;
        } else if (taskType == 2) {
            pet->feed(emp->get_caretaking_skill() * 5);
            pet->increase_happines(emp->get_caretaking_skill() * 3);
            cout << "Pet #" << petIndex+1 << " taken care of!" << endl;
        }
        
        return true;
    }

    bool update() {
        time_t deltaTime = (current_time - prev_time) / 3600;
        cout << "Hours passed: " << deltaTime << endl;
        
        if (deltaTime > 0) {
            for (int i = 0; i < deltaTime; i++) {
                for (Pet* pet : pets) {
                    pet->update_attractivenes();
                    pet->update_hunger();
                    pet->update_happines();
                }
                
                for (Employee* emp : employees) {
                    emp->freeEmployee();
                }
            }
            
            if (deltaTime >= 24) {
                for (Employee* emp : employees) {
                    emp->resetWorkDay();
                }
            }
            return true;
        }
        return false;
    }

    void show_pets_stats() {
        int i = 1;
        for (Pet* pet : pets) {
            cout << "\nPet #" << i++ << ":" << endl;
            if (pet->is_alive()) {
                cout << "Status: ALIVE" << endl;
                cout << "Attractiveness: " << pet->get_attractivenes() << endl;
                cout << "Hunger: " << pet->get_hunger() << endl;
                cout << "Happiness: " << pet->get_happines() << endl;
            } else {
                cout << "Status: DEAD" << endl;
                cout << "Cause: Hunger reached " << pet->get_hunger() << endl;
            }
        }
    }
    
    void show_employees() {
        cout << "\n=== EMPLOYEES ===" << endl;
        for (Employee* emp : employees) {
            emp->showInfo();
        }
    }
    
    vector<Pet*> get_pets() {
        return pets;
    }
    
    vector<Employee*> get_employees() {
        return employees;
    }
};