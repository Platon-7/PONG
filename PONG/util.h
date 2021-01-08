#pragma once
#include <random>
float rand0to1();

float randOper()
{
	char math_op = "+-"[rand() % 2];
	return math_op;
}

struct Disk
{
	float cx, cy;
	float radius;
};
struct Line
{
	float rx, ry;
	float r1x,r2x,r1y,r2y;

};
struct Rectangle
{
	float rx, ry;
	float rw, rh;

};