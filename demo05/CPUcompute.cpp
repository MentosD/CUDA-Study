#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include <windows.h>

#define w 5000

struct Matrix
{
    int width;
    int height;
    float* elements;
};

void matMul(float* M, float* N, float* P, int width) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            float sum = 0;
            for (int k = 0; k < width; k++) {
                float a = M[i * width + k];
                float b = N[k * width + j];
                sum += a * b;
            }
            P[i * width + j] = sum;
        }
    }
}

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
}

int main() {

    int width = w;
    int height = w;

    float* m = (float*)malloc(width * height * sizeof(float));
    float* n = (float*)malloc(width * height * sizeof(float));
    float* p = (float*)malloc(width * height * sizeof(float));

    for (int i = 0; i < width * height; i++) {
        m[i] = 1.0;
        n[i] = 2.0;
    }

    struct timeval t1, t2;
    gettimeofday(&t1, NULL);
    double timeuse;

    matMul(m, n, p, w);

    gettimeofday(&t2, NULL);
    timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) / 1000000.0;
    printf("Use Time:%f\n", timeuse);
    system("pause");
    return 0;

 }
