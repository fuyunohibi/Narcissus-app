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
    Gender gen;
    string face;
    int age;
    float height;
    float weight;
    string address;
    string contact;
    TypeOfCrime crime_type;
    string status;
    int punishment;
    string court;
    string victim;
    string vadd;
    string image;
    map<string, string> caseHistory;
    vector<string> tags;
    bool in_jail;

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