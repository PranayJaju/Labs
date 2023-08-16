import cv2 as cv

img = cv.resize(cv.imread('Resources\\dog.jpg', 0), dsize=None, fx=0.4, fy=0.4)
cv.imshow('Og', img)
canny = cv.Canny(img, 150, 175)
cv.imshow('Canny', canny)

cv.waitKey(0)