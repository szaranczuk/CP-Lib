#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define f first
#define s second
#define x first
#define y second
#define N 1005

typedef pair<long long, long long> p;

int n;
bool col;
pair<p, int> pt[N];
p start;
vector<int> hull;

inline long long det(p& a, p& b, p& c) {
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

inline long long det2(p& a, p& b, p& c){
	return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
}

inline long long dist(p& a, p& b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

inline bool check(p& a, p& b, p& c, bool col){
	long long o = det2(a, b, c);
	return o < 0 || (col && o == 0);
}

auto cmp = [] (pair<p, int>& a, pair<p, int>& b){
	long long o = det(start, a.f, b.f);
	if(o != 0) return o > 0;
	return dist(start, a.f) < dist(start, b.f);
};

void convex_hull(bool col){
	if(col){
		int i = n-1;
		while(i >= 0 && det(pt[0].f, pt[i].f, pt[n-1].f) == 0) i--;
		reverse(pt+i+1, pt+n);
	}

	for(int i=0;i<n;i++){
		while(hull.size() > 1 && !check(pt[hull[hull.size()-2]].f, pt[hull.back()].f, pt[i].f, col)) hull.pop_back();
		hull.push_back(i);
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> col;

	for(int i=0;i<n;i++){
		cin >> pt[i].f.x >> pt[i].f.y;
		pt[i].second = i;
		if(start > pt[i].f) start = pt[i].f;
	}

	sort(pt, pt+n, cmp);

	convex_hull(col);

	for(int i=0;i<(int)hull.size();i++){
		cout << pt[hull[i]].second << " ";
	}

	return 0;
}