#include <stdio.h>

//VD 1:
struct point{
	float x;
	float y;
};

struct triangle{
	point a, b, c;
};

struct circle{
	point c;
	float r;
};

struct rectangle{
	point a, b, c, d;
};

struct polygon{
	point[100] ps;
	int n;
};

struct polygon2{
	point* ps;
};

//VD 2:
struct date{
	int day;
	int month;
	int year;
};

struct person{
	char[100] name;
	date dateofbirth;
	float weight;
};

// person p1; p1.dateofbirth.month;

//VD 3: khai bao ben trong
struct person{
	char[100] name;
	struct date{
		int day;
		int month;
		int year;
	} dateofbirth;
	float weight;
};
