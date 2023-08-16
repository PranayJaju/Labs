import cv2 as cv

img = cv.resize(cv.imread('Resources\\ny_cp.jpg'), dsize=None, fx=0.35, fy=0.35)

gaussian = cv.GaussianBlur(img, (7,7), 0)
cv.imshow('Gaussian Blur',gaussian)

average = cv.blur(img, (7,7))
cv.imshow('Box Filter Blur', average)

cv.waitKey(0)