import wave , struct , time
import sys
print sys.argv

import serial
from serial.tools import list_ports



path = raw_input(">>> select file (Enter path): ")
print path



ports = list(list_ports.comports())
print("There are %d COM port(s) found" % len(ports))
print("==============================")
for x in xrange(0,len(ports)):
	print("[%d] %s" % (x,ports[x][1]))
	pass
print("==============================")

x = raw_input(">>> Choose COM port(Enter number): ")
Serial = serial.Serial(ports[int(x)][0],115200)

st = Serial.readline()
print "Com port opened"

st = Serial.readline()
if st != "0\r\n":
	print st.strip("\r\n")
	print "EEPROM Busy, Try replug the board"
	while 1:
		pass


offset = raw_input(">>> select offset (Enter number): ")



w = wave.open(path)





data_count = w.getnframes()
rate = w.getframerate()
print ("Sample width:%d"%w.getsampwidth())
print ("Frame Rate:%d"%w.getframerate())
print ("channels:%d"%w.getnchannels())
print ("Data Count:%d"%data_count)

if rate != 8000:
	print 'needs to be 8khz sampling rate,program end'
	while 1:
		pass

if w.getsampwidth() != 1 and w.getsampwidth() != 2:
	print 'needs to be 16bit/8bit sampling rate,program end'
	while 1:
		pass
def draw_percentage(p):
	bar = "=" * int(p*10)
	print("Writing Data to EEPROM %s|%3.2f%%" % ( bar,p*100))
	pass



Serial.write("W")
Serial.write(str(offset)+","+str(data_count))

#t.write("const unsigned char sounddata_data PROGMEM = {")
percentage = 0
level =0
if w.getsampwidth()==1:

	for x in range(int(data_count/128)+1):

		percentage = float(x)*128/data_count
		if abs(percentage*100)>level:
			draw_percentage(percentage)
			level = level+0.1
			pass

		try:
			for d in range(128):
				if int(x)*128+int(d) == int(data_count):
					draw_percentage(1)
					break
				waveData = w.readframes(1)
				data = struct.unpack("<B", waveData)
				Serial.write(chr(data[0]))
				pass
			pass

		except Exception, e:
				Serial.write(chr(0))
				print e
				print waveData
				print len(waveData)
				print data
				print x
				pass
		Serial.readline()
		pass
	pass

if w.getsampwidth()==2:

	#waveData = w.readframes(1)
	#data = struct.unpack("<h", waveData)
	#Serial.write(chr(data[0]/256+128))
	for x in range(int(data_count/128)+1):
		print x
		percentage = float(x)*128/data_count
		if abs(percentage*100) > level:
			draw_percentage(percentage)
			level = level+0.1
			pass
		try:
			for d in range(128):
				if int(x)*128+int(d) == int(data_count):
					draw_percentage(1)
					break
				waveData = w.readframes(1)
				data = struct.unpack("<h", waveData)
				Serial.write(chr(data[0]/256+128))
				pass
			pass
		except Exception, e:
				Serial.write(chr(0))
				print e
				print waveData
				print len(waveData)
				print x
				pass
		pass
		Serial.readline()
	pass

st = Serial.readline()

print st
print ("Data Count:%d"%data_count)

while 1:
	pass
#print offset