#include <stdio.h>
#include <math.h>
#include <complex.h>

double PI;
typedef double complex cplx;

void _ifft(cplx buf[], cplx out[], int n, int step) {
    if (step < n) {
        _ifft(out, buf, n, step * 2);
        _ifft(out + step, buf + step, n, step * 2);

        for (int i = 0; i < n; i += 2 * step) {
            cplx t = cexp(+I * PI * i / n) * out[i + step];
            buf[i / 2] = out[i] + t;
            buf[(i + n) / 2] = out[i] - t;
        }
    }
}

void ifft(cplx buf[], int n) {
    cplx out[n];
    for (int i = 0; i < n; i++)
        out[i] = buf[i];

    _ifft(buf, out, n, 1);

    for (int i = 0; i < n; i++)
        buf[i] /= n;
}

int main() {
    PI = atan2(1, 1) * 4;

    FILE* fp = fopen("am_signal_hilbert_fft.csv", "r");
    if (fp == NULL)
        return 1;

    cplx data[1024];
    float real, imag;
    int i = 0;

    while (fscanf(fp, "%f,%f", &real, &imag) == 2 && i < 1024) {
        data[i] = real + imag * I;
        i++;
    }

    ifft(data, 1024);

    fclose(fp);

    FILE* fp1 = fopen("am_signal_ifft.csv", "w");
    for (int i = 0; i < 1024; i++)
    {
        fprintf(fp1, "%f,%f\n", creal(data[i]), cimag(data[i]));
    }

    fclose(fp1);

}