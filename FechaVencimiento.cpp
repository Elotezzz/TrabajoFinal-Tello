#include "FechaVencimiento.h"

FechaVencimiento::FechaVencimiento() : day(1), month(1), year(0) {}
FechaVencimiento::FechaVencimiento(int day, int month, int year) : day(day), month(month), year(year) {}
FechaVencimiento::~FechaVencimiento() {}