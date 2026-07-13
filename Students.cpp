#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
	string name;
	int age;
	double gpa;
};

void inputStudent(struct Student &s)
{

	cout << "Name: "; getline(cin, s.name);
	cout << "Age: "; cin >> s.age;
	cout << "GPA: "; cin >> s.gpa;
}

void printStudent(struct Student s)
{
	cout << "Name: " << s.name << endl;
	cout << "Age: " << s.age << endl;
	cout << "GPA: " << s.gpa << endl;
}

void inputListOfStudent(struct Student list[], int n)
{

	for(int i = 0; i < n; i++)
	{
		fflush(stdin);
		inputStudent(list[i]);
	}
}

void printListOfStudent(struct Student list[], int n)
{
	for(int i = 0; i < n; i++)
		printStudent(list[i]);
}
/*
int findStudent(struct Student list[], int n, string name)
{
	int i;
	for(i = 0; i < n; i++)
		if(list[i].name == name)
			return i;
	return -1;
}

void writeToFile(struct Student list[], int n, char* fname)
{
	fstream out;
	out.open(fname, ios::out);
	for(int i = 0; i < n; i++)
		out << list[i].name << ", " << list[i].age << ", " << list[i].gpa
<< endl;
	out.close();
}

int readFromFile(char *fname, struct Student list[])
{
	fstream fin;
	string s;
	int m, n, k = 0;
	fin.open(fname);
	while (getline(fin, s))
	{
		n = s.find(','); //find the character ‘,’ in s
		list[k].name = s.substr(0, n); // extract the name
		m = s.find(',', n+1); // character ‘,’ next in s
		list[k].age = stoi(s.substr(n+2, m-n-2)); //extract age
		list[k].gpa = stof(s.substr(m+2)); //extract gpa
		k++;
	}
	fin.close();
	return k;
}*/

void listOfGoodStudents(struct Student list[], int n){
	for(int i = 0; i < n; i++){
		if(list[i].gpa >= 8){
			printStudent(list[i]);
		}
	}
}

int appendStudent(struct Student list[], int n, struct Student s){
    list[n] = s;
    n++;
	return n;
}

int countFirstName(struct Student list[], int n){
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(list[i].name.substr(0, 6) == "Nguyen"){
			dem++;	
		}
	}
	return dem;
}

string convertName(string name){
	int pos = name.find_last_of(' ');
	if (pos == string::npos) return name;
	
	return name.substr(pos + 1) + " " + name.substr(0, pos-1);
}

void sortVNName(struct Student list[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(convertName(list[i].name) > convertName(list[j].name)){
				swap(list[i], list[j]);
			}
		}
	}
}

int main()
{
	struct Student m[100], m2[100];
	string name;
	int k;
	inputListOfStudent(m, 2);
	cout << "\nDanh sach sinh vien:\n";
	printListOfStudent(m, 2);
	fflush(stdin);
	/*cout << "Input name for find: "; getline(cin, name);
	k = findStudent(m, 2, name);
	if (k == -1)
		cout << "Not found!";
	else
		printStudent(m[k]);
	

	writeToFile(m, 2, "students.txt");
	
	int n2 = readFromFile("students.txt", m2);
	cout << "Danh sach sinh vien doc tu file:\n";
	printListOfStudent(m2, n2);
	*/
	cout << "\nDanh sach sinh vien co GPA >= 8:\n";
	listOfGoodStudents(m, 2);
	
	cout << "\nNhap sinh vien de them:\n";
	Student s;
	inputStudent(s);
	k = appendStudent(m, 2, s);
	cout << "\n-------\n";
	cout << "Danh sach sau khi them:\n";
	printListOfStudent(m, k);
	
	countFirstName(m, 2);
	cout << "So sinh vien ho NG: " << countFirstName(m, 2);
	
	sortVNName(m, 2);
	cout << "\nDanh sach sinh vien sau sap xep:\n";
	printListOfStudent(m, 2);

}
