#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
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

// 67. Add Binary

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i--] - '0';
            }

            if (j >= 0)
            {
                sum += b[j--] - '0';
            }

            // ans.insert(0, to_string(sum % 2));
            ans += to_string(sum % 2);
            carry = sum / 2;
        }
        if (carry)
        {
            ans += to_string(1);
            // ans.insert(0, to_string(1));
        }

        return ans;
    }
};

// 287. Find the Duplicate Number

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> uoset;
        for (int ele : nums)
        {
            if (uoset.find(ele) == uoset.end())
            {
                uoset.insert(ele);
            }
            else
            {
                return ele;
            }
        }
        return 0;
    }
};

// 268. Missing Number

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = (ans ^ nums[i]) ^ (i + 1);
        }
        return ans;
    }
};

//190. Reverse Bits

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0, i = 31;
        while (n != 0)
        {
            // ans += ((n & 1) << i);
            ans = ans | ((n & 1) << i);
            n = n >> 1;
            i--;
        }
        return ans;
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
