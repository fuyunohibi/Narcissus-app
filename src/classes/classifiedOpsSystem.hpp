#ifndef CLASSIFIED_OPS_SYSTEM_H
#define CLASSIFIED_OPS_SYSTEM_H

#include <string>
#include <vector>
#include <map>
#include "typeOfCrime.hpp"

using namespace std;

// Purpose: Header file for myClass class.
class ClassifiedOpsSystem
{
private:
    string name;
    Gender gender;
    int age;
    float height;
    float weight;
    string address;
    string contact;
    string career;
    string date;
    TypeOfCrime crime_type;
    int victim;
    string term;
    bool in_jail;
    int recordID;
    int count = 0;
    vector<string> all_data;

public:
    string generateUniqueID();

    // screens folder
    void loginScreen();
    void menuScreen();

    // components folder
    void addRecord();
    void input();



    // TODO
    void output();
    void searchRecord();
    void editRecord();
    void viewRecord();
    void deleteRecord();
    void generateReport();
    void storeMedia();
    void courtProgress();
    void notifications();
    void userManagement();
    void classifyRecords();
    void linkRecords();
    void anonymize();
    void exportRecord();
};

#endif // CLASSIFIED_OPS_SYSTEM_H