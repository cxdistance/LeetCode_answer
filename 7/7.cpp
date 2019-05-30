#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
            return true;
        if ((!x % 10))
            return false;
        int res = 0, pop = 0;
        while (res < x)
        {
            pop = x % 10;
            res = res * 10 + pop;
            x /= 10;
        }
        return x == res || res / 10 == x;
    }
};
int main()
{
    int num;
    cin >> num;
    Solution so;
    cout << so.isPalindrome(num) << endl;
    system("pause");
    return 0;
}