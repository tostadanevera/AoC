#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> sum = {0};
    string line;
    while (getline(cin, line))
    {
        if (line == "")
        {
            sum.push_back(0);
        } // starts new sum
        else
        {
            sum.back() += stoi(line);
        } // sum number
    }
    // Sort the first 3 positions of the vector, puts the three highest nums at the beginning
    partial_sort(sum.begin(), sum.begin() + 3, sum.end(), greater<int>());
    cout << "Part 1: " << sum[0] << endl;                   // higher sum
    cout << "Part 2: " << sum[0] + sum[1] + sum[2] << endl; // sum of the 3 highest sums

    return 0;
}