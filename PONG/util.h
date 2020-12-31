#include <random>
float rand0to1()
{
	return rand() / (float)RAND_MAX;
}
float randOper()
{
	char math_op = "+-"[rand() % 2];
	return math_op;
}