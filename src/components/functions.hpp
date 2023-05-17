#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "../constants/colors.hpp"
#include "../constants/fontWeight.hpp"
#include "../helpers/ClearScreen.hpp"
#include "../classes/classifiedOpsSystem.hpp"
#include "../helpers/IDGenerator.hpp"

using namespace std;

void ClassifiedOpsSystem::addRecord()
{
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n\t\t\t ADD NEW RECORD" << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    input();

    string caseId = generateUniqueId();
    caseHistory[caseId] = status;

    cout << setColor(Color::green, "\n\n\t\t『 RECORD ADDED SUCCESSFULLY 』") << endl;
    menuScreen();
}

void ClassifiedOpsSystem::input()
{
    cout << "\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "\n\t\t\tENTER CRIMINAL DETAILS" << endl;
    cout << "\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

    cout << "\n\tEnter Name           : ";
    cin.ignore();
    getline(cin, name);

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
            gender = Gender::Male;
            validGender = true;
            break;
        case 'F':
            gender = Gender::Female;
            validGender = true;
            break;
        case 'O':
            gender = Gender::Other;
            validGender = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter M, F, or O.")) << endl;
            cin.clear();
            break;
        }
    } while (!validGender);


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


    bool validHeight = false;
    while (!validHeight) {
        cout << "\n\tEnter Height         : ";
        if (cin >> height && height > 0 && height <= 300) {
            validHeight = true;
        } else {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Height. Please enter a number between 1 and 300.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } 

    bool validWeight = false;
    while (!validWeight) {
        cout << "\n\tEnter Weight         : ";
        if (cin >> weight && weight > 0 && weight <= 1000) {
            validWeight = true;
        } else {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Weight. Please enter a number between 1 and 1000.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "\n\tEnter Address        : ";
    cin.ignore();
    getline(cin, address);

    cout << "\n\tEnter Contact        : ";
    getline(cin, contact);


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
        cout << "\n\n\tEnter your choice  : ";
        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            crime_type = TypeOfCrime::Theft;
            validCrime = true;
            break;
        case 2:
            crime_type = TypeOfCrime::Assault;
            validCrime = true;
            break;
        case 3:
            crime_type = TypeOfCrime::Fraud;
            validCrime = true;
            break;
        case 4:
            crime_type = TypeOfCrime::Cybercrime;
            validCrime = true;
            break;
        case 5:
            crime_type = TypeOfCrime::Other;
            validCrime = true;
            break;
        default:
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter a number between 1 and 5.")) << endl;
            cin.clear();
            break;
        }
    }

    // TODO: Something wrong with status
    cout << "\n\tEnter Status         : ";
    cin.ignore();
    getline(cin, status);

    bool validPunish = false;
    while (!validPunish) {
        cout << "\n\tEnter Punishment (Y) : ";
        if (cin >> punishment && punishment > 0 && punishment <= 150)
        {
            validPunish = true;
        }
        else
        {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid Punishment. Please enter a number between 1 and 150.")) << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards input characters from the input stream until the specified delimiter
        }
    }

        cout << "\n\tEnter Court          : ";
        cin.ignore();
        getline(cin, court);

        cout << "\n\tEnter Victim         : ";
        getline(cin, victim);

        // cout << "\n\tEnter Victim Address : ";
        // getline(cin, vadd);

        // cout << "\n\tEnter Image Path     : ";
        // getline(cin, image);

        // cout << "\n\tEnter Tags (separated by space): ";
        // string tagString;
        // getline(cin, tagString);
        // stringstream ss(tagString);
        // string tag;
        // while (ss >> tag)
        // {
        //     tags.push_back(tag);
        // }
        bool valid_char = false;
        char jailChar;
        do
        {
            cout << "\n\tIs the Criminal in Jail (Y/N)? ";
            cin >> jailChar;
            in_jail = (toupper(jailChar) == 'Y');
            switch (jailChar)
            {
            case('Y') :
                in_jail = true;
                valid_char = true;
                break;
            
            case('N') :
                in_jail = false;
                valid_char = true;
                break;
            
            default:
                cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tInvalid input. Please enter Y/N ")) << endl;
                cin.clear();
                break;
        }
    }while(!valid_char);
    }

// void output();
// void searchRecord();
// void editRecord();
// void viewRecord();
// void deleteRecord();
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

// auto match_gender(string s)
// {
//     map<string , Gender> map_gen;
//     map_gen["male"] = Gender::male;
//     map_gen["female"] = Gender::female;
//     map_gen["unidentified"] = Gender::unidentified;
//     auto it = map_gen.find(s);
//     if(it == map_gen.end())
//     {
//         return true;
//     }
//     Gender gen = it->second;
//     return gen;
// }

// void addrecord()
// {
//     ClassifiedOpsSystem criminal1;
//     cout << "Enter Criminal Name: " << endl;
//     string name;
//     getline(cin , name);
//     string gender;
//     getline(cin , gender);
//     try
//     {
//         auto gen = match_gender(gender);
//         if(gen)
//         {
//             invalid_argument("Invalid Gender ,please try again")
//         }
//     }
//     catch
//     {
//         getline(cin ,gender);
//     }
//     string faces;
//     getline(cin , faces);
//     string ages;
//     getline(cin , ages);
//     int age = stoi(ages);
//     string heights;
//     getline(cin , heights);
//     int height = stoi(heights);
//     string weights;
//     getline(cin , weights);
//     int weight = stoi(weights);
//     string address;
//     getline(cin , address);
//     string contact;
//     getline(cin , contact);

// }
