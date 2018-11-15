#include<stdio.h>
#include<time.h>
#include<windows.h>
#include "Point.h"
#include "Battery.h"
#include "Bullet.h"    
 
CBattery::CBattery(CPoint* CLocation, int nSpeed, int nGoldNum, int nBulletNum, int nAttack){
	m_CLocation = CLocation;
	m_nSpeed = nSpeed;
	m_nGoldNum = nGoldNum;
	m_nBulletNum = nBulletNum;
	m_nAttack = nAttack;
}

int CBattery::GetSpeed(){
	return m_nSpeed;
}

void CBattery::SetSpeed(int nSpeed){
	m_nSpeed = nSpeed;
}

int CBattery::GetGoldNum(){
	return m_nGoldNum;
}

void CBattery::AddGoldNum(int nAddNum){
	m_nGoldNum += nAddNum;
}

int CBattery::GetBulletNum(){
	return m_nBulletNum;
}

CBullet* CBattery::Luanch(CPoint* CClickLocation){
	if(m_nBulletNum > 0){
		--m_nBulletNum;
		CPoint* CLocation =  new CPoint(m_CLocation->GetX(), m_CLocation->GetY());
		CPoint* CDirection = new CPoint(CClickLocation->GetX() - m_CLocation->GetX(), CClickLocation->GetX() - m_CLocation->GetY());
		CDirection->Unit();
		SYSTEMTIME sTime;
		GetLocalTime(&sTime);
		ULARGE_INTEGER fTime;
		SystemTimeToFileTime(&sTime,(FILETIME*)&fTime);
		long long lLastCheckTime = (long long) (fTime.QuadPart);
		CBullet* Cbullet = new CBullet(CLocation, CDirection, m_nSpeed, lLastCheckTime, m_nAttack);
		return Cbullet;
	}
	return nullptr;
}
