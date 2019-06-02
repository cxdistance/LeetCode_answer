#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
            return true;
        if (x % 10 == 0 || x < 0)
            return false;
        int res = 0, pop = 0;
        while (res < x)
        {
            pop = x % 10;
            res = res * 10 + pop;
            x /= 10;
        }
        return res == x || res / 10 == x;
    }
};
int main()
{
    int x;
    Solution so;
    while (cin >> x)
        cout << so.isPalindrome(x) << endl;
    return 0;
}