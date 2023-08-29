import cv2 as cv
import numpy as np

def CannyEdge(img, thresh_low, thresh_high):
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    blurred = cv.GaussianBlur(gray, (5,5), 0)

    grad_x = cv.Sobel(blurred, cv.CV_64F, 1, 0, ksize=3)
    grad_y = cv.Sobel(blurred, cv.CV_64F, 0, 1, ksize=3)

    grad_mag = np.sqrt(grad_x**2 + grad_y**2)
    grad_dir = np.arctan2(grad_y, grad_x)

    grad_dir = grad_dir * 180.0 / np.pi
    grad_dir[grad_dir < 0] += 180

    suppressed = np.zeros_like(grad_mag)
    for i in range(1, grad_mag.shape[0] - 1):
        for j in range(1, grad_mag.shape[1] - 1):
            angle = grad_dir[i, j]
            if (0 <= angle < 22.5) or (157.5 <= angle <= 180):
                neighbor_pixels = [grad_mag[i, j + 1], grad_mag[i, j - 1]]
            elif 22.5 <= angle < 67.5:
                neighbor_pixels = [grad_mag[i - 1, j - 1], grad_mag[i + 1, j + 1]]
            elif 67.5 <= angle < 112.5:
                neighbor_pixels = [grad_mag[i - 1, j], grad_mag[i + 1, j]]
            else:
                neighbor_pixels = [grad_mag[i - 1, j + 1], grad_mag[i + 1, j - 1]]
            if grad_mag[i, j] >= max(neighbor_pixels):
                suppressed[i, j] = grad_mag[i, j]

    thresh = np.zeros_like(suppressed)
    thresh_high = int(thresh_high)
    thresh_low = int(thresh_low)
    
    weak_pixel_value = 50
    strong_pixel_value = 255
    
    strong_i, strong_j = np.where(suppressed > thresh_high)
    weak_i, weak_j = np.where((suppressed >= thresh_low) & (suppressed <= thresh_high))
    
    thresh[strong_i, strong_j] = strong_pixel_value
    thresh[weak_i, weak_j] = weak_pixel_value
    
    for i in range(1, thresh.shape[0] - 1):
        for j in range(1, thresh.shape[1] - 1):
            if thresh[i, j] == weak_pixel_value:
                if np.max(thresh[i - 1:i + 2, j - 1:j + 2]) == strong_pixel_value:
                    thresh[i, j] = strong_pixel_value
                else:
                    thresh[i, j] = 0
    
    return thresh

image = cv.imread('ny_ts.jpg')

edges = CannyEdge(image, 50, 150)

cv.imshow('Canny Edge Detection', edges)
cv.waitKey(0)