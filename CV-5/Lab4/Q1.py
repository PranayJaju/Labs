import cv2 as cv

img = cv.imread('Resources\\benz.jpg', 0)
cv.imshow('Og', img)

b, bin = cv.threshold(img, 127, 255, cv.THRESH_BINARY)
bi, bin_inv = cv.threshold(img, 127, 255, cv.THRESH_BINARY_INV)
tr, trunc = cv.threshold(img, 127, 255, cv.THRESH_TRUNC)
t0, to_0 = cv.threshold(img, 127, 255, cv.THRESH_TOZERO)
t0i, to_0_inv = cv.threshold(img, 127, 255, cv.THRESH_TOZERO_INV)

cv.imshow('Bin', bin)
cv.imshow('Bin Inv', bin_inv)
cv.imshow('Trunc', trunc)
cv.imshow('To 0', to_0)
cv.imshow('To 0 Inv', to_0_inv)

cv.waitKey(0)