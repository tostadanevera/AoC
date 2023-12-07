#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int res = 0;
    string line;
    while (getline(cin, line))
    {
        int blue = 0, red = 0, green = 0;
        istringstream iss(line);
        string s;

        // Vector to store the input
        vector<string> input;

        // Split the line by (" ") 
        while (iss >> s)
        {
            input.push_back(s);
        }
        for (int i = 2; i < input.size(); i+=2)
        {
            if ((input[i+1] == "red," || input[i+1] == "red;" || input[i+1] == "red") && stoi(input[i]) > red) {
                red = stoi(input[i]);
            }
            else if ((input[i+1] == "green," || input[i+1] == "green;" || input[i+1] == "green") && stoi(input[i]) > green) {
                green = stoi(input[i]);
            }
            else if ((input[i+1] == "blue," || input[i+1] == "blue;" || input[i+1] == "blue") && stoi(input[i]) > blue) {
                blue = stoi(input[i]);
            }
        }
        res += red * green * blue; 
        //cout << red << " " << green << " " << blue << endl;
    }
    cout << res << endl;
    return 0;
}
