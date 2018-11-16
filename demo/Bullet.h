#ifndef BULLET_H
#define BULLET_H

class CPoint;

class CBullet{
private:
	CPoint* m_pLocation;
	CPoint* m_pDirection;
	int m_nSpeed;
	CBullet* m_pNextBullet;
	long long m_lLastCheckTime;
	int m_nAttack;
public:
	CBullet();
	CBullet(CPoint*, CPoint*, int, long long, int);
	~CBullet();
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