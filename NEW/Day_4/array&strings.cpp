// https://leetcode.com/problems/first-missing-positive/
// 41. First Missing Positive
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        nums.push_back(0);
        int n = nums.size();

        for (int &ele : nums)
        {
            if (ele < 0 or ele >= n)
                ele = 0;
        }
        for (int ele : nums)
        {
            if (ele != 0)
                nums[ele % n] = nums[ele % n] + n;
        }
        for (int i = 1; i < n; i++)
        {
            if (nums[i] / n == 0)
                return i;
        }
        return n;
    }
};

//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//448. Find All Numbers Disappeared in an Array
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        nums.push_back(0);
        int n = nums.size();
        for (int ele : nums)
        {
            nums[ele % n] = nums[ele % n] + n;
        }
        for (int i = 1; i < n; i++)
        {
            if (nums[i] / n == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//https://leetcode.com/problems/missing-number/
//268. Missing Number
//method -1 XOR
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xorr = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            xorr ^= i;
        }
        for (int ele : nums)
        {
            xorr ^= ele;
        }
        return xorr;
    }
};

//method-2
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        nums.push_back(0);
        int n = nums.size();
        for (int ele : nums)
        {
            nums[ele % n] = nums[ele % n] + n;
        }
        for (int i = 1; i < n; i++)
        {
            if (nums[i] / n == 0)
            {
                return i;
            }
        }
        return 0;
    }
};

//https://leetcode.com/problems/find-unique-binary-string/
//1980. Find Unique Binary String
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans = "";
        int i = 0, n = nums.size();
        for (string s : nums)
        {
            ans += s[i] == '0' ? '1' : '0';
            // ans.push_back(s[i] == '0' ? '1' : '0');
            // ans = ans.append(1, s[i] == '0' ? '1' : '0');
            i++;
        }
        return ans;
    }
};

//https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
//1779. Find Nearest Point That Has the Same X or Y Coordinate
class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int ans = -1;
        int minn = INT_MAX;
        int i = 0;
        for (vector<int> &v : points)
        {
            if (v[0] == x or v[1] == y)
            {
                int md = abs(v[0] - x) + abs(v[1] - y);
                if (md < minn)
                {
                    minn = md;
                    ans = i;
                }
            }
            i++;
        }
        return ans;
    }
};

//https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
//Find duplicates in O(n) time and O(1) extra space

class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            arr[arr[i] % n] = arr[arr[i] % n] + n;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 2 * n)
            {
                ans.push_back(i);
            }
        }
        return ans.size() == 0 ? ans = {-1} : ans;
    }
};