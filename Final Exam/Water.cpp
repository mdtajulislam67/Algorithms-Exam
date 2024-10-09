#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> height(n);

        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }

        int t_index = 0;
        int sec_t_index = -1;

        for (int i = 1; i < n; i++)
        {
            if (height[i] > height[t_index])
            {
                sec_t_index = t_index;
                t_index = i;
            }
            else if (height[i] > height[sec_t_index] || sec_t_index == -1)
            {
                sec_t_index = i;
            }
        }

        if (sec_t_index < t_index)
        {
            swap(t_index, sec_t_index);
        }

        cout << t_index << " " << sec_t_index << endl;
    }
    return 0;
}