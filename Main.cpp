#include "stdafx.h" 
#include <windows.h>
#include <ctime>
#include "CarGame.h"

using namespace std;

int main()
{
	srand((int)time(0));    //随机种子  
	hideCursor();   //隐藏光标 
	CarGame cargame;
	int flag = -1;
	while (1) {
	flag = cargame.Playing();
	if (flag == 0) break;
	}
	
	return 0;
}




