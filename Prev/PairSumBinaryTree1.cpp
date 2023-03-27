#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include <bits/stdc++.h>

pair<bool, BinaryTreeNode<int> *> deleteData(BinaryTreeNode<int> *root, int data)
{
    if (!root){
        BinaryTreeNode<int> *ptr = NULL;
        return make_pair(false, ptr);
    }
    pair<bool, BinaryTreeNode<int> *> p = deleteData(root->left, data);
    root->left = p.second;
    if (p.first)
        return make_pair(true, root);
    p = deleteData(root->right, data);
    root->right = p.second;
    if (p.first)
        return make_pair(true, root);

    BinaryTreeNode<int> *ptr = NULL;

    if (!root->left && !root->right)
        return make_pair(true, ptr);
    else if (root->left && !root->right)
        return make_pair(true, root->left);
    else if (!root->left && root->right)
        return make_pair(true, root->right);
    else
    {
        BinaryTreeNode<int> *tmp = root->right;
        while (tmp->left)
            tmp = tmp->left;
        root->data = tmp->data;
        p = deleteData(root->right, root->data);
        root->right = p.second;
        return make_pair(true, root);
    }
    return make_pair(true, root);
}

bool hasData(BinaryTreeNode<int> *root, int data)
{
    if (!root)
        return false;
    if (root->data == data)
        return true;
    if (hasData(root->right, data) && hasData(root->left, data))
        return true;
    return false;
}
void pairSum(BinaryTreeNode<int> *root, int sum,BinaryTreeNode<int>* headNode=NULL)
{
    // Write your code here
    if (!root)
        return;
    if(headNode==NULL) headNode=root;
    pairSum(root->left, sum,headNode);
    if (hasData(headNode, sum - root->data) || hasData(headNode, sum - root->data))
    {
        cout << min(root->data, sum - root->data) << " " << max(root->data, sum - root->data) << endl;
        root = (deleteData(headNode, sum - root->data)).second;
    }
    pairSum(root->right, sum,headNode);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}