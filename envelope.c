#include <stdio.h>
#include <math.h>
#include <complex.h>

double PI;
typedef double complex cplx;

int main() {
    PI = atan2(1, 1) * 4;

    FILE* fp = fopen("am_signal_ifft.csv", "r");
    if (fp == NULL)
        return 1;

    cplx data[1024];
    float real, imag;
    int i = 0;

    while (fscanf(fp, "%f,%f", &real, &imag) == 2 && i < 1024) {
        data[i] = real + imag * I;
        i++;
    }

    fclose(fp);

    FILE* fp1 = fopen("am_signal_envelope.csv", "w");
    for (int i = 0; i < 1024; i++)
    {
        fprintf(fp1, "%f\n", cabs(data[i]));
    }

    fclose(fp1);

}