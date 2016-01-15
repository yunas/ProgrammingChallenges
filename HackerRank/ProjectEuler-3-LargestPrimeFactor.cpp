#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main(int argc, char *argv[]) {

		
	long long int N;
	cin>>N;

	for(long long int i=0;i<N;i++)
	{
		long int a,b,n;
		
		cin>>a;
		cin>>b;
		cin>>n;		
		long int sum = 0;
		for (int i= 0 ; i < n; i++){
			sum +=  (pow(2,i)*b);
			cout << a + sum <<" "; 		
		}
		cout << endl;
	}
		
	return 0;
}