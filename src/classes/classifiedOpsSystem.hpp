#ifndef CLASSIFIED_OPS_SYSTEM_H
#define CLASSIFIED_OPS_SYSTEM_H

#include <string>
#include <vector>
#include <map>

using namespace std;

// Purpose: Header file for myClass class.
class ClassifiedOpsSystem
{
private:
    string name;
    string nation;
    string gender;
    int age;
    int height;
    int weight;
    string career;
    string institution;
    string date;
    string crime_type;
    int victim;
    string term;
    int recordID;
    int count = 0;
    vector<string> all_data;
    vector<vector<string>> criminals_data;
    vector<string> data_type{"Record ID", "Name", "Nationality", "Gender", "Age", "Height", "Weight", "Career","Institution", "Date", "Criminal Type", "Victim Age", "Term"};
    int criminalIndex;

public:
    void create_data();
    string generateUniqueID();

    // screens folder
    void loginScreen();
    void menuScreen();

    // components folder
    void addRecord();
    void input();
    void inputName();
    void inputNationality();
    void inputGender();
    void inputAge();
    void inputHeight();
    void inputWeight();
    void inputCrime();
    void inputVictim();
    void output();
    void search(int index);
    void searchRecord();
    void editRecord();
    void edit(int i);
    void viewRecord();
    void notfoundRecord();
    void deleteRecord();
    void generate();
    void generateReport();
    // void storeMedia();
    // void courtProgress();
    // void notifications();
    // void userManagement();
    // void classifyRecords();
    // void linkRecords();
    // void anonymize();
    // void exportRecord();
};

#endif // CLASSIFIED_OPS_SYSTEM_H