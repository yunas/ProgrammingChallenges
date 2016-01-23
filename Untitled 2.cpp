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

vector<long long int> pairs(vector<long long int> a) {
	
	vector<long long int> tmpArr(a.size());
	
	long long int minDiff = __INT_MAX__;

	for ( int i = 0; i < a.size()-1; i++){

			int diff = abs(a[i]-a[i+1]);

			if (minDiff > diff){
				minDiff = diff;
				tmpArr.clear();				
			}
			if (minDiff == diff){
				tmpArr.push_back(a[i]);
				tmpArr.push_back(a[i+1]);				
			}
	}
	sort(tmpArr.begin(), tmpArr.end());
	return tmpArr;
}



/* Tail starts here */
int main() {
	long long int size;
	cin >> size;
	vector<long long int> arr(size);
	long long int item;
	for(int i=0; i<size; i++) {
		cin >> item;
		arr[i] = item;
	}

	sort(arr.begin(), arr.end());
	vector<long long int> arrPairs;
	arrPairs = pairs(arr);
	for(int i=0; i<arrPairs.size(); i++) {
		cout << arrPairs[i] << " ";
	}
	
	return 0;
}

