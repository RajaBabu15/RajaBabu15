#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;
void printNodesAtDeepth(BinaryTreeNode<int> *root,int deepth){
    if(!root||deepth<0) return ;
    if(deepth==0) cout<<root->data<<endl;
    printNodesAtDeepth(root->left,deepth-1);
    printNodesAtDeepth(root->right,deepth-1);
}

int nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    if(!root) return -1;
    if(root->data==node){
        printNodesAtDeepth(root,k);
        return 0;
    }
    int lD=nodesAtDistanceK(root->left,node,k);
    if(lD!=-1){
        if(k-lD-1==0) cout<<root->data<<endl;
        else printNodesAtDeepth(root->right,k-lD-2);
        return lD-1;
    }
    int rD=nodesAtDistanceK(root->right,node,k);
    if(rD!=-1){
        if(k-rD-1==0) cout<<root->data<<endl;
        else printNodesAtDeepth(root->left,k-rD-2);
        return rD-1;
    }
    return -1;
    
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}