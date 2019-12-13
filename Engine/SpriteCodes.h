#pragma once
#include"Location.h"
#include"Graphics.h"
class SpriteCodes
{
public:
	static void DrawRefresh(Location LocLeftUp, Graphics& gfx);
	static void DrawNum(Location LocLeftUp, Graphics& gfx, int num);
	static void DrawCellZERO(Location LocLeftUp, Graphics& gfx); // this is for clock and flag num
	static void DrawCellONE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellTWO(Location LocLeftUp, Graphics& gfx);
	static void DrawCellTHREE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellFOUR(Location LocLeftUp, Graphics& gfx);
	static void DrawCellFIVE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellSIX(Location LocLeftUp, Graphics& gfx);
	static void DrawCellSEVEN(Location LocLeftUp, Graphics& gfx);
	static void DrawCellEIGHT(Location LocLeftUp, Graphics& gfx);
	static void DrawCellNINE(Location LocLeftUp, Graphics& gfx); // this is for clock and flag num
	static void DrawCellMINE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellSAFE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellFLAG(Location LocLeftUp, Graphics& gfx);
	static void DrawCellHIDDEN(Location LocLeftUp, Graphics& gfx);
	static void DrawCellSUSPECTED(Location LocLeftUp, Graphics& gfx);
	static void DrawCellSUSPECTEDMINE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellFLAGMINE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellHIDDENMINE(Location LocLeftUp, Graphics& gfx);
	static void DrawCellNOTMINE(Location LocLeftUp, Graphics& gfx);
	

	static void DrawLevelEasy(Location LocLeftUp, Graphics& gfx);
	static void DrawLevelMiddle(Location LocLeftUp, Graphics& gfx);
	static void DrawLevelDifficult(Location LocLeftUp, Graphics& gfx);
};

