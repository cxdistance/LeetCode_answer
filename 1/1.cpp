#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int>mp;
		int goal;		//	goal=target-nums[i],and use map to find the index;
		vector<int>res;
		for(int i=0;i<nums.size();i++)
			mp[nums[i]]=i;
		for(int i=0;i<nums.size();i++)
		{
			goal=target-nums[i];
			if(mp.count(goal)!=0)
			{
				res.push_back(i);
				res.push_back(mp[goal]);
			}
		}
		return res;
    }
};
int main()
{
	vector<int>nums={1,3,4,5,6};
	int target = 5;
	Solution so;
	vector<int>res=so.twoSum(nums,target);
	cout<<res[0]<<endl<<res[1]<<endl;
	return 0;
}