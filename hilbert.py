import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, ifft, fftfreq
import time

start_time = time.perf_counter()

t = np.linspace(0,1,1024)

msg_signal = np.sin(2*np.pi*5*t)
am_signal = (1 + msg_signal)*np.cos(2*np.pi*100*t)

am_fft = fft(am_signal)
freqs = fftfreq(len(t), t[1]-t[0])

mask = np.zeros_like(am_fft)
mask[freqs > 0] = 2
mask[freqs == 0] = 1

analytic_fft = am_fft * mask
analytic_signal = ifft(analytic_fft)

envelope = np.abs(analytic_signal)

end_time = time.perf_counter()
elapsed_time = end_time - start_time
print(f"Elapsed time (perf_counter): {elapsed_time:.6f} seconds")

plt.figure(figsize=(15, 7.5))
plt.plot(t, envelope, label="test")
plt.plot(t, am_signal, label="test")
plt.legend()
plt.grid(color = 'grey', linestyle = '--', linewidth = 0.5)
plt.show()