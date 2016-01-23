#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool punct(char& c) {
	return ispunct(c);
}

int main(int argc, char *argv[]) {
//	int n;
//	cin>>n;
//	string queryName;
//	getline(cin, queryName);		


//	string str("Replace the vowels in this sentence by asterisks.");
	
	
	string str("He is a very very good boy, isn't he?");
	size_t found;
	
	replace_if(str.begin(),str.end(), punct ,' ');
	
	cout << str << endl;
	int start = 0;
	vector<string> tokens;

//	found = str.find_first_of("aeiou");
	found = str.find_first_of(" [,?. \_'@+]!");
	tokens.push_back(str.substr(start, found - start));	
	start = found;

	while (found != string::npos) {
		str[found]=' ';
		found=str.find_first_of(" [,?. \_'@+]!", found + 1);
		tokens.push_back(str.substr(start, found - start));
		start = found;
		cout << found << endl;
	}
	
	cout<< endl << " TOKENS ( " << tokens.size() << " )" << endl;
	for (int i = 0 ; i < tokens.size(); i++){
		cout << tokens[i] << endl;
	}

	cout << str << endl;

	return 0;
}