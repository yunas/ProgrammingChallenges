#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int ProfessorCreated, StudentCreated;

using namespace std;

class Person{
	public:
	int age;
	string name;
	
	virtual void getdata()=0;
	virtual void
	 putdata() = 0;
};

class Professor: public Person{
	public:
	int publications;
	int cur_id;
	
//	Professor(){
//		ProfessorCreated++;
//	}
	
	void getdata(){
		cin >> name;
		cin >> age;
		cin >> publications;
		cur_id = ProfessorCreated++;
	} 
	
	void putdata(){
		cout << name << " " << age << " " << publications << " " << cur_id+1 << endl;
	}
};

class Student: public Person{
	
	public:
		vector<long> marks ;
		int cur_id;
		
		Student(){
			marks.reserve (6);
//			StudentCreated++;
		}
		
		void getdata(){
			cin >> name;
			cin >> age;
			for (int i = 0 ; i < 6 ; i++){
				cin >> marks[i];	
			}
			cur_id = StudentCreated++;
		} 
		
		void putdata(){

			long sum = 0;
			for (int i = 0 ; i < 6 ; i++){
				sum += marks[i];	
			}	
			cout << name << " " << age << " " << sum << " "<< cur_id+1 << endl;
		}
		
	
};



int main(){

	int n, val;
	cin>>n; //The number of objects that is going to be created.
	Person *per[n];

	for(int i = 0;i < n;i++){

		cin>>val;
		if(val == 1){
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for(int i=0;i<n;i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}

//1
//1
//Walter 56 99
//2
//Jesse 18 50 48 97 76 34 98
//2
//Pinkman 22 10 12 0 18 45 50
//1
//White 58 87¬

//1
//2
//Jesse 18 50 48 97 76 34 98
