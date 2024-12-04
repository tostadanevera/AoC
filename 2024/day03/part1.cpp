#include <bits/stdc++.h>

using namespace std;

int main() {
    regex r(R"(mul\(\d+,\d+\))");
    string s; getline(cin, s);

    int sol = 0;
    
    smatch sm;
    while (regex_search(s, sm, r)) {
        regex rn(R"(\d+)");
        string sn = sm.str(0);
        smatch smn;

        int mult = 1;
        while (regex_search(sn, smn, rn)) {
            mult *= stoi(smn[0].str());
            sn = smn.suffix().str();
        }

        sol += mult;
        s = sm.suffix().str();
    }

    cout << sol << endl;

    return 0;
}
