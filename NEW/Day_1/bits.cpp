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

        while (num > 1)
        {
            trailingZeroes++;
            num = num >> 1;
        }

        // trailingZeroes = __builtin_ctz(num);
        // if (trailingZeroes % 2 == 0)
        if ((trailingZeroes & 1) == 0)
            return true;
    }
    return false;
}

// 136. Single Number

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // for(int ele:nums){
        //     ans=ans^ele;
        // }
        // return ans;

        for (int i = 0; i < 32; i++)
        {
            int mask = 1 << i;
            int count = 0;
            for (int ele : nums)
            {
                if ((ele & mask) != 0)
                {
                    count++;
                }
            }
            if (count % 2 != 0)
            {
                ans = ans | mask;
            }
        }
        return ans;
    }
};

//137. Single Number II

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int mask = 1 << i;
            int count = 0;
            for (int ele : nums)
            {
                if ((ele & mask) != 0)
                {
                    count++;
                }
            }
            if (count % 3 != 0)
            {
                ans = ans | mask;
            }
        }

        return ans;
    }
};

//260. Single Number III

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        if (nums.size() == 2)
            return nums;

        int xorNum = 0;
        for (int ele : nums)
        {
            xorNum = xorNum ^ ele;
        }

        if (xorNum == INT_MIN || xorNum == INT_MAX)
        {
            return {0, xorNum};
        }

        int LSB = (xorNum & (-xorNum)); //it gives the first (or rightmost) set bit
        // Bitwise AND of x and -x give a binary number with only 1 set Bit i.e., LSB

        int a = 0;
        int b = 0;

        for (int ele : nums)
        {
            //making two seperate groups, one with the set  bit and the other with unset bit at that position(LSB)
            if ((ele & LSB) != 0)
            {
                a = a ^ ele;
            }
            else
            {
                b = b ^ ele;
            }
        }
        return {a, b};
    }
};

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
}

int main()
{
    solve();
    return 0;
}