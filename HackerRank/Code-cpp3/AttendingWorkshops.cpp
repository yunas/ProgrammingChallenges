#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <thread>
//#include <chrono>

using namespace std;



//Define the structs Workshops and Available_Workshops.
struct Workshop{
	public:
	long startingTime;
	long duration;
	long endingTime;

	Workshop(long st, long d, long et)
	{
		startingTime = st;
		duration = d;
		endingTime = et;
	}

};

struct Available_Workshops{
	public:
	int numberOfWorkshops ;
	vector<Workshop> workshops;
	

	Available_Workshops(int start_time[ ], int duration[ ],int n){
		numberOfWorkshops = n;
		workshops.reserve(numberOfWorkshops);
		for (int i = 0; i < numberOfWorkshops ; i++){
			workshops[i] = Workshop(start_time[i], duration[i], 0);
		}
	}
	
	Available_Workshops (const Available_Workshops &aWorkShop){
		numberOfWorkshops = aWorkShop.numberOfWorkshops;
		workshops.reserve(numberOfWorkshops);
		for (int i = 0; i < numberOfWorkshops ; i++){
			workshops[i] = Workshop(aWorkShop.workshops[i].startingTime, aWorkShop.workshops[i].duration, aWorkShop.workshops[i].endingTime) ;
		}
	}
	

};


//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize (int start_time[ ], int duration[ ], int N) {
	
	Available_Workshops aWorkshops = Available_Workshops(start_time, duration, N);
	return new Available_Workshops(aWorkshops);
}

int CalculateMaxWorkshops (Available_Workshops *ptr) {

	int numberOfWorkshops = 0;

	long currTime = 0;
	for (int i = 0 ; i < ptr->numberOfWorkshops; i++ ){
		Workshop ws = ptr->workshops[i];	
		if (currTime < ws.startingTime){
			numberOfWorkshops++;
			currTime += ws.duration;
		}
	}
	return numberOfWorkshops;
}



int main()
{
	int n;
	cin>>n;
	int start_time[n],duration[n];
	for(int i=0;i<n;i++)
	{
		cin>>start_time[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>duration[i];
	}
	
	Available_Workshops * ptr;
	ptr=initialize(start_time,duration,n);
	cout<<CalculateMaxWorkshops(ptr)<<endl;
	return 0;
}


