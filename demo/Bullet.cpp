#include "Point.h"
#include "Bullet.h"

CBullet::CBullet(){
	m_pLocation = nullptr;
	m_pDirection = nullptr;
	m_nSpeed = 0;
	m_lLastCheckTime = 0;
	m_pNextBullet = nullptr;
}


CBullet::CBullet(CPoint* pLocation, CPoint* pDirection, int nSpeed, long long LastCheckTime, int nAttack){
	m_pLocation = pLocation;
	m_pDirection = pDirection;
	m_nSpeed = nSpeed;
	m_lLastCheckTime = LastCheckTime;
	m_nAttack = nAttack;
	m_pNextBullet = nullptr;
}

CBullet::~CBullet(){
	if(m_pDirection != nullptr)
		delete m_pDirection;
	
	if(m_pLocation != nullptr)
		delete m_pLocation;
}

CPoint* CBullet::GetLocation(){
	return m_pLocation;
}

void CBullet::SetLocation(CPoint* pLocation){
	m_pLocation = pLocation;
}

CPoint* CBullet::GetDirection(){
	return m_pDirection;
}

void CBullet::SetDirection(CPoint* pDirection){
	m_pDirection = pDirection;
}

int CBullet::GetSpeed(){
	return m_nSpeed;
}

CBullet* CBullet::GetNextBullet(){
	return m_pNextBullet;
}

void CBullet::SetNextBullet(CBullet* pNextBullet){
	m_pNextBullet = pNextBullet;
}

long long CBullet::GetLastCheckTime(){
	return m_lLastCheckTime;
}

int CBullet::GetAttack(){
	return m_nAttack;
}