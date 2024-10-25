#include<iostream>
using namespace std;

class Student
{
	char* name;
	int age;
public:
	Student();
	Student(const char* n, int a);
	Student(const Student& obj);
	~Student();
	void Print();
	void Input();
	void SetName(const char* n);
	void SetAge(int a);
	char* GetName();
	int GetAge();
	Student& operator=(Student& b);
};

Student::Student()
{
	name = nullptr;
	age = 0;
}

Student::Student(const char* n, int a)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	age = a;
}

Student::Student(const Student& obj)
{
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;
}

Student::~Student()
{
	cout << "Destructor\n";
	delete[] name;
	age = 0;
}

void Student::Print()
{
	cout << "Name: " << name << " | Age: " << age << endl;
}

void Student::Input()
{
	char buff[80];
	cout << "Input student's name";
	cin >> buff;
	if (name != nullptr)
	{
		delete[] name;
	}
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
	cout << "Input student's age";
	cin >> age;
}

void Student::SetName(const char* n)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Student::SetAge(int a)
{
	age = a;
}

char* Student::GetName()
{
	return name;
}

int Student::GetAge()
{
	return age;
}

Student& Student::operator=(Student& b)
{
	if (this == &b)
	{
		return *this;
	}
	if (name != nullptr)
	{
		delete[] name;
	}
	name = new char[strlen(b.name) + 1];
	strcpy_s(name, strlen(b.name) + 1, b.name);
	age = b.age;
	return *this;
}

int main()
{
	Student s1("Ivan", 16);
	s1.Print();
	Student s2("Sofia", 21);
	s2.Print();
	s2 = s1;
	s2.Print();
}
