#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class Employee {
private: 
    int id;
    string name;
    int grooming_skill_level;
    int marketing_skill_level;
    int caretaking_skill_level;
    int work_capacity = 8;
    bool isFree = true;
    
public:
    Employee(int id, string name, int grooming, int marketing, int caretaking)
        : id(id), name(name), grooming_skill_level(grooming), 
          marketing_skill_level(marketing), caretaking_skill_level(caretaking) {}
    
    int get_id() { return id; }
    string get_name() { return name; }
    bool get_isFree() { return isFree; }
    int get_grooming_skill() { return grooming_skill_level; }
    int get_marketing_skill() { return marketing_skill_level; }
    int get_caretaking_skill() { return caretaking_skill_level; }
    
    void work(int hours) {
        work_capacity -= hours;
        if (work_capacity < 0) {
            work_capacity = 0;
        }
    }
    
    void doTask(int taskType) {
        if (taskType == 0) {
            cout << name << " does grooming (skill: " << grooming_skill_level << ")" << endl;
        } else if (taskType == 1) {
            cout << name << " does advertising (skill: " << marketing_skill_level << ")" << endl;
        } else if (taskType == 2) {
            cout << name << " takes care of pet (skill: " << caretaking_skill_level << ")" << endl;
        }
        isFree = false;
        work(1);
    }
    
    void freeEmployee() {
        isFree = true;
    }
    
    void resetWorkDay() {
        work_capacity = 8;
        isFree = true;
    }
    
    void showInfo() {
        cout << "Employee: " << name << " (ID: " << id << ")" << endl;
        cout << "Skills - Grooming: " << grooming_skill_level 
             << ", Marketing: " << marketing_skill_level
             << ", Caretaking: " << caretaking_skill_level << endl;
        cout << "Status: " << (isFree ? "Free" : "Busy") << endl;
        cout << "-------------------" << endl;
    }
};