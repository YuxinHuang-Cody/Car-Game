//CarGame.h

#include "Draw.h"

#define CARPOSITION 12
#define BARRIERNUM 6

class CarGame
{
private:
	COORD position[CARPOSITION]; //小车
	Frame barrier[BARRIERNUM];   //障碍物
	int score;          //得分
public:
	//构造函数
	CarGame();

	//初始化所有  
	void initCar();
	void initBarrier();

	//移动所有
	void carMove(char x);
	void barrierMove();

	//填充所有  
	void drawCar();
	void drawCarToNull();
	void drawBarrier();
	void drawBarrierToNull();

	//游戏功能函数
	void Pause();

	//判断函数
	int judgeCarBarrier();  //判断函数小车是否与障碍物相撞
	bool judgeCoordInFrame(Frame frame, COORD spot);

	//游戏开场和结束
	void startMenu();
	int gameOver();
	
	//填充游戏边框和文字
	void drawGameFrame();
	void drawGameRules();
	void drawGameScore();

	//游戏主函数
	int Playing();
};

//在[a, b)之间产生一个随机整数  
int random(int a, int b);

//在两个坐标包括的矩形框内随机产生一个坐标  
COORD random(COORD a, COORD b);