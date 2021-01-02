#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string line, string delim) {
    string token{ "" };
    vector<string> result;
    int pos_start{ 0 }, pos_end{ 0 }, delim_len{ delim.length() };
    while ((pos_end = line.find(delim, pos_start)) != string::npos) {
        token = line.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        result.push_back(token);
    }
    result.push_back(line.substr(pos_start));
    return result;
}

void solve() {
    int solution_1{ 0 }, solution_2{ 0 };
    ifstream file;
    file.open("./day04/input.txt");
    if (file.is_open()) {

    }
    if (file.is_open()) file.close();
    cout << "\nPart 1: " << solution_1 << '\n';
    cout << "Part 2: " << solution_2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}