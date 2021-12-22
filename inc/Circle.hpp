#pragma once
#include <iostream>
#include <Circle.hpp>
#include <Rectangle.hpp>

namespace cir {
	class Circle {
	private:
		int coorx, coory, radius, speed;
	public:
		int getcoorx();
		void setcoorx(int valuex);
		int getcoory();
		void setcoory(int valuey);
		int getradius();
		void setradius(double valueradius);
		int getspeed();
		void setspeed(double valuespeed);
		void move_right(int speed);
		void move_left(int speed);
		void move_x(int x, int speed);
		void move_y(int y, int speed);
	};
}
	
