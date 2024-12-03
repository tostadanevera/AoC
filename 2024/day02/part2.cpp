#include <bits/stdc++.h>

using namespace std;

bool check_safety(vector<int> v) {
    bool increasing = true;
    bool decreasing = true;
    
    for (int i = 0; i < v.size() - 1; i++) {
        int diff = abs(v[i] - v[i + 1]);
        
        if (diff < 1 || diff > 3) {
            return false;
        }
        
        if (v[i] >= v[i + 1]) {
            increasing = false;
        }
        if (v[i] <= v[i + 1]) {
            decreasing = false;
        }
    }
    
    return increasing || decreasing;
}

bool check_safety_removed(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        vector<int> rem;
        for (int j = 0; j < v.size(); j++) {
            if (j != i) {
                rem.push_back(v[j]);
            }
        }
        
        if (check_safety(rem)) {
            return true;
        }
    }
    return false;
}

int main() {
    int sol = 0;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);

        int n;
        vector<int> v;

        while (ss >> n) {
            v.push_back(n);
        }

        if (check_safety(v)) {
            sol++;
        } else {
            if (check_safety_removed(v)) {
                sol++;
            }
        }
    }
    
    cout << sol << endl;

    return 0;
}
