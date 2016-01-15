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

void quickSort(vector <int> &arr, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
 
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
 
	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int pairs(vector<int> a, int k) {
   	int ans = 0;
	
	for ( int i = 0; i < a.size(); i++){
		for ( int j = i+1; j < a.size(); j++){
			
			int diff = abs(a[i]-a[j]);
			if (diff == k){
				ans++;
				break;
			}
			else if (diff >k){
				break;				
			}
		}
	}
	return ans;
}



/* Tail starts here */
int main() {
	int res;
	
	int _a_size,_k;
	cin >> _a_size>>_k;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	vector<int> _a;
	int _a_item;
	for(int _a_i=0; _a_i<_a_size; _a_i++) {
		cin >> _a_item;
		_a.push_back(_a_item);
	}

	quickSort(_a, 0, _a.size()-1);
	
	res = pairs(_a,_k);
	cout << res;
	
	return 0;
}

