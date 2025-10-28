#include <CapacitiveSensor.h>
#include<SPI.h>

#define WREN  6
#define WRDI  4
#define RDSR  5
#define WRSR  1
#define READ  3
#define WRITE 2
#define SLAVESELECT 10		//ss

#define Threadhold 200		//scan button threadhold

int input_pin[7] = {A2,A4,A5,5,6,7,8};	//define touchpad pinouts
CapacitiveSensor *input[7];				//create an CapacitiveSensor object for use in this sketch

const int sounddata_length=11888;		//insert "Data Count:xxxxx" value from wav2uart.exe;

int scanbutton(){
	int total[7] = {0};
	for(byte i=0;i<7;i++){
		total[i] =  input[i]->capacitiveSensor(30);
		if(total[i] >= Threadhold){
			/*uncomment while debugging*/
			Serial.print(F("Button "));
			Serial.println(i);
			return i;
		}
	}
	return -1;
}

void play_eeprom(){
	uint16_t counter=0;
	uint32_t last=0;
	uint8_t read_flag=0;
	uint8_t next_data=0;

	while(counter<sounddata_length){
		if(micros()-last > 125){
			OCR1A = next_data;
			counter++;
			last = micros();
			next_data = readByte(counter);
		}
	}
}

uint8_t readByte(uint16_t address){
	digitalWrite(SLAVESELECT,LOW);
	SPI.transfer(READ);					//read enable
	SPI.transfer((uint8_t)(address>>8));//send MSByte address first
	SPI.transfer((uint8_t)(address));	//send LSByte address
	uint8_t data = SPI.transfer(0);
	digitalWrite(SLAVESELECT,HIGH);		//release chip
	return data;
}

void setup(){
	//Initialize Serial
	Serial.begin(9600);
	Serial.println(F("Started"));
	
	//Initialize I/O
	pinMode(A3, OUTPUT);		//capacitive sensor switcher
	pinMode(9, OUTPUT);			//speaker output
	pinMode(SLAVESELECT,OUTPUT);//SPI SCK
	
	//Initialize SPI EEPROM
	Serial.print(F("Initializing SPI EEPROM..."));
	SPI.begin();
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	digitalWrite(SLAVESELECT,HIGH);
	Serial.println(F("done."));
	
	//Initialize Capacitive Sensor
	Serial.print(F("Initializing Capacitive Sensor..."));
	for(int i=0;i<7;i++)input[i] = new CapacitiveSensor(A3,input_pin[i]);
	Serial.println(F("done."));

	TCCR1B = (1 << WGM12) | (0 << WGM13)| (1 << CS10);
	TCCR1A = (1 << COM1A1)|(1 << WGM10) | (0 << WGM11);
}

void loop(){
	if(scanbutton()!=-1){
		play_eeprom();
	}
}

