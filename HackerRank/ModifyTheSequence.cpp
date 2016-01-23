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
using namespace std;
/* Head ends here */

long long int modifyTheSequence(vector<long long int> arr) {


	long long int moves = 0;	
	for (long long int i = 0; i < arr.size()-1; i++){

		if (arr[i] >=  arr[i+1]){
			if ((arr[i] >= arr[i+1]) && i == 0){
				arr[i] = 0;//arr[i]-1;
			}
			else{
				arr[i+1] = arr[i]+1;				
			}			
			moves ++;
		}

	}
	return moves;
	
}



/* Tail starts here */
int main() {

	long long int size;
	cin >> size;
	vector<long long int> arr(size);
	long long int item;
	for(long long int i=0; i<size; i++) {
		cin >> arr[i];
	}

	cout << modifyTheSequence(arr);
	return 0;
}

//5 2 2 3 4 
