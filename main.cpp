#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "shelter.cpp"
#include "task.cpp"

using namespace std;

int main() {   
    string line;
    ifstream game_data;
    game_data.open("game_data.txt");
    
    getline(game_data, line);
    time_t prev_time = stoi(line, 0, 10);
    time_t timestamp; 
    time(&timestamp);

    Shelter shelter(prev_time, timestamp);

    while(1) {   
        int temp_at, temp_hun, temp_hap;
        if(getline(game_data, line)) { temp_at = stoi(line); } else { break; }
        if(getline(game_data, line)) { temp_hun = stoi(line); } else { break; }
        if(getline(game_data, line)) { temp_hap = stoi(line); } else { break; }
        Pet* test_pet = new Pet(temp_at, temp_hun, temp_hap);
        shelter.addPet(test_pet);
    }
    game_data.close();
    
    Employee* emp1 = new Employee(1, "John", 5, 3, 4);
    Employee* emp2 = new Employee(2, "Sarah", 3, 6, 2);
    shelter.addEmployee(emp1);
    shelter.addEmployee(emp2);
    
    if(shelter.update()) {
        ofstream game_data;
        game_data.open("game_data.txt", ios::out | ios::trunc);
        game_data << timestamp << endl;
        for(Pet* pet: shelter.get_pets()) {
            game_data << pet->get_attractivenes() << endl;
            game_data << pet->get_hunger() << endl;
            game_data << pet->get_happines() << endl;
        }
        game_data.close();
    }
    
    cout << "=== PET SHELTER MANAGEMENT ===" << endl;
    shelter.show_pets_stats();
    shelter.show_employees();
    
    cout << "\n=== TASK SYSTEM ===" << endl;
    if (shelter.get_pets().size() > 0 && shelter.get_pets()[0]->is_alive()) {
        shelter.giveTask(GROOM, 0, 0);
        shelter.giveTask(TAKE_CARE, 0, 1);
    }
    
    cout << "\n=== FINAL STATE ===" << endl;
    shelter.show_pets_stats();
    
    cout << "\n=== TASK TYPES DEMO ===" << endl;
    cout << "GROOM: " << enum_to_string(GROOM) << endl;
    cout << "ADVERTISE: " << enum_to_string(ADVERTISE) << endl;
    cout << "TAKE_CARE: " << enum_to_string(TAKE_CARE) << endl;

    return 0;
}