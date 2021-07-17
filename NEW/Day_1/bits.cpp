#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int noOfSetBits_01(int num)
{
    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        int mask = 1 << i;
        if ((num & mask) != 0)
        {
            count++;
        }
    }
    return count;
}

int noOfSetBits_02(int num)
{
    int count = 0;

    for (int i = 0; num != 0 && i < 32; i++)
    {
        if ((num & 1) != 0)
        {
            count++;
        }
        num = num >> 1;
    }

    return count;
}

int noOfSetBits_03(int num)
{
    return __builtin_popcount(num);
}

bool powerOfTwo(int num)
{
    return ((num > 0) && ((num & (num - 1)) == 0));
}
bool powerOfFour_01(int num)
{
    return ((num > 0) && ((num & (num - 1)) == 0) && ((num - 1) % 3 == 0));
}

bool powerOfFour_02(int num)
{
    if (num <= 0)
        return false;
    while (num != 1)
    {

        if (num % 4 != 0)
        {
            return false;
        }
        num = num / 4;
    }
    return true;
}
bool powerOfFour_03(int num)
{
    if (num <= 0)
    {
        return false;
    }
    if ((num & (num - 1)) == 0)
    {
        int trailingZeroes = 0;
        // trailingZeroes = __builtin_ctz(num);

        while (num > 1)
        {
            trailingZeroes++;
            num = num >> 1;
        }

        // if (trailingZeroes % 2 == 0)
        if ((trailingZeroes & 1) == 0)
            return true;
    }
    return false;
}

void solve()
{
    int num = 6;
    int num2 = 64;
    cout << noOfSetBits_01(num) << endl;
    cout << noOfSetBits_02(num) << endl;
    cout << noOfSetBits_03(num) << endl;

    cout << boolalpha << powerOfTwo(num) << endl;
    cout << boolalpha << powerOfFour_01(num2) << endl;
    cout << boolalpha << powerOfFour_02(num2) << endl;
    cout << boolalpha << powerOfFour_03(num2) << endl;
    // cout << boolalpha << powerOfFour_04(num2) << endl;
}

int main()
{
    solve();
    return 0;
}