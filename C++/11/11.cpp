#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxarea = 0;
        while (left < right)
        {
            maxarea = max(maxarea, (right - left) * min(height[left], height[right]));
            height[left] < height[right] ? left++ : right--;
        }
        return maxarea;
    }
};
int main()
{
    Solution so;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << so.maxArea(height) << endl;
    system("pause");
    return 0;
}