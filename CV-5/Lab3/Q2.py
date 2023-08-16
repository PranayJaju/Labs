import cv2 as cv
import numpy as np

img = cv.imread('Resources\\dog.jpg', 0)
img = cv.resize(img, dsize=None, fx=0.5, fy=0.5)
lap = cv.Laplacian(img, cv.CV_64F)
lap = np.uint8(np.absolute(lap))
cv.imshow('OG', img)
cv.imshow('Laplacian Gradient', lap)

cv.waitKey(0)