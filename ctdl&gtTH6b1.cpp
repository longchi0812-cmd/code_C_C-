 #include <iostream>
#include <fstream>

using namespace std;

struct Word{
	string english;
	string vietnamese;
};

struct EngVietDict{
	Word data;
	EngVietDict *left, *right;
};

//a 
void insertWord(EngVietDict* &root, Word data){
	if(!root){
		root = new EngVietDict;
		root->data = data;
		root->left = root->right = NULL;
	} else if(data.english < root->data.english){
		insertWord(root->left, data);
	} else if(data.english > root->data.english){
		insertWord(root->right, data);
	}
}

//b
void docTepTuDien(EngVietDict* &root, string tenfile){
	ifstream file(tenfile);
	string line;
	while(getline(file, line)){
		int pos = line.find(':');
		string eng = line.substr(0, pos);
		string viet = line.substr(pos + 1);
		Word data = {eng, viet};
		insertWord(root, data);
	}
	file.close();
}

//c 
void printDict(EngVietDict *root){
	if(root){
		printDict(root->left);
		cout << "\t" <<root->data.english << " : " << root->data.vietnamese <<endl;
		printDict(root->right);
	}
}

//d
string findVietnamese(EngVietDict *root, string eng){
	if(!root) return "";
	if(root->data.english == eng){
		return root->data.vietnamese;
	}
	if(eng < root->data.english){
		return findVietnamese(root->left, eng);
	} else {
		return findVietnamese(root->right, eng);
	}
}

//e
EngVietDict *findMin(EngVietDict *root) {
	if (root->left == NULL) {
		return root;
	}
	return findMin(root->left);
}

void deleteWord(EngVietDict *&root, string eng) {
	if (root == NULL) {
		return;
	}
	if (eng < root->data.english) {
		deleteWord(root->left, eng);
	} else if (eng > root->data.english) {
		deleteWord(root->right, eng);
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		} else if (root->left == NULL) {
			EngVietDict *temp = root;
			root = root->right;
			delete temp;
		} else if (root->right == NULL) {
			EngVietDict *temp = root;
			root = root->left;
			delete temp;
		} else {
			EngVietDict *temp = findMin(root->right);
			root->data = temp->data;
			deleteWord(root->right, temp->data.english);
		}
	}
}

//f
void printWordByH(EngVietDict* root){
	if(!root) return;
	if(root->data.english[0] == 'H'){
		cout << "\t" << root->data.english << " : " << root->data.vietnamese << endl;
	}
	printWordByH(root->left);
	printWordByH(root->right);
}

//g
int countAfterAWord(EngVietDict *root, string word){
	int dem = 0;
	if(!root) return dem;
	if(root->data.english > word){
		dem = 1;
	}
	dem += countAfterAWord(root->left, word);
	dem += countAfterAWord(root->right, word);
	
	return dem;
}

//h
void ghiTheoThuTuTruoc(EngVietDict* root, ofstream& file) {
    if(root == NULL) return;
    file << root->data.english << " : " << root->data.vietnamese << endl;
    ghiTheoThuTuTruoc(root->left, file);
    ghiTheoThuTuTruoc(root->right, file);
}

void luuTep(EngVietDict* root, string tenfile) {
    ofstream file(tenfile);
    if(!file) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    ghiTheoThuTuTruoc(root, file); 
    file.close();
    cout << "Da luu tu dien vao tep '" << tenfile << "' thanh cong!" << endl;
}

int main(){
	EngVietDict *root = NULL;
	string eng, viet;
	
	//b
	docTepTuDien(root, "EDV.txt");
	//c
	cout << "Nhung tu trong cay: " << endl;
	printDict(root);
	
	//a
	Word data;
	data.english = "Hat";
	data.vietnamese = "mu";
	insertWord(root, data);
	
	Word data2;
	data2.english = "House";
	data2.vietnamese = "ngoi nha";
	insertWord(root, data2);
	cout << "\nCay sau khi them: " << endl;
	printDict(root);
	
	//d
	cout << "\nNhap tu can tra: "; cin >> eng;
	viet = findVietnamese(root, eng);
	if(viet != ""){
		cout << "\t" << eng << " : " << viet << endl;
	}else{
		cout << "\t" << eng << " : \nKhong tim thay." << endl; 
	}
	
	//e
	string enge = "hello";
	cout << "\nCay sau khi xoa '" << enge << "'" << endl;
	deleteWord(root, enge);
	printDict(root);
	
	//f
	cout << "\nNhung tu bat dau bang H la: " << endl;
	printWordByH(root);
	
	//g
	string word = "begin";
	cout << "\nSo tu trong cay sau tu " << "'" << word << "'" <<" : " << countAfterAWord(root, word) << endl;
	
	//h
	luuTep(root, "EDVs.txt");
	return 0; 
}
