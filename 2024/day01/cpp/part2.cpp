#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    map<int, int> m;
    int n, sol = 0;

    while (cin >> n) {
        v.push_back(n);
        cin >> n;
        m[n]++;
    }

    for (int i = 0; i < v.size(); i++) {
        sol += v[i] * m[v[i]];
    }

    cout << sol << endl;

    return 0;
}
