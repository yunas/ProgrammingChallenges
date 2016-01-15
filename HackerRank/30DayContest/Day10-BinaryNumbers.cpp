#include <iostream>

using namespace std;

long long int calculateBinary(long long int n){
	
	if (n == 0 || n == 1){
		cout << n;
		return n;
	}
	
	
	int remainder = n % 2;
	n = n/2;
//	calculateBinary(n);
//	cout << remainder;
//	return remainder;
	return remainder+10*calculateBinary(n);
}

int main(int argc, char *argv[]) {

	long long int N;
	cin>>N;	
	for ( int i = 0; i < N; i++)
	{
		long long int n ;
		cin >> n;
//		calculateBinary(n);
//		cout << endl;
		cout << calculateBinary(n)<<endl;
	}
	return 0; 	
}

