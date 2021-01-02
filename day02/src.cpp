#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define rf myRange.first - 1
#define rs myRange.second - 1

vector<string> split(string line, string delim) {
    size_t pos_start{ 0 }, pos_end{ 0 }, delim_len{ delim.length() };
    string token{ "" };
    vector<string> result;

    while ((pos_end = line.find(delim, pos_start)) != string::npos) {
        token = line.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        result.push_back(token);
    }
    result.push_back(line.substr(pos_start));
    return result;
}

int countOcc(string str, char letter) {
    int total{ 0 };
    for (auto i: str) {
        total += i == letter;
    }
    return total;
}

pair<int, int> getRange(string myVec) {
    vector<string> stringRange{ split(myVec, "-") };
    return make_pair(stoi(stringRange[0]), stoi(stringRange[1]));
}

void solve() {
    ifstream file;
    int total_1{ 0 }, total_2{ 0 };
    vector<string> myVec;
    file.open("day02/input.dat");
    if (file.is_open()) {
        for (string line; getline(file, line);) {
            myVec = split(line, " ");
            pair<int, int> myRange{ getRange(myVec[0]) };
            char letter{ myVec[1][0] };
            string pass = myVec[2];
            int numOcc{ countOcc(pass, letter) };
            total_1 += numOcc >= myRange.first && numOcc <= myRange.second;
            total_2 += ((pass[rf] == letter) + (pass[rs] == letter)) == 1;
        }
    }
    if (file.is_open()) file.close();
    cout << "\nPart 1: " << total_1 << '\n';
    cout << "Part 2: " << total_2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}