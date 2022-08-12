#define Rf 9
#define Rb 8
#define Lf 5
#define Lb 4
#define H 10
int v=100,i='S';
char b;
void setup() {
  Serial.begin(9600);
  pinMode(Rb,OUTPUT);
  pinMode(Lb,OUTPUT);
    pinMode(H,OUTPUT);
}
void command(int i);
void loop() {
  if(Serial.available()>0)
  {
    i=Serial.read();
    if(i!=255)
  {
    command(i);
    b=i;
    Serial.print(b);
    Serial.print(" ");
    Serial.print(i);
    Serial.print("  ");

  }
}
}
void command(int i)
{
  switch(i)
    {
      case 'F' : analogWrite(Rf,v);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,v);
                 digitalWrite(Lb,LOW);
                 break;
      case 'B' :  analogWrite(Rf,0);
                 digitalWrite(Rb,HIGH);
                 analogWrite(Lf,0);
                 digitalWrite(Lb,HIGH);
                 break;
      case 'R' :  analogWrite(Rf,0);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,v);
                 digitalWrite(Lb,LOW);
                 break;
      case 'L' :  analogWrite(Rf,v);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,0);
                 digitalWrite(Lb,LOW);
                 break;
      case 'G' :  analogWrite(Rf,v);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,v/2);
                 digitalWrite(Lb,LOW);
                 break;
      case 'I' :  analogWrite(Rf,v/2);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,v);
                 digitalWrite(Lb,LOW);
                 break;               
      case 'V' : tone(H,1000,500);
                 delay(500);
                 noTone(H);
                 break; 
      case 'X' : analogWrite(Rf,0);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,0);
                 digitalWrite(Lb,LOW);
                 tone(H,1661,300);
                 delay(400);
                 tone(H,1661,300);
                 delay(400);
                 tone(H,1661,300);
                 delay(400);      
                 tone(H,2489,300);
                 delay(400);
                 tone(H,2217,300);
                 delay(400);
                 tone(H,2489,300);
                 delay(400);
                 tone(H,1976,500);
                 delay(600);
                 tone(H,2217,500);
                 delay(600);
                 tone(H,2637,300);
                 delay(400);
                 tone(H,2489,500);
                 delay(600);
                 noTone(H);
                 break;  
      case 'q' : v = 170;
      break;
      case '0' : v = 100;
      break;
      case 'S' :  analogWrite(Rf,0);
                 digitalWrite(Rb,LOW);
                 analogWrite(Lf,0);
                 digitalWrite(Lb,LOW);
                 

    }
    }

//     The code of any Arduino program would contain two mandatory functions, loop() and setup(). The code block in setup() function will be executed once as soon as the code is uploaded to the Arduino. The code block in the loop() function is executed and iterated indefinitely until the power to the Arduino is switched off.
//   The code begins with #define statements. The labels H(Horn), Rf(Right forward), Rb(Right Backward),  Lf(Left Forward) and Lb(Left Backward) are defined as 10, 9, 8, 5 and 4 respectively to denote digital pin numbers. The pin numbers 9 and 5 are assigned to Rf and Lf respectively as they are the only PWM(Pulse Width Modulation) pins in the Arduino and variable voltages can be given to these pins using analogWrite() function. Variables v(velocity), i(command) and b have been defined with their respective required data types. 

setup() Function
    Serial.begin(9600) is used to communicate to the UART(Universal Asynchronous Receiver Transmitter ) to begin data reception and transmission with the serial ports at a baud rate of 9600 bits per second. 
pinMode(Rb,OUTPUT);
pinMode(Lb,OUTPUT);
pinMode(H,OUTPUT);
   The above stated functions are used to set the mode of the stated pins as OUTPUT. Digital pins have to be classified as OUTPUT or INPUT or INPUT_PULLUP before they can be used in the function digitalWrite(). The pins Lf and Rf are not defined as analogWrite(), which is used for those pins does not require such mode classifications. 
   The prototype of the function command, which is defined later on, is declared.
loop() Function
    An if() statement is placed in the beginning and the condition tested is Serial.available()>0. This checks if there are any incoming bytes waiting to be received from the Rx terminal so that the serial read occurs only when there is an incoming byte. Otherwise a value -1 is read by Serial.rerad(). This is also done so that the parameter I is passed through the function command only when there is an incoming byte and not at other times. i=Serial.rerad() reads the incoming byte from the Tx of the bluetooth module into variable i. 
   As there was a malfunction in the Bluetooth module, it used to send the number 255 repeatedly due to an unknown reason, hence if(i!=255) statement is used. 
     Then the function command() is called and parameter i is passed.
b=i;    Serial.print(b);
Serial.print(" ");
Serial.print(i);
Serial.print("  ");
//  These statements are used to print the received command for debugging purposes.
//command(int i) Function
//   The function command is defined to turn the output pins on and off for the given commands. It is defined in a separate code block so that the code in the loop() function is concise and iterations can take place at a faster rate. The parameter i which will be read in the loop() function is passed to command(). The body of command()  has a switch statement to which i is passed. 
//   When ‘F’ is passed as parameter the Lf and Rf pins are written to voltage v using the function analogWrite(pin,v) . The pins Lb and Rb are set to 0V using the function digitalWrite(pin,LOW). break; is used to avoid fall through condition. Hence forward motion is achieved. Similarly other cases are set so that the desired movement is performed by the car for the given input. 
//   When ‘R’ is passed as parameter the Lf pin is written to voltage v using the function analogWrite(Lf,v) . The Rf pin is written to voltage 0 in the same way. By doing this, only the left wheel rotates forward while the right wheel is stationery, thus bringing about a rotational motion towards right. The pins Lb and Rb are set to 0V using the function digitalWrite(pin,LOW). break; is used to avoid fall through condition.
//   When ‘I’ is passed as parameter the Lf pin is written to voltage v using the function analogWrite(Lf,v). The Rf pin is written to voltage v using the function analogWrite(Lf,v). By doing this, the left wheel rotates forward with velocity ’v’ while the right wheel rotates forward with velocity ’v/2’, thus bringing about a motion both in the forward direction and leftwards. The pins Lb and Rb are set to 0V using the function digitalWrite(pin,LOW). break; is used to avoid fall through condition.
//   When ‘B’ is passed as parameter the Lf and Rf pins are written to voltage 0V using the function analogWrite(pin,0) . The pins Lb and Rb are set to HIGH state using the function digitalWrite(pin,HIGH). break; is used to avoid fall through condition. Hence backward motion is achieved.
//  ‘V’ is passed as parameter by the Bluetooth module to communicate to the Arduino to sound horn. When V is passed, the pin horn is set to HIGH state by using digitalWrite(H,HIGH), this is retained for 500ms using function delay(500); then it switched back to LOW state by using digitalWrite(H,LOW) . Thus, the sounding of horn is achieved. 
//   When ‘S’ is passed as the parameter all pins are set to low state. Hence stopping the car.
//   When ‘0’ is passed as parameter v is set to 100. And when ‘q’ is passed v is set to 170.
//   When ‘X’ is passed, a song is played by the Arduino. By using tone(H,frequency,duration) function the pin H is made to oscillate with given frequency for stated time. The notes of the song are g# g# g# d c# d b c# f d#. The frequencies were set using the following information. The durations were also set accordingly.
//
//   The mobile application sends a signal when a finger is placed on the button and sends an ‘S’ as soon as the finger is lifted off. Hence there are no delay() statements in case definitions.
