#include<iostream>
#include<vector>
#include<algorithm>
#define MIN -10000000
#define MAX 10000000
using namespace std;
class Solution {
public:
	double findmedian(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() > nums2.size())
			return findmedian(nums2, nums1);
		int cut1 = 0, cut2 = 0;
		int right = nums1.size(), left = 0;
		int sum = nums1.size() + nums2.size();
		double L1, L2, R1, R2;
		while (left <= right)
		{
			cut1 = (right - left) / 2 + left;
			cut2 = sum / 2 - cut1;
			L1 = (cut1 == 0) ? MIN : nums1[cut1 - 1];
			L2 = (cut2 == 0) ? MIN : nums2[cut2 - 1];
			R1 = (cut1 == nums1.size()) ? MAX : nums1[cut1];
			R2 = (cut2 == nums2.size()) ? MAX : nums2[cut2];
			if (L1 > R2)
				right = cut1 - 1;
			else if (L2 > R1)
				left = cut1 + 1;
			else
			{
				if (sum & 1)
					return min(R1, R2);
				else
					return (max(L1, +L2) + min(R1, R2)) / 2;
			}
		}
	}
};
int main()
{
	vector<int>nums1 = { 1,2 }, nums2 = { 2,3,4,5 };
	Solution solu;
	cout << solu.findmedian(nums1, nums2);
	return 0;
}