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
	CPoint* m_pLocation;
	CPoint* m_pDirection;
	int m_nSpeed;
	int m_nRadii;
	CFish* m_pNextFish;
	int m_nHP;
	int m_nGoldNum;
	long long m_lLastCheckTime;
public:
	CFish();
	CFish(CPoint* pLocation, CPoint* pDirection, int nSpeed, int nRadii, int nHP, int nGoldNum, long long LastCheckTime);
	~CFish();
	CPoint* GetLocation();
	void SetLocation(CPoint*);
	CPoint* GetDirection();
	void SetDirection(CPoint*);
	int GetSpeed();
	int GetRadii();
	CFish* GetNextFish();
	void SetNextFish(CFish*);
	EIsLive DeleteHP(int);
	int GetGoldNum();
	long long GetLastCheckTime();
};

#endif