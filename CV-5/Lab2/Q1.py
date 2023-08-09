import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('Resources\\landscape.jpg')
# cv.imshow('Cocktail', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('Gray Cocktail', gray)
gray_hist = cv.calcHist([gray],[0],None,[256],[0,256])
plt.subplot(2,1,1)
plt.plot(gray_hist, color=[0,0,0])
plt.title('Grayscale Histogram')
plt.xlim([0,256])

eqHist = cv.equalizeHist(gray)
# cv.imshow('Equalized Gray Cocktail', eqHist)
eq_hist = cv.calcHist([eqHist],[0],None,[256],[0,256])
plt.subplot(2,1,2)
plt.plot(eq_hist)
plt.title('Eq Grayscale Histogram')
plt.xlim([0,256])

res = np.hstack((gray, eqHist))
cv.imshow('OG-EQ', res)

colors = ('b','g','r')
for i,col in enumerate(colors):
    hist = cv.calcHist([img], [i], None, [256], [0,256])
    plt.subplot(2,1,1)
    plt.plot(hist, color=col)
    plt.xlim([0,256])

plt.tight_layout()
plt.show()

cv.waitKey(0)