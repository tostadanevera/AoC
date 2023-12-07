#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int RED = 12, GREEN = 13, BLUE = 14;
    int res = 0;
    string line;
    while (getline(cin, line))
    {
        int blue = 0, red = 0, green = 0, id = 0;
        bool pos = true;
        istringstream iss(line);
        string s;

        // Vector to store the input
        vector<string> input;

        // Split the line by (" ") 
        while (iss >> s)
        {
            input.push_back(s);
        }
        id = stoi(input[1].substr(0, input.size() - 1));
        for (int i = 2; i < input.size(); i+=2)
        {
            if ((input[i+1] == "red," || input[i+1] == "red;" || input[i+1] == "red") && stoi(input[i]) > RED) {
                pos = false; 
            }
            else if ((input[i+1] == "green," || input[i+1] == "green;" || input[i+1] == "green") && stoi(input[i]) > GREEN) {
                pos = false; 
            }
            else if ((input[i+1] == "blue," || input[i+1] == "blue;" || input[i+1] == "blue") && stoi(input[i]) > BLUE) {
                pos = false;
            }
            // cout << input[i] << input[i+1] << endl;
        }
        if (pos) { res += id; }
        // cout << id << " " << res << endl;
    }
    cout << res << endl;
    return 0;
}
