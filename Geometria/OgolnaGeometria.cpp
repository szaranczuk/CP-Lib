#include <iostream>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> p;

inline long long det(p& a, p& b, p& c) { // det(AB, AC)
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

inline long long dot(p& a, p& b, p& c){ // dot(AB, CB)
	return (b.x-a.x)*(c.x-a.x)-(b.y-a.y)*(c.y-a.y);
}

inline bool in_rec(p& a, p& b, p& c){ // A in BC
	return min(b.x, c.x) <= a.x && a.x <= max(b.x, c.x) &&
	min(b.y, c.y) <= a.y && a.y <= max(b.y, c.y);
}

inline int sgn(long long v){ // sign
	return v > 0 ? 1 : v < 0 ? -1 : 0;
}

inline bool on_segment(p& a, p& b, p& c){ // A on BC
	return det(a, b, c) == 0 && in_rec(a, b, c);
}

inline bool in_triangle(p& s, p& a, p& b, p& c){ // S in ABC
	return abs(det(a, b, c)) == abs(det(s, a, b)) + abs(det(s, b, c)) + abs(det(s, c ,a));
}

bool do_segments_cross(p& a, p& b, p& c, p& d){ // AB with CD
	long long s1 = det(a, b, c);
	long long s2 = det(a, b, d);
	long long s3 = det(c, d, a);
	long long s4 = det(c, d, b);

	if(((s1<0&&s2>0)||(s1>0&&s2<0))&&((s3<0&&s4>0)||(s3>0&&s4<0))) return true;
	if(s1 == 0 && in_rec(c, a, b)) return true;
	if(s2 == 0 && in_rec(d, a, b)) return true;
	if(s3 == 0 && in_rec(a, c, d)) return true;
	if(s4 == 0 && in_rec(b, c, d)) return true;
	return false;
}