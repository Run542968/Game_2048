#include "Game_2048.h"
#include"game_widget.h"
#include <iostream>  
#include <windows.h>  
#include <ctime>  
#include<fstream>
#include<conio.h>
using namespace std;

//��������  
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//��Ϸ������״̬  
int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;

//�ļ�����-��ȡ������¼�������������а�
typedef struct
{
	int x;
	char name[10];
	char time[20];
}Record;

enum GameNum
{
	Game_2 = 2,
	Game_4 = 4,
	Game_8 = 8,
	Game_16 = 16,
	Game_32 = 32,
	Game_64 = 64,
	Game_128 = 128,
	Game_256 = 256,
	Game_512 = 512,
	Game_1024 = 1024,
	Game_2048 = 2048,
};
Game_2048::Game_2048() {

}
Game_2048::~Game_2048() {

}
int Game_2048::FirstOrder() {//�Է����������򣬷������ֵ
    FILE* in;
	Record a[100];
	Record t;
	int n = 0;
    in = fopen("./2048_Score.txt", "r");//txt�ļ��ڹ���������buildĿ¼����������Ϳ��Զ�ȡ��Ϣ
    while (fscanf(in, "%s   %s   %d,", a[n].time, a[n].name, &a[n].x) != EOF)
		n++;
	//���ݷ�����������
	for (int i = 1; i <n; i++)
	{
		for (int j = i - 1; j >= 0 && a[j+1].x > a[j].x; j--)
		{
			t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
		}
	}
	fclose(in);
    return a[0].x;
}
void Game_2048::computeScore() {//�������
	score = 0;
	for (int i = 0; i < ROW_1; i++) {
		for (int j = 0; j < COL_1; j++) {
			score += game[i][j];
		}
	}
}
void Game_2048::computeRandom_chance() {//�������ô���
    if (score >= 100&&random_first_100==1) {
		random_chance += 1;
        random_first_100 = 0;
	}
    else if (score >= 500 &&random_first_500 == 1) {
		random_chance += 1;
        random_first_500 = 0;
	}
    else if (score >= 1000 &&random_first_1000 == 1) {
		random_chance += 1;
        random_first_1000 = 0;
	}
}
void Game_2048::computeHammer_chance(){//���㴸�Ӵ���
    if (score >= 100&&hammer_first_100==1) {
        hammer_chance += 1;
        hammer_first_100 = 0;
    }
    else if (score >= 500 &&hammer_first_500 == 1) {
        hammer_chance += 1;
        hammer_first_500 = 0;
    }
    else if (score >= 1000 &&hammer_first_1000 == 1) {
        hammer_chance += 1;
        hammer_first_1000 = 0;
    }
}
void Game_2048::computeBar_chance(){//����ħ��������
    if (score >= 100&&bar_first_100==1) {
        bar_chance += 1;
        bar_first_100 = 0;
    }
    else if (score >= 500 &&hammer_first_500 == 1) {
        bar_chance += 1;
        bar_first_500 = 0;
    }
    else if (score >= 1000 &&hammer_first_1000 == 1) {
        bar_chance += 1;
        bar_first_1000 = 0;
    }
}

bool Game_2048::CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW_1 * COL_1;
	//����֮���ĸ�������2������֮һ�ĸ�������4  
	int whitch = rand() % 3;
	//�ҵ��ո���
	do
	{
		x = rand() % ROW_1;
		y = rand() % COL_1;
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//˵�������Ѿ�����  
	if (times >= maxTimes)
	{
		return false;
	}
	else
	{
		GameNum num;
		if (whitch == 0)
		{
			num = Game_4;
		}
		else if (whitch)
		{
			num = Game_2;
		}
		game[x][y] = num;
	}

	return true;
}

void Game_2048::Process(int direction)
{
	switch (direction)
	{
	case UP:
		//������һ�в���  
		for (int row = 1; row < ROW_1; ++row)
		{
			for (int crow = row; crow >= 1; --crow)
			{
				for (int col = 0; col < COL_1; ++col)
				{
					//��һ������Ϊ��  
					if (game[crow - 1][col] == 0)
					{
						game[crow - 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//�ϲ�  
						if (game[crow - 1][col] == game[crow][col])
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
						}

					}
				}
			}
		}
		break;
	case DOWN:
		//������һ�в���  
		for (int row = ROW_1 - 2; row >= 0; --row)
		{
			for (int crow = row; crow < ROW_1 - 1; ++crow)
			{
				for (int col = 0; col < COL_1; ++col)
				{
					//��һ������Ϊ��  
					if (game[crow + 1][col] == 0)
					{
						game[crow + 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//�ϲ�  
						if (game[crow + 1][col] == game[crow][col])
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
						}

					}
				}
			}
		}
		break;
	case LEFT:
		//�����һ�в���  
		for (int col = 1; col < COL_1; ++col)
		{
			for (int ccol = col; ccol >= 1; --ccol)
			{
				for (int row = 0; row < ROW_1; ++row)
				{
					//��һ������Ϊ��  
					if (game[row][ccol - 1] == 0)
					{
						game[row][ccol - 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//�ϲ�  
						if (game[row][ccol - 1] == game[row][ccol])
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
						}

					}
				}
			}
		}
		break;
	case RIGHT:
		//���ұ�һ�в���  
		for (int col = COL_1 - 2; col >= 0; --col)
		{
			for (int ccol = col; ccol <= COL_1 - 2; ++ccol)
			{
				for (int row = 0; row < ROW_1; ++row)
				{
					//��һ������Ϊ��  
					if (game[row][ccol + 1] == 0)
					{
						game[row][ccol + 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//�ϲ�  
						if (game[row][ccol + 1] == game[row][ccol])
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
						}

					}
				}
			}
		}
		break;
	}

}

//�ж���Ϸ״̬  
int Game_2048::Judge()
{
	//Ӯ����Ϸ  
	for (int i = 0; i < ROW_1; ++i)
	{
		for (int j = 0; j < COL_1; ++j)
		{
			if (game[i][j] == 2048)
			{
				return GAME_WIN;
				break;
			}
		}
	}

	//������  
	for (int i = 0; i < ROW_1; ++i)
	{
		for (int j = 0; j < COL_1 - 1; ++j)
		{
			if (!game[i][j] || (game[i][j] == game[i][j + 1]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}
	//������  
	for (int j = 0; j < COL_1; ++j)
	{
		for (int i = 0; i < ROW_1 - 1; ++i)
		{
			if (!game[i][j] || (game[i][j] == game[i + 1][j]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}

	//��������������״������Ϸ����  
	return GAME_OVER;

}

void Game_2048::Random() {//���Ҷ�ά������ֵ��˳��
	if (random_chance > 0) {
		srand((unsigned int)time(0));
		int  index, temp;
		for (int i = 0; i < ROW_1; i++) {
			for (int j = 0; j < COL_1; j++) {
				index = rand() % 4;
				if (index != j) {
					temp = game[i][j];
					game[i][j] = game[i][index];
					game[i][index] = temp;
				}
			}
		}
		random_chance -= 1;
	}
}
void Game_2048::Hammer(){//���Ӵ�����һ
    if(hammer_chance>0){
        hammer_chance -= 1;
    }
}
void Game_2048::Bar(){//ħ����������һ
    if(bar_chance>0){
        bar_chance -= 1;
    }
}
void Game_2048::note_score(){//��¼��������txt�ļ�
    SYSTEMTIME sys;
    GetLocalTime(&sys);//��ȡ��ǰϵͳʱ���

    ofstream file;
    file.open("2048_Score.txt", ios::app);//���ios::app�󣬾ͻ����ļ�����׷����Ϣ�������Ǹ���ԭ����Ϣ
    file << sys.wYear << '/' << sys.wMonth << '/' << sys.wDay << '-' <<
        sys.wHour << ':' << sys.wMinute << "  " << score << endl;              //��ʱ���-���շ���-�ǳ�¼�����ļ�
    file.close();
}
//��ʼ������
int Game_2048::Begin()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            game[i][j]=0;
        }
    }
    srand((unsigned int)time(0));
    CreateNumber();
    CreateNumber();
}
