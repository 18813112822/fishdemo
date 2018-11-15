#include<stdio.h>
#include<time.h>
#include "Battery.h"
    
long getCurrentTime()  
{  
	
}  

CBattery::CBattery(CPoint* CLocation){
	m_CLocation = CLocation;
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

void CBattery::Luanch(CPoint* CDirection){
	if(m_nBulletNum > 0){
		--m_nBulletNum;

	}
}
