#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include <windows.h>

#define w 3

void matrixmultiply(double a[w][w], double b[w][w], double c[w][w], int width)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < width; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}// 矩阵乘法

void matrixadd(double d[w][w], double e[w][w], double f[w][w], int width)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			f[i][j] = 0;
			f[i][j] = d[i][j] + e[i][j];
		}
	}
}// 矩阵加法

int gettimeofday(struct timeval* tp, void* tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return (0);
} // 计时器

int main()
{
	int width = w;
	int height = w;
	double m[w][w] = { {0,1,2}, {1,2,3}, {2,3,4} };;
	double n[w][w] = { {0,1,2}, {1,2,3}, {2,3,4} };;
	double p[w][w] = { {0,0,0}, {0,0,0}, {0,0,0} };;

	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	double timeuse;

	matrixadd(m, n, p, w);

	gettimeofday(&t2, NULL);
	timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) / 1000000.0;
	printf("Use Time:%f\n", timeuse);

	printf("输出m:\n");
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%f\t", m[i][j]);
		}
		printf("\n");
	}

	printf("输出n:\n");
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%f\t", n[i][j]);
		}
		printf("\n");
	}

	printf("输出p:\n");
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%f\t", p[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}