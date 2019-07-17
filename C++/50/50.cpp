#include <iostream>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        double result = 1;
        bool flag = n > 0;
        long int pow = n;
        if (n < 0)
            pow = -pow;
        while (pow > 0)
        {
            if (pow % 2 == 0)
            {
                pow /= 2;
                x *= x;
            }
            else
            {
                pow = --pow / 2;
                result *= x;
                x *= x;
            }
        }
        return flag ? result : 1 / result;
    }
};
int main()
{
    Solution so;
    cout << so.myPow(2, 4) << endl;
    system("pause");
    return 0;
}
