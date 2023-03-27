#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
#include<stack>
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(!root) return;
    stack<BinaryTreeNode<int> *> in;
    stack<BinaryTreeNode<int> *> rin;
    in.push(root);
    BinaryTreeNode<int>* tmp=root->left;
    while(tmp!=NULL){
        in.push(tmp);
        tmp=tmp->left;
    }
    tmp=root->right;
    while(tmp!=NULL){
        rin.push(tmp);
        tmp=tmp->right;
    }
    while(in.size()>0&&rin.size()>0){
        int sum=in.top()->data+rin.top()->data;
        if(in.top()->data==rin.top()->data) break;
        if(sum==s){
        	cout<<min(in.top()->data,rin.top()->data)<<" "<<max(in.top()->data,rin.top()->data)<<endl;
            tmp=in.top()->right;
            in.pop();
            while(tmp!=NULL){
                in.push(tmp);
                tmp=tmp->right;
            }
            tmp=rin.top()->left;
            rin.pop();
            while(tmp!=NULL){
                rin.push(tmp);
                tmp=tmp->left;
            }
        }
        else if(sum<s){
            tmp=rin.top()->left;
            rin.pop();
            while(tmp!=NULL){
                rin.push(tmp);
                tmp=tmp->left;
            }
        }
        else{
            tmp=in.top()->right;
            in.pop();
            while(tmp!=NULL){
                in.push(tmp);
                tmp=tmp->right;
            }
        }
    }
}

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}       