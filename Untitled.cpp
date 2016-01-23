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
#include <cfloat>

using namespace std;

long double calculatePointDifference (long double x1,long double y1, long double x2, long double y2 ){
	
//	 long double yDiff = pow ((y2 - y1), 2.0);
//	 long double xDiff = pow ((x2 - x1), 2.0);
//	 long double result = sqrt (yDiff-xDiff);
	long double result = hypot((y2 - y1), (x2 - x1));
	return result;
}

int main(int argc, char *argv[]) {
	/* Tail starts here */
	long long int size;
	cin >> size;

	vector<long double> xArr(size);
	vector<long double> yArr(size);
	long double x, y; 
	for(int i=0; i<size; i++) {
		cin >> x >> y;
		xArr[i] =x;
		yArr[i] =y;
	}

	long double maxDifference = DBL_MIN;
	for(int i=0; i<size; i++) {
		long double x1, y1; 
		x1 = xArr[i];
		y1 = yArr[i];
		for(int j=i; j<size; j++) {	
			long double x2, y2; 
			x2 = xArr[j];
			y2 = yArr[j];
			maxDifference = max(maxDifference,calculatePointDifference(x1,y1,x2,y2));
		}
	}
	cout.precision(6);
	cout << fixed << maxDifference << endl;
	
	return 0;
}