#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // nums.erase(unique(nums.begin(), nums.end(), nums.end()));
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            int target = 0 - nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] < target)
                    left++;
                else if (nums[left] + nums[right] > target)
                    right--;
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left + 1 < right && nums[left + 1] == nums[left])
                        left++;
                    while (right - 1 > left && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

