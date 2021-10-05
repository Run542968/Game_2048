#pragma once

int const ROW_1 = 4;
int const COL_1 = 4;

class Game_2048
{
public:
    int game[ROW_1][COL_1] = { 0 };
	int score = 0;
    int hammer_chance=0;
	int random_chance = 0;
    int bar_chance=0;
    int random_first_100 = 1;//用于重置的判断值
    int random_first_500 = 1;
    int random_first_1000 = 1;
    int hammer_first_100 = 1;//用于锤子清除的判断值
    int hammer_first_500 = 1;
    int hammer_first_1000 = 1;
    int bar_first_100 = 1;//用于锤子清除的判断值
    int bar_first_500 = 1;
    int bar_first_1000 = 1;
	int gameState = -1;
public:
	Game_2048();
	~Game_2048();     
	bool CreateNumber();
	void Process(int direction);
	int Judge();
	int Begin();
	void computeScore();
    int FirstOrder();
    void Random();//打乱数字
	void computeRandom_chance();
    void Hammer();//锤子消除数字
    void computeHammer_chance();
    void Bar();//魔法棒修改数字
    void computeBar_chance();
    void note_score();
};
