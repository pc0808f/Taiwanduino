#include <CapacitiveSensor.h>

#define Threadhold 200		//scan button threadhold

int input_pin[7] = {A5,A4,A2,8,5,6,7};	//define touchpad pinouts
CapacitiveSensor *input[7];				//create an CapacitiveSensor object for use in this sketch


//1 period sine of 500Hz
const uint8_t sound1_data[] PROGMEM = {0 ,10 ,37 ,79 ,128 ,177 ,219 ,246 ,255 ,246 ,219 ,177 ,128 ,79 ,37 ,10 ,};
const int sound1_length=16;

int scanbutton(){
	int total[7] = {0};
	for(byte i=0;i<7;i++){
		total[i] =  input[i]->capacitiveSensor(30);
		if(total[i] >= Threadhold){
			/*uncomment while debugging*/
			//Serial.print(F("Button "));
			//Serial.println(i);
			return i;
		}
	}
	return -1;
}

void play(const uint8_t sound_data[], int sound_length, uint32_t samplesdelay, uint32_t stoptime){
	uint32_t counter=0;
	uint32_t last=0;
	stoptime+=millis();
	byte decay = 0;
	while(millis() < stoptime){
		if((stoptime - millis()<1))decay++;
		if(micros()-last > samplesdelay){
			OCR1A = (pgm_read_byte_near(sound_data+counter) >> (byte)(decay*0.1));
			counter++;
			last = micros();
		}
		if(counter == sound_length)counter = 0;
	}
}

void setup(){	
	//Initialize Serial
	Serial.begin(9600);
	Serial.println(F("Started"));
	
	//Initialize I/O
	pinMode(A3, OUTPUT);		//capacitive sensor switcher
	pinMode(9, OUTPUT);			//speaker output
	pinMode(13, OUTPUT);		//LED Chiayi
	
	//Initialize Capacitive Sensor
	Serial.print(F("Initializing Capacitive Sensor..."));
	for(int i=0;i<7;i++)input[i] = new CapacitiveSensor(A3,input_pin[i]);
	Serial.println(F("done."));

	TCCR1B = (1 << WGM12) | (0 << WGM13)| (1 << CS10);
	TCCR1A = (1 << COM1A1)|(1 << WGM10) | (0 << WGM11);

}
float tone_f[7] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
byte keypressed = 0;
byte octave = 0;
 
void loop(){
	short int key = scanbutton();
	if(key != -1){
		keypressed = keypressed | (1 << key);
		digitalWrite(13,HIGH);
		//125ms delay generates sine wave in 500Hz
		//(125*500)ms generates 1Hz 
		play(sound1_data, sound1_length, (uint32_t)((float)(125*500/tone_f[6-key])) << octave, 200);
		digitalWrite(13,LOW);
	}
	if(keypressed == 0b01111111){
		//after all key was touched
		octave++;
		keypressed = 0;
	}
}
