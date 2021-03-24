#define _CRT_SECURE_NO_WARNINGS 1
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#define PWMA 1
#define AIN2 2
#define AIN1 3

#define PWMB 4
#define BIN1 6
#define BIN2 5

void init() {
	if (wiringPiSetup() == -1)
		printf("init unsuccessfully..\n");
	else printf("init successfully..\n");
	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);

	softPwmCreate(PWMA, 0, 255);
	softPwmCreate(PWMB, 0, 255);
	printf("soft pwm create successfully..\n");
}

void run1() {
	digitalWrite(AIN1, 1);
	digitalWrite(AIN2, 0);
	softPwmWrite(PWMA, 150);
	printf("mode1: AIN1-H AIN2-L\n");
	delay(3000);
	softPwmWrite(PWMA, 0);
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 0);
}
void run2() {
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 1);
	softPwmWrite(PWMA, 150);
	printf("mode2: AIN1-L AIN2-H\n");
	delay(3000);
	softPwmWrite(PWMA, 0);
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 0);
}
void run3() {
	digitalWrite(BIN1, 1);
	digitalWrite(BIN2, 0);
	softPwmWrite(PWMB, 150);
	printf("mode3: BIN1-H BIN2-L\n");
	delay(3000);
	softPwmWrite(PWMB, 0);
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 0);
}
void run4() {
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 1);
	softPwmWrite(PWMB, 150);
	printf("mode4: BIN1-L BIN2-H\n");
	delay(3000);
	softPwmWrite(PWMB, 0);
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 0);
}


void go_ahead(int time) {
	softPwmWrite(PWMA, 150);
	softPwmWrite(PWMB, 150);
	digitalWrite(BIN1, 1);
	digitalWrite(BIN2, 0);
	digitalWrite(AIN1, 1);
	digitalWrite(AIN2, 0);
	printf("mode1:go ahead..H-L-H-L\n");
	delay(time);
	softPwmWrite(PWMA, 0);
	softPwmWrite(PWMB, 0);
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 0);
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 0);
	printf("mode1 end..\n");
}

void go_back(int time) {
	softPwmWrite(PWMA, 150);
	softPwmWrite(PWMB, 150);
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 1);
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 1);
	printf("mode2:go back..L-H-L-H\n");
	delay(time);
	softPwmWrite(PWMA, 0);
	softPwmWrite(PWMB, 0);
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 0);
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 0);
	printf("mode2 end..\n");
}

void turn_left(int time) {
	softPwmWrite(PWMB, 150);
	digitalWrite(BIN1, 1);
	digitalWrite(BIN2, 0);
	printf("mode3:turn left..L-L-H-L\n");
	delay(time);
	softPwmWrite(PWMB, 0);
	digitalWrite(BIN1, 0);
	digitalWrite(BIN2, 0);
	printf("mode3 end..\n");
}

void turn_right(int time) {
	softPwmWrite(PWMA, 150);
	digitalWrite(AIN1, 1);
	digitalWrite(AIN2, 0);
	printf("mode4:turn right..H-L-L-L\n");
	delay(time);
	softPwmWrite(PWMA, 0);
	digitalWrite(BIN1, 1);
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 0);
	printf("mode4 end..\n");
}

void control() {
	init();
	char c = '0';
	int time = 250;
	while (c != 'q') {
		system("stty raw");
		c = getchar();
		system("stty -raw");
		switch (c) {
		case 'w': go_ahead(time); delay(50); break;
		case 's': go_back(time); delay(50); break;
		case 'a': turn_left(time); delay(50); break;
		case 'd': turn_right(time); delay(50); break;
		default: break;
		}
	}
	printf("demo end..\n");
}

void auto_control(char  command[]) {
	init();
	int index = 0;
	int time = 1500;
	go_ahead(time);
	while (command[index] != '\0') {
		switch (command[index]) {
		case 'w': go_ahead(time); break;
		case 's': go_back(time); break;
		case 'a': turn_left(time); break;
		case 'd': turn_right(time); break;
		default: break;
		}
		index++;
		delay(50);
	}
	printf("demo end..\n");
}


int main() {
	char command[13] = { 'w','w','a','w','w','a','w','w','a','w', 'w', 'a', '\0' };
	softPwmWrite(PWMA, 150);
	softPwmWrite(PWMB, 150);
	auto_control(command);
	softPwmWrite(PWMA, 0);
	softPwmWrite(PWMB, 0);
	return 0;
}