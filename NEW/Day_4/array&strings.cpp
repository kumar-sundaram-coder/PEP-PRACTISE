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

//https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//Print a given matrix in spiral form
// C++ Program to print a matrix spirally

#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 6

void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;

    /* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
		i - iterator
	*/

    while (k < m && l < n)
    {
        /* Print the first row from
			the remaining rows */
        for (i = l; i < n; ++i)
        {
            cout << a[k][i] << " ";
        }
        k++;

        /* Print the last column
		from the remaining columns */
        for (i = k; i < m; ++i)
        {
            cout << a[i][n - 1] << " ";
        }
        n--;

        /* Print the last row from
				the remaining rows */
        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
            {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }

        /* Print the first column from
				the remaining columns */
        if (l < n)
        {
            for (i = m - 1; i >= k; --i)
            {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}

/* Driver Code */
int main()
{
    int a[R][C] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    // Function Call
    spiralPrint(R, C, a);
    return 0;
}

// This is code is contributed by rathbhupendra

//https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
//Convert array into Zig-Zag fashion
// C++ program to sort an array in Zig-Zag form
#include <iostream>
using namespace std;

// Program for zig-zag conversion of array
void zigZag(int arr[], int n)
{
    // Flag true indicates relation "<" is expected,
    // else ">" is expected. The first expected relation
    // is "<"
    bool flag = true;

    for (int i = 0; i <= n - 2; i++)
    {
        if (flag) /* "<" relation expected */
        {
            /* If we have a situation like A > B > C,
			we get A > B < C by swapping B and C */
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        else /* ">" relation expected */
        {
            /* If we have a situation like A < B < C,
			we get A < C > B by swapping B and C */
            if (arr[i] < arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        flag = !flag; /* flip flag */
    }
}

// Driver program
int main()
{
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    zigZag(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
