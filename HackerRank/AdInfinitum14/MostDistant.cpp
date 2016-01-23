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


class Point
{
	public:
		long  double x;
		long  double y;
		Point(long double _x, long double _y){
			x=_x;
			y=_y;
		}
		
		void display(){
			cout<<" (x,y) => ("<<x <<","<<y <<")" <<endl;
		}
		
};

long double calculatePointDifference (Point *p1,Point *p2 ){
	
	 long double yDiff = pow ((p2->y - p1->y), 2.0);
	 long double xDiff = pow ((p2->x - p1->x), 2.0);
	 long double result = sqrt (yDiff-xDiff);
	return result;
}



int main(int argc, char *argv[]) {
	/* Tail starts here */
	long long int size;
	cin >> size;

	vector<int> arr2(size);
	vector<Point*> arr(size);
	 long double x, y; 
	for(int i=0; i<size; i++) {
		cin >> x >> y;
		arr[i] = new Point(x,y); 
	}

//	for(int i=0; i<size; i++) {
//		Point *p1 = arr[i];
//		p1->display();
//	}

	long double maxDifference = DBL_MIN;
	for(int i=0; i<size; i++) {
		Point *p1 = arr[i];
		for(int j=i; j<size; j++) {	
			Point *p2 = arr[j];
			maxDifference = max(maxDifference,calculatePointDifference(p1,p2));
		}
	}
	cout.precision(6);
	cout << fixed << maxDifference << endl;
	
	return 0;
}