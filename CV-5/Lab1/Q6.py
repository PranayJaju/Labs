import cv2 as cv

img = cv.imread('Lab1/Resources/image.jpg')
cv.imshow('Image', img)

rotated = cv.rotate(img, cv.ROTATE_90_CLOCKWISE)
cv.imshow("Rotated", rotated)

cv.waitKey(0)