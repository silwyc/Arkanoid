#include <Circle.hpp>

namespace cir {
	int Circle::getcoorx() {
		return coorx;
	}
	void Circle::setcoorx(int valuex) {
		coorx = valuex;
	}
	int Circle::getcoory() {
		return coory;
	}
	void Circle::setcoory(int valuey) {
		coory = valuey;
	}
	int Circle::getradius() {
		return radius;
	}
	void Circle::setradius(double valueradius) {
		radius = valueradius;
	}
	int Circle::getspeed() {
		return speed;
	}
	void Circle::setspeed(double valuespeed) {
		speed = valuespeed;
	}
	void Circle::move_right(int speed) {
		coorx += speed;
	}
	void Circle::move_left(int speed) {
		coorx -= speed;
	}
	void Circle::move_x(int x, int speed) {
		coorx = x + speed;
	}
	void Circle::move_y(int y, int speed) {
		coory = y + speed;
	}
}
