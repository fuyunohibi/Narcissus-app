#include <iostream>
#include "src/classes/classifiedOpsSystem.hpp"      // ClassifiedOpsSystem
#include "src/constants/logo.hpp"                  // logo()
#include "src/screens/loginScreen.cpp"            // loginScreen()
#include "src/screens/menuScreen.cpp"            // menuScreen()
using namespace std;

// TODO: If You wanna ctrl+z / ctrl+c please tell the Team first!
int main()
{
    MesanLogoWithStyles();
    ClassifiedOpsSystem criminals;
    criminals.loginScreen();
    criminals.menuScreen();

    return 0;
}