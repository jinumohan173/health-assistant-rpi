#include<SoftwareSerial.h>

SoftwareSerial mySerial(8,9);//rx,tx


int resp_val = 0;
char ReciveData;
int i[50];
int x=-1;
int y=0;
int SYS=0;
int DIA=0;
int H_R=0;
int DAY=0;

int UpperThreshold = 518;
int LowerThreshold = 490;
int reading = 0;
float BPM = 0.0;
bool IgnoreReading = false;
bool FirstPulseDetected = false;
unsigned long FirstPulseTime = 0;
unsigned long SecondPulseTime = 0;
unsigned long PulseInterval = 0;


void setup() {
 Serial.begin(9600);
 mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (Serial.available()){
 ReciveData=Serial.read();
x++;
}
i[x]=ReciveData;
if(x>9)
{

 SYS = ( ((i[0]-48)*100) + ((i[1]-48)*10) + (i[2]-48) );
 DIA = ( ((i[3]-48)*100) + ((i[4]-48)*10) + ((i[5]-48)*1));
 H_R = ( ((i[6]-48)*100) + ((i[7]-48)*10) + (i[8]-48) );
 DAY = ( ((i[9]-48)*10) + ((i[10]-48)) );

 Serial.print("SYS = ");
 Serial.print( SYS );
 mySerial.print( "BP " );
 mySerial.print( "SYS = " );
 mySerial.print( SYS );
 Serial.println(" mmHg/kpa");
 Serial.print("DIA = ");
 Serial.print( DIA );
  mySerial.print("  DIA =  ");
  mySerial.print( DIA );
 Serial.println(" mmHg/kpa");

// mySerial.print("H.R = ");
 Serial.print( H_R );
  //mySerial.print( H_R );
 Serial.println(" PLUSE/Min");

 Serial.print("DAY IS : ");
 Serial.println( DAY );

 Serial.println("");
 mySerial.println("       ");
 Serial.println("");
 
 x=-1;
}

 
respiration();
pulse();
ecg();

  
    }

void ecg ()
{
// pulse();
int ecg = analogRead(A1);
mySerial.print("ecg ");
mySerial.println(analogRead(A1));
 if((digitalRead(10)==1)||(digitalRead(11)==1)){
     // Serial.println("");
     }
  else{Serial.println(analogRead(A1));mySerial.println(analogRead(A1));}
  delay(100);
  return 0;
  }
    
void respiration()
{
 
  int resp = analogRead(A0);
  mySerial.print("respvalue ");
  mySerial.println(resp);
 return 0;
  }
void pulse()
{
 // respiration();
 reading = analogRead(A2);
      // Heart beat leading edge detected.
 if(reading > UpperThreshold && IgnoreReading == false){
        if(FirstPulseDetected == false){
          FirstPulseTime = millis();
          FirstPulseDetected = true;
        }
        else{
          SecondPulseTime = millis();
          PulseInterval = SecondPulseTime - FirstPulseTime;
          FirstPulseTime = SecondPulseTime;
        }
        IgnoreReading = true;
      }

      // Heart beat trailing edge detected.
      if(reading < LowerThreshold){
        IgnoreReading = false;
      }  

      BPM = (1.0/PulseInterval) * 60.0 * 1000;
//int BPM2 = BPM-22;


   Serial.println(" BPM IS ");   
     Serial.println(BPM);
mySerial.print("pulse ");

mySerial.println(BPM);
     
    return 0;
  

 
   
  }



