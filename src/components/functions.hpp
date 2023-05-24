#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <regex>
#include "../constants/colors.hpp"
#include "../constants/fontWeight.hpp"
#include "../helpers/ClearScreen.hpp"
#include "../classes/classifiedOpsSystem.hpp"
#include "../helpers/IDGenerator.hpp"
#include "../data/data.hpp"

using namespace std;

bool validateString(const string &inputString)
{
    regex integerRegex("\\d");

    // Count the number of matches of integers in the input string
    smatch matches;
    regex_search(inputString, matches, integerRegex);
    int matchCount = static_cast<int>(matches.size());

    // Check if the string contains only one integer
    if (matchCount == 1)
    {
        return false; // Error: Only one integer is present
    }

    return true; // String is valid
}

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

void ClassifiedOpsSystem::inputName(){
    bool validName = false;
    while(!validName){
        cout << "\n\tEnter Name           : ";
        getline(cin, name);
        if (validateString(name))
        {
            validName = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter only letters without numbers.")) << endl;
            cin.clear();
        }
    }
}

void ClassifiedOpsSystem::inputNationality()
{
    bool validNation = false;
    while (!validNation)
    {
        cout << "\n\tEnter Nationality    : ";
        getline(cin, nation);
        if (validateString(nation))
        {
            validNation = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter only letters without numbers.")) << endl;
            cin.clear();
        }
    }
}

void ClassifiedOpsSystem::inputGender(){
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
}

void ClassifiedOpsSystem::inputAge(){
    bool validAge = false;
    while (!validAge)
    {
        cout << "\n\tEnter Age            : ";
        if (cin >> age && age > 0 && age <= 150)
        {
            validAge = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Age. Please enter a number between 1 and 150.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards input characters from the input stream until the specified delimiter
        }
    }
}

void ClassifiedOpsSystem::inputHeight(){
    bool validHeight = false;
    while (!validHeight)
    {
        cout << "\n\tEnter Height (cm)    : ";
        if (cin >> height && height > 100 && height <= 300)
        {
            validHeight = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Height. Please enter a number between 100 and 300.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void ClassifiedOpsSystem::inputWeight(){
    bool validWeight = false;
    while (!validWeight)
    {
        cout << "\n\tEnter Weight (kg)    : ";
        if (cin >> weight && weight > 20 && weight <= 500)
        {
            validWeight = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Weight. Please enter a number between 20 and 500.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void ClassifiedOpsSystem::inputCrime(){
    bool validCrime = false;
    while (!validCrime)
    {
        cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" << endl;
        cout << "\n\tEnter Type of Crime  : " << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t1. Theft")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t2. Assault")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t3. Fraud")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t4. Cybercrime")) << endl;
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\t5. Other")) << endl;
        cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
        cout << "\n\n\tEnter your choice    : ";
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string other;
        bool validOther = false;
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
            while(!validOther){
                cout << "\n\tEnter the type of crime : ";
                getline(cin, other);
                if (validateString(other))
                {
                    crime_type = other;
                    validOther = true;
                }
                else
                {
                    cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter only letters without numbers.")) << endl;
                    cin.clear();
                }
            }
            validCrime = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter a number between 1 and 5.")) << endl;
            cin.clear();
            break;
        }
    }
}

void ClassifiedOpsSystem::inputVictim(){
    bool validVictim = false;
    while (!validVictim)
    {
        cout << "\n\tEnter Victim Age     : ";
        cin >> victim;
        if (victim > 0 && victim <= 150)
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    inputName();
    all_data.push_back(name);

    inputNationality();
    all_data.push_back(nation);

    inputGender();
    all_data.push_back(gender);

    inputAge();
    all_data.push_back(to_string(age));

    inputHeight();
    all_data.push_back(to_string(height));

    inputWeight();
    all_data.push_back(to_string(weight));

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n\tEnter Career         : ";
    getline(cin, career);
    all_data.push_back(career);

    cout << "\n\tEnter Institution    : ";
    getline(cin, institution);
    all_data.push_back(institution);

    cout << "\n\tEnter Date (D/M/Y)   : ";
    getline(cin, date);
    all_data.push_back(date);

    inputCrime();
    all_data.push_back(crime_type);

    inputVictim();
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

void ClassifiedOpsSystem::search(int index){
    string ip;
    bool found = false;
    int width = 16;
    do
    {
        cout << "\n\n\tEnter criminal's record ID : ";
        cin >> ip;
        cout << endl;
        for (int i = 0; i < criminals_data.size(); i++)
        {
            if (criminals_data[i][index] == ip)
            {
                cout << setFontWeight(FontWeight::bold, setColor(Color::green, "\n\t\tFound information")) << endl;
                for (int j = 0; j < data_type.size(); j++)
                {
                    cout << "\n\t" << setw(width) << left << data_type[j] << ": " << criminals_data[i][j] << endl;
                }
                criminalIndex = i;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tNo information found")) << endl;
            cin.clear();
            notfoundRecord();
        }
        else
        {
            generate();
        }
    } while (!found);
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
    char ans;
    bool found = false, validAns = false;
    int width = 16;
    switch (n)
    {
    case 1:
        search(0);
    case 2:
        search(1);
    case 3:
        menuScreen();
    default:
        cout << "\n\n            ENTER WRONG CHOICE PRESS AGAIN     \n"
             << endl;
        searchRecord();
        break;
    }
}

void ClassifiedOpsSystem::edit(int i){
    bool edit = false;
    while (!edit)
    {
        for (int j = 0; j < data_type.size(); j++)
        {
            cout << "\n\t" << setw(18) << left << to_string(j + 1) + ". " + data_type[j] << ": " << criminals_data[i][j] << endl;
        }
        int choice;
        bool invalidChoice = false;
        do
        {
            cout << "\n\tEnter your choice of data type you want to edit : ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice){
                case 1:
                    cout << "\n\tEnter Record ID      : ";
                    cin >> recordID;
                    criminals_data[i][choice - 1] = to_string(recordID);
                    break;
                case 2:
                    inputName();
                    criminals_data[i][choice - 1] = name;
                    break;
                case 3:
                    inputNationality();
                    criminals_data[i][choice - 1] = nation;
                    break;
                case 4:
                    inputGender();
                    criminals_data[i][choice - 1] = gender;
                    break;
                case 5:
                    inputAge();
                    criminals_data[i][choice - 1] = to_string(age);
                    break;
                case 6:
                    inputHeight();
                    criminals_data[i][choice - 1] = to_string(height);
                    break;
                case 7:
                    inputWeight();
                    criminals_data[i][choice - 1] = to_string(weight);
                    break;
                case 8:
                    cout << "\n\tEnter Career         : ";
                    getline(cin, career);
                    criminals_data[i][choice - 1] = career;
                    break;
                case 9:
                    cout << "\n\tEnter Institution    : ";
                    getline(cin, institution);
                    criminals_data[i][choice - 1] = institution;
                    break;
                case 10:
                    cout << "\n\tEnter Date           : ";
                    getline(cin, date);
                    criminals_data[i][choice - 1] = date;
                    break;
                case 11:
                    inputCrime();
                    criminals_data[i][choice - 1] = crime_type;
                    break;
                case 12:
                    inputVictim();
                    criminals_data[i][choice - 1] = to_string(victim);
                    break;
                case 13:
                    cout << "\n\tEnter Term           : ";
                    getline(cin, term);
                    criminals_data[i][choice - 1] = term;
                    break;
                default:
                    cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter the correct choice (1 - 13).")) << endl;
                    cin.clear();
                    invalidChoice = true;
                    break;
            }

        } while(invalidChoice);

        char editMore;
        cout << "\n\tWould you like to edit more information about this criminal? (Y/N): ";
        cin >> editMore;
        editMore = toupper(editMore);
        switch (editMore)
        {
        case 'Y':
            break;
        case 'N':
            cout << setColor(Color::green, "\n\n\t\t『 RECORD EDITED SUCCESSFULLY 』") << endl;
            edit = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter Y or N.")) << endl;
            cin.clear();
            break;
        }
    }
}

void ClassifiedOpsSystem::editRecord()
{
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n \t\t             Edit Record                  " << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t1. RECORD ID" << endl;
    cout << "\n\t2. NAME" << endl;
    cout << "\n\t3. GO BACK" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    cout << "\n\n\tEnter your choice : ";
    int n;
    cin >> n;
    string ip;
    bool found = false;
    switch (n)
    {
    case 1:
        do
        {
            cout << "\n\n\tEnter criminal's record ID : ";
            cin >> ip;
            cout << setFontWeight(FontWeight::bold, setColor(Color::green, "\n\t\tFound information")) << endl;
            for (int i = 0; i < criminals_data.size(); i++)
            {
                    if (criminals_data[i][0] == ip)
                    {
                        edit(i);
                        found = true;
                        break;
                    }
            }
            if (!found)
            {
                    cout << setFontWeight(FontWeight::bold, setColor(Color::green, "\n\t\tNo information found")) << endl;
                    cin.clear();
                    notfoundRecord();
            }
        } while (!found);
        menuScreen();
    case 2:
        do
        {
            cout << "\n\n\tEnter criminal's name : ";
            cin >> ip;
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tFound information")) << endl;
            for (int i = 0; i < criminals_data.size(); i++)
            {
                    if (criminals_data[i][1] == ip)
                    {
                        edit(i);
                        found = true;
                        break;
                    }
            }
            if (!found)
            {
                    cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tNo information found")) << endl;
                    cin.clear();
                    notfoundRecord();
            }
        } while (!found);
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

void ClassifiedOpsSystem::viewRecord(){
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n \t\t             View Record                  " << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t" << setw(5) << right << "NO." << setw(15) << right << "RECORD ID" << setw(15) << right << "NAME" << endl;
    for (int i = 0; i < criminals_data.size(); i++)
    {
        cout << "\n\t" << setw(5) << right << i + 1 << setw(15) << right << criminals_data[i][0] << setw(15) << right << criminals_data[i][1] << endl;
    }
    cout << "\n\tPress q to go back" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    bool found = false;
    string n;
    do
    {
        cout << "\n\n\tEnter number of criminal you want to view : ";
        cin >> n;
        cout << endl;
        if (n == "q" || n == "Q")
        {
            menuScreen();
        }
        else
        {
            try
            {
                    int intValue = std::stoi(n);
                    if (intValue <= criminals_data.size() && intValue > 0)
                    {
                        for (int j = 0; j < data_type.size(); j++)
                        {
                            cout << "\n\t" << setw(16) << left << data_type[j] << ": " << criminals_data[stoi(n) - 1][j] << endl;
                        }
                        criminalIndex = intValue;
                        generate();
                        found = true;
                    }
                    else
                    {
                        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter the number in range of the amount specify above.")) << endl;
                        cin.clear();
                        notfoundRecord();
                    }
            }
            catch (const std::exception &e)
            {
                    cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter the number or command 'q' only.")) << endl;
                    cin.clear();
                    notfoundRecord();
            }
        }
    } while (!found);
    menuScreen();
}

void ClassifiedOpsSystem::notfoundRecord(){
    bool validAns = false;
    while(!validAns){
        char ans;
        cout << "\n\tDo you want to try again? (Y/N) : ";
        cin >> ans;
        ans = toupper(ans);
        switch (ans)
        {
        case 'Y':
            validAns = true;
            break;
        case 'N':
            validAns = true;
            cout << setColor(Color::red, "\n\n\t\t\t『 CANCEL 』") << endl;
            menuScreen();
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter Y or N.")) << endl;
            cin.clear();
            break;
        }
    }
}

void ClassifiedOpsSystem::deleteRecord()
{
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n \t\t             Delete Record                  " << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t1. RECORD ID" << endl;
    cout << "\n\t2. NAME" << endl;
    cout << "\n\t3. GO BACK" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    cout << "\n\n\tEnter your choice : ";
    int n;
    cin >> n;
    string ip;
    bool found = false;
    switch (n)
    {
    case 1:
        do {
            cout << "\n\n\tEnter criminal's record ID : ";
            cin >> ip;
            for (int i = 0; i < criminals_data.size(); i++){
                if (criminals_data[i][0] == ip)
                {
                    criminals_data.erase(criminals_data.begin() + i);
                    cout << setColor(Color::green, "\n\n\t\t『 RECORD DELETED SUCCESSFULLY 』") << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tNo information found")) << endl;
                cin.clear();
                notfoundRecord();
            }
        } while(!found);
        menuScreen();
    case 2:
        do
        {
            cout << "\n\n\tEnter criminal's name : ";
            cin >> ip;
            for (int i = 0; i < criminals_data.size(); i++)
            {
                if (criminals_data[i][1] == ip)
                {
                    criminals_data.erase(criminals_data.begin() + i);
                    cout << setColor(Color::green, "\n\n\t\t『 RECORD DELETED SUCCESSFULLY 』") << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tNo information found")) << endl;
                cin.clear();
                notfoundRecord();
            }
        } while (!found);
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

void ClassifiedOpsSystem::generate(){
    bool validAns = false;
    char ans;
    while (!validAns)
    {
        cout << "\n\tDo you want to display this information on the web? (Y/N) : ";
        cin >> ans;
        ans = toupper(ans);
        switch (ans)
        {
        case 'Y':
            validAns = true;
            generateReport();
            break;
        case 'N':
            validAns = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter Y or N.")) << endl;
            cin.clear();
            break;
        }
    }
}

void ClassifiedOpsSystem::generateReport(){
    // Capt part
    for(int i = 0; i < data_type.size(); i++){
        react_data.push_back(criminals_data[criminalIndex][i]);
    }
    // for(const auto& i: react_data){
    //     cout << i << " ";
    // }
    cout << setFontWeight(FontWeight::bold, setColor(Color::green, "\n\t\tGenerated")) << endl;
}
// void storeMedia();
// void courtProgress();
// void notifications();
// void userManagement();
// void classifyRecords();
// void linkRecords();
// void anonymize();
// void exportRecord();

#endif // FUNCTIONS_H