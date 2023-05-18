#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "../constants/colors.hpp"
#include "../constants/fontWeight.hpp"
#include "../helpers/ClearScreen.hpp"
#include "../classes/classifiedOpsSystem.hpp"
#include "../helpers/IDGenerator.hpp"
#include "../data/data.hpp"

using namespace std;

void ClassifiedOpsSystem::addRecord()
{
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n\t\t\t ADD NEW RECORD" << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;

    input();

    cout << setColor(Color::green, "\n\n\t\t『 RECORD ADDED SUCCESSFULLY 』") << endl;
    menuScreen();
}

void ClassifiedOpsSystem::input()
{
    cout << "\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "\n\t\t\tENTER CRIMINAL DETAILS" << endl;
    cout << "\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

    all_data.clear();

    int caseID = generateUniqueId(count);
    recordID = caseID;
    all_data.push_back(to_string(recordID));
    cout << "\n\tRecord ID: " << caseID << endl;
    count += 1;

    cout << "\n\tEnter Name           : ";
    cin.ignore();
    getline(cin, name);
    all_data.push_back(name);

    bool validGender = false;
    char genderChar;
    do
    {
        cout << "\n\tEnter Gender (M/F/O) : ";
        cin >> genderChar;
        genderChar = toupper(genderChar);

        switch (genderChar)
        {
        case 'M':
            gender = "Male";
            validGender = true;
            break;
        case 'F':
            gender = "Female";
            validGender = true;
            break;
        case 'O':
            gender = "Other";
            validGender = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter M, F, or O.")) << endl;
            cin.clear();
            break;
        }
    } while (!validGender);
    all_data.push_back(gender);

    bool validAge = false;
    while (!validAge) {
        cout << "\n\tEnter Age            : ";
        if (cin >> age && age > 0 && age <= 150) {
            validAge = true;
        } else {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Age. Please enter a number between 1 and 150.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards input characters from the input stream until the specified delimiter
        }
    }
    all_data.push_back(to_string(age));

    bool validHeight = false;
    while (!validHeight) {
        cout << "\n\tEnter Height (cm)    : ";
        if (cin >> height && height > 0 && height <= 300) {
            validHeight = true;
        } else {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Height. Please enter a number between 1 and 300.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
    all_data.push_back(to_string(height));

    bool validWeight = false;
    while (!validWeight) {
        cout << "\n\tEnter Weight (kg)    : ";
        if (cin >> weight && weight > 0 && weight <= 1000) {
            validWeight = true;
        } else {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Weight. Please enter a number between 1 and 1000.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    all_data.push_back(to_string(weight));

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n\tEnter Address        : ";
    getline(cin, address);
    all_data.push_back(address);

    cout << "\n\tEnter Contact        : ";
    getline(cin, contact);
    all_data.push_back(contact);

    cout << "\n\tEnter Career         : ";
    getline(cin, career);
    all_data.push_back(career);

    cout << "\n\tEnter Date (D/M/Y)   : ";
    getline(cin, date);
    all_data.push_back(date);

    bool validCrime = false;
    while (!validCrime) {
        cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" << endl;
        cout << "\n\tEnter Type of Crime  : " << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t1. Theft")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t2. Assualt")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t3. Fraud")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t4. Cybercrime")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t5. Other")) << endl;
        cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
        cout << "\n\n\tEnter your choice    : ";
        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            crime_type = "Theft";
            validCrime = true;
            break;
        case 2:
            crime_type = "Assault";
            validCrime = true;
            break;
        case 3:
            crime_type = "Fraud";
            validCrime = true;
            break;
        case 4:
            crime_type = "Cybercrime";
            validCrime = true;
            break;
        case 5:
            crime_type = "Other";
            validCrime = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter a number between 1 and 5.")) << endl;
            cin.clear();
            break;
        }
    }
    all_data.push_back(crime_type);

    bool validVictim = false;
    while (!validVictim)
    {
        cout << "\n\tEnter Victim Age     : ";
        if (cin >> victim && victim > 0 && victim <= 150)
        {
            validVictim = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Age. Please enter a number between 1 and 150.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards input characters from the input stream until the specified delimiter
        }
    }
    all_data.push_back(to_string(victim));

    cout << "\n\tEnter Term           : ";
    cin.ignore();
    getline(cin, term);
    all_data.push_back(term);

    criminals_data.push_back(all_data);
}

void ClassifiedOpsSystem::output(){
    for(const auto& d: criminals_data){
        for(const auto& i: d){
            cout << i << " ";
        }
        cout << endl;
    }
    menuScreen();
}

void ClassifiedOpsSystem::searchRecord(){
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n \t\t             Search Record                  " << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t1. RECORD ID" << endl;
    cout << "\n\t2. NAME" << endl;
    cout << "\n\t3. GO BACK" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    cout << "\n\n\tEnter your choice   : ";
    int n;
    cin >> n;
    string ip;
    switch (n)
    {
    case 1:
        cout << "\n\n\tEnter criminal's record ID  : ";
        cin >> ip;
        for(int i = 0; i < criminals_data.size(); i++){
            if(criminals_data[i][0] == ip){
                cout << "\n\tName          : " << criminals_data[i][1] << endl;
                cout << "\n\tRecord ID     : " << criminals_data[i][0] << endl;
                cout << "\n\tGender        : " << criminals_data[i][2] << endl;
                cout << "\n\tAge           : " << criminals_data[i][3] << " years" << endl;
                cout << "\n\tHeight        : " << criminals_data[i][4] << " cm" << endl;
                cout << "\n\tWeight        : " << criminals_data[i][5] << " kg" << endl;
                cout << "\n\tAddress       : " << criminals_data[i][6] << endl;
                cout << "\n\tContact       : " << criminals_data[i][7] << endl;
                cout << "\n\tCareer        : " << criminals_data[i][8] << endl;
                cout << "\n\tDate          : " << criminals_data[i][9] << endl;
                cout << "\n\tCriminal Type : " << criminals_data[i][10] << endl;
                cout << "\n\tVictim Age    : " << criminals_data[i][11] << " years" << endl;
                cout << "\n\tTerm          : " << criminals_data[i][12] << endl;
                cout << endl;
            }
        }
        menuScreen();
    case 2:
        cout << "\n\n\tEnter criminal's name       : ";
        cin >> ip;
        for (int i = 0; i < criminals_data.size(); i++){
            if (criminals_data[i][1] == ip){
                cout << "\n\tName          : " << criminals_data[i][1] << endl;
                cout << "\n\tRecord ID     : " << criminals_data[i][0] << endl;
                cout << "\n\tGender        : " << criminals_data[i][2] << endl;
                cout << "\n\tAge           : " << criminals_data[i][3] << " years" << endl;
                cout << "\n\tHeight        : " << criminals_data[i][4] << " cm" << endl;
                cout << "\n\tWeight        : " << criminals_data[i][5] << " kg" << endl;
                cout << "\n\tAddress       : " << criminals_data[i][6] << endl;
                cout << "\n\tContact       : " << criminals_data[i][7] << endl;
                cout << "\n\tCareer        : " << criminals_data[i][8] << endl;
                cout << "\n\tDate          : " << criminals_data[i][9] << endl;
                cout << "\n\tCriminal Type : " << criminals_data[i][10] << endl;
                cout << "\n\tVictim Age    : " << criminals_data[i][11] << " years" << endl;
                cout << "\n\tTerm          : " << criminals_data[i][12] << endl;
                cout << endl;
            }
        }
        menuScreen();
    case 3:
        menuScreen();
    default:
        cout << "\n\n            ENTER WRONG CHOICE PRESS AGAIN     \n"
             << endl;
        searchRecord();
        break;
    }
}
// void editRecord();
// void viewRecord();
void ClassifiedOpsSystem::deleteRecord(){
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n \t\t             Delete Record                  " << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t1. RECORD ID" << endl;
    cout << "\n\t2. NAME" << endl;
    cout << "\n\t3. GO BACK" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    cout << "\n\n\tEnter your choice   : ";
    int n;
    cin >> n;
    string ip;
    switch (n)
    {
    case 1:
        cout << "\n\n\tEnter criminal's record ID  : ";
        cin >> ip;
        for (int i = 0; i < criminals_data.size(); i++)
        {
            if (criminals_data[i][0] == ip)
            {
                criminals_data.erase(criminals_data.begin() + i);
            }
        }
        menuScreen();
    case 2:
        cout << "\n\n\tEnter criminal's name       : ";
        cin >> ip;
        for (int i = 0; i < criminals_data.size(); i++)
        {
            if (criminals_data[i][1] == ip)
            {
                criminals_data.erase(criminals_data.begin() + i);
            }
        }
        menuScreen();
    case 3:
        menuScreen();
    default:
        cout << "\n\n            ENTER WRONG CHOICE PRESS AGAIN     \n"
             << endl;
        deleteRecord();
        break;
    }
}
// void generateReport();
// void storeMedia();
// void courtProgress();
// void notifications();
// void userManagement();
// void classifyRecords();
// void linkRecords();
// void anonymize();
// void exportRecord();

#endif // FUNCTIONS_H