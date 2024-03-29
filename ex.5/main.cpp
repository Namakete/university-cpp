// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

struct DataStruct {
    int key1{};
    int key2{};
    std::string str;
};

std::vector<std::string> table = {"A", "B", "C", "D", "E", "F", "G", "H", "K", "L"};

/*
 * @brief - Generating an array of random values.
 */
std::vector<DataStruct> fillVector() {
    std::vector<DataStruct> vec;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-5, 5);
    std::uniform_int_distribution<> dis2(0, 9);

    // Set the dictionary data to random positions in the array.
    for (int i = 0; i < 5; i++) {
        DataStruct ds;

        ds.key1 = dis(gen);
        ds.key2 = dis(gen);
        ds.str = table[dis2(gen)];

        vec.push_back(ds);
    }

    return vec;
}

// c. Sorts the vector like this:
//  i. Asc key1
//  ii. If key1 are the same, then ascending key2
//  iii. If key1 and key2 are the same, then in ascending order the strings str are long
bool compareDataStruct(const DataStruct &a, const DataStruct &b) {
    bool flag = false;

    if (a.key1 < b.key1) {
        flag = true;
    } else if (a.key1 == b.key1) {
        if (a.key2 < b.key2) {
            flag = true;
        } else if (a.key2 == b.key2) {
            if (a.str.length() < b.str.length()) {
                flag = true;
            }
        }
    }

    return flag;
}

int main() {
    std::vector<DataStruct> vec = fillVector();

    for (const DataStruct &ds : vec) {
        std::cout << ds.key1 << " " << ds.key2 << " " << ds.str << std::endl;
    }

    std::sort(vec.begin(), vec.end(), compareDataStruct);

    std::cout << std::endl;

    for (const DataStruct &ds : vec) {
        std::cout << ds.key1 << " " << ds.key2 << " " << ds.str << std::endl;
    }

    return 0;
}