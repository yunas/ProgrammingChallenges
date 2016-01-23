#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>   // std::modulus, std::bind2nd

using namespace std;
/* Head ends here */

int MOD=1000000007;

long long int getXForIndex(vector <long long int> &xArr, vector <long long int> &yArr, long long int index, int a, int b, int c, int d, int e, int f, int g, int h);
long long int getYForIndex(vector <long long int> &xArr, vector <long long int> &yArr, long long int index, int a, int b, int c, int d, int e, int f, int g, int h);

//template <typename T>
//T modpow(T base, T exp, T modulus) {
//	base %= modulus;
//	T result = 1;
//	while (exp > 0) {
//		if (exp & 1) result = (result * base) % modulus;
//		base = (base * base) % modulus;
//		exp >>= 1;
//	}
//	return result;
//}

long long int modpow(long long int base, long long int exp, long long int modulus) {
	base %= modulus;
	long long int result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}


long long int getYForIndex(vector <long long int> &xArr, vector <long long int> &yArr, long long int index, int a, int b, int c, int d, int e, int f, int g, int h){
//yn−e+xn−f+xn−g+n⋅hn
	if (index >= 0){

		if (yArr[index] == -1)
		{
			long long int indexNE = index - e;
			long long int indexNF = index - f;		
			long long int indexNG = index - g;		
			
			long long int yNE = getYForIndex(xArr, yArr,indexNE, a,b,c,d,e,f,g,h);
			long long int xNF = getXForIndex(xArr, yArr,indexNF, a,b,c,d,e,f,g,h);
			long long int xNG = getXForIndex(xArr, yArr,indexNG, a,b,c,d,e,f,g,h);
			
//			long long int HD = fmod(index * fmod(pow (h,index),MOD),MOD)  ;			
//			long long int HD = fmod(index * (pow (h,index)),MOD)  ;						
			long long int HD = index * modpow(h, index, MOD) % MOD;
			
//			yArr[index] =	((yNE % MOD) + (xNF % MOD) + (xNG % MOD) + HD) % MOD;		
//			yArr[index] =	(yNE + xNF + xNG + HD);		
			yArr[index] =	fmod((yNE + xNF + xNG + HD), MOD);		
		}
		return yArr[index];
	}
		
	return 1;
}


long long int getXForIndex(vector <long long int> &xArr, vector <long long int> &yArr, long long int index, int a, int b, int c, int d, int e, int f, int g, int h) {

	if (index >= 0){
		
		if (xArr[index] == -1)
		{
			long long int indexNA = index - a;
			long long int indexNB = index - b;		
			long long int indexNC = index - c;		

			long long int xNA = getXForIndex(xArr, yArr,indexNA, a,b,c,d,e,f,g,h);
			long long int yNB = getYForIndex(xArr, yArr,indexNB, a,b,c,d,e,f,g,h);
			long long int yNC = getYForIndex(xArr, yArr,indexNC, a,b,c,d,e,f,g,h);
//			long long int ND = fmod(index * fmod(pow (d,index),MOD),MOD)  ;			
//			long long int ND = fmod(index * (pow (d,index)),MOD)  ;
			long long int ND = index * modpow(d, index, MOD) % MOD;									
//			xArr[index] = ((xNA % MOD) + (yNB % MOD) + (yNC % MOD) + ND) % MOD;
//			xArr[index] = (xNA + yNB + yNC+ ND);
			xArr[index] = fmod((xNA + yNB + yNC+ ND) , MOD);
		}
		return xArr[index];
	}			
	return 1;
}

/* Tail starts here */
int main() {
	long long int N;
	cin >> N;

	vector <int> a(N), b(N) , c(N) , d(N), e(N), f(N), g(N), h(N);
	vector <long long int> n(N);
	
	for(int i=0; i<N; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> f[i] >> g[i] >> h[i] >> n[i];
	}


	for (int i = 0 ; i < N ; i++){
		long long int size = n[i]+1;
		
		vector <long long int> xArr(size,-1);
		vector <long long int> yArr(size,-1);

		cout << getXForIndex(xArr, yArr, n[i], a[i], b[i], c[i], d[i], e[i], f[i], g[i], h[i]) << " " << getYForIndex(xArr, yArr, n[i], a[i], b[i], c[i], d[i], e[i], f[i], g[i], h[i]) << endl;
	}
//1 2 3 2 2 1 1 4 10
//1 2 3 4 5 6 7 8 90


	return 0;
}

