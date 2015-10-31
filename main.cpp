#include <cmath>
#include <iostream>
#include <string>

#include "Vector.hpp"
#include "Line.hpp"
#include "Geometry.hpp"
#include "Sphere.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Intersection.hpp"
#include "Material.hpp"
#include "Light.hpp"

#include "Scene.hpp"

using namespace std;
using namespace rt;

double imageToViewPlane(int n, int imgSize, double viewPlaneSize) {
  double u = (double)n*viewPlaneSize/(double)imgSize;
  u -= viewPlaneSize/2;
  return u;
}

const Intersection findFirstIntersection(const Line& ray,
                                         double minDist, double maxDist) {
  Intersection intersection;

  for(int i=0; i<geometryCount; i++) {
    Intersection in = scene[i]->getIntersection(ray, minDist, maxDist);
    if(in.valid()) {
      if(!intersection.valid()) {
        intersection = in;
      }
      else if(in.t() < intersection.t()) {
        intersection = in;
      }
    }
  }

  return intersection;
}

int main(int argc, char* argv[]) {
  Vector viewPoint(0, 0, 0);
  Vector viewDirection(0, 0, 1);
  Vector viewUp(0, -1, 0);

  double frontPlaneDist = 2;
  double backPlaneDist = 1000;

  double viewPlaneDist = 90;
  double viewPlaneWidth = 160;
  double viewPlaneHeight = 90;

  int imageWidth = atoi(argv[1]);
  int imageHeight = atoi(argv[2]);

  Vector viewParallel = viewUp^viewDirection;

  viewDirection.normalize();
  viewUp.normalize();
  viewParallel.normalize();

  Image image(imageWidth, imageHeight);

  Color c;

  //Color only
  /*for (int ix = 0; ix < imageWidth; ix++)
  {
	  for (int iy = 0; iy < imageHeight; iy++)
	  {
		  Vector x0 = viewPoint;
		  Vector x1 = viewPoint + viewDirection*viewPlaneDist + viewUp*imageToViewPlane(iy, imageHeight, viewPlaneHeight)s + viewParallel*imageToViewPlane(ix, imageWidth, viewPlaneWidth);
		  Line ray = Line(x0, x1, false);
		  Intersection i = findFirstIntersection(ray, frontPlaneDist, backPlaneDist);
		  if (i.valid())
		  {
			  c = i.geometry().color();
			  image.setPixel(ix, iy, c);
		  }
	  }
  }*/

  Light l = Light(Vector(0,70,150), Color(1,1,1), Color(1, 1, 1), Color(1,1,1), 1);

  for (int ix = 0; ix < imageWidth; ix++)
  {
	  for (int iy = 0; iy < imageHeight; iy++)
	  {
		  Vector x0 = viewPoint;
		  Vector x1 = viewPoint + viewDirection*viewPlaneDist + viewUp*imageToViewPlane(iy, imageHeight, viewPlaneHeight) + viewParallel*imageToViewPlane(ix, imageWidth, viewPlaneWidth);
		  Line ray = Line(x0, x1, false);
		  Intersection i = findFirstIntersection(ray, frontPlaneDist, backPlaneDist);
		  if (i.valid())
		  {
			  Sphere* s = (Sphere*)i.sphere();
			  Material m = i.geometry().material();
			  Vector L = l.position();
			  Vector C = viewPoint;
			  Vector V = i.vec();
			  Vector S = s->center();
			  Vector N = V - S;
			  N.normalize();
			  Vector T = L - V;
			  T.normalize();
			  Vector E = C - V;
			  E.normalize();
			  Vector R = N*(N*T) * 2 - T;
			  R.normalize();
			  //printf("%f %f, %f\n", S.x(), S.y(), S.z());

			  c = m.ambient() * l.ambient();
			  if (N*T > 0)
			  {
				  c += m.diffuse() * l.diffuse() * (N*T);
			  }
			  if (E*R > 0)
			  {
				  c += m.specular() * l.specular() * pow(E*R, m.shininess());
			  }
			  c *= l.intensity();

			  image.setPixel(ix, iy, c);
		  }
	  }
  }

  image.store("scene.ppm");

  for(int i=0; i<geometryCount; i++) {
    delete scene[i];
  }

  return 0;
}

