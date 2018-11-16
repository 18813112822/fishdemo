#include <stdlib.h>
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
	CPoint* pDirection = new CPoint(1, 2);
	for(int i = 0; i < 30; i++){	
		//system("cls");
		if(i % 5 == 0)
			CScreen0.LaunchBullet(pDirection);
		if(i % 4 == 0)
			CScreen0.LauchFish();
		CScreen0.Move();
		CScreen0.Show();
		CScreen0.Check();
		Sleep(1000);
	}
	cout << "gold num " << CScreen0.GetBattery()->GetGoldNum() << endl;
	return 0;
}