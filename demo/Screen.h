#ifndef SCRENN_H
#define SCREEN_H

class CPoint;
class CFish;
class CBattery;
class CBullet;

class CScreen{
private:
	CFish* m_CFirstFish;//首节点为空
	CFish* m_CLastFish;
	CBullet* m_CFirstBullet;//首节点为空
	CBullet* m_CLastBullet;
	CBattery* m_CBattery;
	int m_nLength;
	int m_nWidth;
public:
	CScreen();
	void LauchFish();
	void LaunchBullet(CPoint* CClickLocation);
	void Check();
	void Move();
};

#endif