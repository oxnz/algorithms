#ifndef RECT_HPP
#define RECT_HPP

struct Point {
	double lat;
	double lon;
};

struct Size {
	double width;
	double height;
};

class Rect {
	double minLat;
	double maxLat;
	double minLon;
	double maxLon;
public:
	Rect(double lat, double lon, double width, double height)
	    : minLat(lat), maxLat(lat+width), minLon(lon), maxLon(lon+height) {}
	Rect(const Point& point, const Size& sz)
	    : Rect(point.lat, point.lon, sz.width, sz.height) {}
	bool contains(const Point& point) const {
		return point.lat >= minLat && point.lat <= maxLat
		        && point.lon >= minLon && point.lon <= maxLon;
	}
	bool contains(const Rect& rect) const {
		return !(rect.minLat < minLat || rect.minLon < minLon
		         || rect.maxLat > maxLat || rect.maxLon > maxLon);
	}
	bool disjoint(const Rect& rect) const {
		return (rect.maxLat < minLat || rect.maxLon < minLon
		        || rect.minLat > maxLat || rect.minLon > maxLon);
	}
};

bool rectContains(const Rect& rect, const Point& point) {
	return rect.contains(point);
}

bool rectDisjoint(const Rect& r1, const Rect& r2) {
	return r1.disjoint(r2);
}

bool rectWithin(const Rect& r1, const Rect& r2) {
	return r2.contains(r1);
}

bool rectCrosses(const Rect& r1, const Rect& r2) {
	return !(rectDisjoint(r1, r2) || rectWithin(r1, r2) || rectWithin(r2, r1));
}

bool rectIntersects(const Rect& r1, const Rect& r2) {
	return !rectDisjoint(r1, r2);
}

#endif // RECT_HPP
