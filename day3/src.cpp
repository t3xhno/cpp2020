#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void solve() {
    int solution_1{ 0 }, solution_2{ 0 };
    ifstream file;
    file.open("./day3/input.dat");
    if (file.is_open()) {
        int i{ 0 }, j{ 0 };
        for (string line; getline(file, line);) {
            if (i++ == 0) continue;
            j += 3;
            if (line[j % line.length()] == '#') solution_1++;
        }
    }
    if (file.is_open()) file.close();
    cout << '\n';
    cout << "Part 1: " << solution_1 << '\n';
    cout << "Part 2: " << solution_2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}