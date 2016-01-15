#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
	protected:
		string title;
		string author;
	public:
		Book(string t,string a){
			title=t;
			author=a;
		}
		virtual void display()=0;

};
//Write MyBook class
class MyBook:  public Book{
	protected:
		int price;
	public:
		MyBook(string t, string a, int p): Book(string t, string a){
			price = p;
		}
	
		void display(){
			cout << "Title: "<<title;
			cout << "Author: "<<author;
			cout << "Price: "<< price;
		}

};

int main(int argc, char *argv[]) {
	string title,author;
	int price;
	getline(cin,title);
	getline(cin,author);
	cin>>price;
	MyBook novel(title,author,price);
	novel.display();
	return 0;
}