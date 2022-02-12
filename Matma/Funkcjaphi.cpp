#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> phi;

vector<int> compute_phi(int n){
	vector<int> phi(n+1);
	for(int i=1;i<=n;i++) phi[i] = i;

	for(int i=2;i<=n;i++){
		if(phi[i] == i){
			for(int j=i;j<=n;j+=i){
				phi[j] -= phi[j] / i;
			}
		}
	}

	return phi;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	phi = compute_phi(n);

	for(int i=1;i<n;i++){
		cout << i << ": " << phi[i] << "\n"; 
	}

	return 0;
}