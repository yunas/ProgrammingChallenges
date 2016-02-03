#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
//	Jesse and the Rocks
//7 6
//4 3 7 6 7 2 2

	long long int n, strength, step;
	//vector <long long int> steps;
	bool isSkipped = false;
	cin >> n >> strength;
	long long int i = 0;
	for (i = 0; i < n ; i++){
		cin >> step;
		if (step > strength)
		{
			if (isSkipped) break;
			else if (isSkipped == false) isSkipped = true;
		}
	}
	cout << (isSkipped ? i-1 : i);
	return 0;
}

