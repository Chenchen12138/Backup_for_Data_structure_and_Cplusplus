#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class book
{
private:
	string bookname;
	string authorname;
	string ISBN;
	string price;
public:
	book(string name="no name",string author="no name",string number=0,string pr=0)
	{
		bookname=name;
		authorname=author;
		ISBN=nu;
		price=pr;
	}
	~book(){}

	string GetName();
	string GetAuthorname();
	string GetISBN();
	string GetPrice();

	void SetName(string name);
	void SetAuthorname(string author);
	void SetISBN(string number);
	void SetPrice(string pr);

	void writedata();
	void getdata();

	void display();
};

string book::GetName()
{
	return bookname;
}
string book::GetAuthorname()
{
	return authorname;
}
string book::GetISBN()
{
	return ISBN;
}
string book::GetPrice()
{
	return price;
}
void book::SetName(string name)
{
	bookname=name;
}
void book::SetAuthorname(string author)
{
	authorname=author;
}
void book::SetISBN(string number)
{
	ISBN=number;
}
void book::SetPrice(string pr)
{
	price=pr;
}

void book::writedata()//将图书信息写入文件
{
	char databuf[MaxSize] = { 0 };
	ofstream out;
	out.open("book.txt",ios::binary|ios::app)
	out.write(bookname.c_str(),128);
	out.write(authorname.c_str(),128);
	out.write(ISBN.c_str(),128);
	out.write(price.c_str(),128);
	out.close();
}
void book::getdata()//从文件中获取图书信息
{
	char Name[128];
	char Author[128];
	char Number[128];
	char Price[128];
	ifstream in("book.txt",ios::binary);
	in.seekg(128*4, ios::beg);
	in.read(Name, 128);
	if (in.tellg() > 0)
	{
		bookname = Name;
	}
	in.read(Author, 128);
	if (in.tellg() > 0)
	{
		authorname = Author;
	}
	in.read(Number, 128);
	if (in.tellg() > 0)
	{
		ISBN = Number;
	}
	in.read(Price, 128);
	if (in.tellg() > 0)
	{
		price = Price;
	}
	in.close();
}

void book::display()
{
	cout<<"Name:"<<bookname<<" "<<"Author:"<<authorname<<" "<<"ISBN:"<<ISBN<<" "<<"Price:"<<price<<endl;
}
