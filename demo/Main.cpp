#include <iostream>
#include <windows.h>
#include <time.h>
#include "Battery.h"
#include "Fish.h"
#include "Bullet.h"
#include "Fish.h"
#include "Screen.h"
#include "Point.h"

using namespace std;

int main()
{
	CScreen CScreen0;
	CPoint* CDirection = new CPoint(1, 1);
	for(int i = 0; i < 10; i++){
		CScreen0.LauchFish();
		CScreen0.LaunchBullet(CDirection);
		CScreen0.Check();
		CScreen0.Move();
	}
	return 0;
}