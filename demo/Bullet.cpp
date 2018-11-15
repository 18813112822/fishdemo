#include "Bullet.h"
using namespace std;

CBullet::CBullet(){
	m_CLocation = nullptr;
	m_CDirection = nullptr;
	m_nSpeed = 0;
	m_lLastCheckTime = 0;
	m_CNextBullet = nullptr;
}


CBullet::CBullet(CPoint* CLocation, CPoint* CDirection, int nSpeed, long long LastCheckTime, int nAttack){
	m_CLocation = CLocation;
	m_CDirection = CDirection;
	m_nSpeed = nSpeed;
	m_lLastCheckTime = LastCheckTime;
	m_nAttack = nAttack;
	m_CNextBullet = nullptr;
}

CPoint* CBullet::GetLocation(){
	return m_CLocation;
}

void CBullet::SetLocation(CPoint* CLocation){
	m_CLocation = CLocation;
}

CPoint* CBullet::GetDirection(){
	return m_CDirection;
}

void CBullet::SetDirection(CPoint* CDirection){
	m_CDirection = CDirection;
}

int CBullet::GetSpeed(){
	return m_nSpeed;
}

CBullet* CBullet::GetNextBullet(){
	return m_CNextBullet;
}

void CBullet::SetNextBullet(CBullet* CNextBullet){
	m_CNextBullet = CNextBullet;
}

long long CBullet::GetLastCheckTime(){
	return m_lLastCheckTime;
}

int CBullet::GetAttack(){
	return m_nAttack;
}