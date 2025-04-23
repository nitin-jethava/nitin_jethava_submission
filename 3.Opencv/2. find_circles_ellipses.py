import cv2
import numpy as np

# Load the image
image = cv2.imread('shapes.png')
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(gray, (5, 5), 0)

# Detect circles using Hough Transform
circles = cv2.HoughCircles(blur, cv2.HOUGH_GRADIENT, dp=1.2, minDist=30,
                           param1=50, param2=30, minRadius=0, maxRadius=0)

if circles is not None:
    circles = np.uint16(np.around(circles))
    for (x, y, r) in circles[0, :]:
        cv2.circle(image, (x, y), r, (0, 255, 0), 2)

# Detect contours and fit ellipses
contours, _ = cv2.findContours(blur, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for cnt in contours:
    if len(cnt) >= 5:
        ellipse = cv2.fitEllipse(cnt)
        cv2.ellipse(image, ellipse, (255, 0, 0), 2)

cv2.imshow("Detected Circles and Ellipses", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
