#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI M_PI
typedef double complex cplx;

void _fft(cplx buf[], cplx out[], int n, int step) {
    if (step < n) {
        _fft(out, buf, n, step * 2);
        _fft(out + step, buf + step, n, step * 2);

        for (int i = 0; i < n; i += 2 * step) {
            cplx t = cexp(-I * PI * i / n) * out[i + step];
            buf[i / 2] = out[i] + t;
            buf[(i + n) / 2] = out[i] - t;
        }
    }
}

void fft(cplx buf[], int n) {
    cplx out[n];
    for (int i = 0; i < n; i++)
        out[i] = buf[i];

    _fft(buf, out, n, 1);
}

int main() {

    FILE* fp = fopen("am_signal.csv", "r");
    if (fp == NULL)
        return 1;

    cplx data[1024];
    float time, amp;
    int i = 0;

    while (fscanf(fp, "%f,%f", &time, &amp) == 2 && i < 1024) {
        data[i] = amp + 0.0 * I;
        i++;
    }

    fft(data, 1024);

    fclose(fp);

    FILE* fp1 = fopen("am_signal_fft.csv", "w");
    for (int i = 0; i < 1024; i++)
    {
        fprintf(fp1, "%f,%f\n", creal(data[i]), cimag(data[i]));
    }

    fclose(fp1);

}