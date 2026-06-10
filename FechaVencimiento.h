#pragma once
#include <iostream>

class FechaVencimiento
{
private:
	int day, month, year;

public:
	FechaVencimiento();
	FechaVencimiento(int day, int month, int year);
	~FechaVencimiento();

};