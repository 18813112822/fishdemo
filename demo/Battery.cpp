#include<stdio.h>
#include<time.h>
#include<windows.h>
#include <iostream>
#include "Point.h"
#include "Battery.h"
#include "Bullet.h"    
 
CBattery::CBattery(CPoint* pLocation, int nSpeed, int nGoldNum, int nBulletNum, int nAttack){
	m_pLocation = pLocation;
	m_nSpeed = nSpeed;
	m_nGoldNum = nGoldNum;
	m_nBulletNum = nBulletNum;
	m_nAttack = nAttack;
}

CBattery::~CBattery(){
	if(m_pLocation != nullptr)
		delete m_pLocation;
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

CBullet* CBattery::Luanch(CPoint* pClickLocation){
	if(m_nBulletNum > 0){
		--m_nBulletNum;
		CPoint* pLocation =  new CPoint(m_pLocation->GetX(), m_pLocation->GetY());
		CPoint* pDirection = new CPoint(pClickLocation->GetX() - m_pLocation->GetX(), pClickLocation->GetY() - m_pLocation->GetY());
		//std::cout << "Direction: " << pClickLocation->GetX() << ' ' << pClickLocation->GetY() << std::endl;
		pDirection->Unit();
		SYSTEMTIME sTime;
		GetLocalTime(&sTime);
		ULARGE_INTEGER fTime;
		SystemTimeToFileTime(&sTime,(FILETIME*)&fTime);
		long long lLastCheckTime = (long long) (fTime.QuadPart);
		CBullet* Cbullet = new CBullet(pLocation, pDirection, m_nSpeed, lLastCheckTime, m_nAttack);
		return Cbullet;
	}
	return nullptr;
}
