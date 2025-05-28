#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

template <typename T>
class Package
{
private:
	T item;
public:
	Package(T i) : item(i)
	{

	}

	void label()
	{
		cout << "Generic package containing: " << typeid(T).name() << endl;
	}
};

template <>
class Package <string>
{
private:
	string item;
public:
	Package(string i) : item(i)
	{

	}

	void label()
	{
		cout << "Book package: " << item << endl;
	}
};

template <typename T>
class Package <T*>
{
private:
	T* item;
public:
	Package(T* i) : item(i)
	{

	}

	void label()
	{
		cout << "Fragile package for pointer to type: " << typeid(T).name() << endl;
	}
};

template <typename T, int Size>
class Box
{
private:
	array <T, Size> items;
	int count = 0;
public:
	bool addItem(const T& item)
	{
		if (count < Size)
		{
			items[count++] = item;
			cout << "Item added to box: " << item << endl;
			return true;
		}
		return false;
	}

	void printItems() const
	{
		cout << "Box contents: " << endl;
		for (int i = 0; i < count; i++)
		{
			cout << "- " << items[i] << endl;
		}
	}
};

template <typename T>
void shipItem(const T& item)
{
	cout << "Shipping item of type: " << typeid(T).name() << endl;
}

template<>
void shipItem(const double& item)
{
	cout << "Shipping temperature-controlled item: " << item << "°C" << endl;
}

template<typename T>
T itemInput(T item)
{
	cout << "Enter new item. " << endl;
	cin >> item;
	cin.ignore(255, '\n');
	cin.sync();
	cin.clear();
	return item;
}

int main()
{
	Package<int> genItem{ 5 };
	Package<string> bookItem{ "Book" };
	double fragileItem = 22.5;
	Package<double*> fragItem { &fragileItem };
	Box <string, 3> bookBox;
	string book1;
	string book2;
	string book3;

	genItem.label();
	bookItem.label();
	fragItem.label();

	book1 = itemInput(book1);
	book2 = itemInput(book2);
	book3 = itemInput(book3);

	bookBox.addItem(book1);
	bookBox.addItem(book2);
	bookBox.addItem(book3);

	bookBox.printItems();

	shipItem(genItem);
	shipItem(bookItem);
	shipItem(fragItem);
}