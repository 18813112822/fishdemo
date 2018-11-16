#ifndef BATTERY_H
#define BATTERY_H

class CPoint;
class CBullet;

class CBattery{
private:
	CPoint* m_pLocation;
	int m_nSpeed;
	int m_nGoldNum;
	int m_nBulletNum;
	int m_nAttack;
public:
	CBattery(CPoint* pLocation, int nSpeed, int nGoldNum, int nBulletNum, int nAttack);
	~CBattery();
	int GetSpeed();
	void SetSpeed(int);
	int GetGoldNum();
	void AddGoldNum(int);
	int GetBulletNum();
	CBullet* Luanch(CPoint*);
	int GetAttack();
	void SetAttack(int);
};

#endif
