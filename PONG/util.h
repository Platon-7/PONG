#pragma once
#include <random>
#include <iostream>

float rand0to1();


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