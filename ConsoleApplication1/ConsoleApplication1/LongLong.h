#pragma once

class LongLong {
	long ep;
	unsigned long yp;

public:
	LongLong();
	LongLong(long epNum, unsigned long ypNum);

	void setEp(long epNum);
	void setYp(unsigned long ypNum);

	long getEp();
	unsigned long getYp();

	LongLong add(LongLong second);
	LongLong subtr(LongLong second);
	LongLong mult(LongLong second);
	LongLong div(LongLong second);
};