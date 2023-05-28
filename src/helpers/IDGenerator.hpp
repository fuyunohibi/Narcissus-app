#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <string>
#include <random>
using namespace std;

int generateUniqueId(int count)
{
    int firstID = 65011000;

    return firstID + count; 
}

#endif // ID_GENERATOR_H
