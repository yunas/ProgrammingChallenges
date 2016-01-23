#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
	public:
		  virtual int divisorSum(int n)=0;
};


using namespace std;
class Calculator : public AdvancedArithmetic {
	//Write your code here
	public:
		int divisorSum(int n){
			int tmpN = n;
			int sum = 1;
			int i = 2;
			while (i <= n/2) {
				if (n%i == 0){
					sum += i;
				}
				i++;
			}
			
			if (n == 1){
				return sum;
			}
			
			return sum + n;	
		}
};

int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	AdvancedArithmetic *myCalculator=new Calculator(); 
	int sum=myCalculator->divisorSum(n);
	cout<<"I implemented: AdvancedArithmetic\n"<<sum;
	return 0;
}