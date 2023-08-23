import cv2 as cv
import math
import numpy as np

img = cv.imread('Resources\\build.jpg')
cv.imshow('Build1', img)
imgP = np.copy(img)
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

canny = cv.Canny(gray, 100, 200)

lines = cv.HoughLines(canny, 1, np.pi / 180, 200, None, 0, 0)
for line in lines:
    r = line[0][0]
    theta = line[0][1]
    a = math.cos(theta)
    b = math.sin(theta)
    x0 = a * r
    y0 = b * r
    pt1 = (int(x0 + 1000 * (-b)), int(y0 + 1000 * a))
    pt2 = (int(x0 - 1000 * (-b)), int(y0 - 1000 * a))
    cv.line(img, pt1, pt2, (0, 0, 255), 1, cv.LINE_AA)

linesP = cv.HoughLinesP(canny, 1, np.pi / 180, 75, None, 50, 10)
for lineP in linesP:
    pt = lineP[0]
    cv.line(imgP, (pt[0], pt[1]), (pt[2], pt[3]), (0, 0, 255), 1, cv.LINE_AA)

cv.imshow('With lines', img)
cv.imshow('With Lines P', imgP)
cv.waitKey(0)