#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* node = new Node;
    node->key = x;
    node->left = node->right = NULL;
    return node;
}

//a
bool isBSTUtil(Node* root, int min, int max) {
    if(root == NULL) return true;
    if(root->key <= min || root->key >= max)
        return false;
    return isBSTUtil(root->left, min, root->key) &&
           isBSTUtil(root->right, root->key, max);
}

bool isBinarySearchTree(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

//b
int height(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalancedTree(Node* root) {
    if(root == NULL) return true;

    int l = height(root->left);
    int r = height(root->right);

    if(abs(l - r) > 1) return false;

    return isBalancedTree(root->left) && isBalancedTree(root->right);
}

//c
bool isCompleteBalancedTree(Node* root) {
    if(root == NULL) return true;

    queue<Node*> q;
    q.push(root);
    bool foundNull = false;

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            foundNull = true;
        }else {
            if(foundNull) return false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

int main(){
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    cout << "Kiem tra cay:\n";
	
	//a
    if(isBinarySearchTree(root)){
    	cout << "- La cay tim kiem nhi phan" << endl;
	}else{
		cout << "- Khong la cay tim kiem nhi phan" << endl;
	}

	//b
	if(isBalancedTree(root)){
		cout << "- La cay can bang" << endl;
	}else{
		cout << "- Khong la cay can bang" << endl;
	}
	
	//c
	if(isCompleteBalancedTree(root)){
		cout << "- La cay can bang hoan toan" << endl;
	}else{
		cout << "- Khong la cay can bang hoan toan" << endl;
	}

    return 0;
}
