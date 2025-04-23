import cv2

# Use external camera, usually index 1 or higher
cap = cv2.VideoCapture(1) ## 0 for internal

if not cap.isOpened():
    print("Cannot open external camera")
    exit()

while True:
    ret, frame = cap.read()
    if not ret:
        print("Can't receive frame. Exiting...")
        break

    cv2.imshow('External Camera', frame)
    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
