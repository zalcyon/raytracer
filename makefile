all:
	clang++ -Wall  -g -o raytracer Intersection.cpp Sphere.cpp main.cpp -std=c++1y -pedantic -O3
	
