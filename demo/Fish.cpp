#include "Fish.h"
using namespace std;

CFish::CFish(){
}

CFish::CFish(CPoint* CLocation, CPoint* CDirection, int nSpeed, int nRadii, int nHP, int nLauchTime){
	m_CLocation = CLocation;
	m_CDirection = CDirection;
	m_nSpeed = nSpeed;
	m_nRadii = nRadii;
	m_nHP = nHP;
	m_nLauchTime = nLauchTime;
	m_CNextFish = nullptr;
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

int CFish::GetLaunchTime(){
	return m_nLauchTime;

}