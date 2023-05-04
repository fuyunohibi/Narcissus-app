#include <iostream>
#include <string>
#include "../constants/colors.hpp"
#include "../constants/fontWeight.hpp"
#include "../helpers/ClearScreen.hpp"
#include "../classes/classifiedOpsSystem.hpp"
using namespace std;

void ClassifiedOpsSystem::loginScreen()
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
            if (attempts == 3)
            {
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