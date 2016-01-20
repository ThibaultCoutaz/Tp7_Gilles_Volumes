#include <algorithm>
#include <glut.h>
#include "Circle.h"

#pragma once
class Pixel
{
public:
	float x1, y1,z1;
	float size;//my pixel is a square anyway

	Pixel(){};
	Pixel(float,float,float,float);
	Pixel(point3);
	int IsInTotalCircle(point3,float);
	int IsInTotalCirclesIntersection(Circle, Circle);
	int IsInTotalCirclesUnion(Circle, Circle);
	int IsInTotalCirclesDifference(Circle, Circle);
	Pixel* Divide8Pixel();
	~Pixel();

	void DrawP();
};

