#ifndef FONT_WEIGHT_H
#define FONT_WEIGHT_H

#include <string>
#include <sstream>
using namespace std;

// USAGE: setFontWeight(FontWeights::weight, string)

// EXAMPLE: cout << setFontWeight(FontWeights::bold, "Hello, world!") << endl;

/* DESCRIPTION: This enum defines a set of ANSI escape codes for different font weights,
with reset representing the escape code to reset the font weight to default.
The setFontWeight function takes a FontWeights value and a string, and returns the string
with the appropriate escape code added for the specified font weight. */


enum class FontWeight
{
    normal = 22,
    bold = 1,
    light = 2,
    reset = 0 // reset to default font weight
};

const string setFontWeight(const FontWeight weight, const string &str)
{
    stringstream ss;
    ss << "\033[" << static_cast<int>(weight) << "m" << str << "\033[0m"; // "\033[" is the start of the escape sequence used to apply a font weight to the text.
    return ss.str();
}

#endif // FONT_WEIGHT_H
