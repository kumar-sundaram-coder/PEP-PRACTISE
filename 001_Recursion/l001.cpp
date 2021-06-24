#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for using max(a,b)
#include <climits>   // for using INT_MIN

using namespace std;

// Set 1

void printIncreasing(int a, int b)
{
    if (a == b + 1)
        return;
    cout << a << " ";
    printIncreasing(a + 1, b);
}
void printDecreasing_1(int a, int b)
{
    if (b == a - 1)
        return;
    cout << b << " ";
    printDecreasing_1(a, b - 1);
}

void printDecreasing_2(int a, int b)
{
    if (a == b + 1)
        return;

    printDecreasing_2(a + 1, b);
    cout << a << " ";
}

void printIncrDecr(int a, int b)
{
    if (a == b + 1)
        return;
    cout << a << " ";
    printIncrDecr(a + 1, b);
    cout << a << " ";
}

void printEvenOdd(int a, int b)
{
    if (a == b + 1)
        return;

    if (a % 2 == 0)
        cout << a << " ";

    printEvenOdd(a + 1, b);

    if (a % 2 != 0)
        cout << a << " ";
}

void set1()
{
    int a, b;
    cin >> a >> b;
    printIncreasing(a, b);
    cout << endl;
    printDecreasing_1(a, b);
    cout << endl;
    printDecreasing_2(a, b);
    cout << endl;
    printIncrDecr(a, b);
    cout << endl;
    printEvenOdd(a, b);
}

// Set 2

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * power(a, b - 1);
}

int powerBtr(int a, int b)
{
    if (b == 0)
        return 1;
    int Ans = powerBtr(a, b / 2);
    Ans = Ans * Ans;
    return b % 2 == 0 ? Ans : (a * Ans);
}

void set2()
{
    // int n;
    // cin>>n;
    // cout<<fact(n);

    // int a,b;
    // cin>>a>>b;
    // cout<<power(a,b);
    // cout<<endl;
    // cout<<powerBtr(a,b);
}

// Set 3

void printArray(vector<int> arr, int idx)
{
    if (idx == arr.size())
    {
        return;
    }
    cout << arr[idx] << " ";
    printArray(arr, idx + 1);
}

void findInArray_voidtype(vector<int> arr, int idx, int ele)
{
    if (idx == arr.size())
    {
        cout << ele << " Not Found";
        return;
    }
    if (arr[idx] == ele)
    {
        cout << ele << " Found @Index " << idx;
        return;
    }
    findInArray_voidtype(arr, idx + 1, ele);
}

bool findInArray_return_pre(vector<int> arr, int idx, int ele)
{
    if (idx == arr.size())
        return false;

    if (arr[idx] == ele)
        return true;

    return findInArray_return_pre(arr, idx + 1, ele);
}

bool findInArray_return_post(vector<int> arr, int idx, int ele)
{
    if (idx == arr.size())
        return false;

    bool ans = findInArray_return_post(arr, idx + 1, ele);
    if (ans)
        return true;
    else
        return arr[idx] == ele;
}

int maxelement_01(vector<int> arr, int idx)
{
    if (idx == arr.size() - 1)
        return arr[idx];

    int maxEle = maxelement_01(arr, idx + 1);

    return max(maxEle, arr[idx]);
}

int max_ = INT_MIN;
void maxelement_02(vector<int> arr, int idx)
{
    if (idx == arr.size() - 1)
    {
        return;
    }

    max_ = max(max_, arr[idx]);
    maxelement_02(arr, idx + 1);
}

int minelement_01(vector<int> arr, int idx)
{
    if (idx == arr.size() - 1)
        return arr[idx];

    int minEle = minelement_01(arr, idx + 1);
    return min(minEle, arr[idx]);
}

int min_ = INT_MAX;
void minelement_02(vector<int> arr, int idx)
{
    if (idx == arr.size() - 1)
        return;
    min_ = min(min_, arr[idx]);
    minelement_02(arr, idx + 1);
}

void set3()
{
    vector<int> arr(5, 0);
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    // vector <int> arr {1,2,3,4,5};

    // printArray(arr,0);
    // findInArray_voidtype(arr,0,4);
    // cout<<boolalpha<<findInArray_return_pre(arr,0,4);
    //boolalpha prints true instead of 1 and false instead of 0
    // cout<<boolalpha<<findInArray_return_post(arr,0,4);

    // cout << maxelement_01(arr, 0);
    // cout << endl;
    // maxelement_02(arr, 0); //storing max in Global Variable
    // cout << max_;

    cout << minelement_01(arr, 0);
    cout << endl;
    minelement_02(arr, 0); //storing max in Global Variable
    cout << min_;
}

// Set 4

vector<string> subseq_ret(string str)
{
    if (str.size() == 0)
    {
        vector<string> base{" "};
        return base;
    }

    char ch = str[0];
    string nstr = str.substr(1);

    vector<string> prevAns = subseq_ret(nstr);

    // Case 1: character is not added in the front of prev string
    vector<string> ans(prevAns);

    for (string s : prevAns)
    {
        // Case 2: character is added in the front of prev string
        ans.push_back(ch + s);
    }
    return ans;
}

int subseq_void(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    count += subseq_void(str.substr(1), ans);
    count += subseq_void(str.substr(1), ans + str[0]);

    return count;
}

vector<string> permuation_withDupli_01(string str)
{
    if (str.length() == 1)
    {
        vector<string> base;
        base.push_back(str);
        return base;
    }

    char ch = str[0];
    vector<string> prevAns = permuation_withDupli_01(str.substr(1));
    vector<string> Ans;

    for (string s : prevAns)
    {
        for (int i = 0; i <= s.length(); i++)
        {
            Ans.push_back(s.substr(0, i) + ch + s.substr(i));
        }
    }
    return Ans;
}

int permuation_withDupli_02(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string nstr = str.substr(0, i) + str.substr(i + 1);
        count += permuation_withDupli_02(nstr, ans + ch);
    }
    return count;
}

int permuation_withoutDuplicates(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    vector<bool> visited(26, false);
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (visited[ch - 'a'] == false)
        {
            visited[ch - 'a'] = true;
            string nstr = str.substr(0, i) + str.substr(i + 1);
            count += permuation_withoutDuplicates(nstr, ans + ch);
        }
        else if (visited[ch - 'a'] == true)
        {
            continue;
        }
    }
    return count;
}

void set4()
{

    // vector<string> subSequence = subseq_ret("abcd");
    // for (string s : subSequence)
    // {
    //     cout << s << endl;
    // }

    // cout << subseq_void("abcd", "");

    // vector<string> ans = permuation_withDupli_01("abc");
    //return type
    // for (string s : ans)
    // {
    //     cout << s << endl;
    // }

    cout << permuation_withDupli_02("aba", "");
    cout << endl;
    cout << permuation_withoutDuplicates("aba", "");
}

// Set 5 -- Nokia Keypad

vector<string> words = {
    ":;/",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
    "&*%",
    "#@$",
};

vector<string> nokiaKeyPad_01(string str)
{
    if (str.length() == 0)
    {
        vector<string> base{" "};
        return base;
    }

    int idx = str[0] - '0';
    string word = words[idx];

    vector<string> prevAns = nokiaKeyPad_01(str.substr(1));
    vector<string> Ans;

    for (string s : prevAns)
    {
        for (int i = 0; i < word.length(); i++)
        {
            Ans.push_back(word[i] + s);
        }
    }
    if (str.length() > 1)
    {
        int idx1 = str[1] - '0';
        int num = idx * 10 + idx1;
        if (num == 10 || num == 11)
        {
            word = words[num];
            prevAns = nokiaKeyPad_01(str.substr(2));

            for (string s : prevAns)
            {
                for (int i = 0; i < word.length(); i++)
                {
                    Ans.push_back(word[i] + s);
                }
            }
        }
    }

    return Ans;
}

int nokiaKeyPad_02(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    int idx = str[0] - '0';
    string word = words[idx];

    for (int i = 0; i < word.length(); i++)
    {
        count += nokiaKeyPad_02(str.substr(1), ans + word[i]);
    }

    if (str.length() > 1)
    {
        int idx1 = str[1] - '0';
        int num = idx * 10 + idx1;
        if (num == 10 || num == 11)
        {
            word = words[num];
            for (int i = 0; i < word.length(); i++)
            {
                count += nokiaKeyPad_02(str.substr(2), ans + word[i]);
            }
        }
    }

    return count;
}

void set5()
{
    // vector<string> ans = nokiaKeyPad_01("567");
    // vector<string> ans = nokiaKeyPad_01("10101");

    // for (string s : ans)
    // {
    //     cout << s << "\n";
    // }

    // vector<string> ans = nokiaKeyPad_01("567");
    // cout << nokiaKeyPad_02("567", "");
    cout << nokiaKeyPad_02("10101", "");
}

void solve()
{
    // set1();
    // set2();
    // set3();
    // set4();
    set5();
}

int main()
{
    // string str;
    // getline(cin,str);
    // cout<< str;

    solve();
    return 1;
}
