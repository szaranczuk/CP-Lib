#include <iostream>

using namespace std;

#define N 1005

int n, m;
int inv[N];

int gcd_ext(int a, int b, int& x, int& y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = gcd_ext(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return d;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	inv[1] = 1;

	for(int i=2;i<=n;i++){
		inv[i] = m - (m/i) * inv[m%i]%m;
	}

	for(int i=1;i<=n;i++){
		int x = 0, y = 0;
		if(gcd_ext(i, m, x, y) != 1){
			cout << i << ": nie istnieje\n";
		}
		else{
			cout << i << ": " << inv[i] << " " << (x%m+m)%m << "\n";
		}
	}

	return 0;
}