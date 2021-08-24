// https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/
// Queue based approach for first non-repeating character in a stream

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";
        for (char ch : A)
        {
            q.push(ch);
            freq[ch - 'a']++;
            while (q.size() > 0)
            {
                char ele = q.front();
                if (freq[ele - 'a'] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(ele);
                    break;
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};

// ------------------------ This question is not related to QUEUE ------------
//https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1#
//Non Repeating Character

// Method 1: HashMap and Two-string method traversals.
class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string str)
    {
        //Your code here
        unordered_map<char, int> ump;
        for (char c : str)
        {
            ump[c]++;
        }
        for (char c : str)
        {
            if (ump.find(c) != ump.end())
            {
                if (ump[c] == 1)
                    return c;
                continue;
            }
        }
        return '$';
    }
};

// Method 2: HashMap and single string traversal.

class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string str)
    {
        //Your code here
        vector<pair<int, int>> vec(256, {0, -1});
        int i = 0;
        for (char &c : str)
        {
            vec[c].first++;    //number of times character appears in the string
            vec[c].second = i; // location where we encountered it first(only characters with 1 occurance will be considered later so no need to worry)
            i++;
        }
        int ans = INT_MAX;
        for (auto &ele : vec)
        {
            if (ele.first == 1)
            {
                ans = ans < ele.second ? ans : ele.second;
            }
        }
        return ans == INT_MAX ? '$' : str[ans];
    }
};

// Method #3: Count array and single string traversal:

class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string str)
    {
        vector<int> vec(26, -1);
        int i = 0;
        for (char c : str)
        {
            if (vec[c - 'a'] == -1)
                vec[c - 'a'] = i;
            else if (vec[c - 'a'] != -1)
                vec[c - 'a'] = -2;

            i++;
        }
        int ans = INT_MAX;
        for (int ele : vec)
        {
            if (ele >= 0)
            {
                ans = min(ans, ele);
            }
        }
        return ans == INT_MAX ? '$' : str[ans];
    }
};