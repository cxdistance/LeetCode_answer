#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
        int mp[256]; 
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        /*Also, map is appropriate*/
        /*map<char, int> mp;  
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;*/
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && mp[s[i]]<mp[s[i+1]])
                sum-=mp[s[i]];
            else
                sum+=mp[s[i]];
        }
        return sum;
    }
};

int main()
{
    Solution so;
    string str;
    while (cin >> str)
        cout << so.romanToInt(str) << endl;
    return 0;
}