#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
struct MyException : public exception
{
	protected:
	const char *errorMsg;

	public:
	MyException (const char* str){
		errorMsg = 	str;	
	}
	const char * what () const throw ()
	{
		return errorMsg;
	}
};

class Calculator
{
	public:
		
	int power(int n, int p){
		if ( n < 0 || p < 0){
			throw MyException("n and p should be non-negative");
		}
		return pow(n,p);
	}
};

int main()
{
	Calculator myCalculator=Calculator();
	try{
		int ans=myCalculator.power(2,-2);
		cout<<ans<<endl; 
	}
	catch(exception& e){
		 cout<<e.what()<<endl;
	}
	 
}