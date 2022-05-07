// count occurences of anagrams

// 2 string

// occurences of anagrams of pattern ( string 2 ) present in ( string 1 )

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int search(string pat, string txt)
{
    // code here

    int i = 0, j = 0;
    int n = txt.length();

    map<char, int> m;

    for (auto i : pat)
        ++m[i];

    int cnt = m.size();

    int k = pat.length();
    int ind = 0;

    while (j < n)
    {
        if (m.find(txt[j]) != m.end())
        {
            --m[txt[j]];
            if (m[txt[j]] == 0)
                --cnt;
        }

        if (j - i + 1 < k)
            ++j;

        else if (j - i + 1 == k)
        {
            if (cnt == 0)
                ++ind;

            if (m.find(txt[i]) != m.end())
            {
                ++m[txt[i]];
                if (m[txt[i]] == 1)
                    ++cnt;
            }
            ++i, ++j;
        }
    }

    return ind;
}

int count_occurences(string str1, string str2, int n, int m)
{
    int i = 0, j = 0;
    int ind = 0;
    while (j < n)
    {
        if (j - i + 1 < m)
            ++j;
        else if (j - i + 1 == m)
        {
            string str = "";
            for (int k = i; k <= j; ++k)
            {
                str += str1[k];
            }
            sort(str.begin(), str.end());

            // cout << str << endl;

            if (str2 == str)
                ++ind;
            ++i, ++j;
        }
    }
    return ind;
}

int main()
{
    string str1 = "forxxorfxdofr";
    string str2 = "for";

    sort(str2.begin(), str2.end());

    cout << "Count Occurence of Anagrams (TLE) : " << count_occurences(str1, str2, str1.length(), str2.length()) << endl;

    cout << "Count Occurence of Anagrams (MAP) : " << search("aaba", "aabaabaa") << endl;
}