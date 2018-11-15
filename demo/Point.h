#ifndef POINT_H
#define POINT_H

class CPoint{
private:
	int m_nX;
	int m_nY;

public:
	CPoint(int x, int y);
	void setPoint(int x, int y);	
	int GetX();
	int GetY();
};

#endif