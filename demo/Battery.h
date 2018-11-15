#ifndef BATTERY_H
#define BATTERY_H

class CPoint;

class CBattery{
private:
	CPoint* m_CLocation;
	int m_nGoldNum;
	int m_nBulletNum;
public:
	CBattery(CPoint*);
	int GetGoldNum();
	void AddGoldNum(int);
	int GetBulletNum();
	void Luanch(CPoint*);
};

#endif
