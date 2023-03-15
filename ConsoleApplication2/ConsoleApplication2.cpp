#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct Toys {
	string name;
	int price;
	int minage, maxage;
	int count;
};

vector<Toys> arr;
void f1(int age){
	vector<Toys> mas = arr;

	for (int i = 0; i < mas.size(); i++) {
		if (age >= mas[i].minage and age <= mas[i].maxage) {
			cout << mas[i].name << " " << mas[i].price << " " << mas[i].minage << " " << mas[i].maxage << " " << mas[i].count << endl;
		}
	}
}
void f2() {
	int maxi = arr[0].price;
	string n;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].price > maxi) {
			maxi = arr[i].price;
			n = arr[i].name;
		}
	}
	cout << n << " " << maxi << endl;
}
void f3(int stoimost, int min_age, int max_age) {
	for (int i = 0; i < arr.size(); i++) {
		if ((arr[i].price <= stoimost and arr[i].minage <= min_age and arr[i].maxage >= max_age) || (arr[i].minage >= min_age and arr[i].minage <= max_age and arr[i].maxage >= max_age)) {
			cout << arr[i].name << endl;
		}
	}
}
int main(){
	setlocale(LC_ALL, "Ru");
	Toys t;
	ifstream fin("D:\\Input\\Input.txt");
	while (!fin.eof()) {
		fin >> t.name >> t.price >> t.minage >> t.maxage >> t.count;
		arr.push_back(t);
	}
	cout << "Что хотите узнать?" << endl;
	cout << "1 - названия игрушек, которые подходят ребёнку определенного возвраста" << endl;
	cout << "2 - стоимость и название самой дорогой игрушки" << endl;
	cout << "3 - название игрушки которая по стоимости не превышает Х рублей и подходит ребенку в возврасте от А до В" << endl;
	cout << "4 - Данные обо всех игрушках" << endl;
	int r;
	cin >> r;
	if (r == 1) {
		int age;
		cin >> age;
		f1(age);
	}
	else if (r == 2) {
		f2();
	}
	else if (r == 3) {
		int stoimost, max_age, min_age;
		cin >> stoimost >> min_age >> max_age;
		f3(stoimost, min_age, max_age);
	}
	else if (r == 4) {
		string line;
		ifstream in("D:\\Input\\Input.txt");
		if (in.is_open()) {
			while (getline(in, line)) {
				cout << line << endl;
			}
		}
		in.close();
	}
	else if (r > 4) {
		cout << "Такой команды не существует";
	}
	return 0;
}


//hyhyhyhyjukioln