#include <bits/stdc++.h>
using namespace std;

struct EngDict {
    EngDict* child[27];
};

// Khoi tao nút
EngDict* initDict() {
    EngDict* root = new EngDict;
    for (int i = 0; i < 27; i++) root->child[i] = NULL;
    return root;
}

// Thêm tu vào cây
void insertWord(EngDict* root, string w)
{
    EngDict* p = root;
    for (int i = 0; i < w.size(); i++) {
        int j = w[i] - 'a';
        if (p->child[j] == NULL) {
            p->child[j] = new EngDict;
            for (int k = 0; k < 27; k++) p->child[j]->child[k] = NULL;
        }
        p = p->child[j];
    }

    if (p->child[26] == NULL) {
        p->child[26] = new EngDict;
        for (int k = 0; k < 27; k++) p->child[26]->child[k] = NULL;
    }
}

// Ðoc file tu dien
int readDictFromFile(string fileName, EngDict* root) {
    ifstream file(fileName);
    string word;
    int count = 0;

    while (getline(file, word)) {
        insertWord(root, word);
        count++;
    }
    file.close();
    return count;
}

// Tìm tu
bool findWord(EngDict* root, string w) {
    EngDict* p = root;
    for (char c : w) {
        int j = c - 'a';
        if (p->child[j] == NULL) return false;
        p = p->child[j];
    }
    return (p->child[26] != NULL);
}

// In toàn bo tu dien
void printEngDict(EngDict* root, string w) {
    if (root == NULL) return;

    if (root->child[26] != NULL)
        cout << w << endl;

    for (int i = 0; i < 26; i++) {
        if (root->child[i] != NULL) {
            w.push_back('a' + i);
            printEngDict(root->child[i], w);
            w.pop_back();
        }
    }
}

// 1) Chieu cao cây
int height(EngDict* root) {
    if (root == NULL) return 0;
    int max = 0;
    for (int i = 0; i < 27; i++) {
        if (root->child[i] != NULL) {
            int h = height(root->child[i]);
            if (h > max) max = h;
        }
    }
    return max + 1;
}


// 2) Ðem so tu trong cây
int countWords(EngDict* root) {
    if (root == NULL) return 0;
    int cnt = (root->child[26] != NULL ? 1 : 0);
    for (int i = 0; i < 26; i++)
        if (root->child[i] != NULL)
            cnt += countWords(root->child[i]);

    return cnt;
}

// 3) Nút có ít con nhat (không tính lá)
int minChildren = 1e9;

void findMinChildren(EngDict* root) {
    if (root == NULL) return;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (root->child[i] != NULL) cnt++;
    // bo nút lá
    if (cnt > 0)
        minChildren = min(minChildren, cnt);
    for (int i = 0; i < 26; i++)
        if (root->child[i] != NULL)
            findMinChildren(root->child[i]);
}

// 4) Liet kê tu bat dau bang s
void listPrefix(EngDict* root, string s){
    EngDict* p = root;
    for (char c : s) {
        int j = c - 'a';
        if (p->child[j] == NULL){
        	cout << "Khong co tu nao bat dau bang \"" << s << "\".\n";
        	return;
    	}
    	p = p->child[j];
	}
	printEngDict(p, s);
}

int main() {
    EngDict* root = initDict();

    cout << "Loading dictionary...\n";
    int k = readDictFromFile("tudien.txt", root);
    cout << k << " words loaded.\n\n";

    // 1)
    string x;
    cout << "Nhap tu can tim: ";
    cin >> x;

    if (findWord(root, x))
        cout << "Tu \"" << x << "\" co trong tu dien.\n";
    else
        cout << "Tu \"" << x << "\" KHÔNG co trong tu dien.\n";

    // 2)
    cout << "\nChieu cao cua cay: " << height(root) << endl;

    // 3)
    cout << "So tu trong tu dien: " << countWords(root) << endl;

    // 4)
    minChildren = 1e9;
    findMinChildren(root);
    cout << "Nut co it nut con nhat: " << minChildren << endl;

    // 5)
    string s;
    cout << "\nNhap tien to de liet ke tu: ";
    cin >> s;
    cout << "Cac tu bat dau bang \"" << s << "\":\n";
    listPrefix(root, s);

    return 0;
}

