// Longest Substring with K unique Characters

#include <iostream>
#include <unordered_map>
using namespace std;

int Longest_Substring(string str, int k)
{
    int i = 0, j = 0;
    int n = str.length();
    int mx = INT_MIN;

    unordered_map<char, int> m;

    while (j < n)
    {
        ++m[str[j]];

        if (m.size() < k)
        {
        }

        if (m.size() == k)
        {
            mx = max(mx, j - i + 1);
        }

        else if (m.size() > k)
        {
            while (m.size() > k)
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
    string str = "aabacbebebe";
    int k = 3;

    cout << "Longest Substring with K unique Characters : " << Longest_Substring(str, k);

    return 0;
}