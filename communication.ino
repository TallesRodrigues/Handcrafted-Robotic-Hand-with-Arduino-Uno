#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(10, 11); // RX, TX
Servo finger1,finger2,finger3,finger4,finger5; 

// Pwm pins setup on my Arduino One
const int  f1 = 3 ,f2 =4 , f3 =5 ,f4 =6 ,f5 =7;

// ==================================================================================================//
//   ------------------------------ Prototypes -----------------------------------
void movefinger(int op);
void movethree ();
void initialize();
  
// ==================================================================================================//
//   ------------------------------ Setup -----------------------------------
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  finger1.attach(f1);  finger2.attach(f2);  finger3.attach(f3);
  finger4.attach(f4);  finger5.attach(f5);
  
  mySerial.begin(9600);
  initialize();
}

// ==================================================================================================//
//   ------------------------------ Loop -----------------------------------
void loop() // run over and over
{
 int option,option2;  
  
   if ( mySerial.available()>0 ){
    option2 = mySerial.read();
    
      Serial.println(char(option2));
      movefinger(option2);
    }

} 
//   ------------------------------ Initialize -----------------------------------
void initialize (){
   finger1.write(180);
   finger2.write(180);
   finger3.write(180);
   finger4.write(180);
   finger5.write(180);
}

//   ------------------------------ Move Three Fingers -----------------------------------
void movethree (){
    // Move three fingers like a surfist motherfucker
    finger1.write(0); 
    finger3.write(0); 
    finger5.write(0); 
    
    
    delay(4000);
    
    
    finger1.write(180);
    finger3.write(180);
    finger5.write(180);
      
}  

//   ------------------------------ Move individual finger ----------------------------------
void movefinger(int op){
  /* Move Individual finger according to selected button
   a  - Move finger 1
    b - Move finger 2
    c - Move finger 3
    d - Move finger 4
    e - Move finger 5
  */
  switch(op){

    case 'a':
      finger1.write(0);
      delay(4000);
      finger1.write(180);
    break;
    case 'b':
      finger2.write(0);
      delay(4000);
      finger2.write(180);
    break;
    case 'c':
      finger3.write(0);
      delay(4000);
      finger3.write(180);
    break;
    case 'd':
      finger4.write(0);
      delay(4000);
      finger4.write(180);
    break;
    case 'e':
      finger5.write(0);
      delay(4000);
      finger5.write(180);
    break;
    default:
    break;
  }    
  
}

