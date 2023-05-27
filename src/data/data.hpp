#ifndef DATA_H
#define DATA_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "../classes/classifiedOpsSystem.hpp"
#include <curl/curl.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace std;
using namespace rapidjson;

vector<string> react_data; // Declare the vector as "extern" to indicate it's defined elsewhere

// (MESAN MEMBER - CAPTAIN) Part

#include <curl/curl.h>

// Callback function to capture the response from the server
size_t writeCallback(char *ptr, size_t size, size_t nmemb, string *buffer)
{
   size_t totalSize = size * nmemb;
   buffer->append(ptr, totalSize);
   return totalSize;
}

void ClassifiedOpsSystem::sendDataToReact(const string &jsonStr)
{
   string json_str = jsonStr; // Declare and initialize 'json_str' variable
   cout << endl
        << "JSON Data: " << json_str << endl
        << endl; // Print the JSON data to the console
   CURL *curl = curl_easy_init();
   if (curl)
   {
      // send POST request to the React application running on port 4000
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:4000/receiveData");
      curl_easy_setopt(curl, CURLOPT_POST, 1); // Set the request method to POST
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());

      // Set up a buffer to capture the response
      std::string responseBuffer;
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

      // Set the Content-Type header to specify JSON data
      struct curl_slist *headers = nullptr;
      headers = curl_slist_append(headers, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

      // Perform the request
      CURLcode res = curl_easy_perform(curl);
      if (res == CURLE_OK)
      {
         long responseCode;
         curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
         cout << "Response Code: " << responseCode << endl;
         cout << "Response Body: " << responseBuffer << endl;
      }
      else
      {
         cout << "Failed to perform the request: " << curl_easy_strerror(res) << endl;
      }

      // Clean up
      curl_easy_cleanup(curl);
   }
   else
   {
      std::cout << "Failed to initialize libcurl" << std::endl;
   }
}

void ClassifiedOpsSystem::search()
{
   string id;
   bool found = false;
   int width = 16;
   do
   {
      cout << "\n\n\tEnter criminal's record ID : ";
      cin >> id;
      cout << endl;
      for (int i = 0; i < criminals_data.size(); i++)
      {
         if (criminals_data[i][0] == id)
         {
            cout << setFontWeight(FontWeight::bold, setColor(Color::green, "\n\t\tFound information")) << endl;
            for (int j = 0; j < data_type.size(); j++)
            {
               cout << "\n\t" << setw(width) << left << data_type[j] << ": " << criminals_data[i][j] << endl;
            }
            specificCriminalIndex = i;
            found = true;
            break;
         }
      }
      if (!found)
      {
         cout << setFontWeight(FontWeight::bold, setColor(Color::red, "\n\t\tNo information found")) << endl;
         cin.clear();
         notfoundRecord();
      }
      else
      {
         generate();
      }
   } while (!found);
   menuScreen();
}

void ClassifiedOpsSystem::generate()
{
   bool validAns = false;
   char ans;
   while (!validAns)
   {
      cout << "\n\tDo you want to display this information on the web? (Y/N) : ";
      cin >> ans;
      ans = std::toupper(ans);
      switch (ans)
      {
      case 'Y':
         validAns = true;

         for (int j = 0; j < data_type.size(); j++)
         {
            react_data.push_back(criminals_data[specificCriminalIndex][j]);
         }

         makeMapData();             // Call the makeMapData function to generate the JSON data
         sendDataToReact(json_str); // Pass the JSON data to sendDataToReact
         break;
      case 'N':
         validAns = true;
         break;
      default:
         cout << "\n\t\tInvalid input. Please enter Y or N." << endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         break;
      }
   }
}

void ClassifiedOpsSystem::makeMapData()
{
   map<string, string> record;

   // Adding fields to the record
   record["recordID"] = react_data[0];
   record["name"] = react_data[1];
   record["nationality"] = react_data[2];
   record["gender"] = react_data[3];
   record["age"] = react_data[4];
   record["height"] = react_data[5];
   record["weight"] = react_data[6];
   record["career"] = react_data[7];
   record["institution"] = react_data[8];
   record["date"] = react_data[9];
   record["typeOfCrime"] = react_data[10];
   record["victimAge"] = react_data[11];
   record["term"] = react_data[12];

   // Serialize the data to JSON
   Document json_data(kObjectType);
   for (const auto &field : record)
   {
      Value key(field.first.c_str(), json_data.GetAllocator());
      Value value(field.second.c_str(), json_data.GetAllocator());
      json_data.AddMember(key, value, json_data.GetAllocator());
   }

   // Convert JSON to string and store it in the member variable
   StringBuffer buffer;
   Writer<StringBuffer> writer(buffer);
   json_data.Accept(writer);
   json_str = buffer.GetString();
}

#endif // DATA_H
