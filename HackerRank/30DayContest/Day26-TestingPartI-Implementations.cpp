#include <iostream>

using namespace std;


int calculateFine(){

	int d1, d2, m1, m2, y1, y2 ;
	cin >> d1 >> m1 >> y1;
	cin >> d2 >> m2 >> y2;	
	
	if (y1 > y2){
		return 10000;
	}
	else if (y1 == y2){
		if (m1 > m2){
			return 	(m1-m2)	* 500;
		}
		else if (m1 == m2){
			if (d1 > d2){
				return (d1-d2)*15;
			}
			else {
				return 0;
			}
		}
	}

	return  0;
}

int main(int argc, char *argv[]) {
	

	cout << calculateFine();
	return 0;	
}