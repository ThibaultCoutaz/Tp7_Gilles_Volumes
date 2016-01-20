#include "Pixel.h"
#include "Circle.h"

#pragma once
class BEnglobante
{
private:
	int *** grid;
	Circle *ListCircle;

public:
	point3 p1, p2,center;
	float step;
	int nbStep;
	int nbCircle;

	BEnglobante(){};
	BEnglobante(point3, point3, int, int,Circle*,int);
	void Draw(bool);
	void DrawEB(point3);
	void DrawCPixel(Circle);
	void DrawIntersectionCircle(Circle, Circle);
	void DrawUnionCircle(Circle, Circle);
	bool InPixel(point3, float, point3);

	void DrawCircleArbreOctaux(Circle);
	void ArbresOctaux(Pixel, int, Circle);
	void DrawCircleIntersectArbreOctaux(Circle, Circle);
	void ArbresOctauxIntersect(Pixel, int, Circle, Circle);

	void DrawCircleUnionArbreOctaux(Circle, Circle); 
	void ArbresOctauxUnion(Pixel, int, Circle, Circle);

	void DrawCircleDifferenceArbreOctaux(Circle, Circle);
	void ArbresOctauxDifference(Pixel, int, Circle, Circle);

	~BEnglobante();
};

