#include <bits/stdc++.h>

using namespace std;

bool check_safety(string s) {
    bool increasing = true;
    bool decreasing = true;

    stringstream ss(s);

    int fst, snd;
    ss >> fst;

    while (ss >> snd) {
        int diff = abs(fst - snd);
        
        if (diff < 1 || diff > 3) {
            return false;
        }
        
        if (fst >= snd) {
            increasing = false;
        }
        if (fst <= snd) {
            decreasing = false;
        }

        fst = snd;
    }
    
    return increasing || decreasing;
}

int main() {
    string s;
    int sol = 0;

    while (getline(cin, s)) {
        if (check_safety(s)) {
            sol++;
        }
    }

    cout << sol << endl;

    return 0;
}
