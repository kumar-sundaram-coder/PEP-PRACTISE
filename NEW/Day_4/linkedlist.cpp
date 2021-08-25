/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
    //Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *curr = head;
        Node *prev = NULL;
        Node *nxt = NULL;
        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

//https://www.geeksforgeeks.org/flattening-a-linked-list/
//Flattening a Linked List
// An utility function to merge two sorted
// linked lists
Node *merge(Node *a, Node *b)
{

    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;

    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;

    // Compare the data members of the two linked
    // lists and put the larger one in the result
    Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }

    else
    {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node *flatten(Node *root)
{

    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;

    // Recur for list on right
    root->right = flatten(root->right);

    // Now merge
    root = merge(root, root->right);

    // Return the root
    // it will be in turn merged with its left
    return root;
}

//
//
// C++ Program to sort a linked list 0s, 1s or 2s
// Function to sort a linked list of 0s, 1s and 2s
void sortList(Node *head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    Node *ptr = head;

    /* count total number of '0', '1' and '2'
	* count[0] will store total number of '0's
	* count[1] will store total number of '1's
	* count[2] will store total number of '2's */
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }

    int i = 0;
    ptr = head;

    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
	* now start traversing list from head node,
	* 1) fill the list with 0, till n1 > 0
	* 2) fill the list with 1, till n2 > 0
	* 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

// /* Function to push a node */
// void push (Node** head_ref, int new_data)
// {
// 	/* allocate node */
// 	Node* new_node = new Node();

// 	/* put in the data */
// 	new_node->data = new_data;

// 	/* link the old list off the new node */
// 	new_node->next = (*head_ref);

// 	/* move the head to point to the new node */
// 	(*head_ref) = new_node;
// }

// /* Function to print linked list */
// void printList(Node *node)
// {
// 	while (node != NULL)
// 	{
// 		cout << node->data << " ";
// 		node = node->next;
// 	}
// 	cout << endl;
// }
