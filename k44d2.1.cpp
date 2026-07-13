#include <iostream>
using namespace std;

// Node BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Chèn 1 giá tr? vào BST
void insertBST(Node* &root, int x) {
    if (!root){
       root = new Node;
       root->data = x;
       root->left = root->right =NULL;

    }else if (x < root->data){
        insertBST(root->left, x);
    }else if(x > root->data){
        insertBST(root->right, x);
	}
}

// Tính t?ng các s? ch?n trong BST
int tongSoChan(Node* root) {
    if (!root) return 0;

    int sum = 0;
    if (root->data % 2 == 0)
        sum += root->data;

    sum += tongSoChan(root->left);
    sum += tongSoChan(root->right);

    return sum;
}

// Tìm c?p c?a s? x trong BST
int timCap(Node* root, int x, int cap) {
    if (!root) return 0;

    if (root->data == x)
        return cap;

    if (x < root->data)
        return timCap(root->left, x, cap + 1);
    else
        return timCap(root->right, x, cap + 1);
}

int main() {
    Node* root = NULL;

    // T?o BST theo hình
//    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
//    int n = sizeof(a) / sizeof(a[0]);
	insertBST(root, 8);
	insertBST(root, 3);
	insertBST(root, 10);
	insertBST(root, 1);
	insertBST(root, 6);
	insertBST(root, 14);
	insertBST(root, 4);
	insertBST(root, 7);
	insertBST(root, 13);
	
	
//    for (int i = 0; i < n; i++)
//        root = insertBST(root, a[i]);

    // T?ng s? ch?n
    cout << "Tong cac so chan trong cay: "
         << tongSoChan(root) << endl;

    // C?p c?a s? 6
    cout << "Cap cua so 6 trong cay: "
         << timCap(root, 66, 1) << endl;

    return 0;
}

