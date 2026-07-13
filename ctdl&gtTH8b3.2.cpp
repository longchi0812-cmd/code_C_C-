#include <iostream>
#include <queue>

using namespace std;

struct Student {
	string name;
	int age;
	float gpa;
};
	
struct CompareGPA {
	bool operator()(const Student& a, const Student& b) {
		return a.gpa > b.gpa;
	}
};
	
// a)
struct CompareAge {
	bool operator()(const Student& a, const Student& b) {
		return a.age < b.age;
	}
};
	
	// b) 
struct CompareName {
	bool operator()(const Student& a, const Student& b) {
		return a.name > b.name;
	}
};
	
int main() {
	Student s1 = {"Alice", 20, 3.8};
	Student s2 = {"Bob", 22, 3.5};
	Student s3 = {"Charlie", 21, 4.0};
	
	priority_queue<Student, vector<Student>, CompareGPA> pq;
	pq.push(s1);
	pq.push(s2);
	pq.push(s3);
	cout << "Theo GPA tang dan:\n";
	while (!pq.empty()) {
	    Student top = pq.top();
	    cout << top.name << " " << top.age << " " << top.gpa << endl;
	    pq.pop();
	}
	
	//a
	priority_queue<Student, vector<Student>, CompareAge> pqAge;
	pqAge.push(s1);
	pqAge.push(s2);
	pqAge.push(s3);
	cout << "\nTheo tuoi giam dan:\n";
	while (!pqAge.empty()) {
	    Student top = pqAge.top();
	    cout << top.name << " " << top.age << " " << top.gpa << endl;
	    pqAge.pop();
	}
	
	//b
	priority_queue<Student, vector<Student>, CompareName> pqName;
	pqName.push(s1);
	pqName.push(s2);
	pqName.push(s3);
	cout << "\nTheo ten tang dan:\n";
	while (!pqName.empty()) {
	    Student top = pqName.top();
	    cout << top.name << " " << top.age << " " << top.gpa << endl;
	    pqName.pop();
	}
	
	return 0;
}

