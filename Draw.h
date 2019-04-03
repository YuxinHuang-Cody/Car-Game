#include <windows.h>

typedef struct Frame
{
	COORD position[2];
	int flag;
}Frame;

void SetPos(COORD a);
void SetPos(int i, int j);
void hideCursor();
void drawRow(int y, int x1, int x2, char ch);
void drawRow(COORD a, COORD b, char ch);
void drawCol(int x, int y1, int y2, char ch);
void drawCol(COORD a, COORD b, char ch);
void drawFrame(COORD a, COORD  b, char row, char col);
void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
void drawFrame(Frame frame, char row, char col);