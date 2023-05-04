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
    cout << " \n\t\t\t\tADD NEW RECORD" << endl;
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

    cout << "\n\t\tEnter Name           : ";
    cin.ignore();
    getline(cin, name);

    cout << "\n\t\tEnter Gender (M/F/O) : ";
    char gender;
    cin >> gender;
    gen = static_cast<Gender>(toupper(gender));

    cout << "\n\t\tEnter Face           : ";
    cin.ignore();
    getline(cin, face);

    cout << "\n\t\tEnter Age            : ";
    cin >> age;

    cout << "\n\t\tEnter Height         : ";
    cin >> height;

    cout << "\n\t\tEnter Weight         : ";
    cin >> weight;

    cout << "\n\t\tEnter Address        : ";
    cin.ignore();
    getline(cin, address);

    cout << "\n\t\tEnter Contact        : ";
    getline(cin, contact);

    // cout << "\n\t\tEnter Type of Crime  : ";
    // cin.ignore();
    // getline(cin, crime_type);

    cout << "\n\t\tEnter Status         : ";
    getline(cin, status);

    cout << "\n\t\tEnter Punishment     : ";
    cin >> punishment;

    cout << "\n\t\tEnter Court          : ";
    cin.ignore();
    getline(cin, court);

    cout << "\n\t\tEnter Victim         : ";
    getline(cin, victim);

    cout << "\n\t\tEnter Victim Address : ";
    getline(cin, vadd);

    cout << "\n\t\tEnter Image Path     : ";
    getline(cin, image);

    cout << "\n\t\tEnter Tags (separated by space): ";
    string tagString;
    getline(cin, tagString);
    stringstream ss(tagString);
    string tag;
    while (ss >> tag)
    {
        tags.push_back(tag);
    }

    cout << "\n\t\tIs the Criminal in Jail (Y/N)? ";
    char jailChar;
    cin >> jailChar;
    in_jail = (toupper(jailChar) == 'Y');
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
