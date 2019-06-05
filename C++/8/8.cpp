#include <iostream>
#include <limits.h>
#include <string>
using namespace std;
class Solution
{
public:
    int flag;
    int myAtoi(string str)
    {
        string res = preProcess(str);
        if (res.empty())
            return 0;
        int pop = 0, num = 0;
        for (int i = 0; i < res.size(); i++)
        {
            pop = flag ? (res[i] - 48) : (48 - res[i]);
            if (flag && (num > INT_MAX / 10 || (num == INT_MAX / 10 && pop > 7)))
                return INT_MAX;
            if (!flag && (num < INT_MIN / 10 || (num == INT_MIN / 10 && pop < -8)))
                return INT_MIN;
            num = num * 10 + pop;
        }
        /*It can be faster if you write two loops*/
        /*if (flag)
        {
            for (int i = 0; i < res.size(); i++)
            {
                pop = res[i] - 48;
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && pop > 7))
                    return INT_MAX;
                num = num * 10 + pop;
            }
        }
        else
        {
            for (int i = 0; i < res.size(); i++)
            {
                pop = 48 - res[i];
                if (num < INT_MIN / 10 || (num == INT_MIN / 10 && pop < -8))
                    return INT_MIN;
                num = num * 10 + pop;
            }
        }*/
        return num;
    }
    string preProcess(string &str)
    {
        int i = 0;
        string res;
        while (i < str.size() && str[i] == ' ')
            i++;
        if (i == str.size())
            return "";
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (str[i] > '9' || str[i] < '0')       // may be like "  +-123"
            return "";
        if (i > 0 && str[i - 1] == '-')     
            flag = false;
        else
            flag = true;
        for (; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                res.push_back(str[i]);
            else
                break;
        }
        return res;
    }
};
int main()
{
    Solution so;
    string str;
    while (cin >> str)
        cout << so.myAtoi(str);
    system("pause");
    return 0;
}