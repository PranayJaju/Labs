import cv2 as cv

img = cv.imread('Lab1/Resources/image.jpg')
cv.imshow('Image', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray image', gray)

cv.imwrite('Lab1/Resources/gray_image.jpg', gray)

cv.waitKey(0)