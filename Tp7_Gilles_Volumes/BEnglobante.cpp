#include "BEnglobante.h"

BEnglobante::BEnglobante(point3 _p1, point3 _p2, int _step, int _nbStep, Circle* circles, int _nbCircle) : p1(_p1), p2(_p2), step(_step), nbStep(_nbStep), ListCircle(circles),nbCircle(_nbCircle){
	grid = new int **[nbStep];
	for (int i = 0; i < nbStep; i++){
		grid[i] = new int*[nbStep];
		for (int j = 0; j < nbStep; j++){
			grid[i][j] = new int[nbStep];
			for (int k = 0; k < nbStep; k++){
				grid[i][j][k] = 0;
			}
		}
	}
};

void BEnglobante::Draw(bool drawAABB)
{
	if (drawAABB)
		DrawEB(point3(0.5, 1, 0.5));
	for (int i = 0; i < nbCircle; i++){
		DrawCPixel(ListCircle[i]);
	}
	//DrawUnionCircle(ListCircle[0], ListCircle[1]);
	//DrawCircleDifferenceArbreOctaux(ListCircle[0], ListCircle[1]);
}

void BEnglobante::DrawEB(point3 color){
		glColor3f(color.x,color.y,color.z);
		glBegin(GL_LINES);
		for (int j = 0; j < nbStep+1 ; j++){
			for (int i = 0; i < nbStep+1; i++){
				glVertex3i(p1.x + i*step, p1.y, p1.z + j*step); glVertex3i(p1.x + i*step, p2.y, p1.z + j*step);
			}
		}

		glBegin(GL_LINES);
		for (int j = 0; j < nbStep+1 ; j++){
			for (int i = 0; i < nbStep+1 ; i ++){
				glVertex3i(p1.x, p1.y + i*step, p1.z + j*step); glVertex3i(p2.x, p1.y + i*step, p1.z + j*step);
			}
		}


		glBegin(GL_LINES);
		for (int j = 0; j < nbStep+1; j++){
			for (int i = 0; i < nbStep+1; i++){
				glVertex3i(p1.x + i*step, p1.y + j*step, p1.z); glVertex3i(p1.x + i*step, p1.y + j*step, p2.z);
			}
		}
		glEnd();

}

//To draw a circle
void BEnglobante::DrawCPixel(Circle c){

	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				point3 point(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2);
				if (c.Inside(point)){
					grid[i][j][k] = 1;
					p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
					p.DrawP();
				}
			}
		}
	}
}


bool BEnglobante::InPixel(point3 p,float r, point3 center){
	if ((p - center).lenght() < r) 
		return true;
	return false;
}

BEnglobante::~BEnglobante()
{
}


//**********************************************************************************************************************//
//***************************************Intersection Circles***********************************************************//

void BEnglobante::DrawIntersectionCircle(Circle c1,Circle c2)
{
	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				point3 point(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2);
				if (c1.Inside(point) && c2.Inside(point)){
					grid[i][j][k] = 1;
					p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
					p.DrawP();
				}
			}
		}
	}
}


//**********************************************************************************************************************//
//********************************************************Union Circles*************************************************//

void BEnglobante::DrawUnionCircle(Circle c1, Circle c2)
{
	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				point3 point(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2);
				if (c1.Inside(point) || c2.Inside(point)){
					grid[i][j][k] = 1;
					p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
					p.DrawP();
				}
			}
		}
	}
}


//**********************************************************************************************************************//
//***************************************Draw Circle Arbre Octaux*******************************************************//

void BEnglobante::DrawCircleArbreOctaux(Circle c)
{
	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
				ArbresOctaux(p, 5, c);
			}
		}
	}
}

void BEnglobante::ArbresOctaux(Pixel p,int recurance,Circle c){
	if (!(recurance < 0)){
		int tmp = p.IsInTotalCircle(c.center, c.rayon);
		if (tmp == 8){
			p.DrawP();
		}
		else if (tmp > 0)
		{
			Pixel* Points = p.Divide8Pixel();
			ArbresOctaux(Points[0], recurance - 1, c);
			ArbresOctaux(Points[1], recurance - 1, c);
			ArbresOctaux(Points[2], recurance - 1, c);
			ArbresOctaux(Points[3], recurance - 1, c);
			ArbresOctaux(Points[4], recurance - 1, c);
			ArbresOctaux(Points[5], recurance - 1, c);
			ArbresOctaux(Points[6], recurance - 1, c);
			ArbresOctaux(Points[7], recurance - 1, c);
			ArbresOctaux(Points[8], recurance - 1, c);
		}
	}
	else{
		p.DrawP();
	}
}


//**********************************************************************************************************************//
//***************************************Intersection with Arbre Octaux*************************************************//

void BEnglobante::DrawCircleIntersectArbreOctaux(Circle c1,Circle c2)
{
	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
				ArbresOctauxIntersect(p, 5, c1, c2);
			}
		}
	}
}

void BEnglobante::ArbresOctauxIntersect(Pixel p, int recurance, Circle c1, Circle c2){
	if (!(recurance < 0)){
		int tmp = p.IsInTotalCirclesIntersection(c1, c2);
		tmp += p.IsInTotalCirclesIntersection(c1, c2);
		if (tmp == 16){
			p.DrawP();
		}
		else if (tmp > 0)
		{
			Pixel* Points = p.Divide8Pixel();
			ArbresOctauxIntersect(Points[0], recurance - 1, c1,c2);
			ArbresOctauxIntersect(Points[1], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[2], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[3], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[4], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[5], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[6], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[7], recurance - 1, c1, c2);
			ArbresOctauxIntersect(Points[8], recurance - 1, c1, c2);
		}
	}
	else{
		p.DrawP();
	}
}


//**********************************************************************************************************************//
//***************************************Union with Arbre Octaux********************************************************//

void BEnglobante::DrawCircleUnionArbreOctaux(Circle c1, Circle c2)
{
	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
				ArbresOctauxUnion(p, 5, c1, c2);
			}
		}
	}
}

void BEnglobante::ArbresOctauxUnion(Pixel p, int recurance, Circle c1, Circle c2){
	if (!(recurance < 0)){
		int tmp = p.IsInTotalCirclesUnion(c1, c2);
		tmp += p.IsInTotalCirclesUnion(c1, c2);
		if (tmp == 16){
			p.DrawP();
		}
		else if (tmp > 0)
		{
			Pixel* Points = p.Divide8Pixel();
			ArbresOctauxUnion(Points[0], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[1], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[2], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[3], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[4], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[5], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[6], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[7], recurance - 1, c1, c2);
			ArbresOctauxUnion(Points[8], recurance - 1, c1, c2);
		}
	}
	else{
		p.DrawP();
	}
}

//**********************************************************************************************************************//
//***************************************Difference with Arbre Octaux***************************************************//

void BEnglobante::DrawCircleDifferenceArbreOctaux(Circle c1, Circle c2)
{
	Pixel p;
	for (int i = 0; i < nbStep; i++){
		for (int j = 0; j < nbStep; j++){
			for (int k = 0; k < nbStep; k++){
				p = Pixel(p1.x + i*step + step / 2, p1.y + j*step + step / 2, p1.z + k*step + step / 2, step);
				ArbresOctauxDifference(p, 5, c1, c2);
			}
		}
	}
}

void BEnglobante::ArbresOctauxDifference(Pixel p, int recurance, Circle c1, Circle c2){
	if (!(recurance < 0)){
		int tmp = p.IsInTotalCirclesDifference(c1, c2);
		tmp += p.IsInTotalCirclesDifference(c1, c2);
		if (tmp == 16){
			p.DrawP();
		}
		else if (tmp > 0)
		{
			Pixel* Points = p.Divide8Pixel();
			ArbresOctauxDifference(Points[0], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[1], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[2], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[3], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[4], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[5], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[6], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[7], recurance - 1, c1, c2);
			ArbresOctauxDifference(Points[8], recurance - 1, c1, c2);
		}
	}
	else{
		p.DrawP();
	}
}