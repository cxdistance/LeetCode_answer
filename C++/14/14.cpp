#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res;
		if (strs.empty())
			return "";
		for (int i = 0; i < strs[0].size(); i++)
		{
			for (int j = 1; j < strs.size(); j++)
			{
				if (i > strs[j].size() || strs[0][i] != strs[j][i])
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};
int main()
{
	Solution so;
	vector<string> p = { "a","a" };
	cout << so.longestCommonPrefix(p);
	return 0;
}