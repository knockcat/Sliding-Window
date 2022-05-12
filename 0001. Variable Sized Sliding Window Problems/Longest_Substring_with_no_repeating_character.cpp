// Longset Substring with no repeating characters

#include <iostream>
#include <map>
using namespace std;

int Longest_Substring(string str)
{
    int i = 0, j = 0, n = str.length();

    map<char, int> m;
    int mx = INT_MIN;

    while (j < n)
    {
        ++m[str[j]];
        if (m.size() > j - i + 1)
        {
            // never hit 
        }
        else if (m.size() == j - i + 1)
        {
            mx = max(mx, j - i + 1);
        }
        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                --m[str[i]];
                if (m[str[i]] == 0)
                    m.erase(str[i]);
                ++i;
            }
        }
        ++j;
    }
    return mx;
}

int main()
{
    string str = "pwwkew";

    cout << Longest_Substring(str) << endl;

    return 0;
}