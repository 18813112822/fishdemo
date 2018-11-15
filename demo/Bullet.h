#ifndef BULLET_H
#define BULLET_H

class CPoint;

class CBullet{
private:
	CPoint* m_CLocation;
	CPoint* m_CDirection;
	int m_nSpeed;
	CBullet* m_CNextBullet;
	int m_nLaunchTime;
public:
	CBullet(CPoint*, CPoint*, int, int);
	CPoint* GetLocation();
	void SetLocation(CPoint*);
	CPoint* GetDirection();
	void SetDirection(CPoint*);
	int GetSpeed();
	CBullet* GetNextBullet();
	int GetLaunchTime();
};

#endif