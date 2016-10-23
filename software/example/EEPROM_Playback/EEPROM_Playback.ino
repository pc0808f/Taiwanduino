#include <CapacitiveSensor.h>
#include<SPI.h>
const int cs = 10;

#define SLAVESELECT 10//ss
#define WREN  6
#define WRDI  4
#define RDSR  5
#define WRSR  1
#define READ  3
#define WRITE 2


#define Threadhold 200
CapacitiveSensor input[7];
int input_pin[7] = {A2,A4,A5,5,6,7,8};
int total[7] = {0}; 

const int sounddata_length=20062;		//insert "Data Count:xxxxx" value from wav2uart.exe;
void setup(){
	//cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
	Serial.begin(115200);
	SPI.begin();
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	pinMode(SLAVESELECT,OUTPUT);
	digitalWrite(SLAVESELECT,HIGH);
	pinMode(A3,OUTPUT);
	pinMode(9,OUTPUT);

	Serial.println("Started");

	for(int i=0;i<7;i++){
		input[i].CapacitiveSensor_set(A3,input_pin[i]);
	}


	TCCR1B = (1 << WGM12) | (0 << WGM13)| (1 << CS10);
	TCCR1A = (1 << COM1A1)|(1 << WGM10) | (0 << WGM11);

}


void play(){
	uint16_t counter=0;
	uint32_t last=0;
	uint8_t read_flag=0;
	uint8_t next_data=0;

	while(counter<sounddata_length){
		if(micros()-last > 125){
			//Serial.println(readByte(counter));///
			OCR1A = next_data;//pgm_read_byte_near(sounddata_data+counter);
			counter++;
			last = micros();
			next_data = readByte(counter);
		}
	}

}

uint8_t readByte(uint16_t address){
	digitalWrite(SLAVESELECT,LOW);
	SPI.transfer(READ); //read enable
	SPI.transfer((uint8_t)(address>>8));   //send MSByte address first
	SPI.transfer((uint8_t)(address));      //send LSByte address
	uint8_t data = SPI.transfer(0);
	digitalWrite(SLAVESELECT,HIGH); //release chip
	return data;
}

int scanbutton(){
	for(byte i=0;i<7;i++){
		total[i] =  input[i].capacitiveSensor(30);
		if(total[i] >= Threadhold){
			Serial.print("Button ");
			Serial.println(i);
			return i;
		}
	}
	return -1;
}

void loop()                    
{
	if(scanbutton()!=-1){
		digitalWrite(13,HIGH);
		play();
		digitalWrite(13,LOW);
	}    

}

