#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int calculateBinary(long long int n,  long long int base){
	
	if (n == 0 || n == 1){
//		cout << n;
		return n;
	}
	
	
	int remainder = n % base;
	n = n/base;
//	calculateBinary(n);
//	cout << remainder;
//	return remainder;
	return remainder+10*calculateBinary(n,base);
}

vector <long long int> calculateBinaryForNegative(long long int val){
	vector <long long int> binArr (7);
	long long int i= 0;
	while (val != 1){
		long long int orgVal = val;
		val = ceil(val/-2.0);
		binArr[i++] = orgVal - (val * (-2));		
//		cout << binArr[i-1];
	}
	binArr[i++] = val;		
//	cout << binArr[i-1];
//	cout << endl;
	
	for (int j = 0 ; j < i; j++){
		cout << binArr[j] << " ";
	}

	return binArr;
			
			
			
			
}


long long int solution (vector <long long int> arr){
	
		long long int sum = 0;	
		for (int i = 0 ; i < arr.size();  i++){
			sum += arr[i]* pow(-2,i);
		}	
		
		calculateBinaryForNegative (sum*-1);
		return sum;
}

int main(int argc, char *argv[]) {

	long long int N, n;
	cin>>N;	
	long long int base = -2;
	vector <long long int> arr(N);

//	cout << calculateBinary(N,base) << endl;
//	return 0;
			
	for ( int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	solution(arr);
	return 0; 	
}

//1 0 0 1 1 
