#include <cmath>

typedef long double ld;

const ld EPS = 1e-9;

inline bool isZero(ld number) {return number >= -EPS && number <= EPS;}

struct point
{
	ld x, y;
	point(ld wx = 0, ld wy = 0) : x(wx), y(wy) {}
};

inline ld scalar(point &a, point &b, point &c); //AB dot AC
inline ld dist(point &a, point &b); //AB length
inline ld cast_len(point &a, point &b, point &c); //length of AC casting to AB
inline point point_cast(point &a, point &b, point &c); //cast of C to AB
inline ld det(point &a, point &b, point&c); //length of AB cross AC
inline ld sgn(ld x); //sign of x
inline ld side(point &a, point &b, point &c); //side of C according to AB, 1 if on the left, -1 if on the right, 0 if colinear
inline ld triangle_surface(point &a, point &b, point &c); //surface of ABC triangle
inline ld dist_from_point_to_line(point &a, point &b, point &c); //distance from C to AB line 
inline ld dist_from_point_to_segment(point &a, point &b, point &c); //distance from C to AB line segment
inline point central_symmetry(point &s, point &a); //point B such that S is middle of AB
inline point axis_symmetry(point &a, point &b, point &c); //point D such that middle of CD crosses (and is perpendicular to) AB
inline point scale_point(point& origin, point& p, ld scale); //scale point according to origin
inline point lines_crossing(point &a, point &b, point &c, point &d); //point of AB and CD crossing
inline bool isPointColinear(point &a, point &b, point &c); //true if A, B and C are colinear
inline bool isPointInSegment(point &a, point &b, point &c); //true if segment AB contains C