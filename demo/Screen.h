#ifndef SCRENN_H
#define SCREEN_H

class CPoint;
class CFish;
class CBattery;
class CBullet;

class CScreen{
private:
	CFish* m_pFirstFish;//首节点为空
	CFish* m_pLastFish;
	CBullet* m_pFirstBullet;//首节点为空
	CBullet* m_pLastBullet;
	CBattery* m_pBattery;
	int m_nLength;
	int m_nWidth;
public:
	CScreen();
	~CScreen();
	void LauchFish();
	void LaunchBullet(CPoint* pClickLocation);
	void Check();
	void Move();
	void Show();
	bool IsInScreen(CPoint*);
	bool LineIntersect(CPoint* pPointA, CPoint* pPointB, CPoint* pPointC, CPoint* pPointD);
	void Reflex(CPoint* pStartLocation, CPoint* pEndLocation, CPoint* pDirection);
	CBattery* GetBattery();
};

#endif