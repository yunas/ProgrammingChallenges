#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


using namespace std;

void calculate(long num){
	long three,five,fifteen=0;
	three=(num-1)/3; // => (9/3) => 3
	five=(num-1)/5; // => (9/5) => 1
	fifteen=(num-1)/15; // => (9/15) => 0
		// 3*(3*(3+1)/2) + 5*(5*(5+1)/2) - 15*(0*(0+1/2))
		// 3*(12/2) + 5 * ()
		// 3*6
		// 18
	cout << 3*(three*(three+1)/2)+5*(five*(five+1)/2)-15*(fifteen*(fifteen+1)/2)<<endl;
//	cout << "3's  => "<<3*(three*(three+1)/2)<<endl;
//	cout << "5's  => "<<5*(five*(five+1)/2)<<endl;
//	cout << "15's => "<<15*(fifteen*(fifteen+1)/2)<<endl;

	
}

void calculateIteratively(long num){
	
	long sum = 0;
	for (int i = 0; i < num; i ++){
		if (i% 3 == 0 || i%5 == 0){
			sum +=i;
		}
	}
	cout<< sum <<endl;
}


int main(int argc, char *argv[]) {

		
	long N,num=0;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		cin>>num;
		calculateIteratively(num);
	}
		
	return 0;
}