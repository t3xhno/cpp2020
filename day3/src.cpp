#include <fstream>
#include <iostream>
using namespace std;

#define ll long long

void solve() {
    ll solution_1{ 0 }, solution_2{ 1 };
    int steps[5][2] = {{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};
    ifstream file;
    file.open("./day3/input.dat");
    if (file.is_open()) {
        for (int k = 0; k < 5; k++) {
            file.clear(); file.seekg(0);
            int i{ 0 }, j{ 0 };
            int total{ 0 };
            int i_step{ steps[k][0] }, j_step{ steps[k][1] };
            for (string line; getline(file, line);) {
                if (i++ % i_step != 0) {
                    continue;
                }
                if (line[j] == '#') total++;
                j += j_step; j %= line.length();
            }
            if (k == 1) solution_1 = total;
            solution_2 *= total;
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