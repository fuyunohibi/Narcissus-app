#ifndef DATA_H
#define DATA_H

#include <vector>

using namespace std;


template <class T>
vector<T> criminals_data;

template <class T>
const static vector<T> data(vector<T> d) {
    criminals_data.push_back(d);
}

#endif //DATA_H