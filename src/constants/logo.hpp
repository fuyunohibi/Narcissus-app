#ifndef LOGO_H
#define LOGO_H

#include <iostream>
#include <string>
#include "colors.hpp"
#include "fontWeight.hpp"
using namespace std;

string MesanLogo() {
    string logo =  " __    __     ______     ______     ______     __   __        ______   ______     ______     __  __  \n"
                   "/\\ \"-./  \\   /\\  ___\\   /\\  ___\\   /\\  __ \\   /\\ \"-.\\ \\      /\\__  _\\ /\\  ___\\   /\\  ___\\   /\\ \\_\\ \\ \n"
                   "\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\___  \\  \\ \\  __ \\  \\ \\ \\-.  \\     \\/_/\\ \\/ \\ \\  __\\   \\ \\ \\____  \\ \\  __ \\ \n"
                   " \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\\"\\_\\        \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\\n"
                   "  \\/_/  \\/_/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_/ \\/_/         \\/_/   \\/_____/   \\/_____/   \\/_/\\/_/\n";
    return logo;
}

string MesanEndingLogo() {
    string ending = "\n\t________________________________________________________ \n\n"
                    "\t╔═╗─╔╗\n"
                    "\t║║╚╗║║\n"
                    "\t║╔╗╚╝╠══╦═╦══╦╦══╦══╦╗╔╦══╗\n"
                    "\t║║╚╗║║╔╗║╔╣╔═╬╣══╣══╣║║║══╣\n"
                    "\t║║─║║║╔╗║║║╚═╣╠══╠══║╚╝╠══║\n"
                    "\t╚╝─╚═╩╝╚╩╝╚══╩╩══╩══╩══╩══╝\n"
                    "\n  \t\t\t\t\t Developed by Mesan Tech   "
                    "\n\t________________________________________________________\n\n\n ";

    return ending;
}

void MesanLogoWithStyles() {
    string logo = MesanLogo();
    cout << setColor(Color::red, "\n\nMade by") << endl;
    cout << setColor(Color::blue, logo) << endl;
}

void MesanEndingLogoWithStyles() {
    string endingLogo = MesanEndingLogo();
    cout << setFontWeight(FontWeight::bold, setColor(Color::red, endingLogo)) << endl;
}

#endif // LOGO_H


