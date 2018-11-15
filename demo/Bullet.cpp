#include "Bullet.h"
using namespace std;

CBullet::CBullet(CPoint* CLocation, CPoint* CDirection, int nSpeed, int LaunchTime){
	m_CLocation = CLocation;
	m_CDirection = CDirection;
	m_nSpeed = nSpeed;
	m_nLaunchTime = LaunchTime;
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

int CBullet::GetLaunchTime(){
	return m_nLaunchTime;
}