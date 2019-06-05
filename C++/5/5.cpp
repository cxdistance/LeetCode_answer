//Manacher Algorithm
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		string str = PreProcess(s);
		int id = 0, mx = 0;
		int len = str.size() - 1;
		vector<int> p(len, 1);
		for (int i = 1; i < len; i++)		// we use s.size()-1 and start from 1,because there is a '^' as the border,if we use char[] , '^' was instead by '\0' 
		{
			if (i < mx)
				p[i] = min(p[2 * id - i], mx - i);
			while (str[i + p[i]] == str[i - p[i]])		// due to '$' or '^' , we don't have to pay attention to the border
				p[i]++;
			if (i + p[i] > mx)
			{
				id = i;
				mx = i + p[i];
			}
		}
		// warning!! value of id may not the maxid
		// image that if i == mx ,so p[i] = 1. Then id was update to i , and the value of mx = mx + 1;
		// if we just want to know the maxlen , just add one more sentence in the previous loop: maxlen = max ( maxlen , p[i]-1 );
		// now we need to find the maxid and maxlen
		int maxid = 0, maxlen = p[0];
		for (int i = 1; i < len; i++)
		{
			if (p[i] > maxlen)
			{
				maxid = i;
				maxlen = p[i];
			}
		}
		return s.substr((maxid - maxlen) / 2, maxlen - 1);		// This is a magical law
	}
	string PreProcess(string& s)
	{
		string res;
		res.push_back('$');
		res.push_back('#');
		for (int i = 0; i < s.size(); i++)
		{
			res.push_back(s[i]);
			res.push_back('#');
		}
		res.push_back('^');
		return res;
	}
};
int main()
{
	string s;
	while (cin >> s)
	{
		Solution so;
		cout << so.longestPalindrome(s) << endl;
	}
	return 0;
}