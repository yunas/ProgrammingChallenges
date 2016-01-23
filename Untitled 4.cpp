#include <iostream>
#include <functional>   // std::modulus, std::bind2nd
#include <algorithm>    // std::transform
#include <cmath>

using namespace std;
// modulus example


template <typename T>
T modpow(T base, T exp, T modulus) {
	base %= modulus;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

int main(int argc, char *argv[]) {
	int numbers[]={1,2,3,4,5};
	int remainders[5];
//	transform (numbers, numbers+5, remainders, bind2nd(modulus<int>(),3));
		cout << modpow(2, 3, 3) << endl ;	
	for (int i=0; i<5; i++)

		std::cout << i << " is " << (fmod(i,2)==0?"even":"odd") << '\n';
	return 0;
	
}