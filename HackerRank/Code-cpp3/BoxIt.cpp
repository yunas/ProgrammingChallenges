#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;


class Box{
	public:
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
	long l,b,h;

// The class should have the following functions : 
// Constructors: 
// Box();
	Box(){
		l = b = h = 0;
		BoxesCreated++;
	}
// Box(int,int,int);
	Box (int length, int breadth, int height){
		l = length;
		b = breadth;
		h = height;
		BoxesCreated++;
	}
	// Box(Box);
	Box(Box &_box){
		l = _box.l;
		b = _box.b;
		h = _box.h;
		BoxesCreated++;		
	}
	
	// Destructor
	 ~Box()
	 {
		BoxesDestroyed++;
	 }
	
	 int getLength(){ 
		// Return box's length
	 	return l;
	 }
	 int getBreadth (){
		// Return box's breadth
		return b;	
	 } 
	 int getHeight (){
		//Return box's height
		return h;	
	 }	  
	
	 long long CalculateVolume(){
		// Return the volume of the box
	 	return l * b * h;
	 } 

	//Overload operator < as specified
	//bool operator<(Box &b)
	bool operator<(const Box &box){
//		Overload the operator < for the class Box. Box A < Box B if:
//		A.l < B.l
//		A.b < B.b and A.l==B.l
//		A.h < B.h and A.b==B.b and A.l==B.l
		
		if (l < box.l){
			return true;
		}
		if (b < box.b && l == box.l){
			return true;
		}
		if (h < box.h && b == box.b && l == box.l){
			return true;
		}
		return false;
	}


	//Overload operator << as specified
	//ostream& operator<<(ostream& out, Box B)
	friend ostream& operator<<(ostream& output, const Box B)
	{ 
		output <<B.l << " " << B.b << " "<<B.h ;
		return output;            
	}

};








void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
	{
	int type;
	cin>>type;
	if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser"<<endl;
		}
			else
			{
				cout<<"Greater"<<endl;
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	BoxesCreated = 0;
	BoxesDestroyed = 0;
	check2();
	cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}