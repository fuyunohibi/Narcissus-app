// #include <iostream>
// #include <string>
// #include <map>
// #include "src/TypeOfCrime.cpp"

// using namespace std;

// auto match_gender(string s)
// {
//     map<string , Gender> map_gen;
//     map_gen["male"] = Gender::male;
//     map_gen["female"] = Gender::female;
//     map_gen["unidentified"] = Gender::unidentified;
//     auto it = map_gen.find(s);
//     if(it == map_gen.end())
//     {
//         return true;
//     }
//     Gender gen = it->second;
//     return gen;
// }


// void addrecord()
// {
//     ClassifiedOpsSystem criminal1;
//     cout << "Enter Criminal Name: " << endl;
//     string name;
//     getline(cin , name);
//     string gender;
//     getline(cin , gender);
//     try
//     {
//         auto gen = match_gender(gender);
//         if(gen)
//         {
//             invalid_argument("Invalid Gender ,please try again")
//         }
//     }
//     catch
//     {
//         getline(cin ,gender);
//     }
//     string faces;
//     getline(cin , faces);
//     string ages;
//     getline(cin , ages);
//     int age = stoi(ages);
//     string heights;
//     getline(cin , heights);
//     int height = stoi(heights);
//     string weights;
//     getline(cin , weights);
//     int weight = stoi(weights);
//     string address;
//     getline(cin , address);
//     string contact;
//     getline(cin , contact);

    

// }