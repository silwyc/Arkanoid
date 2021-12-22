#pragma once
#include <iostream>
namespace rec {
	class Rectangle
	{
	private:
		int coorx, coory, width, lenght, speed;
	public:
		int move_right(int speed);
		int move_left(int speed);
		int getcoorx();
		void setcoorx(int valuex);
		int getcoory();
		void setcoory(int valuey);
		int getwidht_x();
		void setwidht_x(int valuex);
		int getlenght_y();
		void setlenght_y(int valuey);
		int getspeed();
		void setspeed(double valuespeed);
	};
}

