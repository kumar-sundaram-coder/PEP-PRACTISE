#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// mazePath Set

vector<string> mazepath_HV_01(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base{" "};
        return base;
    }
    vector<string> Ans;

    if (sc + 1 <= ec)
    { // we can move horizontally
        vector<string> Hori = mazepath_HV_01(sr, sc + 1, er, ec);
        for (string s : Hori)
        {
            Ans.push_back("H" + s);
        }
    }

    if (sr + 1 <= er)
    {
        //we can move vertically
        vector<string> Verti = mazepath_HV_01(sr + 1, sc, er, ec);
        for (string s : Verti)
        {
            Ans.push_back("V" + s);
        }
    }
    return Ans;
}

vector<string> mazepath_HVD_01(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base{" "};
        return base;
    }

    vector<string> Ans;

    if (sc + 1 <= ec)
    {
        vector<string> Hori = mazepath_HVD_01(sr, sc + 1, er, ec);
        for (string s : Hori)
        {
            Ans.push_back("H" + s);
        }
    }
    if (sc + 1 <= ec && sr + 1 <= er)
    {
        vector<string> Diag = mazepath_HVD_01(sr + 1, sc + 1, er, ec);
        for (string s : Diag)
        {
            Ans.push_back("D" + s);
        }
    }
    if (sr + 1 <= er)
    {
        vector<string> Verti = mazepath_HVD_01(sr + 1, sc, er, ec);
        for (string s : Verti)
        {
            Ans.push_back("V" + s);
        }
    }
    return Ans;
}

vector<string> mazepath_multiHVD_01(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base{" "};
        return base;
    }

    vector<string> Ans;

    for (int jump = 1; sc + jump <= ec; jump++)
    {
        vector<string> Hori = mazepath_multiHVD_01(sr, sc + jump, er, ec);
        for (string s : Hori)
        {
            Ans.push_back("H" + to_string(jump) + s);
        }
    }

    for (int jump = 1; sc + jump <= ec && sr + jump <= er; jump++)
    {
        vector<string> Diag = mazepath_multiHVD_01(sr + jump, sc + jump, er, ec);
        for (string s : Diag)
        {
            Ans.push_back("D" + to_string(jump) + s);
        }
    }

    for (int jump = 1; sr + jump <= er; jump++)
    {
        vector<string> Verti = mazepath_multiHVD_01(sr + jump, sc, er, ec);
        for (string s : Verti)
        {
            Ans.push_back("V" + to_string(jump) + s);
        }
    }
    return Ans;
}

int mazepath_HV_02(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    if (sc + 1 <= ec)
    {
        count += mazepath_HV_02(sr, sc + 1, er, ec, ans + "H");
    }

    if (sr + 1 <= er)
    {
        count += mazepath_HV_02(sr + 1, sc, er, ec, ans + "V");
    }
    return count;
}

int mazepath_HVD_02(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    if (sc + 1 <= ec)
    {
        count += mazepath_HVD_02(sr, sc + 1, er, ec, ans + "H");
    }
    if (sc + 1 <= ec && sr + 1 <= er)
    {
        count += mazepath_HVD_02(sr + 1, sc + 1, er, ec, ans + "D");
    }
    if (sr + 1 <= er)
    {
        count += mazepath_HVD_02(sr + 1, sc, er, ec, ans + "V");
    }
    return count;
}

int mazepath_multiHVD_02(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int jump = 1; sc + jump <= ec; jump++)
    {
        count += mazepath_multiHVD_02(sr, sc + jump, er, ec, ans + "H" + to_string(jump));
    }

    for (int jump = 1; sc + jump <= ec && sr + jump < er; jump++)
    {
        count += mazepath_multiHVD_02(sr + jump, sc + jump, er, ec, ans + "D" + to_string(jump));
    }

    for (int jump = 1; sr + jump <= er; jump++)
    {
        count += mazepath_multiHVD_02(sr + jump, sc, er, ec, ans + "V" + to_string(jump));
    }

    return count;
}

void mazePathSet()
{
    int sr = 0, sc = 0, er = 3, ec = 3;
    vector<string> ans;

    // ans = mazepath_HV_01(sr, sc, er, ec);
    // ans = mazepath_HVD_01(sr, sc, er, ec);

    //If we need to sort the paths in increasing order
    // sort(ans.begin(), ans.end(), [](const string &first, const string &second)
    //      { return first.size() < second.size(); });

    // ans = mazepath_multiHVD_01(sr, sc, er, ec);
    // for (string s : ans)
    // {
    //     cout << s << endl;
    // }

    // cout << mazepath_HV_02(sr, sc, er, ec, "");
    // cout << mazepath_HVD_02(sr, sc, er, ec, "");
    cout << mazepath_multiHVD_02(sr, sc, er, ec, "");
}

//============================''coinChange''==========================

int coinChangePermuINFI_01(vector<int> arr, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinChangePermuINFI_01(arr, tar - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

int coinChangePermutation_01(vector<int> arr, int tar, vector<bool> vis, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (vis[i] == false && tar - arr[i] >= 0)
        {
            vis[i] = true;
            count += coinChangePermutation_01(arr, tar - arr[i], vis, ans + to_string(arr[i]) + " ");
            vis[i] = false;
        }
    }

    return count;
}

int coinChangeCombinationINFI_01(vector<int> arr, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinChangeCombinationINFI_01(arr, i, tar - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

int coinChangeCombination_01(vector<int> arr, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinChangeCombination_01(arr, i + 1, tar - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

int coinChangeCombination_02(vector<int> arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1; // 1 possible Combination Found
        }

        return 0; // No possible Combination Found
    }

    int count = 0;

    if (tar - arr[idx] >= 0)
    {
        count += coinChangeCombination_02(arr, idx + 1, tar - arr[idx], ans + to_string(arr[idx]) + " ");
    }
    count += coinChangeCombination_02(arr, idx + 1, tar, ans);
    return count;
}
int coinChangeCombinationINFI_02(vector<int> arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1; // 1 possible Combination Found
        }

        return 0; // No possible Combination Found
    }

    int count = 0;

    if (tar - arr[idx] >= 0)
    {
        count += coinChangeCombinationINFI_02(arr, idx, tar - arr[idx], ans + to_string(arr[idx]) + " ");
    }
    count += coinChangeCombinationINFI_02(arr, idx + 1, tar, ans);
    return count;
}

int coinChangePermuINFI_02(vector<int> arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1; // 1 possible solution Found
        }

        return 0; // No possible solution Found
    }

    int count = 0;

    if (tar - arr[idx] >= 0)
    {
        count += coinChangePermuINFI_02(arr, 0, tar - arr[idx], ans + to_string(arr[idx]) + " ");
    }
    count += coinChangePermuINFI_02(arr, idx + 1, tar, ans);
    return count;
}

int coinChangePermutation_02(vector<int> arr, int idx, int tar, string ans, vector<bool> vis)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1; // 1 possible solution Found
        }

        return 0; // No possible solution Found
    }

    int count = 0;

    if (tar - arr[idx] >= 0 && vis[idx] == false)
    {
        vis[idx] = true;
        count += coinChangePermutation_02(arr, 0, tar - arr[idx], ans + to_string(arr[idx]) + " ", vis);
        vis[idx] = false;
    }

    count += coinChangePermutation_02(arr, idx + 1, tar, ans, vis);

    return count;
}

void coinChange()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar;
    cin >> tar;
    int ans = 0;
    vector<bool> vis(arr.size(), false);
    // ans = coinChangePermuINFI_01(arr, tar, "");
    // ans = coinChangePermutation_01(arr, tar, vis, "");

    // ans = coinChangeCombinationINFI_01(arr, 0, tar, "");
    // ans = coinChangeCombination_01(arr, 0, tar, "");

    // ans = coinChangeCombination_02(arr, 0, tar, "");
    // ans = coinChangeCombinationINFI_02(arr, 0, tar, "");

    // ans = coinChangePermuINFI_02(arr, 0, tar, "");
    ans = coinChangePermutation_02(arr, 0, tar, "", vis);

    cout << ans;
}

void solve()
{
    // mazePathSet();
    coinChange();
}

int main()
{
    solve();
    return 1;
}