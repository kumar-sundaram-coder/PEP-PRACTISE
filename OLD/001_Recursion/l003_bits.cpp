// When we apply bitwise & between n and (n-1) then the rightmost set bit (1) gets inverted (i.e. "0") and all the zeroes right to it also get inverted (i.e. "1") .
// For Example :
// n    =   8 -> 1000
// n-1  =   7-> 0111
// so, ( 8 & 7) = 0000.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Kth_OFF_To_On(int num, int k)
{
    int mask = (1 << k);
    return (num | mask);
}

int Kth_ON_To_OFF(int num, int k)
{
    int mask = (~(1 << k));
    return (num & mask);
}

int noOfSetBits(int num)
{
    int setBits = 0;

    for (int i = 0; num != 0 && i < 32; i++) //Total Bits are 32
    {
        if ((num & 1) != 0)
        {
            setBits++;
        }
        num = num >> 1;
    }

    return setBits;
}

//Leetcode 338: Counting Bits

//Method 1

class Solution
{
public:
    int count(int num)
    {
        int setBits = 0;
        for (int i = 0; num != 0 && i < 32; i++)
        {
            if ((num & 1) != 0)
            {
                setBits++;
            }
            num = num >> 1;
        }
        return setBits;
    }

    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i < n + 1; i++)
        {
            ans.push_back(count(i));
        }
        return ans;
    }
};

//Method 2
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i < n + 1; i++)
        {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};

// When we apply bitwise & between n and (n-1) then the rightmost set bit (1) gets inverted (i.e. "0") and all the zeroes right to it also get inverted (i.e. "1") .
// For Example :
// n    =   8 -> 1000
// n-1  =   7-> 0111
// so, ( 8 & 7) = 0000
// Now, coming to this particular problem, we know every power of two has the MSB as 1 and rest all as 0 e.g. 2,4,8...... so when we apply n & (n-1) operation if we get output as 0 it means n is a power of 2.

//Leetcode 231. Power of Two

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        if ((n & (n - 1)) == 0)
            return true;

        return false;
    }
};

// When we apply bitwise & between n and (n-1) then the rightmost set bit (1) gets inverted (i.e. "0") and all the zeroes right to it also get inverted (i.e. "1") .
// For Example :
// n    =   8 -> 1000
// n-1  =   7-> 0111
// so, ( 8 & 7) = 0000

// Now, coming to this particular problem, we know every power of two has the MSB as 1 and rest all as 0 e.g. 2,4,8...... so when we apply n & (n-1) operation if we get output as 0 it means n is a powerr of 2.

// if is it a power of 2
// then we check.... if ((n - 1) % 3 == 0)
// to check if (number -1) is a multiple of 3.....bcz it will prove that (number) is a power of 4

//  (4^n - 1) % 3 == 0
// another proof:
// (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
// (2) among any 3 consecutive numbers, there must be one that is a multiple of 3
// among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one, therefore either (2^n-1) or (2^n+1) must be a multiple of 3, and 4^n-1 must be a multiple of 3 as well.

//Leetcode 342. Power of Four

//Method 1
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
        {                         //is it a power of 2
            if ((n - 1) % 3 == 0) // to check if (number -1) is a multiple of 3.....bcz it will prove that (number) is a power of 4
                return true;
        }
        return false;
    }
};

//Method 2
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;

        while (n != 1)
        {
            if (n % 4 != 0)
                return false;

            n = n / 4;
        }
        return true;
    }
};
// Method 3

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
        { //is it a power of 2
            int trailingZeros = __builtin_ctz(n);
            if (trailingZeros % 2 == 0)
            {
                return true;
            }
        }
        return false;
    }
};

// Method 4

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
        { //is it a power of 2

            int trailingZeros = 0;

            //   int trailingZeros = __builtin_ctz(n);

            while (n > 1)
            {
                trailingZeros++;
                n = n >> 1;
            }

            if (trailingZeros % 2 == 0)
            {
                return true;
            }
        }
        return false;
    }
};

// Method 5

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
        { //is it a power of 2

            int trailingZeros = 0;

            while (n > 1)
            {
                trailingZeros++;
                n = n >> 1;
            }

            if ((trailingZeros & 1) == 0)
            {
                // The idea is to check whether the last bit of the number is set or not. If last bit is set then the number is odd, otherwise even.
                // As we know bitwise AND Operation of the Number by 1 will be 1, If it is odd because the last bit will be already set. Otherwise it will give 0 as output.
                return true;
            }
        }
        return false;
    }
};

// Leetcoode 136. Single Number

// Method 1
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int ele : nums)
        {
            ans = ans ^ ele;
        }
        cout << ans;
        return ans;
    }
};

//Method 2

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            int mask = 1 << i;

            for (int ele : nums)
            {
                if ((ele & mask) != 0)
                {
                    count++;
                }
            }
            if ((count % 2) != 0)
            {
                ans = ans | mask;
            }
        }
        return ans;
    }
};

// Leetcoode 137. Single Number II

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {

            int count = 0;
            int mask = 1 << i;

            for (int ele : nums)
            {
                if ((ele & mask) != 0)
                {
                    count++;
                }
            }
            if (count % 3 != 0)
            {
                ans = (ans | mask);
            }
        }

        return ans;
    }
};

// Leetcoode 260. Single Number III

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        if (nums.size() < 2)
        {
            vector<int> temp;
            return temp;
        }

        if (nums.size() == 2)
        {
            return nums;
        }

        int xorNum = 0;

        for (int ele : nums)
        {
            xorNum = xorNum ^ ele;
        }

        if (xorNum == INT_MAX || xorNum == INT_MIN)
        {
            return {0, xorNum};
        }

        int LSB = (xorNum & (-xorNum)); // Bitwise AND of x and -x give a binary number with only 1 set Bit i.e., LSB

        int a = 0;
        int b = 0;

        for (int ele : nums)
        {
            if ((ele & LSB) != 0)
            { //making a grp of all those ele with SET bit(1) at the position where the bit is set in LSB
                a = a ^ ele;
            }

            else
            {
                //making a grp of all those ele with  UNSET bit(0)  at the position where the bit is set in LSB
                b = b ^ ele;
            }
        }

        vector<int> ans{a, b};
        return ans;
    }
};

void solve()
{

    // cout << Kth_OFF_To_On(0, 4);
    // cout << Kth_ON_To_OFF(18,1);
    cout << noOfSetBits(15);
}

int main()
{
    solve();
    return 0;
}
