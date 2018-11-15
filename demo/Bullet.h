#ifndef BULLET_H
#define BULLET_H

class CPoint;

class CBullet{
private:
	CPoint* m_CLocation;
	CPoint* m_CDirection;
	int m_nSpeed;
	CBullet* m_CNextBullet;
	long long m_lLastCheckTime;
	int m_nAttack;
public:
	CBullet();
	CBullet(CPoint*, CPoint*, int, long long, int);
	CPoint* GetLocation();
	void SetLocation(CPoint*);
	CPoint* GetDirection();
	void SetDirection(CPoint*);
	int GetSpeed();
	CBullet* GetNextBullet();
	void SetNextBullet(CBullet*);
	long long GetLastCheckTime();
	int GetAttack();
};

#endif