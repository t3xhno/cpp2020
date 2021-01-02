#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define UNIMPLEMENTED

vector<string> split(string line, string delim) {
    string token{ "" };
    vector<string> result;
    size_t pos_start{ 0 }, pos_end{ 0 }, delim_len{ delim.length() };
    while ((pos_end = line.find(delim, pos_start)) != string::npos) {
        token = line.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        result.push_back(token);
    }
    result.push_back(line.substr(pos_start));
    return result;
}

string join(vector<string> myVec, string delim) {
    return "Unimplemented";
}

void solve() {
    int solution_1{ 0 }, solution_2{ 0 };
    vector<string> passports;
    ifstream file;
    file.open("./day04/input.txt");
    if (file.is_open()) {
        for (string line; getline(file, line);) {

            // Codes go here

        }
    }

    #ifndef UNIMPLEMENTED
        if (file.is_open()) file.close();
        cout << "\nPart 1: " << solution_1 << '\n';
        cout << "Part 2: " << solution_2 << '\n';
    #else
        cout << "\nUNIMPLEMENTED\n";
    #endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}