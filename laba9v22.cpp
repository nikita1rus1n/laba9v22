#include <iostream>
#include <string>
#include <Windows.h>
#include <locale.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;


 namespace My {
class Exception
{
protected:
	int error;
public:
	Exception()
	{
		error = 0;
	}
	Exception(int err)
	{
		error = err;
	}
	~Exception()
	{

	};
	void Print()
	{
		if (this->error == 1)
		{
			cout << "Error! (only int)" << endl;
		}
		if (this->error == 2)
		{
			cout << "Error! (only double)" << endl;
		}if (this->error == 4)
		{
			cout << "Error! " << endl;
		}
	}
};

class Info {
public:
	string name;
	int age;

	Info()
	{
		this->name = "-";
		this->age = 0;
	}
	Info(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	Info(const Info& a)
	{
		this->name = a.name;
		this->age = a.age;
	}

	string getN() {
		return name;
	}
};


class MyClass {
public:
	int key;
	Info pr;
	MyClass()
	{
		this->key = 0;
	}
	MyClass(int key, Info pr)
	{
		this->key = key;
		this->pr = pr;
	}
	MyClass(const MyClass& a)
	{
		this->key = a.key;
		this->pr = a.pr;
	}

	~MyClass()
	{

	}

	 bool operator<(const MyClass& rv) const {
		 if (rv.key < this->key) {
			 return false;
		 }
		 else return true;
	}

	string getName() {
		return pr.getN();
		
	}
	int getKey() {
		return key;
	}

};
ostream& operator<<(ostream& out, const MyClass& a)
{
	out << "Ключ - " << a.key << endl;
	out << "Имя - " << a.pr.name << endl;
	out << "Возраст - " << a.pr.age << endl;
	return out;
}

int count(char c, MyClass temp) {
	int i,k=0;
	bool world=true;

	for (i = 0; i < temp.pr.name.length(); i++) {
		
		if (temp.pr.name[i] == c && world) {
			k++;
			world = false;
		}

		if (temp.pr.name[i] == ' ') {
			world = true;
		}
	}
	return k;
}
int countage(int agemin, MyClass temp) {
	if (temp.pr.age <= agemin) { return 1; }else return 0;

}

bool checkKey(MyClass temp, int key) {
	if (temp.key == key) { return true; }
	else return false;
}

int getKey(MyClass temp) {
	return temp.key;
}

}
int main()
{
	int i,k=0,temp=0,temp2=0;
	int key1, key2;
	setlocale(LC_ALL, "Russian");

	
	set <My::MyClass> st;

	My::Info inf("anime dsfsd sdffdss fagsf a",18);
	My:: MyClass test(1,inf);
	
	My::Info inf2("  daad sdffdss fagsf a ddddd aas ss d as", 25);
	My::MyClass test2(2, inf2);

	My::Info inf3("fdggdf dsf", 10);
	My::MyClass test3(3, inf3);
	
	st.insert(test); 
	st.insert(test2);
	st.insert(test3);
	set<My::MyClass>::iterator it;
	it = st.begin();
	cout << "Стек: " << endl;
	for (i = 0; i < 3; i++) {
		cout << *it;
		it++;
	}
	// алгоритм 1
	cout << "\nАлгоритм - 1:\n";
	
	it = st.begin();
	cout << *it;
	cout << "Слов с символом 'a' (ключ 1): " << My::count( 'a', *it) << endl;
	it++;
	cout << *it;
	cout <<"Слов с символом 's' (ключ 2): " << My::count('s', *it) << endl;
	it++;
	cout << *it;
	cout << "Слов с символом 't' (ключ 3): " << My::count('t', *it) << endl;

	// алгоритм 2
	cout << "\nАлгоритм - 2:\n";
	it = st.begin();
	k = 0;
	k=k+My::countage(18, *it);
	it++;
	k = k + My::countage(18, *it);
	it++;
	k = k + My::countage(18, *it);
	cout << "Возраст меньше 18 (включительно) у " << k <<" объектов стэка"<< endl;

	return 0;
}