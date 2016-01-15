#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

vector<int> calculateZ(string input) {
	
	int n = (int) input.length();
	vector<int> Z(n);
	
	int left = 0;
	int right = 0;
	for(int k = 1; k < input.length(); k++) {
		if(k > right) {
			left = right = k;
			while(right < input.length() && input[right] == input[right - left]) {
				right++;
			}
			Z[k] = right - left;
			right--;
		} else {
			//we are operating inside box
			int k1 = k - left;
			//if value does not stretches till right bound then just copy it.
			if(Z[k1] < right - k + 1) {
				Z[k] = Z[k1];
			} else { //otherwise try to see if there are more matches.
				left = k;
				while(right < input.length() && input[right] == input[right - left]) {
					right++;
				}
				Z[k] = right - left;
				right--;
			}
		}
	}
	return Z;
}

int main(int argc, char *argv[]) {
	int t;
	cin >> t;
	string s;
	for (int i=0;i<t;i++) {
		//scanf("%s",s);
		cin >> s;
		vector<int> z = calculateZ(s);//z_function(s);
		long long sum = s.length();
		long long zSize = z.size();
		for (int i = 0; i < zSize ; i++){
			sum +=z[i];
		}
		cout << sum <<endl;
	}
	return 0;
}