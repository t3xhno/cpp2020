#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

int solve() {
    unordered_set<int> uset;
    ifstream file("./day1/input.dat");
    if (file.is_open()) {
        for (string number; getline(file, number);) {
            int num{ stoi(number) };
            if (uset.find(2020 - num) != uset.end()) {
                file.close();
                return num * (2020 - num);
            }
            else uset.insert(num);
        }
    }
    if (file.is_open()) file.close();
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << '\n';

    return 0;
}