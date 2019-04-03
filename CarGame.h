//CarGame.h

#include "Draw.h"

#define CARPOSITION 12
#define BARRIERNUM 6

class CarGame
{
private:
	COORD position[CARPOSITION]; //С��
	Frame barrier[BARRIERNUM];   //�ϰ���
	int score;          //�÷�
public:
	//���캯��
	CarGame();

	//��ʼ������  
	void initCar();
	void initBarrier();

	//�ƶ�����
	void carMove(char x);
	void barrierMove();

	//�������  
	void drawCar();
	void drawCarToNull();
	void drawBarrier();
	void drawBarrierToNull();

	//��Ϸ���ܺ���
	void Pause();

	//�жϺ���
	int judgeCarBarrier();  //�жϺ���С���Ƿ����ϰ�����ײ
	bool judgeCoordInFrame(Frame frame, COORD spot);

	//��Ϸ�����ͽ���
	void startMenu();
	int gameOver();
	
	//�����Ϸ�߿������
	void drawGameFrame();
	void drawGameRules();
	void drawGameScore();

	//��Ϸ������
	int Playing();
};

//��[a, b)֮�����һ���������  
int random(int a, int b);

//��������������ľ��ο����������һ������  
COORD random(COORD a, COORD b);