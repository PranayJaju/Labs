import cv2 as cv

img = cv.imread('Resources\\ny_ts.jpg')
img = cv.resize(img, dsize=None, fx=0.5, fy=0.5)
gaussian = cv.GaussianBlur(img, (11,11), 0)
unsharp = cv.addWeighted(img, 2.0, gaussian, -1.0, 0)
cv.imshow('OG', img)
cv.imshow('Unsharp', unsharp)

cv.waitKey(0)