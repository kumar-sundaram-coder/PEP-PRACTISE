//Circular Queue
// C or C++ program for insertion and
// deletion in Circular Queue
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

/* Driver of the program */
int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}

//Min Stack

class MinStack
{
public:
    vector<pair<int, int>> s;

    MinStack() {}

    void push(int val)
    {
        if (s.empty())
            s.push_back({val, val});
        else
            s.push_back({val, min(s.back().second, val)});
    }

    void pop() { s.pop_back(); }

    int top() { return s.back().first; }

    int getMin() { return s.back().second; }
};
// The Time complexity of each operation is O(1)
// The Space complexity is O(N)

//using 2 stacks(doubt)
// class MinStack
// {
// private:
//     stack<int> s1;
//     stack<int> s2;

// public:
//     void push(int x)
//     {
//         s1.push(x);
//         if (s2.empty() || x <= getMin())
//             s2.push(x);
//     }
//     void pop()
//     {
//         if (s1.top() == getMin())
//             s2.pop();
//         s1.pop();
//     }
//     int top()
//     {
//         return s1.top();
//     }
//     int getMin()
//     {
//         return s2.top();
//     }
// };

// 1. stocks max profit problem
class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        if (n == 2)
        {
            return (nums[1] - nums[0] > 0 ? nums[1] - nums[0] : 0);
        }
        int min_ele = INT_MAX, max_profit = 0;
        for (int &ele : nums)
        {
            if (ele < min_ele)
            {
                min_ele = ele;
            }
            else if (ele - min_ele > max_profit)
            {
                max_profit = ele - min_ele;
            }
        }
        return max_profit;
    }
};
// 2. 2sum
vector<int> twoSum(vector<int> &nums, int tar)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int a;
    for (int i = 0; i < n; i++)
    {
        a = tar - nums[i];
        if (mp.find(a) != mp.end())
            return {i, mp[a]};
        else
            mp.insert({nums[i], i});
    }
    return {};
}

// 3. 3sum

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int i = 0;
        int nTar;
        for (i = 0; i < n; i++)
        {
            nTar = -(nums[i]);
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum > nTar)
                {
                    r--;
                }
                else if (sum < nTar)
                {
                    l++;
                }
                else
                {
                    vector<int> smallAns = {nums[i], nums[l], nums[r]};
                    ans.push_back(smallAns);
                    //to remove duplicacy
                    while (l < r and nums[l] == smallAns[1])
                        l++;
                    while (r > l and nums[r] == smallAns[2])
                        r--;
                }
            }
            while (i + 1 < n and nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return ans;
    }
};

// 901. Online Stock Span
class StockSpanner
{
public:
    stack<pair<int, int>> s;
    StockSpanner() {}

    int next(int price)
    {
        int ans = 1;
        while (!s.empty() and s.top().second <= price)
        {
            ans += s.top().first;
            s.pop();
        }
        s.push({ans, price});
        return ans;
    }
};

//122. Best Time to Buy and Sell Stock II
class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        if (n == 2)
            return nums[1] - nums[0] > 0 ? nums[1] - nums[0] : 0;
        int max_profit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                max_profit += nums[i + 1] - nums[i];
        }
        return max_profit;
    }
};

//Count pairs with given sum
//https://www.geeksforgeeks.org/count-pairs-with-given-sum/

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(k - arr[i]) != mp.end())
            {
                ans += mp[k - arr[i]];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};

//Size of Binary Tree
/* Computes the number of nodes in a tree. */

int getSize(Node *node)
{
    // Your code here
    if (node == NULL)
    {
        return 0;
    }
    int count = getSize(node->left) + getSize(node->right) + 1;
    return count;
}

//Height of Binary Tree
//Function to find the height of a binary tree.
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    int ans = 0;
    ans = max(height(node->left), height(node->right)) + 1;
    return ans;
}

// Max and min element in Binary Tree
class Solution
{
public:
    int maxx = INT_MIN;
    int minn = INT_MAX;

    int findMax(Node *root)
    {
        if (root == NULL)
            return 0;

        findMax(root->left);
        findMax(root->right);
        maxx = max(maxx, root->data);
        return maxx;
    }

    int findMin(Node *root)
    {
        if (root == NULL)
            return 0;

        findMin(root->left);
        findMin(root->right);
        minn = min(minn, root->data);
        return minn;
    }
};

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int size = q.size();
        int flag = 0;
        while (size--)
        {
            Node *temp = q.front();
            q.pop();
            if (flag == 0)
            {
                ans.push_back(temp->data);
                flag = 1;
            }
            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}
//-----------------------TREE TRAVERSALS-----------------------------------

//1.Inorder
// Function to return a list containing the inorder traversal of the tree.
vector<int> ans;
vector<int> inOrder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    inOrder(root->left);
    ans.push_back(root->data);
    inOrder(root->right);
    return ans;
}

//2. Preorder

//Function to return a list containing the preorder traversal of the tree.
vector<int> ans;
void preorder_(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    preorder_(root->left);
    preorder_(root->right);
}

vector<int> preorder(Node *root)
{
    ans = {};
    preorder_(root);
    return ans;
}

//3. Postorder
//Function to return a list containing the postorder traversal of the tree.
vector<int> ans;

void postOrder_(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder_(root->left);
    postOrder_(root->right);
    ans.push_back(root->data);
    return;
}
vector<int> postOrder(Node *root)
{
    ans = {};
    postOrder_(root);
    return ans;
}

// 4. Level Order traversal
//Function to return the level order traversal of a tree.
vector<int> levelOrder(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}

// Identical Trees
//Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL and r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL)
        return false;
    bool res = false;
    if (r1->data != r2->data)
    {
        return false;
    }
    res = isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    return res;
}

//Mirror tree

// Function to convert a binary tree into its mirror tree.
//a. using BFS
void mirror(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front();
            q.pop();
            swap(temp->left, temp->right);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return;
}

// b. Using DFS
// Function to convert a binary tree into its mirror tree.
void mirror(Node *root)
{
    if (root == NULL)
        return;

    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

// Minimum element in BST
//method 2. recursive/dfs
int minValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int ans = 0;
    if (root->left != NULL)
    {
        ans = minValue(root->left);
        return ans;
    }
    return root->data;
}

// method 2. iterative
int minValue(Node *root)
{
    Node *curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr->data;
}

// LCA
//Function to find the lowest common ancestor in a BST.
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root;
}

// count leaves in a Binary Tree
/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
int countLeaves(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int count = 0;
    if (root->left != NULL)
        count += countLeaves(root->left);
    if (root->right != NULL)
        count += countLeaves(root->right);

    return count;
}

//
//Function to check whether a Binary Tree is BST or not.

// Method 1
//space O(n)
vector<int> vec;
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    vec.push_back(root->data);
    inorder(root->right);
}
bool isBST(Node *root)
{
    vec = {};
    inorder(root);

    return is_sorted(vec.begin(), vec.end());
}

// Method 2
//space O(1)
bool isBST_(Node *root, Node *&prev)
{
    if (root == NULL)
        return true;
    if (isBST_(root->left, prev) == false)
        return false;
    if (prev != NULL and prev->data >= root->data)
        return false;
    prev = root;
    return isBST_(root->right, prev);
}

bool isBST(Node *root)
{
    Node *prev = NULL;
    return isBST_(root, prev);
}

//Level order traversal in spiral form

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    stack<Node *> s1; //Right to Left
    stack<Node *> s2; //Left to Right
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {

        while (s1.size() > 0)
        {
            Node *temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            //children
            if (temp->right != NULL)
            {
                s2.push(temp->right);
            }
            if (temp->left != NULL)
            {
                s2.push(temp->left);
            }
        }

        while (s2.size() > 0)
        {
            Node *temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);
            //children
            if (temp->left != NULL)
            {
                s1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                s1.push(temp->right);
            }
        }
    }
    return ans;
}

//-------------VIEWS----------------------------

//1. left View

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    if (root == NULL)
        return {};
    queue<Node *> q;
    q.push(root);
    vector<int> arr;
    while (q.size() > 0)
    {
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 1)
                arr.push_back(temp->data);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return arr;
}

//Right View

//Function to return list containing elements of right view of binary tree.

vector<int> rightView(Node *root)
{
    if (root == NULL)
        return {};

    queue<Node *> q;
    q.push(root);

    vector<int> arr;

    while (q.size() > 0)
    {
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == size)
                arr.push_back(temp->data);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return arr;
}

//Top View

//Function to return a list of nodes visible from the top view
//from left to right in Binary Tree.

vector<int> topView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front().first;
            int d = q.front().second;
            q.pop();

            if (mp.find(d) == mp.end())
                mp[d] = temp->data;

            if (temp->left != NULL)
                q.push({temp->left, d - 1});
            if (temp->right != NULL)
                q.push({temp->right, d + 1});
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans.push_back(i->second);
    }
    return ans;
}

//Bottom View
vector<int> bottomView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front().first;
            int d = q.front().second;
            q.pop();

            mp[d] = temp->data;

            if (temp->left != NULL)
                q.push({temp->left, d - 1});
            if (temp->right != NULL)
                q.push({temp->right, d + 1});
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans.push_back(i->second);
    }
    return ans;
}

//Vertical Order Traversal

//Function to find the vertical order traversal of Binary Tree.

vector<int> verticalOrder(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, vector<int>> mp;
    q.push({root, 0});
    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front().first;
            int d = q.front().second;
            q.pop();

            mp[d].push_back(temp->data);

            if (temp->left != NULL)
                q.push({temp->left, d - 1});
            if (temp->right != NULL)
                q.push({temp->right, d + 1});
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for (int ele : i->second)
        {
            ans.push_back(ele);
        }
    }
    return ans;
}

//Add two numbers Linked List
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    vector<int> nums1, nums2;
    while (l1)
    {
        nums1.push_back(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        nums2.push_back(l2->val);
        l2 = l2->next;
    }

    int m = nums1.size(), n = nums2.size();
    int sum = 0, carry = 0;

    ListNode *head = nullptr, *p = nullptr;

    for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
    {
        sum = carry;
        if (i >= 0)
            sum += nums1[i];

        if (j >= 0)
            sum += nums2[j];

        carry = sum / 10;

        p = new ListNode(sum % 10);
        p->next = head;
        head = p;
    }

    return head;
}

// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
// Diameter of Binary Tree
class Solution
{
public:
    class abc
    {
    public:
        int dia;
        int ht;
        abc(int d, int h)
        {
            dia = d;
            ht = h;
        }
    };

    abc diameter_(Node *root)
    {
        if (root == NULL)
            return abc(0, 0);
        if (root->left == NULL and root->right == NULL)
            return abc(1, 1);
        //left
        abc ll = diameter_(root->left);
        //right
        abc rr = diameter_(root->right);
        //including root
        return abc(max({ll.dia, rr.dia, ll.ht + rr.ht + 1}), max(ll.ht, rr.ht) + 1);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        abc ans = diameter_(root);
        return ans.dia;
    }
};