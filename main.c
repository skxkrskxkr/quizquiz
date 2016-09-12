#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getrn(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;

	return temp;

}
// 원그리기
//bool incircle(const double x, const double y)
//{
//	const double x_c = 0.5;
//	const double y_c = 0.5;
//	const double r = 0.5;
//
//	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r * r;
//
//	if (f > 0.0) return false;
//	else return true;
//}
//
//void main()
//{
//	FILE *of = fopen("circle.txt", "w");
//
//	srand((unsigned int)time(NULL));
//
//	for (int i = 0; i < 10000; i++)
//	{
//		double x = getrn(0.0, 1.0);
//		double y = getrn(0.0, 1.0);
//
//		if (incircle(x, y) == true)
//			fprintf(of, "%f, %f\n", x, y);
//
//	}
//
//	fclose(of);
//}


//덤벨그리기
//bool incircle(const double x, const double y)
//{
//	const double x_c = 0.5;
//	const double y_c = 0.5;
//	const double r = 0.5;
//
//	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r * r;
//
//	if (f > 0.0) return false;
//	else return true;
//}
//
//bool incircle2(const double x, const double y)
//{
//	const double x_c = 2.5;
//	const double y_c = 0.5;
//	const double r = 0.5;
//
//	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r * r;
//
//	if (f > 0.0) return false;
//	else return true;
//}
//
//bool nemo(const double x, const double y)
//{
//	if (y > 0.7) return false;
//	else if (y < 0.3) return false;
//	else return true;
//}
//
//
//void main()
//{
//	FILE *of = fopen("circle1.txt", "w");
//
//	srand((unsigned int)time(NULL));
//
//	for (int i = 0; i < 10000; i++)
//	{
//		double x = getrn(0.0, 1.0);
//		double y = getrn(0.0, 1.0);
//
//		if (incircle(x, y) == true)
//			fprintf(of, "%f, %f\n", x, y);
//
//	}
//
//	fclose(of);
//	FILE *off = fopen("dom.txt", "w");
//
//	srand((unsigned int)time(NULL));
//
//	for (int i = 0; i < 10000; i++)
//	{
//		double x = getrn(1.0, 2.0);
//		double y = getrn(0.0, 1.0);
//
//		if (nemo(x, y) == true)
//			fprintf(of, "%f, %f\n", x, y);
//
//	}
//
//	fclose(off);
//	FILE *ofs = fopen("circle2.txt", "w");
//	
//	srand((unsigned int)time(NULL));
//
//	for (int i = 0; i < 10000; i++)
//	{
//		double x = getrn(2.0, 3.0);
//		double y = getrn(0.0, 1.0);
//
//		if (incircle2(x, y) == true)
//			fprintf(of, "%f, %f\n", x, y);
//
//	}
//
//	fclose(ofs);
//}

bool eclipse(const double x, const double y)
{
	const double x_c = 1.0;
	const double y_c = 0.5;

	double f = ((x - x_c) / 1 * (x - x_c) / 1) + ((y - y_c) / 0.5*(y - y_c) / 0.5) - 1;	
	if (f > 0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("town.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getrn(0.0, 2.0);
		double y = getrn(0.0, 1.0);

		if (eclipse(x, y) == true)
			fprintf(of, "%f, %f\n", x, y);

	}

	fclose(of);
}