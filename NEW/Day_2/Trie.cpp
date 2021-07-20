
//================= 208. Implement Trie (Prefix Tree) ====================================

class Trie
{

    class Node
    {
    public:
        bool wordEnd;
        vector<Node *> Children;

        Node()
        {
            this->wordEnd = false;
            this->Children.assign(26, nullptr);
        }
    };

    //create a ROOT node
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *curr = root;
        int n = word.length();

        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';
            if (curr->Children[idx] == nullptr)
            {
                curr->Children[idx] = new Node();
            }

            curr = curr->Children[idx];
        }
        curr->wordEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *curr = root;
        int n = word.length();

        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';
            if (curr->Children[idx] == nullptr)
                return false;
            curr = curr->Children[idx];
        }

        //if's its a valid word then it's wordEnd will be marked true otherwise it will be false
        return curr->wordEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *curr = root;
        int n = prefix.length();

        for (int i = 0; i < n; i++)
        {
            int idx = prefix[i] - 'a';
            if (curr->Children[idx] == nullptr)
                return false;
            curr = curr->Children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//================================ 211. Design Add and Search Words Data Structure =============================

class WordDictionary
{

    class Node
    {
    public:
        int wordEnd;
        vector<Node *> Children;

        Node()
        {
            this->wordEnd = false;
            this->Children.assign(26, nullptr);
        }
    };

    Node *root = nullptr;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *curr = root;
        int n = word.length();

        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';

            if (curr->Children[idx] == nullptr)
            {
                curr->Children[idx] = new Node();
            }
            curr = curr->Children[idx];
        }
        curr->wordEnd = true;
    }

    bool search_(Node *currNode, int si, string word)
    {
        //stopping condition
        if (si == word.length())
        {
            return currNode->wordEnd;
        }

        bool res = false;

        if (word[si] == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (currNode->Children[i] != nullptr)
                    res = res || search_(currNode->Children[i], si + 1, word);
            }
        }
        else
        {
            int idx = word[si] - 'a';
            if (currNode->Children[idx] == nullptr)
            {
                return false;
            }
            else
            {
                res = res || search_(currNode->Children[idx], si + 1, word);
            }
        }

        return res;
    }

    bool search(string word)
    {
        return search_(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

//======================================= 212. Word Search II ==============================================

class Solution
{

    class Node
    {
    public:
        bool wordEnd;
        vector<Node *> Children;
        string Word;

        Node()
        {
            this->wordEnd = false;
            this->Children.assign(26, nullptr);
            this->Word = "";
        }
    };

    Node *root = new Node();

public:
    void insertIntoTrie(string &str)
    {
        Node *curr = root;
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            if (curr->Children[idx] == nullptr)
            {
                curr->Children[idx] = new Node();
            }
            curr = curr->Children[idx];
        }
        curr->wordEnd = true;
        curr->Word = str;
    }

    vector<string> ans;
    vector<vector<int>> dirA{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    void dfs(int r, int c, Node *currNode, vector<vector<char>> &board)
    {

        // condition to push the string into ans
        if (currNode->wordEnd == true)
        {
            ans.push_back(currNode->Word);
            currNode->wordEnd = false;

            // To avoid duplicacy in the answer
            //if left ture(unchanged) same string may be added at some later point while traversing the board
            // For eg: if EAT can be formed in row 2 as well as row 4, but we only need to add EAT once in our Answer
        }

        char ch = board[r][c];
        board[r][c] = '$'; //adding this to mark this cell visited during this dfs traversal

        for (int d = 0; d < 4; d++)
        {

            int x = r + dirA[d][0];
            int y = c + dirA[d][1];

            if (x < m && x >= 0 && y < n && y >= 0 && board[x][y] != '$' && (currNode->Children[board[x][y] - 'a'] != nullptr))
            {
                dfs(x, y, currNode->Children[board[x][y] - 'a'], board);
            }
        }
        board[r][c] = ch; // changing it back to original after backtracking
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        // if (!board.size() || !board[0].size() || !words.size())
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return {};

        for (string &str : words)
        {
            insertIntoTrie(str);
        }

        m = board.size();    //Row
        n = board[0].size(); //Column

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (root->Children[board[i][j] - 'a'] != nullptr)
                {
                    dfs(i, j, root->Children[board[i][j] - 'a'], board);
                }
            }
        }
        return ans;
    }
};