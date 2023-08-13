import cv2 as cv
import numpy as np

blank = np.zeros((500,500,3), dtype='uint8')

cv.rectangle(blank, (100,200), (300,400), (155,90,80), 2)
cv.rectangle(blank, (200,100), (400,300), (0,255,0), 2)

cv.imshow('Rectangle', blank)

cv.waitKey(0)