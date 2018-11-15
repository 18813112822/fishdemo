#include "Fish.h"
using namespace std;

CFish::CFish(){
	m_CNextFish = nullptr;
}

CFish::CFish(CPoint* CLocation, CPoint* CDirection, int nSpeed, int nRadii, int nHP, int nGoldNum, long long lLastCheckTime){
	m_CLocation = CLocation;
	m_CDirection = CDirection;
	m_nSpeed = nSpeed;
	m_nRadii = nRadii;
	m_nHP = nHP;
	m_lLastCheckTime = lLastCheckTime;
	m_CNextFish = nullptr;
	m_nGoldNum = nGoldNum;
}

CPoint* CFish::GetLocation(){
	return m_CLocation;
}

void CFish::SetLocation(CPoint* CLocation)
{
	m_CLocation = CLocation;
}

CPoint* CFish::GetDirection(){
	return m_CDirection;
}

void CFish::SetDirection(CPoint* CDirection){
	m_CDirection = CDirection;
}

int CFish::GetSpeed(){
	return m_nSpeed;
}

int CFish::GetRadii(){
	return m_nRadii;
}

CFish* CFish::GetNextFish(){
	return m_CNextFish;
}

void CFish::SetNextFish(CFish* nextFish){
	m_CNextFish = nextFish; 
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