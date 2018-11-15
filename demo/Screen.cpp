#include <windows.h>
#include <iostream>
#include "Screen.h"
#include "Point.h"
#include "Fish.h"
#include "Bullet.h"
#include "Battery.h"

CScreen::CScreen(){
	m_CFirstBullet = new CBullet();
	m_CLastBullet = m_CFirstBullet;
	m_CFirstFish = new CFish();
	m_CLastFish = m_CFirstFish;
	CPoint* CLocation = new CPoint(0, 0);
	int nSpeed = 10;
	int nGoldNum = 10;
	int nBulletNum = 10;
	int nAttack = 1;
	m_CBattery = new CBattery(CLocation, nSpeed, nGoldNum, nBulletNum, nAttack);
	m_nLength = 100;
	m_nWidth = 100;
}

void CScreen::LauchFish(){
		std::cout << "LaunchFish" << std::endl;
		CPoint* CStartLocation = new CPoint(0, 50);
		CPoint* CDirection = new CPoint(1, 0);
		int nSpeed = 10;
		int nRadii = 10;
		int nHp = 1;
		int nGoldNum = 10;

		SYSTEMTIME sTime;
		GetLocalTime(&sTime);
		ULARGE_INTEGER fTime;
		SystemTimeToFileTime(&sTime,(FILETIME*)&fTime);
		long long lLastCheckTime = (long long) (fTime.QuadPart);

		CFish* CNewFish = new CFish(CStartLocation, CDirection, nSpeed, nRadii, nHp, nGoldNum, lLastCheckTime);
		m_CLastFish->SetNextFish(CNewFish);
		m_CLastFish = CNewFish;
}

void CScreen::LaunchBullet(CPoint* CClickLocation){
	std::cout << "LaunchBullet" << std::endl;
	CBullet* CNewBullet = m_CBattery->Luanch(CClickLocation);
	m_CLastBullet->SetNextBullet(CNewBullet);
	m_CLastBullet = CNewBullet;
}

void CScreen::Check(){
	std::cout << "Check" << std::endl;
	CBullet* pBulletPre = m_CFirstBullet;
	CBullet* pBulletCur = m_CFirstBullet->GetNextBullet();
	CFish* pFishPre = m_CFirstFish;
	CFish* pFishCur = m_CFirstFish->GetNextFish();
	double distance = 0;

	while(pBulletCur != nullptr){
		while(pFishCur != nullptr){
			distance = CPoint::GetDistance(pBulletCur->GetLocation(), pFishCur->GetLocation());
			if(distance <= pFishCur->GetRadii()){
				if(pFishCur->DeleteHP(pBulletCur->GetAttack()) == EIL_Die){
					m_CBattery->AddGoldNum(pFishCur->GetGoldNum());
					pFishPre->SetNextFish(pFishCur->GetNextFish());
					pFishCur = pFishPre->GetNextFish();
					pBulletPre->SetNextBullet(pBulletCur->GetNextBullet());
					pBulletCur = pBulletPre;
					std::cout << "kill fish" << std::endl << std::endl;
					break;
				}
			}
			else
			{
				pFishPre = pFishCur;
				pFishCur = pFishCur->GetNextFish();
			}
		}
		pBulletPre = pBulletCur;
		pBulletCur = pBulletPre->GetNextBullet();
	}
	m_CLastFish = pFishPre;
	m_CLastBullet = pBulletPre;

}

void CScreen::Move(){
	std::cout << "Move" << std::endl;
	CBullet* pBulletPre = m_CFirstBullet;
	CBullet* pBulletCur = m_CFirstBullet->GetNextBullet();
	CFish* pFishPre = m_CFirstFish;
	CFish* pFishCur = m_CFirstFish->GetNextFish();

	while(pBulletCur != nullptr){
		CPoint* pCNewLocation = pBulletCur->GetLocation();
		double dNewX, dNewY;		
		dNewX = pCNewLocation->GetX() + pBulletCur->GetSpeed() * (pBulletCur->GetDirection())->GetX();
		dNewY = pCNewLocation->GetY() + pBulletCur->GetSpeed() * (pBulletCur->GetDirection())->GetY();
		std::cout << "Bullet dNewX:" << dNewX << "dNew:" << dNewY << std::endl;
		pCNewLocation->setPoint(dNewX, dNewY);

		if(dNewX < 0 || dNewX > m_nLength || dNewY < 0 || dNewY > m_nWidth)
		{
			pBulletPre->SetNextBullet(pBulletCur->GetNextBullet());
			pBulletCur = pBulletPre;
		}
		pBulletPre = pBulletCur;
		pBulletCur = pBulletCur->GetNextBullet();
		
		
	}

	while(pFishCur != nullptr){
		CPoint* pCNewLocation = pFishCur->GetLocation();
		double dNewX, dNewY;
		dNewX = pCNewLocation->GetX() + pFishCur->GetSpeed() * (pFishCur->GetDirection())->GetX();
		dNewY = pCNewLocation->GetY() + pFishCur->GetSpeed() * (pFishCur->GetDirection())->GetY();
		std::cout << "Fish dNewX:" << dNewX << "dNew:" << dNewY << std::endl;
		pCNewLocation->setPoint(dNewX, dNewY);
		if(dNewX < 0 || dNewX > m_nLength || dNewY < 0 || dNewY > m_nWidth)
		{
			pFishPre->SetNextFish(pFishCur->GetNextFish());
			pFishCur = pFishPre;
		}
		pFishPre = pFishCur;
		pFishCur = pFishCur->GetNextFish();
	}
	m_CLastFish = pFishPre;
	m_CLastBullet = pBulletPre;

}