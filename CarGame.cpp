#include "stdafx.h"
#include "CarGame.h"
#include <iostream>
#include<conio.h>  

using namespace std;

//���캯��
CarGame::CarGame() {
	initCar();
	initBarrier();
	score = 0;
}

//��ʼ������  
void CarGame::initCar() {
	COORD lfw = { 13, 20};   //left front wheel ��ǰ��
	position[0].X = position[2].X = position[6].X = position[8].X = lfw.X;
	position[3].X = position[9].X = lfw.X + 1;
	position[4].X = position[10].X = lfw.X + 2;
	position[1].X = position[5].X = position[7].X = position[11].X = lfw.X + 3;
	position[0].Y = position[1].Y = lfw.Y - 1;
	position[2].Y = position[3].Y = position[4].Y = position[5].Y = lfw.Y;
	position[6].Y = position[7].Y = lfw.Y + 1;
	position[8].Y = position[9].Y = position[10].Y = position[11].Y = lfw.Y + 2;
}
void CarGame::initBarrier() {
	COORD a = { 1, 1};
	COORD b = { 26, 8};
	for (int i = 0; i < BARRIERNUM; i++)
	{
		barrier[i].position[0] = random(a, b);
		barrier[i].position[1].X = barrier[i].position[0].X + 3;
		barrier[i].position[1].Y = barrier[i].position[0].Y + 2;
	}
}

//�ƶ�����
void CarGame::carMove(char x) {
	if (x == 'a')
		if (position[0].X != 1)
			for (int i = 0; i < CARPOSITION; i++)
				position[i].X -= 1;

	if (x == 's')
		if (position[8].Y != 23)
			for (int i = 0; i < CARPOSITION; i++)
				position[i].Y += 1;

	if (x == 'd')
		if (position[5].X != 29)
			for (int i = 0; i < CARPOSITION; i++)
				position[i].X += 1;

	if (x == 'w')
		if (position[0].Y != 1)
			for (int i = 0; i < CARPOSITION; i++)
				position[i].Y -= 1;
}
void CarGame::barrierMove() {
	for (int i = 0; i < BARRIERNUM; i++)
	{
		for (int j = 0; j<2; j++)
			barrier[i].position[j].Y++;

		if (barrier[i].position[1].Y == 24)
		{
			score++;
			COORD a = {1, 1 };
			COORD b = {26, 7};
			barrier[i].position[0] = random(a, b);
			barrier[i].position[1].X = barrier[i].position[0].X + 3;
			barrier[i].position[1].Y = barrier[i].position[0].Y + 2;
		}
	}
}

//�������  
void CarGame::drawCar() {
	for (int i = 0; i < CARPOSITION; i++)
	{
		SetPos(position[i]);
		if (i == 0) cout << "\\";
		else if (i == 1) cout << "/";
		else if (i == 2 || i == 5 || i == 8 || i == 11) cout << "0";
		else if (i == 3 || i == 4 || i == 9 || i == 10) cout << "-";
		else if (i == 6 || i == 7)	cout << "|";
	}
}
void CarGame::drawCarToNull() {
	for (int i = 0; i < CARPOSITION; i++)
	{
		SetPos(position[i]);
		cout << " ";
	}
}
void CarGame::drawBarrier() {
	for (int i = 0; i < BARRIERNUM; i++)
	{
		drawFrame(barrier[i].position[0], barrier[i].position[1], '-', '|');
	}
}
void CarGame::drawBarrierToNull() {
	for (int i = 0; i < BARRIERNUM; i++)
	{
		drawFrame(barrier[i], ' ', ' ');
	}
}

//��Ϸ���ܺ���
void CarGame::Pause() {
	SetPos(34, 3);
	cout << "��ͣ��...";
	char c = _getch();
	while (c != 'p')
		c = _getch();
	SetPos(34, 3);
	cout << "         ";
}

//�жϺ���
int CarGame::judgeCarBarrier() {
	for (int i = 0; i < BARRIERNUM; i++)
		for (int j = 0; j < CARPOSITION; j++)
			if (judgeCoordInFrame(barrier[i], position[j]))
			{
				drawFrame(barrier[i], '#', '#');
				Sleep(1000);
				return gameOver();
				
			}
}
bool CarGame::judgeCoordInFrame(Frame frame, COORD spot) {
	if (spot.X >= frame.position[0].X)
		if (spot.X <= frame.position[1].X)
			if (spot.Y >= frame.position[0].Y)
				if (spot.Y <= frame.position[0].Y)
					return true;
	return false;
}

//��Ϸ�����ͽ���
void CarGame::startMenu() {
	drawFrame(0, 0, 45, 24, '=', '|');
	SetPos(16, 9);
	cout << "CAR     GAME";
	SetPos(24, 20);
	cout << "�밴���������...";
	while (1) {
		if (_kbhit()) break;
	}
	system("cls");
}
int CarGame::gameOver() {
	system("cls");
	drawFrame(0, 0, 45, 24, '=', '|');
	COORD p1 = {17, 9};
	COORD p2 = {27, 11};
	drawFrame(p1, p2, '=', '|');
	SetPos(18, 10);
	string str = "Game Over";
	for (int i = 0; i<str.size(); i++)
	{
		Sleep(80);
		cout << str[i];
	}
	Sleep(1000);

	system("cls");
	drawFrame(0, 0, 45, 24, '=', '|');
	drawFrame(p1, p2, '=', '|');
	SetPos(19, 10);
	cout << "�÷֣�" << score;
	Sleep(2000);

	system("cls");
	drawFrame(0, 0, 45, 24, '=', '|');
	SetPos(16, 10);
	cout << "����һ��? Y/N";
	fflush(stdin);
	char flag = _getch();
	while (1) {
		if (flag == 'y') return 1;
		else if(flag == 'n') return 0;
		else flag = _getch();
	}
	
}

//�����Ϸ�߿������
void CarGame::drawGameFrame() {
	drawFrame(0, 0, 30, 24, '=', '|');  //  �����Ϸ�߿�
	drawFrame(31, 0, 45, 6, '-', '|');//    �����Ϸ״̬�߿�
	drawFrame(31, 6, 45, 12, '-', '|');//     ���÷ֱ߿�  
	drawFrame(31, 12, 45, 24, '-', '|');//   �����������߿�  
}
void CarGame::drawGameRules() {
	SetPos(34, 15);
	cout << "����������";
	SetPos(35, 16);
	cout << "w ����";
	SetPos(35, 17);
	cout << "a ����";
	SetPos(35, 18);
	cout << "s ����";
	SetPos(35, 19);
	cout << "d ����";
	SetPos(35, 20);
	cout << "p ��ͣ";
}
void CarGame::drawGameScore(){
	SetPos(34, 9);
	cout << "�÷֣�" << score;
}

//��Ϸ����������
int CarGame::Playing() { //return 0 ->������Ϸ return 1 ->���¿�ʼ��Ϸ
	system("cls");
	int flag_barrier = 0; //����
	int flag_gameOver = -1;

	startMenu();
	initCar();
	initBarrier();
	drawCar();
	drawBarrier();
	drawGameFrame();
	drawGameRules();
	drawGameScore();

	while (1)
	{
		Sleep(8);
		if (_kbhit())
		{
			char x = _getch();
			if ('a' == x || 's' == x || 'd' == x || 'w' == x)
			{
				drawCarToNull();
				carMove(x);
				drawCar();
				flag_gameOver = judgeCarBarrier();
				if (flag_gameOver == 0 || flag_gameOver == 1) return flag_gameOver;
			}
			else if ('p' == x)
				Pause();
			else if ('e' == x)
			{
				return gameOver();
			}
		}
		flag_barrier++;
		if (flag_barrier == 25) {
			drawBarrierToNull();
			barrierMove();
			drawBarrier();
			flag_gameOver = judgeCarBarrier();
			if (flag_gameOver == 0 || flag_gameOver == 1) return flag_gameOver;
			flag_barrier = 0;
		}
		drawGameScore();
	}
}

//��[a, b)֮�����һ���������  
int random(int a, int b)
{
	int c = (rand() % (a - b)) + a;
	return c;
}

//��������������ľ��ο����������һ������  
COORD random(COORD a, COORD b)
{
	int x = random(a.X, b.X);
	int y = random(a.Y, b.Y);
	COORD c = { x, y };
	return c;
}