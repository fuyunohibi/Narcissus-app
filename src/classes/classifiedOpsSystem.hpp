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
    vector<string> all_data;
    vector<vector<string>> criminals_data = {
        {"65011000", "John Doe", "Thai", "Male", "64", "165", "64", "officer", "BCC", "19/12/1987", "Theft", "19", "LIFE"},
        {"65011001", "Kim Sum", "Korean", "Female", "24", "155", "49", "Software Engineer", "Somebody", "25/12/1987", "Cybercrime", "30", "LIFE"},
        {"65011002", "Jung Petch", "Korean", "Male", "24", "190", "70", "Super Star", "Mesan", "31/12/2004", "Cybercrime with Kim Sum", "30", "LIFE"},
        {"65011003", "Lee Wan", "Korean", "Male", "19", "186", "170", "Super Man", "Mesan", "31/12/2004", "Stole the kid's candy", "7", "1 Day"}};
    vector<string> data_type={"Record ID", "Name", "Nationality", "Gender", "Age", "Height", "Weight", "Career", "Institution", "Date", "Criminal Type", "Victim Age", "Term"};
    int count = criminals_data.size();
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
    void search(int n);
    void searchRecord();
    void editRecord();
    void edit(int i);
    void viewRecord();
    void notfoundRecord();
    void deleteRecord();

    // mapping the vector for making mapped data to parse into json format => send to react
    void makeMapData();

    // sending data to react
    void generate(int &specificCriminalIndex);
    void sendDataToReact(const string &jsonStr);
};


#endif // CLASSIFIED_OPS_SYSTEM_H