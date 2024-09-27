import threading
import time
import cv2
import RPi.GPIO as GPIO
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torchvision import transforms, models
from PIL import Image

# GPIO 핀 설정
PWMA = 18
AIN1 = 22
AIN2 = 27
PWMB = 23
BIN1 = 25
BIN2 = 24

def motor_back(speed):
    L_Motor.ChangeDutyCycle(speed)
    GPIO.output(AIN2, False)
    GPIO.output(AIN1, True)
    R_Motor.ChangeDutyCycle(speed)
    GPIO.output(BIN2, False)
    GPIO.output(BIN1, True)

def motor_go(speed):
    L_Motor.ChangeDutyCycle(speed)
    GPIO.output(AIN2, True)
    GPIO.output(AIN1, False)
    R_Motor.ChangeDutyCycle(speed)
    GPIO.output(BIN2, True)
    GPIO.output(BIN1, False)

def motor_stop():
    L_Motor.ChangeDutyCycle(0)
    GPIO.output(AIN2, False)
    GPIO.output(AIN1, False)
    R_Motor.ChangeDutyCycle(0)
    GPIO.output(BIN2, False)
    GPIO.output(BIN1, False)

def motor_right(speed):
    L_Motor.ChangeDutyCycle(speed)
    GPIO.output(AIN2, True)
    GPIO.output(AIN1, False)
    R_Motor.ChangeDutyCycle(0)
    GPIO.output(BIN2, False)
    GPIO.output(BIN1, True)

def motor_left(speed):
    L_Motor.ChangeDutyCycle(0)
    GPIO.output(AIN2, False)
    GPIO.output(AIN1, True)
    R_Motor.ChangeDutyCycle(speed)
    GPIO.output(BIN2, True)
    GPIO.output(BIN1, False)

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(AIN2, GPIO.OUT)
GPIO.setup(AIN1, GPIO.OUT)
GPIO.setup(PWMA, GPIO.OUT)
GPIO.setup(BIN1, GPIO.OUT)
GPIO.setup(BIN2, GPIO.OUT)
GPIO.setup(PWMB, GPIO.OUT)

L_Motor = GPIO.PWM(PWMA, 100)
L_Motor.start(0)
R_Motor = GPIO.PWM(PWMB, 100)
R_Motor.start(0)

# ResNet 모델 로드
model = models.resnet18(pretrained=False)
num_ftrs = model.fc.in_features
model.fc = nn.Linear(num_ftrs, 1)
model.load_state_dict(torch.load('/home/qwer1234/AI_CAR/model/main.pth'))
model.eval()

# 이미지 전처리
resize = transforms.Resize((66,200))
tf_toTensor = transforms.ToTensor()
normalize = transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])

def img_preprocess(image):
    height, _, _ = image.shape
    image = image[int(height/2):,:,:]
    image = cv2.cvtColor(image, cv2.COLOR_BGR2YUV)
    image = cv2.resize(image, (200,66))
    image = cv2.GaussianBlur(image,(5,5),0)
    _,image = cv2.threshold(image,140,255,cv2.THRESH_BINARY_INV)
    return image

camera = cv2.VideoCapture(-1)
camera.set(3, 640)
camera.set(4, 480)

def detect_crosswalk(image):
    # 횡단보도 감지: 이미지 처리 및 Hough 변환을 사용한 선 감지
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2YUV)
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    edges = cv2.Canny(blurred, 100, 150)
    lines = cv2.HoughLinesP(edges, 1, np.pi/180, 100, minLineLength=100, maxLineGap=10)

    blocks = []
    if lines is not None:
        for line in lines:
            x1, y1, x2, y2 = line[0]
            block_width = abs(x2 - x1)
            block_height = abs(y2 - y1)
            if block_width * block_height > 50 * 40: 
                blocks.append(((x1, y1), (x2, y2)))

    if len(blocks) >= 8:
        return True
    else:
        return False

def main():
    carState = "go"
    crosswalk_detected = False
    stop_time = 0
    go_time = 0
    ignore_crosswalk = False
    ignore_start_time = 0

    try:
        while True:
            keyValue = cv2.waitKey(1)

            if keyValue == ord('q'):
                break
            elif keyValue == 82:
                print("go")
                carState = "go"
            elif keyValue == 84:
                print("stop")
                carState = "stop"

            _, image = camera.read()
            image = cv2.flip(image,-1)
            preprocessed = img_preprocess(image)
            cv2.imshow('pre', preprocessed)
            preprocessed = tf_toTensor(preprocessed)
            preprocessed = preprocessed.unsqueeze(0)

            outputs = model(preprocessed)
            steering_angle = outputs.item()
            print("predict angle:", steering_angle)

            if not ignore_crosswalk and detect_crosswalk(image):
                crosswalk_detected = True
                stop_time = time.time()
                go_time = stop_time + 3  # 3초 후 직진 시작
                ignore_crosswalk = True
                ignore_start_time = time.time()

            if ignore_crosswalk and time.time() - ignore_start_time >= 10:
                ignore_crosswalk = False

            if carState == "go":
                if crosswalk_detected:
                    if time.time() < go_time:
                        motor_stop()
                    elif time.time() < go_time + 3:
                        motor_go(40)
                    else:
                        crosswalk_detected = False
                else:
                    if 65 <= steering_angle <= 87:
                        print("go")
                        motor_go(40)
                    elif steering_angle > 87:
                        print("right")
                        motor_right(35)
                    elif steering_angle < 65:
                        print("left")
                        motor_left(35)
            elif carState == "stop":
                motor_stop()

    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    main()
    cv2.destroyAllWindows()