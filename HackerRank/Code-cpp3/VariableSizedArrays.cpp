#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int nSequences, nQueries;
	cin >> nSequences >> nQueries;
	
	int **arr2D = new int*[nSequences];
	
	for (int i = 0; i < nSequences ; i++){
		int size ;
		cin >> size;
		int* arr = new int[size];
			for (int j = 0; j < size ; j++){
				cin >> arr[j];
			}
			arr2D[i] = arr;
	}
	
	
	for (int i = 0; i < nQueries; i++){
		int seq, query;
		cin >> seq >> query;
		cout << arr2D[seq][query] << endl;
	}
	return 0;
}