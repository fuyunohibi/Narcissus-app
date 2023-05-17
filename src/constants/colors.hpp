#ifndef COLORS_H
#define COLORS_H

#include <string>
#include <sstream>
using namespace std;

// USAGE: setColor(Colors::color, string) 

// EXAMPLE: cout << colorize(Colors::red, "Hello, world!") << endl;

/* DESCRIPTION: This enum defines a set of ANSI escape codes for different colors,
with reset representing the escape code to reset the terminal color to default.
The colorize function takes a Colors value and a string, and returns the string
with the appropriate escape code added for the specified color. */

enum class Color {
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    reset = 0 // reset to default color
};

const string setColor(const Color color, const string &str)
{
    stringstream ss;
    ss << "\033[" << static_cast<int>(color) << "m" << str << "\033[0m"; // "\033[" is the start of the escape sequence used to apply a color to the text.
    return ss.str();
}

#endif // COLORS_H