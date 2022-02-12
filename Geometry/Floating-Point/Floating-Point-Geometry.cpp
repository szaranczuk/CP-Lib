#include "Floating-Point-Geometry.hpp"

//Mostly from lecture https://youtu.be/1C7fOJDmW-Y (in polish)

inline ld scalar(point &a, point &b, point &c) //AB dot AC
{
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

inline ld dist(point &a, point &b) //AB length
{
	return sqrtl(scalar(a, b, b));
}

inline ld cast_len(point &a, point &b, point &c) //length of AC casting to AB
{
	return scalar(a, b, c) / dist(a, b);
}

inline point point_cast(point &a, point &b, point &c) //cast of C to AB
{
	ld f = scalar(a, b, c) / scalar(a, b, b);
	return point(a.x + f * (b.x - a.x), a.y + f * (b.y - a.y));
}

inline ld det(point &a, point &b, point&c) //length of AB cross AC
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline ld sgn(ld x) //sign of x
{
	return x < -EPS ? -1.0 : (x > EPS ? 1.0 : 0.0);
}

inline ld side(point &a, point &b, point &c) //side of C according to AB, 1 if on the left, -1 if on the right, 0 if colinear
{
	return sgn(det(a, b, c));
}

inline ld triangle_surface(point &a, point &b, point &c) //surface of ABC triangle
{
	return fabsl(det(a, b, c)) / 2.0;
}

inline ld dist_from_point_to_line(point &a, point &b, point &c) //distance from C to AB line 
{
	return fabsl(det(a, b, c)) / dist(a, b);
}

inline ld dist_from_point_to_segment(point &a, point &b, point &c) //distance from C to AB line segment
{
	if (scalar(a, b, c) > 0.0 && scalar(b, a, c) > 0.0)
	{
		return dist_from_point_to_line(a, b, c);
	}
	return std::max(dist(a, c), dist(b, c));
}

inline point central_symmetry(point &s, point &a) //point B such that S is middle of AB
{
	return point(2.0 * s.x - a.x, 2.0 * s.y - a.y);
}

inline point axis_symmetry(point &a, point &b, point &c) //point D such that middle of CD crosses (and is perpendicular to) AB
{
	point q = point_cast(a, b, c);
	return central_symmetry(q, c);
}

inline void symmetry_line(point &a, point &b, point &p, point &q) //overwrites P and Q, such that PQ is perpendicular to AB, and divides AB into halves
{
	p = point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
	q = point((p.x + (b.y - a.y), p.y + (b.x - a.x)));
}

inline point rotation(point &origin, point &p, ld angle) //point p rotated by an angle, according to origin
{
	ld cosangle = cosl(angle);
	ld sinangle = sinl(angle);
	point v(p.x - origin.x, p.y - origin.y);
	return point(origin.x + v.x * cosangle - origin.y + v.y * sinangle,
		origin.x + v.x * cosangle + origin.y + v.y * sinangle);
}

inline point scale_point(point& origin, point& p, ld scale) //scale point according to origin
{
	return point(origin.x + (p.x - origin.x) * scale, origin.y + (p.y - origin.y) * scale);
}

inline point lines_crossing(point &a, point &b, point &c, point &d) //point of AB and CD crossing
{
	ld s1 = triangle_surface(a, c, d) + triangle_surface(b, c, d);
	ld s2 = triangle_surface(a, c, d);
	ld s3 = triangle_surface(b, c, d);
	if (isZero(s2))
	{
		return a;
	}
	else if (isZero(s3))
	{
		return b;
	}
	ld quotient = s2 / s1;
	return scale_point(a, b, quotient);
}

inline bool isPointColinear(point &a, point &b, point &c) //true if A, B and C are colinear
{
	return isZero(side(a, b, c));
}

inline bool isPointInSegment(point &a, point &b, point &c) //true if segment AB contains C
{
	return (scalar(a, b, c) > 0.0 && scalar(b, a, c) > 0.0 && isZero(side(a, b, c)));
}