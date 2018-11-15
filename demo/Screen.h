#ifndef SCRENN_H
#define SCREEN_H

class CPoint;
class CFish;
class CBattery;
class CBullet;

class CScreen{
private:
	CFish* m_CFirstFish;//�׽ڵ�Ϊ��
	CFish* m_CLastFish;
	CBullet* m_CFirstBullet;//�׽ڵ�Ϊ��
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