#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrimeNumber (long long int n){
	bool status = true;
	long int sqVal= sqrt (n);

	if (n== 1) {status = false; }
	else if (sqVal * sqVal == n){ status = false; } 
	else{

		for(long long int i=2; i<sqVal;i++)
		{
			if(n%i==0)
			{
				status = false;
				break;
			}
		}
	}
	

	return status;
}
	
int main(int argc, char *argv[]) {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
		
		
		int N;
			cin>>N;	
			for ( int i = 0; i < N; i++)
			{
				long long int n ;
				cin >> n;
				if (isPrimeNumber(n)){
					cout << "Prime" << endl;            
				}
				else{
					cout << "Not prime" << endl;
				}
			}
			return 0; 	
}

