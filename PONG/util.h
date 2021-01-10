#pragma once
#include <random>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

float rand0to1();

float randOper(float a, float b) {
	srand(time(NULL));
	int rNUM = rand() % 2;
	if (rNUM == 0) {
		return a + b;
	}
	else {
		return a - b;
	}
}
int rangeRandom(int min, int max) {
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	do {
		x = rand();
	} while (x >= RAND_MAX - remainder);
	return min + x % n;
}

struct Disk
{
	float cx, cy;
	float radius;
};
struct Rectangle
{
	float rx, ry;
	float rw, rh;

};