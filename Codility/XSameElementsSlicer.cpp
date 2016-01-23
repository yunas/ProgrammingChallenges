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


long long int solution(int X, vector<int> &A) {

	long long int counterSlice = 0;
	long long int histogramCountX = 0;

	long long int histogramCountD = 0;
	long long int histogramCountRX = 0;
	
	long long int N = A.size();

	for (long long int i = 0 ; i < N ; i++){
		if (A[i] == X){
			histogramCountX++;
		}		
	}		
	
	if (histogramCountX == 0 || histogramCountX > N/2){
		return 0;
	}


	histogramCountRX = histogramCountX;
	
	long long int k = N-1;
	for ( k = N-1 ; k >= N/2 ; k--){
		if (A[k] == X){
			histogramCountRX--;
		}	
		else{
			histogramCountD++;
		}
		
		if (histogramCountRX == histogramCountD){
			counterSlice = k;
			break;
		}
	}

	
 	return counterSlice;
}

/* Tail starts here */
int main() {
	long long int N;
	int X;
	cin >> X >> N;

	vector <int> arr(N);
	
	for(int i=0; i<N; i++) { cin >> arr[i]; }

	cout << solution(X, arr) ;
	return 0;
}

// 5 5 1 7 2 3 5
// 5 5 5 7 2 3 5
// 5 5 7 2 3 5
//1 4 3 3 1 2
//6 6 4 4 
