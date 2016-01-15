#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateSum (vector <vector<int> > a, int i , int j) {
   	int sum = 0;

	sum = a[i][j]+ a[i][j+1]+ a[i][j+2];
	sum+= a[i+1][j+1];
	sum+= a[i+2][j]+a[i+2][j+1]+ a[i+2][j+2];

	return sum;
}



int main(){
	vector< vector<int> > arr(6, vector<int> (6));
	for(int arr_i = 0;arr_i < 6;arr_i++){
	   for(int arr_j = 0;arr_j < 6;arr_j++){
		  cin >> arr[arr_i][arr_j];
	   }
	}

	//LOGIC
	int maxSum = INT_MIN;
	for(int arr_i = 0;arr_i < 6-2;arr_i++){
	   for(int arr_j = 0;arr_j < 6-2;arr_j++){
		maxSum = max(maxSum,calculateSum(arr, arr_i, arr_j));  
	   }
	}
	cout << maxSum;
	return 0;
}


