#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// addr,en,rw,rs,d4,d5,d6,d7,bl,blpol
// addr can be 0x3F or 0x27
#define tripin 11
#define echopin 10
#define IR1Pin 4 
#define IR2Pin 7
int IR1_Val = 0, IR2_Val = 0;
//commit sommgmmgth


// left 9 6
// right 5 3

#define left_a 9
#define left_b 6
#define right_a 5
#define right_b 3
void move(int x, int y, int z, int v);
char x;
int y, z;


void setup() {
	pinMode(9, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4,INPUT_PULLUP);
	pinMode(7,INPUT_PULLUP);
	Serial.begin(9600);

}

// the loop function runs over and over again until power down or reset
// x -> direction, y -> action, z -> delay, v -> speed
// y, 1 -> no run, 2 -> forward, 3 -> reverse, 4 -> brake
// z -> delay
// v -> speed
void loop() {
  move( 3 , 2 , 2000 , 200);
}

void move(int x, int y, int z, int v)
{
	int c, d;
	switch (y)
	{
	case 1:
	{
		c = 0;
		d = 0;
		// no run
	}
		break;
	case 2:
	{
		c = 0;
		d = v;
		// forward
	}
		break;
	case 3:
	{
		c = v;
		d = 0;
		// reverse
	}
		break;
	case 4:
	{
		c = 200;
		d = 200;
		// brake
	}
		break;
	}
		switch (x)
		{
		case 1:
		{
			analogWrite(left_a, c);
			analogWrite(left_b, d);
			delay(z);
			analogWrite(left_a, 200);
			analogWrite(left_b, 200);
			return;
			// left
		}
		break;
		case 2:
		{
			analogWrite(right_a, c);
			analogWrite(right_b, d);
			delay(z);
			analogWrite(right_a, 200);
			analogWrite(right_b, 200);
			return;
			// right
		}
		break;
		case 3:
		{
			analogWrite(left_a, c);
			analogWrite(left_b, d);
			analogWrite(right_a, c);
			analogWrite(right_b, d);
			delay(z);
			analogWrite(left_a, 200);
			analogWrite(left_b, 200);
			analogWrite(right_a, 200);
			analogWrite(right_b, 200);
			return;
			// both
		}
		break;
		}
}

