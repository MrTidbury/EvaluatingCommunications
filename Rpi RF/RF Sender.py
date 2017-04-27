import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
TRIG = 23 
ECHO = 24
RF = 25
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(RF,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.setwarnings(False)
GPIO.output(TRIG, False)
GPIO.output(RF, False)


def finddistance():
  GPIO.output(TRIG, True)
  time.sleep(0.00001)
  GPIO.output(TRIG, False)
  while GPIO.input(ECHO)==0:
    pulse_start = time.time()
  while GPIO.input(ECHO)==1:
    pulse_end = time.time()
  pulse_duration = pulse_end - pulse_start
  distance = pulse_duration * 17150
  distance = round(distance, 2)
  return distance

def triggercoms(difference):
  print "RF PIN SET TO HIGH"
  GPIO.ourput(RF, True)
  time.sleep(2)
  GPIO.ourput(RF, False)
  print "RF PIN SET TO LOW"
while (True):
  distance1 = finddistance()
  time.sleep(0.5)
  distance2 = finddistance()
  difference = distance1 - distance2
  if ( difference > 20):
    triggercoms(difference)
    time.sleep(2)
    

GPIO.cleanup()
