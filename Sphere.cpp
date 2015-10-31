#include "Sphere.hpp"
#include <cmath>

using namespace rt;

Intersection Sphere::getIntersection(const Line& line,
                                     double minDist,
                                     double maxDist) {
  Intersection in;

  double t1 =
	  (0 - (line.dx())*(line.x0() - _center)
		- sqrt(
			(line.dx()*(line.x0() - _center))*(line.dx()*(line.x0() - _center))
			- (line.dx()*line.dx())*(((line.x0() - _center))*((line.x0() - _center)) - _radius*_radius)))
	  / (line.dx()*line.dx());

  double t2 =
	  (0 - (line.dx())*(line.x0() - _center)
		+ sqrt(
			(line.dx()*(line.x0() - _center))*(line.dx()*(line.x0() - _center))
			- (line.dx()*line.dx())*(((line.x0() - _center))*((line.x0() - _center)) - _radius*_radius)))
	  / (line.dx()*line.dx());

  bool valid1 = true;
  bool valid2 = true;

  if (isnan(t1) || t1 < minDist || t1 > maxDist){
	  valid1 = false;
  }

  if (isnan(t2) || t2 < minDist || t2 > maxDist){
	  valid2 = false;
  }

  if (valid1 && valid2){
	  return (t1 < t2) ? in = Intersection(valid1, *this, line, t1) : in = Intersection(valid2, *this, line, t2);
  }

  if (valid1){
	  in = Intersection(valid1, *this, line, t1);
  }

  return in = Intersection(valid2, *this, line, t2);
}

