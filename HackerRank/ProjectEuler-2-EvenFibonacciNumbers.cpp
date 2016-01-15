#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int fibIteration(long long int n) {
	long long int x = 0, y = 1, z = 1;
	long long int sum = 0;
	for (long long int i = 0; z < n; i++) {
		x = y;
		y = z;
		z = x + y;
		if (z < n){
			if (z%2 == 0){
				sum +=z;
			}	
		}
		
	}
	return sum;
}

int main(int argc, char *argv[]) {

		
	long long int N;
	cin>>N;

	for(long long int i=0;i<N;i++)
	{
		long long int num;
		cin>>num;
		cout<<fibIteration(num)<<endl;

	}
		
	return 0;
}