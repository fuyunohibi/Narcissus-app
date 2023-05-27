#include <iostream>
#include "src/classes/classifiedOpsSystem.hpp"      // ClassifiedOpsSystem
#include "src/constants/logo.hpp"                  // logo()
#include "src/screens/loginScreen.cpp"            // loginScreen()
#include "src/screens/menuScreen.cpp"            // menuScreen()
using namespace std;

// TODO: If You wanna ctrl+z / ctrl+c please tell the Team first!
// ID: 65011000 for initial criminal

// To compile and run the program correctly, you should use the generated executable from CMake, 
// correct command to run the program:
// "/Users/capt/Desktop/developments/Mesan-Project/Narcissus-app/build" && ./ NarcissusApp 
// Make sure you are running this command from the build directory.This will execute the NarcissusApp executable,
// which was built using CMake and contains the necessary linker settings to find the RapidJSON library.


int main()
{
    MesanLogoWithStyles();
    ClassifiedOpsSystem criminals;
    criminals.loginScreen();
    criminals.menuScreen();

    return 0;
}