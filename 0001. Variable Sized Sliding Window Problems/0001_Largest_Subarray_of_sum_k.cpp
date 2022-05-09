// Largert Subarray of Sum k

#include <iostream>
#include <vector>
using namespace std;

int Longest_subarray_sum_k(vector<int> v, int k)
{
    int i = 0, j = 0;
    int n = v.size();

    long long sum = 0;
    int mx = INT_MIN;

    while (j < n)
    {
        sum += v[j];

        if (sum == k)
        {
            mx = max(mx, j - i + 1); // Longest Subarray
        }
        else if (sum > k)
        {
            while (sum > k)
                sum -= v[i++];
        }
        ++j;
    }

    return mx;
}

int main()
{
    vector<int> v = {4, 1, 1, 1, 2, 3, 5};
    // {4, 1} {2, 3} {5} {1, 1, 1, 2}

    int k = 5; // largest of all subarray with sum 5

    cout << "Longest Subarray with Sum k : " << Longest_subarray_sum_k(v, k) << endl;

    return 0;
}