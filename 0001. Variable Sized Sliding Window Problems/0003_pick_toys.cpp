//  pick toys

// have to take toys in line cannot skip any single one
// can take only toys of two types
// we have to get john max toys

// Input : str = "abaccab"; every letter is a type of toy (arr of toys)

#include <iostream>
#include <map>
#include <climits>
using namespace std;

int Max_Toys(string str)
{
    int i = 0, j = 0, n = str.length();
    map<char, int> m;
    int mx = INT_MIN;
    int k = 2; // max john can have toys of two types

    while (j < n)
    {
        ++m[str[j]];
        if (m.size() < 2)
        {
        }
        else if (m.size() == 2)
        {
            mx = max(mx, j - i + 1);
        }
        else if (m.size() > 2)
        {
            while (m.size() > 2)
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
    string str = "abaccab";

    cout << "Maximum toys john can have with respect to given condition : " << Max_Toys(str) << endl;

    return 0;
}
