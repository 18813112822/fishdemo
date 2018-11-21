#include <windows.h>
#include <iostream>
#include "Screen.h"
#include "Point.h"
#include "Fish.h"
#include "Bullet.h"
#include "Battery.h"

CScreen::CScreen(){
	m_pFirstBullet = new CBullet();
	m_pLastBullet = m_pFirstBullet;
	m_pFirstFish = new CFish();
	m_pLastFish = m_pFirstFish;
	CPoint* pLocation = new CPoint(0, 0);
	int nSpeed = 5;
	int nGoldNum = 10;
	int nBulletNum = 10;
	int nAttack = 1;
	m_pBattery = new CBattery(pLocation, nSpeed, nGoldNum, nBulletNum, nAttack);
	m_nLength = 50;
	m_nWidth = 50;
}

CScreen::~CScreen(){
	CFish* pFishCur = m_pFirstFish;
	CFish* pFishNext = m_pFirstFish->GetNextFish();
	int n = -1;
	while(pFishCur != nullptr){
		n++;
		delete pFishCur;
		pFishCur = pFishNext;
		if(pFishNext != nullptr){
			pFishNext = pFishCur->GetNextFish();
		}
		
	}
	std::cout << "剩余鱼数：" << n << std::endl;
	CBullet* pBulletCur = m_pFirstBullet;
	CBullet* pBulletNext = m_pFirstBullet->GetNextBullet();
	while(pBulletCur != nullptr){
		delete pBulletCur;
		pBulletCur = pBulletNext;
		if(pBulletNext != nullptr){
			pBulletNext = pBulletCur->GetNextBullet();
		}
	}

	if(m_pBattery != nullptr)
		delete m_pBattery;
}

void CScreen::LauchFish(){
		std::cout << "LaunchFish" << std::endl;
		CPoint* pStartLocation = new CPoint(0, 25);
		CPoint* pDirection = new CPoint(1, 0);
		int nSpeed = 5;
		int nRadii = 5;
		int nHp = 1;
		int nGoldNum = 10;

		SYSTEMTIME sTime;
		GetLocalTime(&sTime);
		ULARGE_INTEGER fTime;
		SystemTimeToFileTime(&sTime,(FILETIME*)&fTime);
		long long lLastCheckTime = (long long) (fTime.QuadPart);

		CFish* pNewFish = new CFish(pStartLocation, pDirection, nSpeed, nRadii, nHp, nGoldNum, lLastCheckTime);
		m_pLastFish->SetNextFish(pNewFish);
		m_pLastFish = pNewFish;
}

void CScreen::LaunchBullet(CPoint* pClickLocation){
	std::cout << "LaunchBullet" << std::endl;
	CBullet* pNewBullet = m_pBattery->Luanch(pClickLocation);
	m_pLastBullet->SetNextBullet(pNewBullet);
	m_pLastBullet =pNewBullet;
}

void CScreen::Check(){
	std::cout << "Check" << std::endl;
	CBullet* pBulletPre = m_pFirstBullet;
	CBullet* pBulletCur = m_pFirstBullet->GetNextBullet();
	CFish* pFishPre = m_pFirstFish;
	CFish* pFishCur = m_pFirstFish->GetNextFish();
	double distance = 0;
	
	CFish* pF = pFishCur;
	while(pF != nullptr){
		std::cout << "Fish X:" << (pF->GetLocation())->GetX() << "Y:" << (pF->GetLocation())->GetY() << std::endl;
		pF = pF->GetNextFish();
	}

	CBullet* pB = pBulletCur;
	while(pB != nullptr){
		std::cout << "Bullet X:" << (pB->GetLocation())->GetX() << "Y:" << (pB->GetLocation())->GetY() << std::endl;
		pB = pB->GetNextBullet();
	}

	while(pBulletCur != nullptr){
		pFishCur = m_pFirstFish->GetNextFish();
		while(pFishCur != nullptr){
			distance = CPoint::GetDistance(pBulletCur->GetLocation(), pFishCur->GetLocation());
			//std::cout << "distance:" << distance << std::endl;
			if(distance <= pFishCur->GetRadii()){
				if(pFishCur->DeleteHP(pBulletCur->GetAttack()) == EIL_Die){
					m_pBattery->AddGoldNum(pFishCur->GetGoldNum());
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
	//std::cout << std::endl;
	m_pLastFish = m_pFirstFish;
	while(m_pLastFish->GetNextFish() != nullptr){
		m_pLastFish = m_pLastFish->GetNextFish();
	}
	m_pLastBullet = m_pFirstBullet;
	while(m_pLastBullet->GetNextBullet() != nullptr){
		m_pLastBullet = m_pLastBullet->GetNextBullet();
	}
}

void CScreen::Move(){
	std::cout << "Move" << std::endl;
	CBullet* pBulletPre = m_pFirstBullet;
	CBullet* pBulletCur = m_pFirstBullet->GetNextBullet();
	CFish* pFishPre = m_pFirstFish;
	CFish* pFishCur = m_pFirstFish->GetNextFish();

	CPoint* pOldLocation = new CPoint(0, 0);
	while(pBulletCur != nullptr){
		CPoint* pCNewLocation = pBulletCur->GetLocation();
		pOldLocation->setPoint(pCNewLocation->GetX(), pCNewLocation->GetY());
		double dNewX, dNewY;		
		dNewX = pCNewLocation->GetX() + pBulletCur->GetSpeed() * (pBulletCur->GetDirection())->GetX();
		dNewY = pCNewLocation->GetY() + pBulletCur->GetSpeed() * (pBulletCur->GetDirection())->GetY();
		//std::cout << "Bullet dNewX:" << dNewX << "dNew:" << dNewY << std::endl;
		pCNewLocation->setPoint(dNewX, dNewY);

		if(!IsInScreen(pCNewLocation))
		{
			Reflex(pOldLocation, pCNewLocation, pBulletCur->GetDirection());
		}
		pBulletPre = pBulletCur;
		pBulletCur = pBulletCur->GetNextBullet();
	}
	delete pOldLocation;
	int n = 0;
	while(pFishCur != nullptr){
		n++;
		CPoint* pCNewLocation = pFishCur->GetLocation();
		double dNewX, dNewY;
		dNewX = pCNewLocation->GetX() + pFishCur->GetSpeed() * (pFishCur->GetDirection())->GetX();
		dNewY = pCNewLocation->GetY() + pFishCur->GetSpeed() * (pFishCur->GetDirection())->GetY();
		//std::cout << "Fish dNewX:" << dNewX << "dNew:" << dNewY << std::endl;
		pCNewLocation->setPoint(dNewX, dNewY);
		if(!IsInScreen((pCNewLocation)))
		{
			pFishPre->SetNextFish(pFishCur->GetNextFish());
			delete pFishCur;
			pFishCur = pFishPre;
		}
		pFishPre = pFishCur;
		pFishCur = pFishCur->GetNextFish();
	}
	//std::cout << n << "条鱼" << std::endl;
	m_pLastFish = pFishPre;
	m_pLastBullet = pBulletPre;
}

void CScreen::Show(){
	std::cout << "Show" << std::endl;
	char screen[100][50];
	for(int i = 0; i < m_nLength; i++){
		for(int j = 0; j < m_nWidth; j++){
			screen[i][j] = ' ';
		}
	}

	if(m_pFirstFish == nullptr){
		std::cout << "m_pFirstFish is NULL" << std::endl;
		return;
	}
	CFish* pFishCur = m_pFirstFish->GetNextFish();
	while(pFishCur != nullptr){
		CPoint* pLocation = pFishCur->GetLocation();
		int x = (int)pLocation->GetX();
		int y = (int)pLocation->GetY();
		//std::cout << "Fish x:" << pLocation->GetX() << " y :" << pLocation->GetY() << std::endl;
		int nRadii = pFishCur->GetRadii();
		screen[x][y] = '*';
		for(int i = 1; i <= nRadii; i++){
			if(x+i < m_nLength){
				screen[x+i][y] = '*';
			}
			if(x-i >= 0){
				screen[x-i][y] = '*';
			}
			if(y+i < m_nWidth){
				screen[x][y+i] = '*';
			}
			if(y-i >= 0){
				screen[x][y-i] = '*';
			}
		}
		pFishCur = pFishCur->GetNextFish();
	}

	if(m_pFirstBullet == nullptr){
		std::cout << "m_pFirstBullet is NULL" << std::endl;
		return;
	}
	CBullet* pBulletCur = m_pFirstBullet->GetNextBullet();
	while(pBulletCur != nullptr){
		CPoint* pLocation = pBulletCur->GetLocation();
		int x = (int)pLocation->GetX();
		int y = (int)pLocation->GetY();
		//std::cout << "Bullet x:" << pLocation->GetX() << " y :" << pLocation->GetY() << std::endl;
		screen[x][y] = '*';
		pBulletCur = pBulletCur->GetNextBullet();
	}
	
	for(int i = 0; i < m_nLength+2; i++)
		std::cout << '-';
	std::cout << std::endl;
	for(int i = 0; i < m_nLength; i++){
		std::cout << '|';
		for(int j = 0; j < m_nWidth; j++){
			std::cout << screen[i][j];
		}
		std::cout << '|' << std::endl;
	}
	for(int i = 0; i < m_nLength+2; i++)
		std::cout << '-';
	std::cout << std::endl;
}

bool CScreen::IsInScreen(CPoint* pPoint){
	if(pPoint->GetX() < 0 || pPoint->GetX() > m_nLength-1 || pPoint->GetY() < 0 || pPoint->GetY() > m_nWidth-1){
		return false;
	}
	return true;
}

//判断线段相交
bool CScreen::LineIntersect(CPoint* pPointA, CPoint* pPointB, CPoint* pPointC, CPoint* pPointD){
	if(min(pPointA->GetX(), pPointB->GetX()) > max(pPointC->GetX(), pPointD->GetX()))
		return false;
	if(min(pPointA->GetY(), pPointB->GetY()) > max(pPointC->GetY(), pPointD->GetY()))
		return false;
	if(max(pPointA->GetX(), pPointB->GetX()) < min(pPointC->GetX(), pPointD->GetX()))
		return false;
	if(max(pPointA->GetY(), pPointB->GetY()) < min(pPointC->GetY(), pPointD->GetY()))
		return false;

	double u,v,w,z;//分别记录两个向量
	u=(pPointC->GetX()-pPointA->GetX())*(pPointB->GetY()-pPointA->GetY())-(pPointB->GetX()-pPointA->GetX())*(pPointC->GetY()-pPointA->GetY());
	v=(pPointD->GetX()-pPointA->GetX())*(pPointB->GetY()-pPointA->GetY())-(pPointB->GetX()-pPointA->GetX())*(pPointD->GetY()-pPointA->GetY());
	w=(pPointA->GetX()-pPointC->GetX())*(pPointD->GetY()-pPointC->GetY())-(pPointD->GetX()-pPointC->GetX())*(pPointA->GetY()-pPointC->GetY());
	z=(pPointB->GetX()-pPointC->GetX())*(pPointD->GetY()-pPointC->GetY())-(pPointD->GetX()-pPointC->GetX())*(pPointB->GetY()-pPointC->GetY());
	//std::cout << "u*v:" << u*v  << " w*z:" << std::endl;
	return (u*v<=0.00000001 && w*z<=0.00000001);
}

void CScreen::Reflex(CPoint* pStartLocation, CPoint* pEndLocation,CPoint* pDirection){
	CPoint* pPointO = new CPoint(0, 0);//原点
	CPoint* pPointA = new CPoint(m_nLength-1, 0); //x轴最大
	CPoint* pPointB = new CPoint(0, m_nWidth-1);	//y轴最大
	CPoint* pPointC = new CPoint(m_nLength-1, m_nWidth-1);	//xy均最大
	//std::cout << "Reflex start" << std::endl;
	while(!IsInScreen(pEndLocation)){
		if(pDirection->GetY() > 0 && LineIntersect(pStartLocation, pEndLocation, pPointB, pPointC)){
			pStartLocation->setPoint(pStartLocation->GetX(), 2 * (m_nWidth - 1) - pStartLocation->GetY());
			pEndLocation->setPoint(pEndLocation->GetX(), 2 * (m_nWidth - 1) - pEndLocation->GetY());
			pDirection->setPoint(pDirection->GetX(), -pDirection->GetY());
		}
		else if(pDirection->GetX() > 0 && LineIntersect(pStartLocation, pEndLocation, pPointA, pPointC))
		{
			pStartLocation->setPoint(2*(m_nLength-1)-pStartLocation->GetX(), pStartLocation->GetY());
			pEndLocation->setPoint(2*(m_nLength-1)-pEndLocation->GetX(), pEndLocation->GetY());
			pDirection->setPoint(-pDirection->GetX(), pDirection->GetY());
		}
		else if(pDirection->GetY() < 0 && LineIntersect(pStartLocation, pEndLocation, pPointO, pPointA))
		{
			pStartLocation->setPoint(pStartLocation->GetX(), -pStartLocation->GetY());
			pEndLocation->setPoint(pEndLocation->GetX(), -pEndLocation->GetY());
			pDirection->setPoint(pDirection->GetX(), -pDirection->GetY());
		}
		else if(pDirection->GetX() < 0 && LineIntersect(pStartLocation, pEndLocation, pPointO, pPointB))
		{
			pStartLocation->setPoint(-pStartLocation->GetX(), pStartLocation->GetY());
			pEndLocation->setPoint(-pEndLocation->GetX(), pEndLocation->GetY());
			pDirection->setPoint(-pDirection->GetX(), pDirection->GetY());
		}
		//std::cout << "X:" << pEndLocation->GetX() << " Y:" << pEndLocation->GetY() << std::endl;
		//getchar();
	}
	//std::cout << "Reflex end" << std::endl;
	
}

CBattery* CScreen::GetBattery(){
	return m_pBattery;
}