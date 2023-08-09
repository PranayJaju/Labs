import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
def find_nearest_above(my_array, target):
    diff = my_array - target
    mask = np.ma.less_equal(diff, -1)
    # We need to mask the negative differences
    # since we are looking for values above
    if np.all(mask):
        c = np.abs(diff).argmin()
        return c # returns min index of the nearest if target is greater than any value
    masked_diff = np.ma.masked_array(diff, mask)
    return masked_diff.argmin()


def hist_match(original, specified):
    oldshape = original.shape
    original = original.ravel()
    specified = specified.ravel()

    # get the set of unique pixel values and their corresponding indices and counts
    s_values, bin_idx, s_counts = np.unique(original, return_inverse=True, return_counts=True)
    t_values, t_counts = np.unique(specified, return_counts=True)

    # Calculate s_k for original image
    s_quantiles = np.cumsum(s_counts).astype(np.float64)
    s_quantiles /= s_quantiles[-1]

    # Calculate s_k for specified image
    t_quantiles = np.cumsum(t_counts).astype(np.float64)
    t_quantiles /= t_quantiles[-1]

    # Round the values
    sour = np.around(s_quantiles * 255)
    temp = np.around(t_quantiles * 255)

    # Map the rounded values
    b = []
    for data in sour[:]:
        b.append(find_nearest_above(temp, data))
    b = np.array(b, dtype='uint8')

    return b[bin_idx].reshape(oldshape)


# Load the images in greyscale
original = cv.imread('Resources\\cocktail.jpg', 0)
specified = cv.imread('Resources\\landscape.jpg', 0)

# perform Histogram Matching
new = hist_match(original, specified)

# Display the image
cv.imshow('New', np.array(new, dtype='uint8'))
cv.imshow('OG', original)
cv.imshow('Spec', specified)

gray = cv.calcHist([original],[0],None,[256],[0,256])
plt.subplot(3,1,1)
plt.plot(gray,color='r')
plt.title('Og Grayscale Histogram')
plt.xlim([0,256])

gray_1 = cv.calcHist([specified],[0],None,[256],[0,256])
plt.subplot(3,1,2)
plt.plot(gray_1, color='b')
plt.title('Ref Grayscale Histogram')
plt.xlim([0,256])

gray_2 = cv.calcHist([new],[0],None,[256],[0,256])
plt.subplot(3,1,3)
plt.plot(gray_2, color='g')
plt.title('NEw Grayscale Histogram')
plt.xlim([0,256])

plt.tight_layout()
plt.show()


cv.waitKey(0)