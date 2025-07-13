#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define FS 1000.0 

#define PI 3.14159265358979323846

int main()
{
    FILE* fp = fopen("am_signal.csv", "w");
    if (fp == NULL)
    {
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        float t = i / FS;
        float message = sin(2 * PI * 5.0 * t);
        float am_signal = (1 + message) * cos(2 * PI * 100.0 * t);

        fprintf(fp, "%f,%f\n", t, am_signal);
    }

    fclose(fp);
    return 0;
}
