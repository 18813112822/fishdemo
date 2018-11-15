#ifndef FISH_H
#define FISH_H

class CPoint;
class CFish;
enum EIsLive{
	EIL_Live,
	EIL_Die
};

class CFish{
private:
	CPoint* m_CLocation;
	CPoint* m_CDirection;
	int m_nSpeed;
	int m_nRadii;
	CFish* m_CNextFish;
	int m_nHP;
	int m_nLauchTime;
public:
	CFish();
	CFish(CPoint* CLocation, CPoint* CDirection, int nSpeed, int nRadii, int nHP, int nLauchTime);
	CPoint* GetLocation();
	void SetLocation(CPoint*);
	CPoint* GetDirection();
	void SetDirection(CPoint*);
	int GetSpeed();
	int GetRadii();
	CFish* GetNextFish();
	void SetNextFish(CFish*);
	EIsLive DeleteHP(int);
	int GetLaunchTime();
};

#endif