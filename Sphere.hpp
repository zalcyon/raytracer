#include "Vector.hpp"
#include "Line.hpp"

#include "Geometry.hpp"
#include "Color.hpp"

#ifndef RT_SPHERE_INCLUDED
#define RT_SPHERE_INCLUDED

namespace rt {

  class Sphere : public Geometry {
  private:
    Vector _center;
    double _radius;

  public:
    Sphere(const Vector& center, double radius, const Material& material)
    : Geometry(material) {
      _center = Vector(center);
      _radius = radius;
    }

    Sphere(double x, double y, double z, double radius,
           double ar, double ag, double ab,
		   double dr, double dg, double db,
		   double sr, double sg, double sb,
		   double s, double o, double r)
    : Geometry (Material(Color(ar,ag,ab), Color(dr,dg,db), Color(sr,sg,sb), s, o, r)){
      _center = Vector(x, y, z);
      _radius = radius;
    }

    virtual Intersection getIntersection(const Line& line,
                                         double minDist,
                                         double maxDist);

    inline double& radius() {
      return _radius;
    }

    inline Vector& center() {
      return _center;
    }
  };
}

#endif
