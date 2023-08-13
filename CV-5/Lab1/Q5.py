import cv2 as cv

img = cv.imread('Lab1/Resources/image.jpg')
cv.imshow('Image', img)

resized = cv.resize(img, (400,400), interpolation=cv.INTER_AREA)
cv.imshow('Resized', resized)

cv.waitKey(0)