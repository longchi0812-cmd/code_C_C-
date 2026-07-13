#include <iostream>
#include <vector>

#define max 100

using namespace std;
struct Customer
{
	string name;
	string address;
	vector<string> phoneNumbers;
};

struct ListOfCustomers
{
	Customer arrCustomers[max];
	int numOfCustomers;
};

void inputCustomer(Customer &c)
{
	int i, n; string phone;
	fflush(stdin);
	cout << "Name: "; getline(cin, c.name);
	cout << "Address: "; getline(cin, c.address);
	cout << "Num of phones: "; cin >> n;
	fflush(stdin);
	for(int i = 0; i < n; i++){
		cout << "Phone number " << i << " : "; getline(cin, phone);
		c.phoneNumbers.push_back(phone);
	}
}

void outputCustomer(Customer c)
{
	int i;
	cout << "Name: " << c.name << endl;
	cout << "Address: " << c.address << endl;
	cout << "List of phone: ";
	for(int i = 0; i < c.phoneNumbers.size(); i++)
		cout << c.phoneNumbers[i] << " ";
	cout << endl;
}

void inputListOfCustomer(ListOfCustomers& list){
	cout << "Number of customers: "; cin >> list.numOfCustomers;
	for(int  i = 0; i < list.numOfCustomers; i++)
		inputCustomer(list.arrCustomers[i]);
}

void outputListOfCustomers(ListOfCustomers list){
	cout << "Number of customers: " << list.numOfCustomers << endl;
	for(int i = 0; i < list.numOfCustomers; i++)
		outputCustomer(list.arrCustomers[i]);
}

void deleteCustomerByName(ListOfCustomers &list, string name){
	for(int i = 0; i < list.numOfCustomers; i++){
		if(list.arrCustomers[i].name == name){
			for(int j = i; j < list.numOfCustomers - 1; j++){
				list.arrCustomers[j] = list.arrCustomers[j + 1];
			}
			list.numOfCustomers--;
			i--;
		}
	}
}

int findCustomerByPhone(ListOfCustomers list, string phone){
	for(int i = 0; i < list.numOfCustomers; i++){
		for(int j = 0; j < list.arrCustomers[i].phoneNumbers.size(); j++){
			if(list.arrCustomers[i].phoneNumbers[j] == phone){
				return i;
			}
		}
	}
	return -1;
}

void deletePhone(ListOfCustomers &list, string phone){
	int k = findCustomerByPhone(list, phone);
	if(k == -1){
		cout << "Khong tim thay sdt nay." << endl;
		return;
	}
	for(int i = 0; i < list.arrCustomers[k].phoneNumbers.size(); i++){
		if(list.arrCustomers[k].phoneNumbers[i] == phone){
			for(int j = i; j < list.arrCustomers[k].phoneNumbers.size() - 1; j++){
				list.arrCustomers[k].phoneNumbers[j] = list.arrCustomers[k].phoneNumbers[j + 1];
			}
			list.arrCustomers[k].phoneNumbers.pop_back();
			break;
		}
	}
}

void appendPhone(ListOfCustomers &list, string name, string phone){
	for(int i = 0; i < list.numOfCustomers; i++){
		if(list.arrCustomers[i].name == name){
			list.arrCustomers[i].phoneNumbers.push_back(phone);
			return;
		}
	}
	cout << "Khong tim thay khach hang ten: " << name << endl;
}

void mergeCustomer(ListOfCustomers &list, Customer c){
	for(int i = 0; i < list.numOfCustomers; i++){
		if(list.arrCustomers[i].name == c.name){
			for(int j = 0; j < c.phoneNumbers.size(); j++){
				string phone = c.phoneNumbers[j];
				bool kiemtra = false;
				for(int k = 0; k < list.arrCustomers[i].phoneNumbers.size(); k++){
					if(list.arrCustomers[i].phoneNumbers[k] == phone){
						kiemtra = true;
						break;
					}
				}
				if(!kiemtra){
					list.arrCustomers[i].phoneNumbers.push_back(phone);
				}
			}
			return;
		}else {
			list.arrCustomers[list.numOfCustomers] = c;
		}
	}
	list.numOfCustomers++;
}
int main(){
	Customer c;
	ListOfCustomers l;
	string name; 
	int k;
	
	inputListOfCustomer(l);
	cout <<"\n--------\n";
	outputListOfCustomers(l);
	
	cout <<"\n--------\n";
	deleteCustomerByName(l, "Nam");
	cout << "\nDanh sach khach hang sau khi xoa:\n";
	outputListOfCustomers(l);
	
	cout <<"\n--------\n";
	k = findCustomerByPhone(l, "0912345678");
	if(k == -1){
		cout << "\nKhong tim thay sodienthoai.";
	} else {
		cout << "\nKhach hang co sdt la: " << l.arrCustomers[k].name;
	}
	
	cout <<"\n--------\n";
	string sdt;
	cout << "\nNhap so dien thoai can xoa: ";
	cin >> sdt;
	deletePhone(l, sdt);
	cout << "\nDanh sach sdt sau khi xoa:\n";
	outputListOfCustomers(l);
	
	cout <<"\n--------\n";
	appendPhone(l, "An", "0989123456");
	for(int i = 0; i < l.numOfCustomers; i++){
		if(l.arrCustomers[i].name == "An"){
			cout << "\nDanh sach sau khi them sdt:\n";
			outputListOfCustomers(l);
		}
	}
	
	cout <<"\n--------\n";
	cout << "Nhap thong tin khach hang moi:\n";
	int i, n; string phone;
	inputCustomer(c);
	fflush(stdin);
	
	mergeCustomer(l, c);
	cout <<"\n--------\n";
	cout << "\nDanh sach sau khi bo sung:\n";
	outputListOfCustomers(l);

}
