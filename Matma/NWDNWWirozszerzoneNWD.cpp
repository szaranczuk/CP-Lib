#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
	return a / gcd(a,b) * b;
}

int gcd_ext(int a, int b, int& x, int& y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1 = 0, y1 = 0;
	int d = gcd_ext(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return d;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> a >> b;

	int x = 0, y = 0;

	cout << gcd(a, b) << " " << lcm(a, b) << " " << gcd_ext(a, b, x, y) << "\n";

	cout << x << " " << y << "\n";
}