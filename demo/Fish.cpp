#include "Point.h"
#include "Fish.h"
using namespace std;

CFish::CFish(){
	m_pLocation = nullptr;
	m_pDirection = nullptr;
	m_pNextFish = nullptr;
}

CFish::CFish(CPoint* pLocation, CPoint* pDirection, int nSpeed, int nRadii, int nHP, int nGoldNum, long long lLastCheckTime){
	m_pLocation = pLocation;
	m_pDirection = pDirection;
	m_nSpeed = nSpeed;
	m_nRadii = nRadii;
	m_nHP = nHP;
	m_lLastCheckTime = lLastCheckTime;
	m_pNextFish = nullptr;
	m_nGoldNum = nGoldNum;
}

CFish::~CFish(){
	if(m_pLocation != nullptr)
		delete m_pLocation;
	if(m_pDirection != nullptr)
		delete m_pDirection;
}

CPoint* CFish::GetLocation(){
	return m_pLocation;
}

void CFish::SetLocation(CPoint* pLocation)
{
	m_pLocation = pLocation;
}

CPoint* CFish::GetDirection(){
	return m_pDirection;
}

void CFish::SetDirection(CPoint* pDirection){
	m_pDirection = pDirection;
}

int CFish::GetSpeed(){
	return m_nSpeed;
}

int CFish::GetRadii(){
	return m_nRadii;
}

CFish* CFish::GetNextFish(){
	return m_pNextFish;
}

void CFish::SetNextFish(CFish* nextFish){
	m_pNextFish = nextFish; 
}

EIsLive CFish::DeleteHP(int attack){
	if(m_nHP > attack)
	{
		m_nHP -= attack;
		return EIL_Live;
	}
	else
	{
		m_nHP = 0;
		return EIL_Die;
	}
}

int CFish::GetGoldNum(){
	return m_nGoldNum;
}

long long CFish::GetLastCheckTime(){
	return m_lLastCheckTime;

}