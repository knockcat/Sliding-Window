// Minimum Window Substring

#include <iostream>
#include <unordered_map>
using namespace std;

string MinimumWindowSubstring(string s, string t)
{
    unordered_map<char, int> m;
    int i = 0, j = 0, n = s.length();
    int k = t.length();
    int mn = INT_MAX;
    int start = 0;

    for (char i : t)
        ++m[i];

    int cnt = m.size();

    while (j < n)
    {
        --m[s[j]];
        if (m[s[j]] == 0)
            --cnt;

        if (cnt == 0)
        {
            while (cnt == 0)
            {
                if (mn > j - i + 1)
                {
                    mn = j - i + 1;
                    start = i;
                }

                ++m[s[i]];
                if (m[s[i]] > 0)
                    ++cnt;
                ++i;
            }
        }
        ++j;
    }
    cout << "LENGTH OF MINIMUM SUBSTRING : " << mn << endl;
    return mn == INT_MAX ? "" : s.substr(start, mn);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << MinimumWindowSubstring(s, t) << endl;

    return 0;
}