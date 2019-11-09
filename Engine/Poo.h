#pragma once
#include"Graphics.h"
#include"Dude.h"
class Poo
{
public:
	void Init(float x_1, float y_1, float vx_1, float vy_1);
	void UpdateAndClamp();
	void TestCollide(const Dude& dude);
	void Draw(Graphics& gfx)const;
	bool IsEaten()const;
private:
	float x;
	float y;
	float vx;
	float vy;
	bool isEaten = false;
	bool isInitilized = false;	//for robust and safety check
public:
	static constexpr int width = 24;
	static constexpr int height = 24;
};