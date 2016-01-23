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


long long int findUniqueElement(vector <long long int> arr, long long int N ){
	map<long long int,long long int> histogram;

	for (int i = 0 ; i < N ; i++){
		long long int key = arr[i];
		if (histogram.count(key)){
			histogram[key] = histogram[key] + 1;
		}
		else{
			histogram[key] = 1;
		}
	}		

	for (int i = 0 ; i < N ; i++){
		long long int key = arr[i];
		if (histogram[key] == 1){
			return key;
		}
	}
	return -1;
}

/* Tail starts here */
int main() {
	long long int N;
	cin >> N;

	vector <long long int> arr(N);
	
	for(int i=0; i<N; i++) { cin >> arr[i]; }

	cout << findUniqueElement(arr, N);
	return 0;
}

//1 4 3 3 1 2
//6 6 4 4 
