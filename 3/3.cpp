#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> mp;
		int maximum = 0, pre = 0;
		for (int i = 0; i < s.size(); i++)
		{
			pre = max(pre, mp[s[i]]);
			maximum = max(maximum, i + 1 - pre);
			mp[s[i]] = i + 1;
		}
		return maximum;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution solu;
	cout << solu.lengthOfLongestSubstring(s) << endl;
}