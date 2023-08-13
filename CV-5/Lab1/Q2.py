import cv2 as cv

capture = cv.VideoCapture('LAb1/Resources/video.mp4')
while True:
    isTrue, frame = capture.read()
    cv.imshow('Video', frame)

    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()