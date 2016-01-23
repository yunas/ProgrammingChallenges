#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;
class Palindrome {
	//Write your code here
	public:
		stack<char> s;
		queue<char> que;
		
	Palindrome(){
		
	}

	void pushCharacter(char ch){
	//	Pushes a character onto a stack.
		s.push(ch);
	} 

	void enqueueCharacter(char ch){
	//: Enqueues a character in a queue.	
		que.push(ch);
	}
	
	void printStack(){
		cout << "printing stack"<< endl;
		while (!s.empty())
		{
			 cout << s.top() << " ";
			 s.pop();
		}
	}

	void printQueue(){

		cout << "printing queue"<< endl;
		while (!que.empty())
		{
			 cout << que.front() << " ";
			 que.pop();
		}
	}

	char popCharacter(){
		//: Pops and returns the top character.	
		char ch ;
		if (!s.empty()){
			ch = s.top();
			s.pop();
		}
		return ch;
	}

	char dequeueCharacter(){
	//: Dequeues and returns the first character.	
		char ch ;
		if (!que.empty()){
			ch = que.front();
			que.pop();
		}
		return ch;
	}

};

int main(int argc, char *argv[]) {
	string s;
		getline(cin, s);
		
	  	// create the Palindrome class object p.
		Palindrome p;
		
		// push all the characters of string s to stack.
		for (int i = 0; i < s.length(); i++) {
			p.pushCharacter(s[i]);
		}
		
		// enqueue all the characters of string s to queue.
		for (int i = 0; i < s.length(); i++) {
			p.enqueueCharacter(s[i]);
		}
		
		p.printQueue();
		p.printStack();
		
		bool f = true;
		
		// pop the top character from stack.
		// dequeue the first character from queue.
		// compare both the characters.
		for (int i = 0; i < s.length(); i++) {
			if (p.popCharacter() != p.dequeueCharacter()) {
				f = false;
				
				break;
			}
		}
		
		// finally print whether string s is palindrome or not.
		if (f) {
			cout << "The word, " << s << ", is a palindrome.";
		} else {
			cout << "The word, " << s << ", is not a palindrome.";
		}
		
		return 0;
}