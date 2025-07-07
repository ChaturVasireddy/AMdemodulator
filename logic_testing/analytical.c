#include <stdio.h>
#include <math.h>
#include <complex.h>

double PI;
typedef double complex cplx;

void hilbert(cplx buf[], int n) {
    for (int k = 0; k < n; k++) {
        if (k == 0 || (n % 2 == 0 && k == n / 2))
            buf[k] *= 1;
        else if (k > 0 && k < n / 2)
            buf[k] *= 2;
        else
            buf[k] = 0;
    }
}

int main() {
    PI = atan2(1, 1) * 4;

    FILE* fp = fopen("am_signal_fft.csv", "r");
    if (fp == NULL)
        return 1;

    cplx data[1024];
    float real, imag;
    int i = 0;

    while (fscanf(fp, "%f,%f", &real, &imag) == 2 && i < 1024) {
        data[i] = real + imag * I;
        i++;
    }

    hilbert(data, 1024);

    fclose(fp);

    FILE* fp1 = fopen("am_signal_analytical.csv", "w");
    for (int i = 0; i < 1024; i++)
    {
        fprintf(fp1, "%f,%f\n", creal(data[i]), cimag(data[i]));
    }

    fclose(fp1);

}