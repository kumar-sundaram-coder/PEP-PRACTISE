#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> //For accumulate operation
#include <sstream> //For stringstream
#include <string>
#include <unordered_map>

using namespace std;

//=================== STL ==================

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
}

struct Interval
{
    int start, end;
};

bool compareInterval(Interval I1, Interval I2)
{
    if (I1.start != I2.start)
        return (I1.start < I2.start);
    return (I1.end < I2.end);
}

void set1()
{
    // int arr[] = {1, 3, 2, 1, 4, 4, 1, 3, 5, 6, 7, 5, 3, 2, 1};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // show(arr, n);

    // //sort in ascending order
    // sort(arr, arr + n);
    // cout << endl;
    // show(arr, n);
    // cout << endl;

    // //binary_search
    // bool res = false;
    // res = binary_search(arr, arr + n, 5);
    // cout << ((res == true) ? "Found" : "Not Found");
    // cout << endl;

    // //sort in descending order
    // sort(arr, arr + n, greater<int>());
    // show(arr, n);
    // cout << endl;

    // //reverse
    // reverse(arr, arr + n);
    // show(arr, n);
    // cout << endl;

    // //max element
    // cout << *max_element(arr, arr + n);
    // cout << endl;

    // //min element
    // cout << *min_element(arr, arr + n);
    // cout << endl;

    // //The summation of array's elements, taking 0 as initial value of sum

    // cout << accumulate(arr, arr + n, 0);
    // cout << endl;

    // //count , to count the occurrences of a element (say X) in the array
    // cout << count(arr, arr + n, 1);
    // cout << endl;

    // // find, Returns an iterator to the first occurence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.

    // vector<int> v(arr, arr + n); //initializing a vector with the help of an array
    // cout << (find(v.begin(), v.end(), 77) != v.end() ? "Found" : "Not Found");
    // cout << endl;

    // // sort in a particular order
    // //by creating our own comparator function and passing it as a third parameter

    // Interval Arr[] = {{1, 2}, {9, 0}, {-1, 2}, {1, 1}, {6, 2}};
    // int N = sizeof(Arr) / sizeof(Arr[0]);

    // sort(Arr, Arr + N, compareInterval);

    // for (int i = 0; i < N; i++)
    // {
    //     cout << "[ " << Arr[i].start << ", " << Arr[i].end << " ] ";
    // }

    //partition

    vector<int> vec = {2, 1, 5, 6, 8, 7};

    // partition(vec.begin(), vec.end(), [](int x)
    //           { return x % 2 == 0; });

    // for (int x : vec)
    // {
    //     cout << x << " ,";
    // }
    cout << endl;

    stable_partition(vec.begin(), vec.end(), [](int x)
                     { return x % 2 == 0; });
    for (int x : vec)
    {
        cout << x << " ,";
    }

    cout << endl;

    vector<int>::iterator it;

    it = partition_point(vec.begin(), vec.end(), [](int x)
                         { return x % 2 == 0; });
    cout << *it;
}

void set2()
{

    // CPP program to demonstrate use of stringstream
    // to count frequencies of words.
    unordered_map<string, int> mp;

    string str = "Geeks For Geeks Ide Geeks For Geeks Ide";

    stringstream ss(str);
    string word;

    while (ss >> word)
    {
        // cout<<word;
        mp[word]++;
    }

    for (auto ele : mp)
    {
        cout << ele.first << " -> " << ele.second;
        cout << endl;
    }

    //program to convert string to int
    // 1. using stoi()
    string str1 = "12345";
    int x = stoi(str1);
    cout << x << endl;

    //2.using stringstream
    string str2 = "12345";
    stringstream ss1(str2);
    int y = 0;
    ss1 >> y;
    cout << y;
}

void solve()
{
    // set1();
    set2();
}

int main()
{

    solve();

    return 0;
}

//