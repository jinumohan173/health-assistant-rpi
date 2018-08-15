import time
import serial
import RPi.GPIO as GPIO
import os
pulse = ""
bp = ""
ecg = ""
intro = "espeak "+"'" + "hello i am your health assistant you can check your health"+"'"+" -s 100"
os.system(intro)

GPIO.setmode(GPIO.BCM)

GPIO.setup(21,GPIO.IN,pull_up_down=GPIO.PUD_DOWN) #pin number 1 from last 5v

port = serial.Serial(
              
               port='/dev/ttyAMA0',
               baudrate = 9600,
               parity=serial.PARITY_NONE,
               stopbits=serial.STOPBITS_ONE,
               bytesize=serial.EIGHTBITS,
               timeout=1
           )


while 1 :
	sw1 = GPIO.input(21)
	if(sw1==1):
		os.system("sudo fswebcam -r 640x480  -S 10 /var/www/html/image2.jpg")
		print 'taking picture'
	x=port.readline()
	time.sleep(.1)
	print(x)
	


	if(x[0]=='p'):
		print 'pulse rate'
		pulse = "pulse rate is "+x[6:]
		print pulse
		f=open('p.txt','w')
		f.write(pulse)
		f.close()
		
	if(x[0]=='r'):
		print 'respiration  rate'
		res = "respiration rate is "+x[9:]
		#res = x 
		print res
		f=open('r.txt','w')
		f.write(res)
		f.close()
	if(x[0]=='e'):
		print 'Ecg value'
		ecg = "Ecg reading is "+x[4:]
		print ecg
		f=open('e.txt','w')
		f.write(ecg)
		f.close()
	if(x[0]=='B'):
		print 'BP value'
		bp = "Bp reading is " + x[3:]	
		print bp	
		f=open('b.txt','w')
		f.write(bp)
		f.close()
		
		
	
