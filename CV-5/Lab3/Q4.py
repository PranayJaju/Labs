import cv2 as cv
import numpy as np

img = cv.resize(cv.imread('Resources\\ny_ts.jpg', 0), dsize=None, fx=0.4, fy=0.4)

sobelx = cv.Sobel(img, cv.CV_64F, 1, 0)
sobely = cv.Sobel(img, cv.CV_64F, 0, 1)
combined_sobel = cv.bitwise_or(sobelx,sobely)

# c_sq_sobel = np.sqrt(np.square(sobelx)+np.square(sobely))
# sobel_img = cv.Sobel(img, cv.CV_64F, 1, 1)

cv.imshow('Combined Sobel', combined_sobel)
# cv.imshow('Sobel', sobel_img)
# cv.imshow('Sobel sq', c_sq_sobel)

cv.waitKey(0)