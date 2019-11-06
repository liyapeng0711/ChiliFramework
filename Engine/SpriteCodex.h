#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );//84*64
	static void DrawTitle( int x,int y,Graphics& gfx );//214*160
	static constexpr int overWidth = 84;
	static constexpr int overHeight = 64;
	static constexpr int titleWidth = 214;
	static constexpr int titleHeight = 160;
};