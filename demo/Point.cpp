#include "Point.h"

CPoint::CPoint(int x, int y){
	m_nX = x;
	m_nY = y;
}
	
void CPoint::setPoint(int x, int y){
	m_nX = x;
	m_nY = y;
}
	
int CPoint::GetX(){
	return m_nX;
}

int CPoint::GetY(){
	return m_nY;
}