// Maximum of all Subarray of Size K

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> Max_in_all_Subarray(vector<int> v, int k)
{
    int i = 0, j = 0;
    int n = v.size();

    list<int> l;
    vector<int> ans;

    while (j < n)
    {
        while (l.size() > 0 && l.back() < v[j])
            l.pop_back();

        l.push_back(v[j]);

        if (j - i + 1 < k)
            ++j;

        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());

            if (l.front() == v[i])
                l.pop_back();

            ++i, ++j;
        }
    }

    return ans;
}

int main(void)
{

    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = Max_in_all_Subarray(v, k);

    cout << "Max of all Subarray of Length K : " << endl;

    for (auto i : ans)
        cout << i << " ";
}