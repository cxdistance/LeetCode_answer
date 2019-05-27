#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iterator>
#include<limits>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		string s = pre(str);
		if (s.empty())
			return 0;
		int res;
		flag ? res = s[0] - 48 : res = 48 - s[0];
		if (flag)
		{
			for (int i = 1; i < s.size(); i++)
			{
				int pop = s[i] - 48;
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7))
					return INT_MAX;
				else
					res = res * 10 + pop;
			}
		}
		else
		{
			for (int i = 1; i < s.size(); i++)
			{
				int pop = 48 - s[i];
				if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8))
					return INT_MIN;
				else
					res = res * 10 + pop;
			}
		}
		return res;



	}
	string pre(string& s)
	{
		string res;
		int pos = 0;
		flag = false;
		while (pos != s.size() && s[pos] == ' ')
			pos++;
		if (pos == s.size())
			return "";
		if (s[pos] == '+' || s[pos] == '-')
			pos++;
		if (s[pos]<'0' || s[pos]>'9')
			return "";
		if (pos > 0 && s[pos - 1] == '-')
			flag = false;
		else
			flag = true;
		for (int i = pos; i < s.size(); i++)
		{
			res.push_back(s[i]);
			if (i == s.size() - 1 || s[i + 1]<'0' || s[i + 1]>'9')
				break;
		}
		return res;
	}
	bool flag;
};
int main()
{
	int a;
	string s;
	while (getline(cin, s))
	{
		Solution so;
		cout << so.myAtoi(s) << endl;
	}
	return 0;
}

