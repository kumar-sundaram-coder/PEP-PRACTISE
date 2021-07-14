#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> //For accumulate operation

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
    int arr[] = {1, 3, 2, 1, 4, 4, 1, 3, 5, 6, 7, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    show(arr, n);

    //sort in ascending order
    sort(arr, arr + n);
    cout << endl;
    show(arr, n);
    cout << endl;
    bool res = false;
    res = binary_search(arr, arr + n, 5);
    cout << ((res == true) ? "Found" : "Not Found");
    cout << endl;

    //sort in descending order
    sort(arr, arr + n, greater<int>());
    show(arr, n);
    cout << endl;

    //reverse
    reverse(arr, arr + n);
    show(arr, n);
    cout << endl;

    //max element
    cout << *max_element(arr, arr + n);
    cout << endl;

    //min element
    cout << *min_element(arr, arr + n);
    cout << endl;

    //The summation of array's elements, taking 0 as initial value of sum

    cout << accumulate(arr, arr + n, 0);
    cout << endl;

    // sort in a particular order
    //by creating our own comparator function and passing it as a third parameter

    Interval Arr[] = {{1, 2}, {9, 0}, {-1, 2}, {1, 1}, {6, 2}};
    int N = sizeof(Arr) / sizeof(Arr[0]);

    sort(Arr, Arr + N, compareInterval);

    for (int i = 0; i < N; i++)
    {
        cout << "[ " << Arr[i].start << ", " << Arr[i].end << " ] ";
    }
}

void solve()
{
    set1();
}

int main()
{

    solve();

    return 0;
}

//