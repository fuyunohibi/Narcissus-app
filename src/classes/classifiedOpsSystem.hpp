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
    vector<vector<string> > criminals_data={{"65011000", "John Doe", "Thai", "Male", "64", "50", "64", "officer", "BCC", "19/12/1987", "Theft", "19", "LIFE"}};
    vector<string> data_type={"Record ID", "Name", "Nationality", "Gender", "Age", "Height", "Weight", "Career", "Institution", "Date", "Criminal Type", "Victim Age", "Term"};
    int specificCriminalIndex;

    // Declare json_str as a member variable
    string json_str; 

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
    void search();
    void searchRecord();
    void editRecord();
    void edit(int i);
    void viewRecord();
    void notfoundRecord();
    void deleteRecord();
    // void storeMedia();
    // void courtProgress();
    // void notifications();
    // void userManagement();
    // void classifyRecords();
    // void linkRecords();
    // void anonymize();
    // void exportRecord();

    // mapping the vector for making mapped data to parse into json format => send to react
    void makeMapData();

    // sending data to react
    void generate();
    void sendDataToReact(const string &jsonStr);
};


#endif // CLASSIFIED_OPS_SYSTEM_H