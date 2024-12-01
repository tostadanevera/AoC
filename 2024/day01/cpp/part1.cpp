#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v1, v2;
    int n, sol = 0;

    while (cin >> n) {
        v1.push_back(n);
        cin >> n;
        v2.push_back(n);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++) {
        sol += abs(v1[i] - v2[i]);
    }

    cout << sol << endl;

    return 0;
}
