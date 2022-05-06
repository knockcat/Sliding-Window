// First negative integer in every window of size k

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<long long> printFirstNegativeIntegerTLE(vector<long long> A, long long int N, long long int K)
{
    vector<long long> v;

    int i = 0, j = 0, flag;

    while (j < N)
    {
        if (j - i + 1 < K)
            ++j;

        else if (j - i + 1 == K)
        {
            flag = 0;
            for (int m = i; m <= j; ++m)
            {
                if (A[m] < 0)
                {
                    flag = 1;
                    v.push_back(A[m]);
                    break;
                }
            }
            if (flag == 0)
                v.push_back(0);

            ++i, ++j;
        }
    }
    return v;
}

vector<long long> printFirstNegativeInteger(vector<long long> A, long long int N, long long int K)
{
    vector<long long> v;
    list<long long> l;
    int i = 0, j = 0;

    while (j < N)
    {
        if (A[j] < 0)
            l.push_back(A[j]);
        if (j - i + 1 < K)
            ++j;

        else if (j - i + 1 == K)
        {
            if (l.empty())
                v.push_back(0);
            else
            {
                v.push_back(l.front());
                if (A[i] == l.front())
                    l.pop_front();
            }
            //   if(A[i] < 0)
            //         l.pop_front();
            ++i, ++j;
        }
    }
    return v;
}

int main()
{
    vector<long long> v = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = v.size();
    int k = 3; // window size

    // accepted gfg
    vector<long long> ans = printFirstNegativeInteger(v, v.size(), k);

    cout << "First negative integer in every window of size k :" << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl
         << endl;

    // tle in few cases
    cout << "First negative integer in every window of size k (TLE):" << endl;

    vector<long long> res = printFirstNegativeIntegerTLE(v, v.size(), k);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
}