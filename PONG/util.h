#pragma once
#include <random>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

float rand0to1();// pairnw tyxaious arithmous apo 0 mexri 1

float randOper(float a, float b) {// pairno random operator h '+' h '-' gia thn arxikopoihsh ths mpalas 
	srand(time(NULL));
	int rNUM = rand() % 2;
	if (rNUM == 0) {
		return a + b;
	}
	else {
		return a - b;
	}
}
int rangeRandom(int min, int max) {// mia synarthsh poy ths dinw anw kai katw orio kai moy epistrefei ena tyxaio noymero poy einai bounded apo ta inputs poy edwsa
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	srand(time(NULL));
	do {
		x = rand();
	} while (x >= RAND_MAX - remainder);
	return min + x % n;
}

struct Disk// structs poy tha bohthsoyn sta collisions
{
	float cx, cy;
	float radius;
};
struct Rectangle
{
	float rx, ry;
	float rw, rh;

};