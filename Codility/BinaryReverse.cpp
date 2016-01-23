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

vector <int> calculateBinaryForNegative(long long int val, long long int N){
	vector <int> binArr (N);
	long long int i= 0;
	while (val != 1){
		long long int orgVal = val;
		val = ceil(val/-2.0);
		binArr[i++] = orgVal - (val * (-2));		
	}
	binArr[i++] = val;		
	
	if (i != N){
		//just for formatting
		vector <int> binArrFormatted (i);		
		for ( int j = 0; j < N; j++)
		{
			binArrFormatted[j] = binArr[j];
		}
		return binArrFormatted;
	}	
	return binArr;
}


vector<int> solution(vector<int> &A) {
	
		long long int sum = 0;	
		for (long long int i = 0 ; i < A.size();  i++){
			sum += A[i]* pow(-2,i);
		}	
		vector<int> binArr = calculateBinaryForNegative (sum*-1, A.size()+1);
		return binArr;
}

int main(int argc, char *argv[]) {

	long long int N, n;
	cin>>N;	
	long long int base = -2;
	vector <int> arr(N);

//	cout << calculateBinary(N,base) << endl;
//	return 0;
			
	for ( int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	vector<int> binArr = solution(arr);
	for (int j = 0 ; j < binArr.size(); j++){
		cout << binArr[j] << " ";
	}

	
	return 0; 	
}

// 1 0 0 1 1 
// 1 0 0 1 1 1 