import cv2 as cv

img = cv.imread('Lab1/Resources/image.jpg')
bgr = img[303,303]
print(bgr)