#include <iostream>

using namespace std;

int f( int x , int y )
{
	int delta = x - y;

	if( y > delta )
		return 2 * ( ( y - delta ) / 3 ) + delta;
	else
		return delta - 2 * ( ( delta - y ) / 4 );
}

int main(int argc, char *argv[]) {
	cout << f(2,2);	
}