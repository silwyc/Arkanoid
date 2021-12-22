#include <Rectangle.hpp>

namespace rec {
	int Rectangle::move_right(int speed) {
		return coorx += speed;
	}
	int Rectangle::move_left(int speed) {
		return coorx -= speed;
	}
	int Rectangle::getcoorx() {
		return coorx;
	}
	void Rectangle::setcoorx(int valuex) {
		coorx = valuex;
	}
	int Rectangle::getcoory() {
		return coory;
	}
	void Rectangle::setcoory(int valuey) {
		coory = valuey;
	}
	int Rectangle::getwidht_x() {
		return width;
	}
	void Rectangle::setwidht_x(int valuex) {
		width = valuex;
	}
	int Rectangle::getlenght_y() {
		return lenght;
	}
	void Rectangle::setlenght_y(int valuey) {
		lenght = valuey;
	}
	int Rectangle::getspeed() {
		return speed;
	}
	void Rectangle::setspeed(double valuespeed) {
		speed = valuespeed;
	}
}
	


