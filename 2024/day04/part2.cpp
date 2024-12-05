#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>>& vv, int x, int y) {
    if (vv[x-1][y-1] == 'M' && vv[x-1][y+1] == 'M' && vv[x+1][y+1] == 'S' && vv[x+1][y-1] == 'S') {
        return 1;
    }
    else if (vv[x-1][y-1] == 'S' && vv[x-1][y+1] == 'M' && vv[x+1][y+1] == 'M' && vv[x+1][y-1] == 'S') {
        return 1;
    }
    else if (vv[x-1][y-1] == 'S' && vv[x-1][y+1] == 'S' && vv[x+1][y+1] == 'M' && vv[x+1][y-1] == 'M') {
        return 1;
    }
    else if (vv[x-1][y-1] == 'M' && vv[x-1][y+1] == 'S' && vv[x+1][y+1] == 'S' && vv[x+1][y-1] == 'M') {
        return 1;
    }
    return 0;
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
            if (vv[i][j] == 'A' && i != 0 && j != 0 && i != vv.size()-1 && j != vv[0].size()-1) {
                sol += solve(vv, i, j);
            }
        }
    }

    cout << sol << endl;

    return 0;
}
