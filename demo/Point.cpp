#include "Point.h"
#include <cmath>

CPoint::~CPoint(){

}

CPoint::CPoint(double x, double y){
	m_nX = x;
	m_nY = y;
}
	
void CPoint::setPoint(double x, double y){
	m_nX = x;
	m_nY = y;
}
	
double CPoint::GetX(){
	return m_nX;
}

double CPoint::GetY(){
	return m_nY;
}

double CPoint::GetDistance(CPoint* p1, CPoint* p2){
	return sqrt(pow(p1->GetX() - p2->GetX(), 2) + pow(p1->GetY() - p2->GetY(), 2));
}

void CPoint::Unit(){
	double len = sqrt(pow(m_nX, 2) + pow(m_nY, 2));
	m_nX = m_nX / len;
	m_nY = m_nY / len;
}