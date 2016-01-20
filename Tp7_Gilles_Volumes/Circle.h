//#include "BEnglobante.h"
#include "struct.h"
//#include "Pixel.h"

#pragma once
class Circle
{
public:
	float rayon;
	point3 center;
	//BEnglobante *AABB;
	Circle();
	Circle(point3,float/*,int*/);

	void DrawC(bool);

	bool Inside(point3);

	~Circle();
};

