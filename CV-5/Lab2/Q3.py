import cv2 as cv

#Crop
img = cv.imread('Resources\\cocktail.jpg')
cv.imshow('Cocktail', img)
cropped = img[(img.shape)[1]//2:(img.shape)[1], 0:(img.shape)[1]//2]
cv.imshow('Cocktail crop', cropped)

#Resize
img = cv.imread('Resources\\landscape.jpg')
cv.imshow('Landscape', img)
resize = cv.resize(img, None, fx=0.5, fy=0.75, interpolation=cv.INTER_AREA)
cv.imshow('Landscape Resize', resize)

cv.waitKey(0)