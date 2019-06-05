#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        int i=0;
        while(num>0)
        {
            if(num>=value[i])
            {
                res+=str[i];
                num-=value[i];
            }
            else
                i++;
        }
        return res;
    }
};
int main()
{
    Solution so;
    int x;
    while (cin >> x)
        cout << so.intToRoman(x) << endl;
    system("pause");
    return 0;
}