#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;

int solve_1() {
    unordered_set<int> uset;
    ifstream file("day1/input.dat");
    if (file.is_open()) {
        for (string number; getline(file, number);) {
            int num{ stoi(number) };
            if (uset.find(2020 - num) != uset.end()) {
                file.close();
                return num * (2020 - num);
            }
            uset.insert(num);
        }
    }
    if (file.is_open()) file.close();
    return 0;
}

int solve_2_hashing() {
    ifstream file;
    int number;
    vector<int> myVec;
    
    file.open("day1/input.dat");
    while (file >> number) {
        myVec.push_back(number);
    }

    for (int i = 0; i < myVec.size() - 2; i++) {
        unordered_set<int> uset;
        for (int j = i + 1; j < myVec.size(); j++) {
            if (uset.find(2020 - myVec[i] - myVec[j]) != uset.end()) {
                file.close();
                return myVec[i] * myVec[j] * (2020 - myVec[i] - myVec[j]);
            }
            uset.insert(myVec[j]);
        }
    }
    if (file.is_open()) file.close();
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Part 1: " << solve_1() << '\n';
    cout << "Part 2: " << solve_2_hashing() << '\n';

    return 0;
}