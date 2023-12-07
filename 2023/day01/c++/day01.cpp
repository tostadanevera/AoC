#include <iostream>
#include <algorithm> 
#include <string>
#include <map>

using namespace std;

char findWord(string current) {
    map<string, char> numMap { { "one", '1' }, { "two", '2' }, { "three", '3' }, { "four", '4' }, { "five", '5' }, { "six", '6' }, { "seven", '7' }, { "eight", '8' }, { "nine", '9' } };
    for (const auto& pair : numMap) {
        if(current.find(pair.first) != string::npos) { return pair.second; break;}
    }
    return '0';
}

int main() {
    int res = 0;
    string line;
    while (getline(cin, line)) {
        char n1, n2;
        string current;
        for (char c : line) {
            current += c;
            if (isdigit(c)) { n1 = c; break; }
            n1 = findWord(current);
            if (n1 != '0') { break; }
        }
        current.clear();
        reverse(line.begin(), line.end());
        for (char c : line) {
            current += c;
            reverse(current.begin(), current.end());
            if (isdigit(c)) { n2 = c; break; }
            n2 = findWord(current);
            if (n2 != '0') { break; }
            reverse(current.begin(), current.end());
        }
        cout << n1 << n2 << endl;
        res += stoi(string(1,n1) + string(1,n2));
    }
    cout << res << endl;

    return 0;
}