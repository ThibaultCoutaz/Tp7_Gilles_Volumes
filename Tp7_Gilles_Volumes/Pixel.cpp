#include "Pixel.h"


Pixel::Pixel(float _x, float _y, float _z, float _size) :x1(_x), y1(_y), z1(_z), size(_size/2)
{
	
}

void Pixel::DrawP(){
	glColor3f((float)rand() / (RAND_MAX)+1, (float)rand() / (RAND_MAX)+1, (float)rand() / (RAND_MAX)+1);
	//Face face
	glBegin(GL_QUADS);
	glVertex3d(x1 - size, y1 - size, z1 - size);
	glVertex3d(x1 - size, y1 + size, z1 - size);
	glVertex3d(x1 + size, y1 + size, z1 - size);
	glVertex3d(x1 + size, y1 - size, z1 - size);


	//Face gauche
	glBegin(GL_QUADS);
	glVertex3d(x1 - size, y1 - size, z1 - size);
	glVertex3d(x1 - size, y1 - size, z1 + size);
	glVertex3d(x1 - size, y1 + size, z1 + size);
	glVertex3d(x1 - size, y1 + size, z1 - size);

	//Face bas
	glBegin(GL_QUADS);
	glVertex3d(x1 - size, y1 - size, z1 - size);
	glVertex3d(x1 + size, y1 - size, z1 - size);
	glVertex3d(x1 + size, y1 - size, z1 + size);
	glVertex3d(x1 - size, y1 - size, z1 + size);

	//Face Haut
	glBegin(GL_QUADS);
	glVertex3d(x1 - size, y1 + size, z1 - size);
	glVertex3d(x1 - size, y1 + size, z1 + size);
	glVertex3d(x1+size , y1 + size, z1+size);
	glVertex3d(x1 + size, y1 + size, z1 - size);

	//Face droite
	glBegin(GL_QUADS);
	glVertex3d(x1 + size, y1 - size, z1 - size);
	glVertex3d(x1 + size, y1 + size, z1 - size);
	glVertex3d(x1 + size, y1 + size, z1 + size);
	glVertex3d(x1 + size, y1 - size, z1 + size);

	//Face Font
	glBegin(GL_QUADS);
	glVertex3d(x1 - size, y1 - size, z1 + size);
	glVertex3d(x1 + size, y1 - size, z1 + size);
	glVertex3d(x1 + size, y1 + size, z1 + size);
	glVertex3d(x1 - size, y1 + size, z1 + size);
	glEnd();
}

/*Return if the pixel/Voxel is totally in the Circle
* Return the number of Vertices Inside
*/
int Pixel::IsInTotalCircle(point3 center,float rayon){
	int nbVerticesInside = 0;
	point3 p1(x1 - size, y1 - size, z1 - size);
	point3 p2(x1 - size, y1 + size, z1 - size);
	point3 p3(x1 + size, y1 + size, z1 - size);
	point3 p4(x1 + size, y1 - size, z1 - size);
	point3 p5(x1 - size, y1 - size, z1 + size);
	point3 p6(x1 - size, y1 + size, z1 + size);
	point3 p7(x1 + size, y1 + size, z1 + size);
	point3 p8(x1 + size, y1 - size, z1 + size);

	if ((p1 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p2 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p3 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p4 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p5 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p6 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p7 - center).lenght() < rayon)
		nbVerticesInside++;
	if ((p8 - center).lenght() < rayon)
		nbVerticesInside++;
	
	return nbVerticesInside;
}

/*Return if the pixel/Voxel is totally in the Intersection between two Circles
* Return the number of Vertices Inside
*/
int Pixel::IsInTotalCirclesIntersection(Circle c1,Circle c2){
	int nbVerticesInside = 0;
	point3 p1(x1 - size, y1 - size, z1 - size);
	point3 p2(x1 - size, y1 + size, z1 - size);
	point3 p3(x1 + size, y1 + size, z1 - size);
	point3 p4(x1 + size, y1 - size, z1 - size);
	point3 p5(x1 - size, y1 - size, z1 + size);
	point3 p6(x1 - size, y1 + size, z1 + size);
	point3 p7(x1 + size, y1 + size, z1 + size);
	point3 p8(x1 + size, y1 - size, z1 + size);

	if (c1.Inside(p1) && c2.Inside(p1))
		nbVerticesInside++;
	if (c1.Inside(p2) && c2.Inside(p2))
		nbVerticesInside++;
	if (c1.Inside(p3) && c2.Inside(p3))
		nbVerticesInside++;
	if (c1.Inside(p4) && c2.Inside(p4))
		nbVerticesInside++;
	if (c1.Inside(p5) && c2.Inside(p5))
		nbVerticesInside++;
	if (c1.Inside(p6) && c2.Inside(p6))
		nbVerticesInside++;
	if (c1.Inside(p7) && c2.Inside(p7))
		nbVerticesInside++;
	if (c1.Inside(p8) && c2.Inside(p8))
		nbVerticesInside++;

	return nbVerticesInside;
}


/*Return if the pixel/Voxel is totally in the Union between two Circles
* Return the number of Vertices Inside
*/
int Pixel::IsInTotalCirclesUnion(Circle c1, Circle c2){
	int nbVerticesInside = 0;
	point3 p1(x1 - size, y1 - size, z1 - size);
	point3 p2(x1 - size, y1 + size, z1 - size);
	point3 p3(x1 + size, y1 + size, z1 - size);
	point3 p4(x1 + size, y1 - size, z1 - size);
	point3 p5(x1 - size, y1 - size, z1 + size);
	point3 p6(x1 - size, y1 + size, z1 + size);
	point3 p7(x1 + size, y1 + size, z1 + size);
	point3 p8(x1 + size, y1 - size, z1 + size);

	if (c1.Inside(p1) || c2.Inside(p1))
		nbVerticesInside++;
	if (c1.Inside(p2) || c2.Inside(p2))
		nbVerticesInside++;
	if (c1.Inside(p3) || c2.Inside(p3))
		nbVerticesInside++;
	if (c1.Inside(p4) || c2.Inside(p4))
		nbVerticesInside++;
	if (c1.Inside(p5) || c2.Inside(p5))
		nbVerticesInside++;
	if (c1.Inside(p6) || c2.Inside(p6))
		nbVerticesInside++;
	if (c1.Inside(p7) || c2.Inside(p7))
		nbVerticesInside++;
	if (c1.Inside(p8) || c2.Inside(p8))
		nbVerticesInside++;

	return nbVerticesInside;
}

/*Return if the pixel/Voxel is totally in the Difference between two Circles
* Return the number of Vertices Inside
*/
int Pixel::IsInTotalCirclesDifference(Circle c1, Circle c2){
	int nbVerticesInside = 0;
	point3 p1(x1 - size, y1 - size, z1 - size);
	point3 p2(x1 - size, y1 + size, z1 - size);
	point3 p3(x1 + size, y1 + size, z1 - size);
	point3 p4(x1 + size, y1 - size, z1 - size);
	point3 p5(x1 - size, y1 - size, z1 + size);
	point3 p6(x1 - size, y1 + size, z1 + size);
	point3 p7(x1 + size, y1 + size, z1 + size);
	point3 p8(x1 + size, y1 - size, z1 + size);

	if (c1.Inside(p1) && !c2.Inside(p1))
		nbVerticesInside++;
	if (c1.Inside(p2) && !c2.Inside(p2))
		nbVerticesInside++;
	if (c1.Inside(p3) && !c2.Inside(p3))
		nbVerticesInside++;
	if (c1.Inside(p4) && !c2.Inside(p4))
		nbVerticesInside++;
	if (c1.Inside(p5) && !c2.Inside(p5))
		nbVerticesInside++;
	if (c1.Inside(p6) && !c2.Inside(p6))
		nbVerticesInside++;
	if (c1.Inside(p7) && !c2.Inside(p7))
		nbVerticesInside++;
	if (c1.Inside(p8) && !c2.Inside(p8))
		nbVerticesInside++;

	return nbVerticesInside;
}

Pixel* Pixel::Divide8Pixel()
{
	float _size = size/2;
	Pixel* ListPixel= new Pixel[8];
	ListPixel[0] = Pixel(x1 - _size, y1 - _size, z1 - _size, size);
	ListPixel[1] = Pixel(x1 - _size, y1 + _size, z1 - _size, size);
	ListPixel[2] = Pixel(x1 + _size, y1 + _size, z1 - _size, size);
	ListPixel[3] = Pixel(x1 + _size, y1 - _size, z1 - _size, size);
	ListPixel[7] = Pixel(x1 + _size, y1 - _size, z1 + _size, size);
	ListPixel[4] = Pixel(x1 - _size, y1 - _size, z1 + _size, size);
	ListPixel[5] = Pixel(x1 - _size, y1 + _size, z1 + _size, size);
	ListPixel[6] = Pixel(x1 + _size, y1 + _size, z1 + _size, size);

	return ListPixel;
}

Pixel::~Pixel()
{
}
