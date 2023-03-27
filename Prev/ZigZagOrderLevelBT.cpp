#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
void helperZigZagOrder(vector<BinaryTreeNode<int>*> nodeLevel){
    if(!nodeLevel.size()) return;
	vector<BinaryTreeNode<int>*> nextNodeLevel;
    while(nodeLevel.size()){
		BinaryTreeNode<int> * dataNode=nodeLevel.back();
        nodeLevel.pop_back();
        cout<<dataNode->data<<" ";
        if(dataNode->left) nextNodeLevel.push_back(dataNode->left);
        if(dataNode->right) nextNodeLevel.push_back(dataNode->right);
    }
    helperZigZagOrder(nextNodeLevel);
}
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return ;
    helperZigZagOrder(vector<BinaryTreeNode<int>*>{root})   ;  
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}