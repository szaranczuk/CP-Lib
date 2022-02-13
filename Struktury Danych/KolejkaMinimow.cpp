#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Minqueue{
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;

	void insert(int v){
		v1.push_back({v, min(v, (v1.empty() ? v : v1.back().second))});
	} 

	void erase(){
		if(!v2.empty()) v2.pop_back();
		else{
			while(!v1.empty()){
				int v = v1.back().first; v1.pop_back();
				v2.push_back({v, min(v, (v2.empty() ? v : v2.back().second))});
			}
			v2.pop_back();
		}
	}

	int mini(){
		if(v1.empty() && v2.empty()) return 0;
		if(v2.empty()) return v1.back().second;
		if(v1.empty()) return v2.back().second;	
		return min(v1.back().second, v2.back().second);
	}
} q;

int main(){
	return 0;
}