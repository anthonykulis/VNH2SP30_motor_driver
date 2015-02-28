


class VNH2SP30 {


public:

	// constructor
	VNH2SP30();
	
	// configuration
	void setLeftInControlPins(int a, int b);
	void setRightInControlPins(int a, int b);
	void setPWMPins(int left, int right);
	
	// direction control
	void counterClockwise(int pin);
	void clockwise(int pin);

	// speed control
	void speedup(int amount=10);
	void slowdown(int amount=10);
	void setLeftSpeed(int speed);
	void setRightSpeed(int speed);
	inline int getRightSpeed(){ return right_speed; }
	inline int getLeftSpeed(){ return left_speed; }
	void brake();
	void fullSpeed();

	static const int LEFT = 0;
	static const int RIGHT = 1;

private:

	int left_speed;
	int right_speed;

	// 0 is cw, 1 is ccw
	int left_direction;
	int right_direction;

	int left_in_a;
	int left_in_b;
	int right_in_a;
	int right_in_b;

	int pwm_left;
	int pwm_right;

	void _setSpeeds(bool left=true, bool right=true);
};	