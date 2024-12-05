#include <bits/stdc++.h>
using namespace std;

int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

bool isInBounds(vector<vector<char>>& vv, int x, int y) {
    return x >= 0 && x < vv.size() && y >= 0 && y < vv[0].size();
}

int solve(vector<vector<char>>& vv, int x, int y) {
    string target = "XMAS";
    int count = 0;
    
    for (auto& dir : directions) {
        int new_x = x, new_y = y, k;
        for (k = 0; k < target.size(); k++) {
            new_x = x + dir[0] * k;
            new_y = y + dir[1] * k;
            if (!isInBounds(vv, new_x, new_y) || vv[new_x][new_y] != target[k]) {
                break;
            }
        }
        if (k == target.size()) {
            count++;
        }
    }
    
    return count;
}

int main() {
    string s;
    vector<vector<char>> vv;
    int sol = 0;

    while (getline(cin, s)) {
        vector<char> v;
        stringstream ss(s);
        char c;
        while (ss >> c) {
            v.push_back(c);
        }
        vv.push_back(v);
    }

    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            if (vv[i][j] == 'X') {
                sol += solve(vv, i, j);
            }
        }
    }

    cout << sol << endl;

    return 0;
}