#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>   // std::modulus, std::bind2nd

using namespace std;
/* Head ends here */


long long int getSlicesCount(vector <long long int> arr , long long int N){

	long long int counterSlice = 0;
	long long int sumArr = 0;

	for (int i = 0 ; i < N ; i++){
		sumArr += arr[i];
	}		

	long long int sumSlice = 0;

	for (int i = 0 ; i < N ; i++){
		long long int sumSlice = arr[i];
		if (sumSlice == sumArr){
			counterSlice++;
//			cout << "Pair (i, j) => (" << i << " , " << i << ")" << endl;
		}
		
		for (int j = i+1 ; j < N; j++){
			sumSlice += arr[j];
			if (sumSlice == sumArr){
				counterSlice++;
//				cout << "Pair (i, j) => (" << i << " , " << j << ")" << endl;
			}
		}	
	}
	if (counterSlice > 0) return counterSlice;
	return -1;
}

/* Tail starts here */
int main() {
	long long int N;
	cin >> N;

	vector <long long int> arr(N);
	
	for(int i=0; i<N; i++) { cin >> arr[i]; }

	cout << getSlicesCount(arr, N);
	return 0;
}

//1 4 3 3 1 2
//6 6 4 4 
