#pragma once
#include"Graphics.h"
#include"Dude.h"
#include"Vec2.h"
class Poo
{
public:
	void Init(Vec2 pos_1, Vec2 vel_1);
	void UpdateAndClamp(float dt);
	void TestCollide(const Dude& dude);
	void Draw(Graphics& gfx)const;
	bool IsEaten()const;
private:
	Vec2 pos;
	Vec2 vel;
	bool isEaten = false;
	bool isInitilized = false;	//for robust and safety check
public:
	static constexpr int width = 24;
	static constexpr int height = 24;
};