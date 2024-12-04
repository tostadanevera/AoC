#include <bits/stdc++.h>

using namespace std;

int match(string s) {
    regex r(R"(mul\(\d+,\d+\))");

    int sum = 0;
    
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

        sum += mult;
        s = sm.suffix().str();
    }

    return sum;
}

int main() {
    regex rd(R"(do\(\))");
    regex rdt(R"(don\'t\(\))");

    string s; 
    getline(cin, s);

    int sol = 0;

    smatch sm, smd;

    regex_search(s, sm, rdt);
    sol += match(sm.prefix().str());
    s = sm.suffix().str();

    while (regex_search(s, sm, rd)) {
        string temp = sm.suffix().str();
        if (regex_search(temp, smd, rdt)) {
            sol += match(smd.prefix().str());
            s = smd.suffix().str();
        }
        else {
            sol += match(temp);
            break;
        }
    }
    
    cout << sol << endl;

    return 0;
}
