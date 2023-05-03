#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "src/components/TypeOfCrime.cpp"
#include "src/constants/colors.cpp"
#include "src/components/functions.cpp"
#include "src/constants/logo.cpp"
#include "src/helpers/ClearScreen.cpp"
#include "src/constants/fontWeight.cpp"

// TODO: If You wanna ctrl+z / ctrl+c please tell the Team first!

using namespace std;

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
    void login();
    void mainMenu();
    void input();
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

void ClassifiedOpsSystem::mainMenu()
{
    cout << "\n\t___________________________________________________________" << endl;
    cout << " \n \t\t             MANAGEMENT SYSTEM                  " << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t1. ADD RECORD" << endl;
    cout << "\n\t2. SEARCH RECORD" << endl;
    cout << "\n\t3. EDIT RECORD" << endl;
    cout << "\n\t4. VIEW RECORD" << endl;
    cout << "\n\t5. DELETE RECORD" << endl;
    cout << "\n\t6. EXIT" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    cout << "\n\n\tEnter your choice: ";
    int n;
    cin >> n;
    switch (n) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            MesanEndingLogoWithStyles();
            exit(0);
        default:
            cout << "\n\n            ENTER WRONG CHOICE PRESS AGAIN     \n" << endl;
            mainMenu();
            break;
    }

}

void ClassifiedOpsSystem::login()
{
    int attempts = 0;
    const int MAX_attempts = 3;
    string attemps_left;
    string username = "mesan";
    string password = "1234";

    while (attempts < MAX_attempts)
    {
            cout << "\n\n\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
            cout << "\n\t\t\t" << setFontWeight(FontWeight::bold, "Welcome Back") << "\t\t" << endl;
            cout << "\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

            // prompt user for username and password
            cout << "\n\t\tENTER USERNAME     : "
                 << "\t";
            string input_username;
            cin >> input_username;

            cout << "\n\t\tENTER PASSWORD     :  "
                 << "\t";
            string input_password;
            cin >> input_password;

            clearScreen();

            if (input_username == username && input_password == password)
            {
                cout << "\n\n\n\n\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
                cout << "\n\t\t\t      "
                     << setFontWeight(FontWeight::bold, setColor(Color::green, "Login Succesful")) << endl;
                cout << "\n\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n\n"
                     << endl;
                break;
            }
            else
            {
                attempts++;
                attemps_left = to_string(MAX_attempts - attempts);
                cout << setColor(Color::red, "\n『 You have entered the wrong Username or Password  』") << endl;
                cout << attemps_left << setColor(Color::green, " attempts left") << endl;
                if (attempts == 3) {
                    clearScreen();
                }

                
            }
    }

    if (attempts >= MAX_attempts)
    {
            cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\n\t『 Login Unsuccessful 』\n")) << endl;
            exit(0);
    }

    // clearScreen();
}

void ClassifiedOpsSystem::input()
{
    // implementation for inputting a criminal record
}

void ClassifiedOpsSystem::output()
{
    // implementation for outputting a criminal record
}

void ClassifiedOpsSystem::searchRecord()
{
    // implementation for searching a criminal record
}

void ClassifiedOpsSystem::editRecord()
{
    // implementation for editing a criminal record
}

void ClassifiedOpsSystem::viewRecord()
{
    // implementation for viewing a criminal record
}

void ClassifiedOpsSystem::deleteRecord()
{
    // implementation for deleting a criminal record
}

void ClassifiedOpsSystem::generateReport()
{
    // implementation for generating reports
}

void ClassifiedOpsSystem::storeMedia()
{
    // implementation for storing and displaying images or videos
}

void ClassifiedOpsSystem::courtProgress()
{
    // implementation for tracking the progress of a criminal case
}

void ClassifiedOpsSystem::notifications()
{
    // implementation for generating alerts or notifications
}

void ClassifiedOpsSystem::userManagement()
{
    // implementation for user management
}

void ClassifiedOpsSystem::classifyRecords()
{
    // implementation for classifying criminal records using machine learning algorithms
}

void ClassifiedOpsSystem::linkRecords()
{
    // implementation for linking related criminal records
}

void ClassifiedOpsSystem::anonymize()
{
    // implementation for anonymizing or redacting sensitive information in criminal records
}

void ClassifiedOpsSystem::exportRecord()
{
    // implementation for exporting criminal records to different formats
}



int main()
{
    MesanLogoWithStyles();
    ClassifiedOpsSystem Captain;
    Captain.login();
    Captain.mainMenu();
    

    return 0;
}
