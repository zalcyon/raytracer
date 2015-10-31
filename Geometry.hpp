#include "Material.hpp"
#include "Vector.hpp"
#include "Line.hpp"
#include "Intersection.hpp"

#ifndef RT_GEOMETRY_INCLUDED
#define RT_GEOMETRY_INCLUDED

namespace rt {

  class Geometry {
  private:

    Material _material;

  public:
    Geometry(const Material& material): _material(material) { }

    Geometry(const Geometry& geometry): _material(geometry._material) {}
    virtual ~Geometry(void) {}

    virtual Intersection getIntersection(const Line& line,
                                         double minDist,
                                         double maxDist) {
      Intersection in(false, *this, line, 0);
      return in;
    };

    inline Material material() const {
      return _material;
    }
  };
}

#endif
