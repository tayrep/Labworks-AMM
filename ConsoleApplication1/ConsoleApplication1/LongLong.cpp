#include "LongLong.h"

LongLong::LongLong() {
	ep = 0;
	yp = 0;
}

LongLong::LongLong(long epNum, unsigned long ypNum) {
	ep = epNum;
	yp = ypNum;
}

void LongLong::setEp(long epNum) {
	ep = epNum;
}

void LongLong::setYp(unsigned long ypNum) {
	yp = ypNum;
}

long LongLong::getEp() {
	return ep;
}

unsigned long LongLong::getYp() {
	return yp;
}

LongLong LongLong::add(LongLong second) {
	;
}

LongLong LongLong::subtr(LongLong second) {
	return LongLong(ep - second.getEp(), yp - second.getYp());
}