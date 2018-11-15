#include <iostream>
#include "Fish.h"
#include "Point.h"
#include "Bullet.h"

using namespace std;

int main(){
	CPoint* CLoc = new CPoint(1, 2);
	CPoint* CDir = new CPoint(1, 1);
	CFish fish(CLoc, CDir, 10, 10, 10);
	CBullet bullet(CLoc, CDir, 10);
	return 0;
}