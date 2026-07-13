#include <iostream>
using namespace std;

// C?u trúc node cây nh? phân
struct Node {
    int data;
    Node* left;
    Node* right;
};

// T?o 1 node
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Tìm s? x trong cây
bool timX(Node* root, int x) {
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    return timX(root->left, x) || timX(root->right, x);
}

int timMax(Node* root) {
    if (root == NULL)
        return -1000000000;   // giá tr? r?t nh?

    int max = root->data;

    int maxLeft = timMax(root->left);
    int maxRight = timMax(root->right);

    if (maxLeft > max)  max = maxLeft;
    if (maxRight > max) max = maxRight;

    return max;
}


int main() {
    // T?o cây nhu hình:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Tìm s? 5
    if (timX(root, 5))
        cout << "So 5 CO trong cay\n";
    else
        cout << "So 5 KHONG co trong cay\n";

    // Tìm s? l?n nh?t
    cout << "So lon nhat trong cay: " << timMax(root) << endl;

    return 0;
}

