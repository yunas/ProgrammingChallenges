#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<char> instersection(vector<char> &v1, vector<char> &v2)
{

	vector<char> v3;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

	return v3;
}


int main(int argc, char *argv[]) {
//	Make it Anagram
//cde
//abc
//4
	string input1,input2 ;
	
	getline(cin,input1);
	getline(cin,input2);

	vector<char> inputArr1(input1.begin(), input1.end());
	vector<char> inputArr2(input2.begin(), input2.end());
	auto v3 = instersection(inputArr1, inputArr2);
	
	cout << inputArr1.size()+inputArr2.size()- 2*v3.size();
	
	return 0;
}

