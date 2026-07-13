#include <iostream>

using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

Node* taoNode(char c) {
    Node* node = new Node;
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

int timViTri(string inorder, char c, int start, int end) {
    for(int i = start; i <= end; i++)
        if(inorder[i] == c)
            return i;
    return -1;
}

Node* xayDung(string preorder, string inorder, int &viTriPre, int start, int end) {
    if(start > end) return NULL;
    
    char kyTu = preorder[viTriPre++];
    Node* node = taoNode(kyTu);

    if(start == end) return node;

    int pos = timViTri(inorder, kyTu, start, end);

    node->left = xayDung(preorder, inorder, viTriPre, start, pos - 1);
    node->right = xayDung(preorder, inorder, viTriPre, pos + 1, end);

    return node;
}

void inDuyetSau(Node* root) {
    if(root == NULL) return;
    inDuyetSau(root->left);
    inDuyetSau(root->right);
    cout << root->data << " ";
}

int main() {
    string preorder = "ABDEC";
    string inorder = "DBEAC";

    int viTriPre = 0;
    Node* root = xayDung(preorder, inorder, viTriPre, 0, inorder.size() - 1);

    cout << "Duyet thu tu sau: ";
    inDuyetSau(root);
    cout << endl;

    return 0;
}

