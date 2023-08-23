import cv2 as cv

img = cv.imread('Resources\\rose.jpg')
cv.imshow('Color', img)

hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
cv.imshow('HSV', hsv)

lower = (100, 50, 50)
upper = (130, 255, 255)

mask = cv.inRange(hsv, lower, upper)
result = cv.bitwise_and(img, img, mask=mask)

cv.imshow('Segmentation', result)

cv.waitKey(0)