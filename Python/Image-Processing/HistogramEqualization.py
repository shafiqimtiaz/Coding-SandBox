import numpy as np
import cv2
import matplotlib.pyplot as plt

# Given histogram
grey_levels = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
pixels = np.array([1, 9, 15, 45, 93, 50, 23, 12, 7, 1, 0, 0, 0, 0, 0, 0])

# Create a figure with multiple subplots
fig = plt.figure(figsize=(15,10))

# a) Plot the histogram of the image given in the table above.
ax1 = fig.add_subplot(311)
ax1.bar(grey_levels,pixels)
ax1.set_title('Original Histogram')
ax1.set_xlabel('Grey Level')
ax1.set_ylabel('# of Pixels')

# b) Perform histogram equalization
# i) Calculate the grey level sk in the image after histogram equalization from the table.
cdf = pixels.cumsum() # cumulative distribution function
cdf_normalized = cdf * grey_levels[-1] / cdf[-1] # normalize

# ii) Plot the probability density functions pr(rk) and ps(sk).
ax2 = fig.add_subplot(312)
ax2.plot(grey_levels,cdf_normalized,color='black')
ax2.set_title('CDF of Original Image and Equalized Image')
ax2.set_xlabel('Grey Level')
ax2.set_ylabel('Cumulative Sum')
ax2.legend(['Original CDF','Equalized CDF'])

# c) Plot the new histogram after performing the histogram equalization.
equalized_pixels = np.interp(pixels,(pixels.min(),pixels.max()),(0,grey_levels[-1]))
ax3 = fig.add_subplot(313)
ax3.hist(equalized_pixels,bins=16,color='gray',alpha=0.5)
ax3.set_title('Equalized Histogram')
ax3.set_xlabel('Grey Level')
ax3.set_ylabel('# of Pixels')

# Show all plots
plt.tight_layout()
plt.show()