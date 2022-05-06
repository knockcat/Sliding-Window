// Max Sum Subarray of size K

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {43, 21, 54, 76, 32, 8, 2, 877, 302};
    int k = 4; // window size;

    int n = v.size();

    int i = 0, j = 0, sum = 0, mx = INT_MIN;

    while (j < n)
    {
        sum += v[j];

        if (j - i + 1 < k)
            ++j;

        else if (j - i + 1 == k)
        {
            mx = max(mx, sum);
            sum -= v[i];
            ++i, ++j;
        }
    }

    cout << "MAXIMUM SUBARRAY OF SIZE k IS : " << mx << endl;
}