#pragma once
enum Level
{
	EASY, //10*10 with 10(20pp * 20pp) --> 200* 200     mind the screen 800*600 (bar and board should be inside)
	MIDDLE, //20*20 with 40(20pp * 20pp) --> 400* 400   the bar is 20 * 20 for mine (2), number (2), and refresh
	DIFFICULT, //30*20 with 60(20pp * 20pp) --> 600* 400
};

struct BoardPara
{
	static const int easyCellSize = 20;
	static const int middleCellSize = 20;
	static const int difficultCellSize = 20;

	static const int easyCellXNum = 10;
	static const int easyCellYNum = 10;
	static const int middleCellXNum = 20;
	static const int middleCellYNum = 20;
	static const int difficultCellXNum = 30;
	static const int difficultCellYNum = 20;

	static const int easyMineNum = 10;
	static const int middleMineNum = 40;
	static const int difficultMineNum = 60;

	static const int dividingY = 100;

	//static const int easyWidth = easyCellSize*easyCellXNum;
	//static const int easyHeight = easyCellSize*easyCellYNum;
	//static const int middleWidth = middleCellSize*middleCellXNum;
	//static const int middleHeight = middleCellSize*middleCellYNum;
	//static const int difficultWidth = difficultCellSize*difficultCellXNum;
	//static const int difficultHeight = difficultCellSize*difficultCellYNum;
	
};