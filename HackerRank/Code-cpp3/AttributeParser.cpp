#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

stack<string> _stack;
typedef map<string, string> Tokenizer;
Tokenizer allTags;

string keyName;
string keyTags;

bool punct(char& c) {
	return ispunct(c);
}

bool isDoubleQoute(char &c){
	return c == '"' ? true : false; 
}

bool isSpace(char &c){
	return c == ' ' ? true : false; 
}


bool isStartingTag(string l){
	bool status = false;
	string startTag = "<tag";
	if (l.find(startTag) != std::string::npos){
			status = true;
	}
	return status;
}



bool isEndingTag(string l){
	bool status = false;
	string endTag = "</tag";
	if (l.find(endTag) != std::string::npos){
		status = true;
	}
	return status;
}

void removeTagOpener(string &l){
	int start = 1;
	size_t found;
	found = l.find_first_of(" ");
	l = l.substr(found, l.size() - found);	
//	cout << str;
}

void removeTagCloser(string &l){
	int start = 1;
	size_t found;
	found = l.find_first_of(">");
	l = l.substr(start, found - start);	
//	cout << str;
}

void removeDoubleQoutes(string &l){
	replace_if(l.begin(),l.end(), isDoubleQoute ,' ');
}

string ReplaceString(std::string subject, const std::string& search,
						  const std::string& replace) {
	size_t pos = 0;
	while((pos = subject.find(search, pos)) != std::string::npos) {
		 subject.replace(pos, search.length(), replace);
		 pos += replace.length();
	}
	return subject;
}

Tokenizer getValuesFromLine(string l){
	size_t found;
	int start = 0;
	vector<string> tokens;

	found = l.find_first_of("=");
	tokens.push_back(l.substr(start, found - start));	
	start = found;

	while (found != string::npos) {
		l[found]=' ';
		found=l.find_first_of("", found + 1);
		tokens.push_back(l.substr(start, found - start));
		start = found;
//		cout << found << endl;
	}
	
	Tokenizer tokenMap;
//	cout<< endl << " TOKENS ( " << tokens.size() << " )" << endl;
	for (int i = 0 ; i < tokens.size(); i+=2){
		string tokenKey = tokens[i];
		//token.replace(" ","");
		tokenKey = ReplaceString(tokenKey, " ", "");
		string tokenValue = tokens[i+1];
		tokenValue = ReplaceString(tokenValue, " ", "");

		tokenMap[tokenKey] = tokenValue;	
		string tmpKey = keyTags+"~"+tokenKey;
		allTags[tmpKey] = tokenValue;
	}

	return tokenMap;
}

Tokenizer getValuesFrom(string l){
	removeTagOpener(l);
	removeTagCloser(l);
//	cout << l << endl;
	removeDoubleQoutes(l);
//	cout << l << endl;
	return getValuesFromLine(l);
}

void addKeyTag(string key){
	if (keyTags.length() == 0){
		keyTags = key;
	}
	else{
		keyTags = keyTags + "."+ key;
	}
//	cout << "KEY TAG  => " << keyTags;
}

void removeKeyTag(string key){

	int start = 0;
	size_t found;
	found = keyTags.find_last_of(".");
	
	if (found){
		keyTags = keyTags.substr(start, found - start);
	}
	else{
		keyTags = "";
	}
}


void updateTagName(string &l){
	string startTag = "<tag";
	string endTag = "</tag";
	if (isStartingTag(l)) {
		
		int start = 1;
		size_t found;
		found = l.find_first_of(" ");
		string tagName = l.substr(start, found - start);	
		start = found;
//		cout << "tagName =>" << tagName;
		_stack.push(tagName);
		addKeyTag(tagName);
//		cout << endl << "GET VALUES FROM STRING " << endl;
		
		Tokenizer tokenMap = getValuesFrom(l);

//		for (Tokenizer::iterator ii = tokenMap.begin(); ii != tokenMap.end(); ++ii) {
//			cout << "[key] =>" << ii->first << " value => " << ii->second<< endl;
//		}

		
	}
	else if (isEndingTag(l)) {
//		cout << "Popping "<< _stack.top() << endl;
		_stack.pop();
	}
}

void parse(string l){
//	cout << endl;
	updateTagName(l);
}


int main(int argc, char *argv[]) {
	
	int nSequences, nQueries;
	cin >> nSequences >> nQueries;
	
	vector<string> hkSequences (nSequences);
	cin.ignore();
	for(int i=0;i < nSequences;i++)
	{
		
		string line;
		getline(std::cin, line);
		hkSequences[i] = line;
	}
	
//	cout << endl;
	
	for (int i = 0; i <  nSequences ; i++){
//		cout << hkSequences[i] << endl;
		parse(hkSequences[i]);
	}
	
	
//	cout << endl << endl;
//
//	for (Tokenizer::iterator ii = allTags.begin(); ii != allTags.end(); ++ii) {
//		cout << "Tokens[" << ii->first << "] => " << ii->second<< endl;
//	}

	string queryName;
	for (int i = 0; i < nQueries ; i++){

		getline(std::cin, queryName);	

		if (queryName.length() > 0){
			if (allTags.count(queryName) > 0)
			{
				cout << allTags[queryName] << endl;
			}else{
					cout <<"Not Found!" << endl;								
				}
			}
		else{
				cout <<"Not Found!" << endl;								
			}
		queryName = "";
	} 


//4 0
//<tag1 value = "HelloWorld">
//<tag2 name = "Name1">
//</tag2>
//</tag1>
}