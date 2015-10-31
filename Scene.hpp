#include "Geometry.hpp"
#include "Sphere.hpp"

using namespace rt;

int geometryCount = 7;

Geometry* scene[] = {
  /*new Sphere(-50, -25, 175, 30, 1, 0, 0),
  new Sphere(-10,   0, 100, 10, 1, 1, 0),
  new Sphere(  0,   0, 200, 40, 0, 1, 0),
  new Sphere(  0, -50, 200, 10, 1, 1, 1),
  new Sphere( 10,   0,  20,  5, 0, 1, 1),
  new Sphere(-70,   0, 100, 10, 1, 0, 1),
  new Sphere( 50,  25,  75, 50, 0, 0, 1)*/
	new Sphere(-50, -25, 175, 30,
					0.1, 0, 0 /*ambient*/,
					0.3, 0, 0 /*diffuse*/,
					0.5,0,0/*specular*/,
					10, 0, 0),
	new Sphere(-10, 0, 100, 10,
					0.1, 0.1, 0 /*ambient*/,
					0.3, 0.3, 0 /*diffuse*/,
					0.5,0.5,0 /*specular*/,
					10, 0, 0),
	new Sphere(0, 20, 180, 40,
					0, 0.1, 0 /*ambient*/,
					0, 0.3, 0 /*diffuse*/,
					0.5,0.5,0/*specular*/,
					196, 0, 0),
	new Sphere(0, -50, 200, 10,
					0.1, 0.1, 0.1 /*ambient*/,
					0.3, 0.3, 0.3 /*diffuse*/,
					0.5,0.5,0.5 /*specular*/,
					10, 0, 0),
	new Sphere(10, 0, 20, 5,
					0, 0.1, 0.1 /*ambient*/,
					0, 0.3, 0.3 /*diffuse*/,
					0,0.5,0.5 /*specular*/,
					10, 0, 0),
	new Sphere(-70, 0, 100, 10,
					0.1, 0, 0.1 /*ambient*/,
					0.3, 0, 0.3 /*diffuse*/,
					0.5,0,0.5 /*specular*/,
					10, 0, 0),
	new Sphere(50, 25, 75, 50,
					0, 0, 0.1 /*ambient*/,
					0, 0, 0.3 /*diffuse*/,
					0,0,0.5 /*specular*/,
					10, 0, 0),
};

