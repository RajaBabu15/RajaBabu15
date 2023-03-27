#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

#include <string>
using namespace std;
class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    bool isPalindrome(string str)
    {
        string rev = string(str);
        reverse(rev.begin(), rev.end());
        if (rev.compare(str) == 0)
            return true;
        else
            return false;
    }

    bool checkPalindrome(vector<string> *words)
    {
        for (int i = 0; i < words->size(); i++)
        {
            string word = words->at(i);
            bool flag = isPalindrome(word);
            if (!flag)
                return false;
        }
        return true;
    }

    void getList(TrieNode *root, string pattern, vector<string> *vect)
    {
        try
        {
            if (root == NULL)
                return;
            if (root->isTerminal)
                vect->push_back(pattern);
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                    getList(root->children[i], pattern + root->children[i]->data, vect);
            }
        }
        catch (...)
        {
        }
    }

    void addWord(TrieNode *root, string word, vector<string> *vect)
    {
        if (word.size() == 0)
        {
            getList(root, "", vect);
            if(word.size()!=0) vect->push_back(word);
            root->isTerminal = true;
            count++;
            return;
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
            addWord(root->children[index], word.substr(1), vect);
        else
        {
            TrieNode *child = new TrieNode(word[0]);
            root->children[index] = child;
            if(root->isTerminal){
                vect->push_back(word);
                return ;
            }
            addWord(root->children[index], word.substr(1), vect);
        }
    }

    bool isPalindromePair(vector<string> wordss)
    {
        // Write your code here
        vector<string> *words=new vector<string>();
        for(int  i=0;i<wordss.size();i++){
            words->push_back(wordss[i]);
        }
        bool flag = checkPalindrome(words);
        if (flag)
            return true;
        bool flag1;
        for (int i = 0; i < words->size(); i++)
        {
            flag1=false;
            vector<string>* vect=new vector<string>();
            addWord(root, words->at(i), vect);
            if (vect->size() != 0)
                flag1 = checkPalindrome(vect);
            if (flag1)
                return true;
            vect = new vector<string>();
            string rev = words->at(i);
            reverse(rev.begin(), rev.end());
            addWord(root, rev, vect);
            if (vect->size() != 0) {
                flag1 = checkPalindrome(vect);
            }
            if (flag1)
                return true;
            vect = new vector<string>();
            getList(root,"",vect);
        }
        return false;
    }
};
int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}