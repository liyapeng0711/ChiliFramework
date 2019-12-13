#pragma once
#include "Mouse.h"
#include "Graphics.h"

#include "SpriteCodes.h"
#include"GameStatus.h"
#include"Level.h"

#include "Location.h"
#include"RectI.h"

class Bar
{
public:
	Bar() = default;
public:	
	void UpdateClock(float dt);
	void UpdateFlag(int num);
	bool IsRefresh(Mouse& mouse);
	void StopClock();
	void Draw(Graphics& gfx);
	void Initialize(Level level);

private:
	RectI GetRefreshRect()const;
	void DrawClock(Graphics& gfx)const;
	void DrawRefresh(Graphics& gfx)const;
	void DrawFlagNum(Graphics& gfx)const;
private:
	bool isStopped = false;
	int flagNum = 0;
	float clockNum = 0.0f;
	int cubeSize;
	Location locRefresh = { 0,BoardPara::dividingY }; // not really, x and y both change. (1cube)
	Location locClock = { 0,BoardPara::dividingY }; // not really, x and y both change.   (3cube)
	Location locFlagNum = { 0,BoardPara::dividingY }; // not really, x and y both change. (2cube)
};

