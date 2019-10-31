#include "Dude.h"
#include "Graphics.h"

void Dude::ClampXY()
{
	if (x < 0)
	{
		x = 0;
	}
	else if (x + width - 1 >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width;
	}
	else
	{
		
	}

	if (y < 0)
	{
		y = 0;
	}
	else if (y + height - 1 >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height;
	}
	else
	{
		
	}
}

void Dude::Draw(Graphics& gfx)const
{
	gfx.PutPixel(0 + x, 0 + y, 158, 110, 90);
	gfx.PutPixel(1 + x, 0 + y, 171, 119, 97);
	gfx.PutPixel(2 + x, 0 + y, 184, 133, 112);
	gfx.PutPixel(3 + x, 0 + y, 184, 141, 124);
	gfx.PutPixel(4 + x, 0 + y, 189, 145, 132);
	gfx.PutPixel(5 + x, 0 + y, 204, 155, 140);
	gfx.PutPixel(6 + x, 0 + y, 202, 155, 139);
	gfx.PutPixel(7 + x, 0 + y, 198, 158, 146);
	gfx.PutPixel(8 + x, 0 + y, 208, 160, 146);
	gfx.PutPixel(9 + x, 0 + y, 212, 168, 155);
	gfx.PutPixel(10 + x, 0 + y, 207, 167, 155);
	gfx.PutPixel(11 + x, 0 + y, 206, 164, 152);
	gfx.PutPixel(12 + x, 0 + y, 199, 155, 142);
	gfx.PutPixel(13 + x, 0 + y, 206, 160, 145);
	gfx.PutPixel(14 + x, 0 + y, 209, 166, 150);
	gfx.PutPixel(15 + x, 0 + y, 210, 168, 154);
	gfx.PutPixel(16 + x, 0 + y, 192, 157, 138);
	gfx.PutPixel(17 + x, 0 + y, 187, 139, 125);
	gfx.PutPixel(18 + x, 0 + y, 195, 143, 130);
	gfx.PutPixel(19 + x, 0 + y, 183, 141, 125);
	gfx.PutPixel(0 + x, 1 + y, 166, 116, 107);
	gfx.PutPixel(1 + x, 1 + y, 150, 112, 103);
	gfx.PutPixel(2 + x, 1 + y, 124, 94, 84);
	gfx.PutPixel(3 + x, 1 + y, 151, 116, 110);
	gfx.PutPixel(4 + x, 1 + y, 182, 145, 139);
	gfx.PutPixel(5 + x, 1 + y, 205, 172, 163);
	gfx.PutPixel(6 + x, 1 + y, 211, 175, 161);
	gfx.PutPixel(7 + x, 1 + y, 210, 167, 150);
	gfx.PutPixel(8 + x, 1 + y, 214, 170, 161);
	gfx.PutPixel(9 + x, 1 + y, 216, 177, 162);
	gfx.PutPixel(10 + x, 1 + y, 212, 174, 155);
	gfx.PutPixel(11 + x, 1 + y, 212, 171, 153);
	gfx.PutPixel(12 + x, 1 + y, 211, 167, 154);
	gfx.PutPixel(13 + x, 1 + y, 206, 166, 158);
	gfx.PutPixel(14 + x, 1 + y, 192, 162, 154);
	gfx.PutPixel(15 + x, 1 + y, 141, 118, 110);
	gfx.PutPixel(16 + x, 1 + y, 122, 103, 96);
	gfx.PutPixel(17 + x, 1 + y, 119, 89, 81);
	gfx.PutPixel(18 + x, 1 + y, 152, 112, 100);
	gfx.PutPixel(19 + x, 1 + y, 182, 140, 124);
	gfx.PutPixel(0 + x, 2 + y, 141, 98, 89);
	gfx.PutPixel(1 + x, 2 + y, 109, 74, 72);
	gfx.PutPixel(2 + x, 2 + y, 82, 53, 57);
	gfx.PutPixel(3 + x, 2 + y, 65, 43, 45);
	gfx.PutPixel(4 + x, 2 + y, 60, 44, 44);
	gfx.PutPixel(5 + x, 2 + y, 101, 85, 85);
	gfx.PutPixel(6 + x, 2 + y, 158, 130, 126);
	gfx.PutPixel(7 + x, 2 + y, 193, 154, 139);
	gfx.PutPixel(8 + x, 2 + y, 211, 173, 170);
	gfx.PutPixel(9 + x, 2 + y, 210, 173, 164);
	gfx.PutPixel(10 + x, 2 + y, 222, 185, 169);
	gfx.PutPixel(11 + x, 2 + y, 210, 170, 158);
	gfx.PutPixel(12 + x, 2 + y, 173, 134, 127);
	gfx.PutPixel(13 + x, 2 + y, 128, 94, 93);
	gfx.PutPixel(14 + x, 2 + y, 87, 63, 61);
	gfx.PutPixel(15 + x, 2 + y, 75, 60, 55);
	gfx.PutPixel(16 + x, 2 + y, 112, 88, 88);
	gfx.PutPixel(17 + x, 2 + y, 130, 101, 97);
	gfx.PutPixel(18 + x, 2 + y, 142, 108, 99);
	gfx.PutPixel(19 + x, 2 + y, 165, 125, 115);
	gfx.PutPixel(0 + x, 3 + y, 142, 109, 100);
	gfx.PutPixel(1 + x, 3 + y, 144, 107, 101);
	gfx.PutPixel(2 + x, 3 + y, 147, 112, 106);
	gfx.PutPixel(3 + x, 3 + y, 151, 124, 113);
	gfx.PutPixel(4 + x, 3 + y, 130, 105, 98);
	gfx.PutPixel(5 + x, 3 + y, 124, 90, 88);
	gfx.PutPixel(6 + x, 3 + y, 114, 75, 70);
	gfx.PutPixel(7 + x, 3 + y, 147, 109, 98);
	gfx.PutPixel(8 + x, 3 + y, 183, 145, 136);
	gfx.PutPixel(9 + x, 3 + y, 200, 160, 152);
	gfx.PutPixel(10 + x, 3 + y, 207, 162, 156);
	gfx.PutPixel(11 + x, 3 + y, 192, 149, 142);
	gfx.PutPixel(12 + x, 3 + y, 165, 126, 119);
	gfx.PutPixel(13 + x, 3 + y, 161, 126, 120);
	gfx.PutPixel(14 + x, 3 + y, 164, 131, 124);
	gfx.PutPixel(15 + x, 3 + y, 200, 167, 158);
	gfx.PutPixel(16 + x, 3 + y, 224, 185, 180);
	gfx.PutPixel(17 + x, 3 + y, 207, 170, 162);
	gfx.PutPixel(18 + x, 3 + y, 185, 151, 142);
	gfx.PutPixel(19 + x, 3 + y, 182, 148, 139);
	gfx.PutPixel(0 + x, 4 + y, 164, 128, 128);
	gfx.PutPixel(1 + x, 4 + y, 177, 143, 133);
	gfx.PutPixel(2 + x, 4 + y, 199, 166, 147);
	gfx.PutPixel(3 + x, 4 + y, 224, 189, 170);
	gfx.PutPixel(4 + x, 4 + y, 229, 185, 172);
	gfx.PutPixel(5 + x, 4 + y, 212, 160, 146);
	gfx.PutPixel(6 + x, 4 + y, 196, 147, 130);
	gfx.PutPixel(7 + x, 4 + y, 175, 132, 115);
	gfx.PutPixel(8 + x, 4 + y, 178, 131, 113);
	gfx.PutPixel(9 + x, 4 + y, 183, 137, 122);
	gfx.PutPixel(10 + x, 4 + y, 196, 149, 139);
	gfx.PutPixel(11 + x, 4 + y, 192, 145, 135);
	gfx.PutPixel(12 + x, 4 + y, 195, 149, 134);
	gfx.PutPixel(13 + x, 4 + y, 208, 165, 148);
	gfx.PutPixel(14 + x, 4 + y, 213, 175, 162);
	gfx.PutPixel(15 + x, 4 + y, 213, 179, 169);
	gfx.PutPixel(16 + x, 4 + y, 199, 171, 159);
	gfx.PutPixel(17 + x, 4 + y, 200, 162, 153);
	gfx.PutPixel(18 + x, 4 + y, 206, 166, 156);
	gfx.PutPixel(19 + x, 4 + y, 197, 165, 154);
	gfx.PutPixel(0 + x, 5 + y, 181, 142, 135);
	gfx.PutPixel(1 + x, 5 + y, 170, 122, 112);
	gfx.PutPixel(2 + x, 5 + y, 146, 103, 96);
	gfx.PutPixel(3 + x, 5 + y, 130, 109, 106);
	gfx.PutPixel(4 + x, 5 + y, 84, 68, 68);
	gfx.PutPixel(5 + x, 5 + y, 133, 103, 95);
	gfx.PutPixel(6 + x, 5 + y, 196, 153, 137);
	gfx.PutPixel(7 + x, 5 + y, 195, 152, 133);
	gfx.PutPixel(8 + x, 5 + y, 196, 150, 134);
	gfx.PutPixel(9 + x, 5 + y, 202, 163, 148);
	gfx.PutPixel(10 + x, 5 + y, 207, 173, 161);
	gfx.PutPixel(11 + x, 5 + y, 210, 173, 157);
	gfx.PutPixel(12 + x, 5 + y, 208, 162, 146);
	gfx.PutPixel(13 + x, 5 + y, 200, 158, 144);
	gfx.PutPixel(14 + x, 5 + y, 127, 100, 93);
	gfx.PutPixel(15 + x, 5 + y, 44, 33, 31);
	gfx.PutPixel(16 + x, 5 + y, 124, 110, 101);
	gfx.PutPixel(17 + x, 5 + y, 135, 96, 91);
	gfx.PutPixel(18 + x, 5 + y, 167, 117, 108);
	gfx.PutPixel(19 + x, 5 + y, 202, 160, 144);
	gfx.PutPixel(0 + x, 6 + y, 176, 139, 121);
	gfx.PutPixel(1 + x, 6 + y, 161, 106, 99);
	gfx.PutPixel(2 + x, 6 + y, 139, 89, 88);
	gfx.PutPixel(3 + x, 6 + y, 148, 130, 130);
	gfx.PutPixel(4 + x, 6 + y, 34, 29, 33);
	gfx.PutPixel(5 + x, 6 + y, 97, 77, 79);
	gfx.PutPixel(6 + x, 6 + y, 162, 125, 117);
	gfx.PutPixel(7 + x, 6 + y, 202, 164, 145);
	gfx.PutPixel(8 + x, 6 + y, 197, 154, 145);
	gfx.PutPixel(9 + x, 6 + y, 214, 177, 168);
	gfx.PutPixel(10 + x, 6 + y, 223, 189, 179);
	gfx.PutPixel(11 + x, 6 + y, 211, 175, 163);
	gfx.PutPixel(12 + x, 6 + y, 213, 173, 161);
	gfx.PutPixel(13 + x, 6 + y, 177, 140, 131);
	gfx.PutPixel(14 + x, 6 + y, 129, 104, 100);
	gfx.PutPixel(15 + x, 6 + y, 62, 47, 50);
	gfx.PutPixel(16 + x, 6 + y, 166, 143, 137);
	gfx.PutPixel(17 + x, 6 + y, 184, 145, 138);
	gfx.PutPixel(18 + x, 6 + y, 183, 135, 125);
	gfx.PutPixel(19 + x, 6 + y, 198, 155, 139);
	gfx.PutPixel(0 + x, 7 + y, 184, 147, 139);
	gfx.PutPixel(1 + x, 7 + y, 184, 146, 137);
	gfx.PutPixel(2 + x, 7 + y, 190, 151, 136);
	gfx.PutPixel(3 + x, 7 + y, 195, 154, 136);
	gfx.PutPixel(4 + x, 7 + y, 186, 142, 129);
	gfx.PutPixel(5 + x, 7 + y, 193, 145, 141);
	gfx.PutPixel(6 + x, 7 + y, 203, 159, 150);
	gfx.PutPixel(7 + x, 7 + y, 203, 165, 146);
	gfx.PutPixel(8 + x, 7 + y, 199, 155, 144);
	gfx.PutPixel(9 + x, 7 + y, 211, 163, 153);
	gfx.PutPixel(10 + x, 7 + y, 223, 175, 165);
	gfx.PutPixel(11 + x, 7 + y, 216, 169, 159);
	gfx.PutPixel(12 + x, 7 + y, 213, 173, 161);
	gfx.PutPixel(13 + x, 7 + y, 217, 177, 165);
	gfx.PutPixel(14 + x, 7 + y, 205, 162, 153);
	gfx.PutPixel(15 + x, 7 + y, 212, 165, 157);
	gfx.PutPixel(16 + x, 7 + y, 217, 179, 168);
	gfx.PutPixel(17 + x, 7 + y, 219, 186, 171);
	gfx.PutPixel(18 + x, 7 + y, 215, 186, 170);
	gfx.PutPixel(19 + x, 7 + y, 210, 178, 165);
	gfx.PutPixel(0 + x, 8 + y, 186, 152, 142);
	gfx.PutPixel(1 + x, 8 + y, 197, 163, 153);
	gfx.PutPixel(2 + x, 8 + y, 207, 173, 163);
	gfx.PutPixel(3 + x, 8 + y, 216, 182, 172);
	gfx.PutPixel(4 + x, 8 + y, 219, 182, 173);
	gfx.PutPixel(5 + x, 8 + y, 220, 182, 173);
	gfx.PutPixel(6 + x, 8 + y, 218, 178, 170);
	gfx.PutPixel(7 + x, 8 + y, 204, 161, 154);
	gfx.PutPixel(8 + x, 8 + y, 203, 156, 150);
	gfx.PutPixel(9 + x, 8 + y, 209, 160, 153);
	gfx.PutPixel(10 + x, 8 + y, 215, 167, 157);
	gfx.PutPixel(11 + x, 8 + y, 212, 165, 155);
	gfx.PutPixel(12 + x, 8 + y, 207, 167, 157);
	gfx.PutPixel(13 + x, 8 + y, 219, 182, 173);
	gfx.PutPixel(14 + x, 8 + y, 226, 189, 181);
	gfx.PutPixel(15 + x, 8 + y, 225, 187, 178);
	gfx.PutPixel(16 + x, 8 + y, 227, 194, 185);
	gfx.PutPixel(17 + x, 8 + y, 231, 198, 189);
	gfx.PutPixel(18 + x, 8 + y, 226, 192, 183);
	gfx.PutPixel(19 + x, 8 + y, 222, 188, 179);
	gfx.PutPixel(0 + x, 9 + y, 201, 164, 155);
	gfx.PutPixel(1 + x, 9 + y, 209, 175, 165);
	gfx.PutPixel(2 + x, 9 + y, 220, 186, 177);
	gfx.PutPixel(3 + x, 9 + y, 219, 185, 176);
	gfx.PutPixel(4 + x, 9 + y, 220, 186, 176);
	gfx.PutPixel(5 + x, 9 + y, 220, 182, 173);
	gfx.PutPixel(6 + x, 9 + y, 215, 175, 167);
	gfx.PutPixel(7 + x, 9 + y, 203, 160, 151);
	gfx.PutPixel(8 + x, 9 + y, 198, 151, 143);
	gfx.PutPixel(9 + x, 9 + y, 199, 152, 146);
	gfx.PutPixel(10 + x, 9 + y, 212, 167, 161);
	gfx.PutPixel(11 + x, 9 + y, 205, 160, 154);
	gfx.PutPixel(12 + x, 9 + y, 205, 163, 151);
	gfx.PutPixel(13 + x, 9 + y, 220, 180, 168);
	gfx.PutPixel(14 + x, 9 + y, 221, 183, 172);
	gfx.PutPixel(15 + x, 9 + y, 231, 194, 186);
	gfx.PutPixel(16 + x, 9 + y, 228, 195, 188);
	gfx.PutPixel(17 + x, 9 + y, 236, 203, 196);
	gfx.PutPixel(18 + x, 9 + y, 233, 198, 192);
	gfx.PutPixel(19 + x, 9 + y, 225, 190, 184);
	gfx.PutPixel(0 + x, 10 + y, 206, 169, 161);
	gfx.PutPixel(1 + x, 10 + y, 214, 180, 171);
	gfx.PutPixel(2 + x, 10 + y, 220, 185, 179);
	gfx.PutPixel(3 + x, 10 + y, 220, 187, 180);
	gfx.PutPixel(4 + x, 10 + y, 219, 184, 178);
	gfx.PutPixel(5 + x, 10 + y, 216, 177, 170);
	gfx.PutPixel(6 + x, 10 + y, 208, 165, 158);
	gfx.PutPixel(7 + x, 10 + y, 188, 144, 135);
	gfx.PutPixel(8 + x, 10 + y, 193, 138, 131);
	gfx.PutPixel(9 + x, 10 + y, 202, 151, 148);
	gfx.PutPixel(10 + x, 10 + y, 218, 168, 169);
	gfx.PutPixel(11 + x, 10 + y, 219, 169, 168);
	gfx.PutPixel(12 + x, 10 + y, 205, 155, 146);
	gfx.PutPixel(13 + x, 10 + y, 204, 155, 141);
	gfx.PutPixel(14 + x, 10 + y, 226, 179, 169);
	gfx.PutPixel(15 + x, 10 + y, 228, 185, 178);
	gfx.PutPixel(16 + x, 10 + y, 227, 192, 188);
	gfx.PutPixel(17 + x, 10 + y, 236, 201, 197);
	gfx.PutPixel(18 + x, 10 + y, 232, 197, 193);
	gfx.PutPixel(19 + x, 10 + y, 223, 188, 184);
	gfx.PutPixel(0 + x, 11 + y, 202, 165, 157);
	gfx.PutPixel(1 + x, 11 + y, 215, 180, 174);
	gfx.PutPixel(2 + x, 11 + y, 221, 186, 182);
	gfx.PutPixel(3 + x, 11 + y, 219, 184, 180);
	gfx.PutPixel(4 + x, 11 + y, 217, 180, 174);
	gfx.PutPixel(5 + x, 11 + y, 216, 173, 167);
	gfx.PutPixel(6 + x, 11 + y, 191, 142, 135);
	gfx.PutPixel(7 + x, 11 + y, 179, 126, 120);
	gfx.PutPixel(8 + x, 11 + y, 194, 143, 139);
	gfx.PutPixel(9 + x, 11 + y, 217, 172, 169);
	gfx.PutPixel(10 + x, 11 + y, 220, 176, 177);
	gfx.PutPixel(11 + x, 11 + y, 227, 183, 182);
	gfx.PutPixel(12 + x, 11 + y, 209, 160, 155);
	gfx.PutPixel(13 + x, 11 + y, 192, 144, 134);
	gfx.PutPixel(14 + x, 11 + y, 200, 158, 146);
	gfx.PutPixel(15 + x, 11 + y, 226, 190, 178);
	gfx.PutPixel(16 + x, 11 + y, 229, 194, 190);
	gfx.PutPixel(17 + x, 11 + y, 233, 198, 194);
	gfx.PutPixel(18 + x, 11 + y, 227, 192, 188);
	gfx.PutPixel(19 + x, 11 + y, 219, 186, 179);
	gfx.PutPixel(0 + x, 12 + y, 201, 167, 158);
	gfx.PutPixel(1 + x, 12 + y, 206, 171, 165);
	gfx.PutPixel(2 + x, 12 + y, 220, 185, 179);
	gfx.PutPixel(3 + x, 12 + y, 224, 187, 181);
	gfx.PutPixel(4 + x, 12 + y, 219, 178, 174);
	gfx.PutPixel(5 + x, 12 + y, 205, 157, 153);
	gfx.PutPixel(6 + x, 12 + y, 174, 121, 115);
	gfx.PutPixel(7 + x, 12 + y, 195, 138, 131);
	gfx.PutPixel(8 + x, 12 + y, 188, 132, 135);
	gfx.PutPixel(9 + x, 12 + y, 193, 143, 144);
	gfx.PutPixel(10 + x, 12 + y, 216, 168, 168);
	gfx.PutPixel(11 + x, 12 + y, 202, 152, 153);
	gfx.PutPixel(12 + x, 12 + y, 202, 148, 148);
	gfx.PutPixel(13 + x, 12 + y, 199, 145, 143);
	gfx.PutPixel(14 + x, 12 + y, 190, 143, 135);
	gfx.PutPixel(15 + x, 12 + y, 213, 176, 160);
	gfx.PutPixel(16 + x, 12 + y, 230, 193, 187);
	gfx.PutPixel(17 + x, 12 + y, 231, 197, 188);
	gfx.PutPixel(18 + x, 12 + y, 222, 188, 179);
	gfx.PutPixel(19 + x, 12 + y, 214, 180, 171);
	gfx.PutPixel(0 + x, 13 + y, 187, 153, 144);
	gfx.PutPixel(1 + x, 13 + y, 196, 162, 153);
	gfx.PutPixel(2 + x, 13 + y, 212, 175, 167);
	gfx.PutPixel(3 + x, 13 + y, 215, 176, 169);
	gfx.PutPixel(4 + x, 13 + y, 215, 172, 165);
	gfx.PutPixel(5 + x, 13 + y, 204, 155, 150);
	gfx.PutPixel(6 + x, 13 + y, 180, 127, 121);
	gfx.PutPixel(7 + x, 13 + y, 161, 104, 97);
	gfx.PutPixel(8 + x, 13 + y, 131, 69, 74);
	gfx.PutPixel(9 + x, 13 + y, 157, 97, 99);
	gfx.PutPixel(10 + x, 13 + y, 170, 112, 111);
	gfx.PutPixel(11 + x, 13 + y, 159, 100, 102);
	gfx.PutPixel(12 + x, 13 + y, 142, 82, 84);
	gfx.PutPixel(13 + x, 13 + y, 194, 135, 137);
	gfx.PutPixel(14 + x, 13 + y, 206, 153, 147);
	gfx.PutPixel(15 + x, 13 + y, 215, 169, 156);
	gfx.PutPixel(16 + x, 13 + y, 222, 185, 176);
	gfx.PutPixel(17 + x, 13 + y, 226, 189, 180);
	gfx.PutPixel(18 + x, 13 + y, 216, 182, 172);
	gfx.PutPixel(19 + x, 13 + y, 205, 171, 161);
	gfx.PutPixel(0 + x, 14 + y, 178, 141, 133);
	gfx.PutPixel(1 + x, 14 + y, 187, 150, 142);
	gfx.PutPixel(2 + x, 14 + y, 202, 164, 155);
	gfx.PutPixel(3 + x, 14 + y, 207, 167, 157);
	gfx.PutPixel(4 + x, 14 + y, 202, 159, 150);
	gfx.PutPixel(5 + x, 14 + y, 197, 153, 142);
	gfx.PutPixel(6 + x, 14 + y, 202, 155, 145);
	gfx.PutPixel(7 + x, 14 + y, 181, 133, 123);
	gfx.PutPixel(8 + x, 14 + y, 185, 134, 130);
	gfx.PutPixel(9 + x, 14 + y, 193, 142, 139);
	gfx.PutPixel(10 + x, 14 + y, 176, 125, 122);
	gfx.PutPixel(11 + x, 14 + y, 198, 147, 144);
	gfx.PutPixel(12 + x, 14 + y, 194, 147, 141);
	gfx.PutPixel(13 + x, 14 + y, 200, 157, 148);
	gfx.PutPixel(14 + x, 14 + y, 208, 168, 158);
	gfx.PutPixel(15 + x, 14 + y, 216, 178, 167);
	gfx.PutPixel(16 + x, 14 + y, 215, 177, 166);
	gfx.PutPixel(17 + x, 14 + y, 220, 182, 171);
	gfx.PutPixel(18 + x, 14 + y, 212, 176, 164);
	gfx.PutPixel(19 + x, 14 + y, 201, 167, 155);
	gfx.PutPixel(0 + x, 15 + y, 179, 140, 133);
	gfx.PutPixel(1 + x, 15 + y, 178, 140, 131);
	gfx.PutPixel(2 + x, 15 + y, 190, 152, 141);
	gfx.PutPixel(3 + x, 15 + y, 194, 154, 142);
	gfx.PutPixel(4 + x, 15 + y, 196, 157, 142);
	gfx.PutPixel(5 + x, 15 + y, 197, 157, 145);
	gfx.PutPixel(6 + x, 15 + y, 189, 149, 137);
	gfx.PutPixel(7 + x, 15 + y, 195, 155, 145);
	gfx.PutPixel(8 + x, 15 + y, 200, 156, 143);
	gfx.PutPixel(9 + x, 15 + y, 197, 150, 142);
	gfx.PutPixel(10 + x, 15 + y, 191, 142, 138);
	gfx.PutPixel(11 + x, 15 + y, 204, 157, 151);
	gfx.PutPixel(12 + x, 15 + y, 207, 168, 153);
	gfx.PutPixel(13 + x, 15 + y, 205, 170, 151);
	gfx.PutPixel(14 + x, 15 + y, 206, 173, 158);
	gfx.PutPixel(15 + x, 15 + y, 209, 177, 166);
	gfx.PutPixel(16 + x, 15 + y, 212, 172, 162);
	gfx.PutPixel(17 + x, 15 + y, 212, 174, 163);
	gfx.PutPixel(18 + x, 15 + y, 205, 169, 157);
	gfx.PutPixel(19 + x, 15 + y, 201, 167, 155);
	gfx.PutPixel(0 + x, 16 + y, 182, 143, 136);
	gfx.PutPixel(1 + x, 16 + y, 180, 140, 132);
	gfx.PutPixel(2 + x, 16 + y, 186, 148, 135);
	gfx.PutPixel(3 + x, 16 + y, 190, 153, 137);
	gfx.PutPixel(4 + x, 16 + y, 182, 146, 130);
	gfx.PutPixel(5 + x, 16 + y, 178, 140, 129);
	gfx.PutPixel(6 + x, 16 + y, 175, 134, 128);
	gfx.PutPixel(7 + x, 16 + y, 168, 124, 121);
	gfx.PutPixel(8 + x, 16 + y, 149, 92, 98);
	gfx.PutPixel(9 + x, 16 + y, 163, 96, 103);
	gfx.PutPixel(10 + x, 16 + y, 172, 101, 107);
	gfx.PutPixel(11 + x, 16 + y, 170, 105, 109);
	gfx.PutPixel(12 + x, 16 + y, 163, 107, 108);
	gfx.PutPixel(13 + x, 16 + y, 183, 134, 130);
	gfx.PutPixel(14 + x, 16 + y, 193, 153, 141);
	gfx.PutPixel(15 + x, 16 + y, 192, 161, 140);
	gfx.PutPixel(16 + x, 16 + y, 208, 168, 156);
	gfx.PutPixel(17 + x, 16 + y, 206, 170, 158);
	gfx.PutPixel(18 + x, 16 + y, 204, 172, 161);
	gfx.PutPixel(19 + x, 16 + y, 201, 171, 161);
	gfx.PutPixel(0 + x, 17 + y, 175, 142, 133);
	gfx.PutPixel(1 + x, 17 + y, 190, 156, 146);
	gfx.PutPixel(2 + x, 17 + y, 181, 145, 131);
	gfx.PutPixel(3 + x, 17 + y, 183, 146, 130);
	gfx.PutPixel(4 + x, 17 + y, 188, 149, 134);
	gfx.PutPixel(5 + x, 17 + y, 167, 123, 114);
	gfx.PutPixel(6 + x, 17 + y, 121, 72, 67);
	gfx.PutPixel(7 + x, 17 + y, 108, 54, 54);
	gfx.PutPixel(8 + x, 17 + y, 129, 63, 77);
	gfx.PutPixel(9 + x, 17 + y, 143, 69, 84);
	gfx.PutPixel(10 + x, 17 + y, 148, 70, 86);
	gfx.PutPixel(11 + x, 17 + y, 151, 79, 93);
	gfx.PutPixel(12 + x, 17 + y, 132, 69, 80);
	gfx.PutPixel(13 + x, 17 + y, 118, 61, 68);
	gfx.PutPixel(14 + x, 17 + y, 144, 94, 93);
	gfx.PutPixel(15 + x, 17 + y, 194, 151, 144);
	gfx.PutPixel(16 + x, 17 + y, 208, 168, 156);
	gfx.PutPixel(17 + x, 17 + y, 207, 171, 159);
	gfx.PutPixel(18 + x, 17 + y, 206, 174, 163);
	gfx.PutPixel(19 + x, 17 + y, 204, 174, 163);
	gfx.PutPixel(0 + x, 18 + y, 176, 143, 134);
	gfx.PutPixel(1 + x, 18 + y, 176, 142, 132);
	gfx.PutPixel(2 + x, 18 + y, 179, 141, 128);
	gfx.PutPixel(3 + x, 18 + y, 185, 146, 131);
	gfx.PutPixel(4 + x, 18 + y, 184, 142, 128);
	gfx.PutPixel(5 + x, 18 + y, 190, 143, 133);
	gfx.PutPixel(6 + x, 18 + y, 182, 129, 123);
	gfx.PutPixel(7 + x, 18 + y, 167, 112, 109);
	gfx.PutPixel(8 + x, 18 + y, 176, 119, 125);
	gfx.PutPixel(9 + x, 18 + y, 180, 115, 121);
	gfx.PutPixel(10 + x, 18 + y, 182, 112, 120);
	gfx.PutPixel(11 + x, 18 + y, 186, 124, 129);
	gfx.PutPixel(12 + x, 18 + y, 177, 122, 125);
	gfx.PutPixel(13 + x, 18 + y, 189, 138, 137);
	gfx.PutPixel(14 + x, 18 + y, 207, 160, 154);
	gfx.PutPixel(15 + x, 18 + y, 205, 165, 155);
	gfx.PutPixel(16 + x, 18 + y, 206, 167, 152);
	gfx.PutPixel(17 + x, 18 + y, 203, 167, 153);
	gfx.PutPixel(18 + x, 18 + y, 202, 170, 159);
	gfx.PutPixel(19 + x, 18 + y, 201, 169, 158);
	gfx.PutPixel(0 + x, 19 + y, 170, 131, 124);
	gfx.PutPixel(1 + x, 19 + y, 179, 139, 131);
	gfx.PutPixel(2 + x, 19 + y, 182, 142, 130);
	gfx.PutPixel(3 + x, 19 + y, 179, 137, 123);
	gfx.PutPixel(4 + x, 19 + y, 180, 138, 124);
	gfx.PutPixel(5 + x, 19 + y, 181, 139, 125);
	gfx.PutPixel(6 + x, 19 + y, 186, 142, 131);
	gfx.PutPixel(7 + x, 19 + y, 188, 141, 133);
	gfx.PutPixel(8 + x, 19 + y, 185, 141, 130);
	gfx.PutPixel(9 + x, 19 + y, 166, 116, 107);
	gfx.PutPixel(10 + x, 19 + y, 159, 106, 98);
	gfx.PutPixel(11 + x, 19 + y, 182, 135, 125);
	gfx.PutPixel(12 + x, 19 + y, 197, 158, 143);
	gfx.PutPixel(13 + x, 19 + y, 206, 167, 152);
	gfx.PutPixel(14 + x, 19 + y, 207, 170, 152);
	gfx.PutPixel(15 + x, 19 + y, 200, 167, 148);
	gfx.PutPixel(16 + x, 19 + y, 205, 168, 152);
	gfx.PutPixel(17 + x, 19 + y, 203, 167, 153);
	gfx.PutPixel(18 + x, 19 + y, 200, 166, 154);
	gfx.PutPixel(19 + x, 19 + y, 196, 164, 153);
}

bool Dude::IsCollide(int x2, int y2, int width2, int height2)
{
	const int box1Left = x;
	const int box1Right = x + width - 1;
	const int box1Up = y;
	const int box1Down = y + height - 1;
	const int box2Left = x2;
	const int box2Right = x2 + width2 - 1;
	const int box2Up = y2;
	const int box2Down = y2 + height2 - 1;
	return box1Left <= box2Right && box1Right >= box2Left &&
		box1Up <= box2Down && box1Down >= box2Up;
}

void Dude::AddX(int a)
{
	x += a;
}

void Dude::AddY(int a)
{
	y += a;
}

int Dude::GetX() const
{
	return x;
}

int Dude::GetY() const
{
	return y;
}
