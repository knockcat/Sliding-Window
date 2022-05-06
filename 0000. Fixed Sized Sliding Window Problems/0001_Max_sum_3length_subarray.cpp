// sliding Window

// maximum sum of subarrary of length 3

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()

{
    vector<int> arr = {2,3,999,4,100,3,43,4,34,545,4,555};
    // vector<int> arr = {0,1,4,2,8};
    // vector<int> arr = {2, 3, 6};
    // vector<int> arr = {2,3};
    int mx = INT_MIN;

    if (arr.size() < 3)
    {
        cout << "Array length is less than 3" << endl;
        return 0;
    }
    else
    {
        int ans = arr[0] + arr[1] + arr[2];
        mx = ans;
        for (int i = 3; i < arr.size(); ++i)
        {
            // one element is subtracted & one is added to the Window to avoid repetition
            ans -= arr[i - 3];
            ans += arr[i];
            if (ans > mx)
                mx = max(mx, ans);
        }

        cout << "Maximum Sum of subarrary of  3 lenght is : " << mx << endl;
    }
    return 0;
}