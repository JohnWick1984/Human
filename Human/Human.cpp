#include <iostream>
#include <string>

using namespace std;

class Data {
	int day;
	string month;
	int year;

public:
	Data(int day, string month, int year) : day(day), month(month), year(year) {}

	void PrintData() {
		cout << day << " " << month << " " << year << endl;
	}
};

class Human {
private:
	static int count; // статическое поле для подсчета созданных объектов класса
	int ID;
	string LastName;
	string Name;
	string MiddleName;
	Data data;

public:
	Human(int ID, string LastName, string Name, string MiddleName, Data data) :
		ID(ID), LastName(LastName), Name(Name), MiddleName(MiddleName), data(data)
	{
		count++;
	}

	Human() : Human(0, "", "", "", Data(0, "", 0)) {} // конструктор по умолчанию

	Human(const Human& other) : ID(other.ID), LastName(other.LastName),
		Name(other.Name), MiddleName(other.MiddleName), data(other.data) // конструктор копирования
	{
		count++;
	}

	~Human() // деструктор
	{
		count--;
	}

	static int GetCount() // функция-член для подсчета созданных объектов класса
	{
		return count;
	}

	// сеттеры/геттеры для соответствующих полей класса
	void SetID(int ID) {
		this->ID = ID;
	}

	int GetID() const {
		return ID;
	}

	void SetLastName(string LastName) {
		this->LastName = LastName;
	}

	string GetLastName() const {
		return LastName;
	}

	void SetName(string Name) {
		this->Name = Name;
	}

	string GetName() const {
		return Name;
	}

	void SetMiddleName(string MiddleName) {
		this->MiddleName = MiddleName;
	}

	string GetMiddleName() const {
		return MiddleName;
	}

	void SetData(Data data) {
		this->data = data;
	}

	Data GetData() const {
		return data;
	}


	void PrintHuman()
	{
		cout << ID << " " << LastName << " " << Name << " " << MiddleName << " ";
		data.PrintData();
	}
};




int Human::count = 0;

int main()
{
	// Создание объектов класса Human
	Data data1(1, "January", 2000);
	Data data2(14, "February", 1985);
	Data data3(9, "May", 1984);
	Human human1(1, "Smith", "John", "Adamovich", data1);
	Human human2(2, "Doe", "Jane", "Romanovich", data2);
	Human human3(3, "Cook", "Niko", "Bitoff",data3);
	// Вывод информации о созданных объектах
	cout << "Number of Humans created: " << Human::GetCount() << endl << endl;

	human1.PrintHuman();
	cout << endl << endl;
	human2.PrintHuman();
	cout << endl << endl;
	human3.PrintHuman();

	return 0;
}