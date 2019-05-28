#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
	/*		solution 1: */
   /* vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int>mp;
		int goal;		//	goal=target-nums[i],and use map to find the index;
		for(int i=0;i<nums.size();i++)
			mp[nums[i]]=i;
		for(int i=0;i<nums.size();i++)
		{
			goal=target-nums[i];
			if(mp.count(goal)!=0 && mp[goal]!=i)
				return{i,mp[goal};
		}
		return {};
    }*/
		/* Solution 2: it is faster than Solution 1*/
   		vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        map<int,int>::iterator it=mp.end();
        for(int i=0;i<nums.size();i++)
        {
            it=mp.find(nums[i]);
            if(it!=mp.end())
                return {it->second,i};
            else
                mp.emplace(target-nums[i],i);
        }
        return {};
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
