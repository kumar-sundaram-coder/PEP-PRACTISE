// https://leetcode.com/problems/sort-characters-by-frequency/
// 451. Sort Characters By Frequency
class Solution
{
public:
    string frequencySort(string str)
    {
        unordered_map<char, int> mp;
        for (char c : str)
            mp[c]++;
        priority_queue<pair<int, char>> pq; //max heap...stores element in decreasing order of count
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (pq.size() > 0)
        {
            pair<int, char> temp = pq.top();
            pq.pop();
            ans.append(temp.first, temp.second);
            //ans.append(10, 'a'); this Appends 10 occurrences of 'a' to ans
        }
        return ans;
    }
};

//https://leetcode.com/problems/top-k-frequent-elements/
//347. Top K Frequent Elements
class Solution
{
public:
    struct myComp
    {
        bool operator()(pair<int, int> &p1, pair<int, int> &p2)
        {
            return p1.first > p2.first; //min heap
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int ele : nums)
            mp[ele]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (pq.size() > 0)
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};

//https://leetcode.com/problems/top-k-frequent-words/
// 692. Top K Frequent Words

class Solution
{
public:
    struct myComp
    {
        // in pq comparator functions works in totally opposite way as compared to vector, if we need to sort pq in decreasing order then we use "this < other", while in vector we would use "this > other"

        bool operator()(const pair<int, string> &p1, const pair<int, string> &p2)
        {
            if (p1.first == p2.first)
                return p1.second > p2.second; //check if str1 comes before str2 in lexicographical order, cz it's pq therefore sign is opposite i.e., > is used instead of using <
            return p1.first < p2.first;       // check if count/frequency of 1st is more than 2nd,cz it's pq therefore sign is opposite i.e., < is used instead of using >
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (string str : words)
            mp[str]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        vector<string> ans;
        while (pq.size() > 0 and k > 0)
        {
            pair<int, string> temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
            k--;
        }
        return ans;
    }
};

//https://leetcode.com/problems/kth-largest-element-in-an-array/
//215. Kth Largest Element in an Array

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int ele : nums)
        {
            pq.push(ele);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

//https://leetcode.com/problems/k-closest-points-to-origin/
//973. K Closest Points to Origin

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        int i = 0;
        for (auto &v : points)
        {
            pq.push({v[0] * v[0] + v[1] * v[1], i});
            if (pq.size() > k)
            {
                pq.pop();
            }
            i++;
        }
        while (pq.size() > 0)
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            ans.push_back(points[temp.second]);
        }
        return ans;
    }
};
