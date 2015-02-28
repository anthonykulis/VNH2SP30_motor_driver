
#include "Arduino.h"
#include "VNH2SP30.h"

VNH2SP30::VNH2SP30(){
	left_speed = right_speed = left_direction = right_direction = 0;
}


void VNH2SP30::setLeftInControlPins(int a, int b){
	left_in_a = a;
	left_in_b = b;
}

void VNH2SP30::setRightInControlPins(int a, int b){
	right_in_a = a;
	right_in_b = b;
}

void VNH2SP30::setPWMPins(int left, int right){
	pwm_left = left;
	pwm_right = right;
}

// possible are VNH2SP30::LEFT, VNH2SP30::RIGHT
void VNH2SP30::counterClockwise(int SIDE){

	if(SIDE == LEFT){
		digitalWrite(left_in_a, LOW);
		digitalWrite(left_in_b, HIGH);
		left_direction = 1;
	}
	else if(SIDE == RIGHT){
		digitalWrite(right_in_a, LOW);
		digitalWrite(right_in_b, HIGH);
		right_direction = 1;
	}

}

void VNH2SP30::clockwise(int SIDE){

	if(SIDE == LEFT){
		digitalWrite(left_in_a, HIGH);
		digitalWrite(left_in_b, LOW);
		left_direction = 1;
	}
	else if(SIDE == RIGHT){
		digitalWrite(right_in_a, HIGH);
		digitalWrite(right_in_b, LOW);
		right_direction = 1;
	}
}

void VNH2SP30::speedup(int amount){
	left_speed += amount;
	right_speed += amount;

	if(left_speed > 255) left_speed = 255;
	if(right_speed > 255) right_speed = 255;

	_setSpeeds();
}

void VNH2SP30::slowdown(int amount){
	left_speed -= amount;
	right_speed -= amount;

	if(left_speed < 0) left_speed = 0;
	if(right_speed < 0) right_speed = 0;

	_setSpeeds();
}

void VNH2SP30::setRightSpeed(int speed){
	if(speed > 255) speed = 255;
	else if(speed < 0) speed = 0;
	right_speed = speed;
	_setSpeeds(false);
}

void VNH2SP30::setLeftSpeed(int speed){
	if(speed > 255) speed = 255;
	else if(speed < 0) speed = 0;
	left_speed = speed;
	_setSpeeds(true, false);
}


void VNH2SP30::brake(){
	digitalWrite(left_in_a, left_direction ? LOW : HIGH);
	digitalWrite(left_in_b, left_direction ? LOW : HIGH);
	digitalWrite(right_in_a, right_direction ? LOW : HIGH);
	digitalWrite(right_in_b, right_direction ? LOW : HIGH);
	left_speed = right_speed = 0;
	_setSpeeds();
}

void VNH2SP30::fullSpeed(){
	left_speed = right_speed = 255;
	_setSpeeds();
}


void VNH2SP30::_setSpeeds(bool left, bool right){
	if(left) analogWrite(pwm_left, left_speed);
	if(right) analogWrite(pwm_right, right_speed);	
}