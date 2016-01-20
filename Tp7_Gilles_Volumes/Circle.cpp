#include "Circle.h"

Circle::Circle(){ }

Circle::Circle(point3 c, float r/*, int _decoupage*/) :center(c), rayon(r){

	//AABB = new BEnglobante(point3(c.x - r, c.y - r, c.z - r), point3(c.x + r, c.y + r, c.z + r),r * 2 / _decoupage,_decoupage);
}


Circle::~Circle()
{
}

void Circle::DrawC(bool drawAABB){
	//if (drawAABB)
		//AABB->DrawEB(point3(0.5,1,0.5));
	//AABB->DrawCPixel(rayon,center);
}

bool Circle::Inside(point3 p){
	return (p - center).lenght() < rayon;
}
