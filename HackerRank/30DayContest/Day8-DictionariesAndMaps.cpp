#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef map<string, string> MyMap;

int main(int argc, char *argv[]) {

	long long int N;
	cin >> N;
	MyMap phoneBookMap;
	cin.ignore();	
	for(long long int i=0;i<N;i++)
	{
		string name;
		string phone;
		

		getline(std::cin, name);
		getline(std::cin, phone);
		if (name.length() > 0){
			phoneBookMap[name] = phone;	
		}
		
	}

//	for (MyMap::iterator ii = phoneBookMap.begin(); ii != phoneBookMap.end(); ++ii) {
//		cout << "[key] =>" << ii->first << " value => " << ii->second<< endl;
//	}

	string queryName;
	getline(std::cin, queryName);	
	
	do {
		if (queryName.length() > 0){
			if (phoneBookMap.count(queryName) > 0)
			{
				cout << queryName << "=" << phoneBookMap[queryName] << endl;								
			}else{
					cout <<"Not found" << endl;								
				}
			}
			else{
				cout <<"Not found" << endl;								
			}
			queryName = "";
		} while (getline(cin, queryName));

	return 0;
}