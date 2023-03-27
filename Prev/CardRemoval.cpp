#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

#include<utility>
pair<Node<int>*,Node<int>*>* constructLinkedList2(BinaryTreeNode<int> * root){
    if(!root) return  NULL;
    pair<Node<int>*,Node<int>*>* leftLL=constructLinkedList2(root->left);
    pair<Node<int>*,Node<int>*>* rightLL = constructLinkedList2(root->right);
    Node<int>* dataNode=new Node<int>(root->data);
    Node<int>* tail;
    Node<int>* head;
    if(leftLL!=NULL&&leftLL->first==NULL){
        head=dataNode;
        tail=dataNode;
    } else{
        head=leftLL->first;
        leftLL->second->next=dataNode;
        tail=dataNode;
    }
    if(rightLL!=NULL){
        tail->next=rightLL->first;
        tail=rightLL->second;
    }
    pair<Node<int>*,Node<int>*>* output=new pair<Node<int>*,Node<int>*>(head,tail);
    return output;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(!root) return NULL;
    cout<<"Heerer";
    pair<Node<int>*,Node<int>*>* output=constructLinkedList2(root);
    return output->first;
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
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}