#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string reverse (string normal)
{
	int len = normal.length ();
	string rStr = normal;
	for (int i = 0; i < len/2; i++)
	{
		char ch = rStr[len-1 - i];		
		rStr[len-1 - i] = rStr[i];
		rStr[i] = ch;
	}
	return rStr;
}

bool isStringFunny(string s)
{
	bool isFunny = true;
	string r = 	reverse(s);
	int ss,rr;
	
	for (int i = 1 ; i < s.length(); i++){
		ss = abs((int)s[i] - (int)s[i-1]);
		rr = abs((int)r[i] - (int)r[i-1]);
		
		if (ss != rr){
			isFunny = false;
			break;
		}
	}
	return isFunny;
}

int main(int argc, char *argv[]) {
	
	int n ;
	cin >> n;	
	
	while (n){
		string input ;
		getline(cin,input);
		cin >> input;

		cout << (isStringFunny(input) ? "Funny" : "Not Funny") << endl;
		n--;
	}
	return 0;
}