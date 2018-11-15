#ifndef POINT_H
#define POINT_H

class CPoint{
private:
	double m_nX;
	double m_nY;
public:
	CPoint(double x, double y);
	void setPoint(double x, double y);	
	double GetX();
	double GetY();
	void Unit();
	static double GetDistance(CPoint*, CPoint*);
};

#endif