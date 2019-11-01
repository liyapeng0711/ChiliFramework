#pragma once
#include"Graphics.h"
#include"Dude.h"
class Poo
{
public:
	void Init(int x_1, int y_1, int vx_1, int vy_1);
	void UpdateAndClamp();
	void TestCollide(const Dude& dude);
	void Draw(Graphics& gfx)const;
	bool IsEaten()const;
private:
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;
	bool isInitilized = false;	//for robust and safety check
public:
	static constexpr int width = 24;
	static constexpr int height = 24;
};