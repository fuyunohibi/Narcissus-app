#include <iostream>
#include <string>
#include "../constants/logo.hpp"
#include "../constants/colors.hpp"
#include "../constants/fontWeight.hpp"
#include "../helpers/ClearScreen.hpp"
#include "../classes/classifiedOpsSystem.hpp"
#include "../components/functions.hpp"
using namespace std;

void ClassifiedOpsSystem::menuScreen()
{
    cout << "\n\t___________________________________________________________" << endl;
    cout << setFontWeight(FontWeight::bold, 
            setColor(Color::cyan, 
            " \n \t\t\t             MANAGEMENT SYSTEM                  ")) 
        << endl;
    cout << "\t___________________________________________________________\n\n"
         << endl;
    cout << "\t1. ADD RECORD" << endl;
    cout << "\n\t2. SEARCH RECORD" << endl;
    cout << "\n\t3. EDIT RECORD" << endl;
    cout << "\n\t4. VIEW RECORD" << endl;
    cout << "\n\t5. DELETE RECORD" << endl;
    cout << "\n\t6. EXIT" << endl;
    cout << "\n\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1";
    cout << "\n\n\tEnter your choice  : ";
    int n;
    cin >> n;
    if(criminals_data.size() == 0 && n != 1 && n != 6){
        cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\tCurrently there are no criminal information in the recorder. Please add record first.")) << endl;
        menuScreen();
    }
    else{
        switch (n)
        {
        case 1:
            addRecord();
        case 2:
            searchRecord();
        case 3:
            editRecord();
        case 4:
            viewRecord();
        case 5:
            deleteRecord();
        case 6:
            MesanEndingLogoWithStyles();
            exit(0);
        default:
            cout << "\n\n            ENTER WRONG CHOICE PRESS AGAIN     \n"
                 << endl;
            menuScreen();
            break;
        }
    }
}