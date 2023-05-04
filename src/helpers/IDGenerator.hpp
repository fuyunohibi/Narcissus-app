#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <string>
#include <random>
using namespace std;

string generateUniqueId()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 61);

    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string id = "";
    for (int i = 0; i < 8; i++)
    {
        id += chars[dis(gen)];
    }
    
    return id;
}

#endif // ID_GENERATOR_H
