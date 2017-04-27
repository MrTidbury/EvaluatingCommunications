import RPi.GPIO as GPIO
import time
import easygui

GPIO.setmode(GPIO.BCM)
RF = 23
GPIO.setup(TRIG,GPIO.IN)

while True:
  print GPIO.input(RF) #Used for debugging as it prints current reading to console
  time.sleep(1)
  if GPIO.input(RF)==1:
    easygui.msgbox('Movement Sensor Triggered','WARNING')
    time.sleep(1)
GPIO.cleanup()

