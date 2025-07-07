#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <time.h>

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
    clock_t start_time, end_time;
    start_time = clock();

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
    hilbert(data, 1024);
    ifft(data, 1024);
    for (int i = 0; i < 1024; i++)
    {
        data[i] = cabs(data[i]) + 0.0 * I;
    }

    end_time = clock();

    fclose(fp);

    FILE* fp1 = fopen("envelope.csv", "w");
    for (int i = 0; i < 1024; i++)
    {
        fprintf(fp1, "%f\n", creal(data[i]));
    }

    fclose(fp1);

    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Function took %f seconds to execute.\n", cpu_time_used);
}