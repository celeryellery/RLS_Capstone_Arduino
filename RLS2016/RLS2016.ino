String temp = "null";
int test = 0;
int test1 = 0;

String serial_message = "null";
String serial_message_num = "null";

//board_5 setup: start
//R1
int Board_5_R1_State = 1;
const int Board_5_Switch2_In4 = 23;
//R2
int Board_5_R2_State = 1;
const int Board_5_Switch2_In3 = 25;
//R3
int Board_5_R3_State = 1;
const int Board_5_Switch1_In1 = 26;
//C1
int Board_5_C1_State = 1;
const int Board_5_Switch2_In1 = 22;
//C2
int Board_5_C2_State = 1;
const int Board_5_Switch2_In2 = 24;
//board_5 setup: end


//board_ID: start
const int buttonPin_A = A0;     
const int buttonPin_B = A1;
const int buttonPin_C = A2;
const int buttonPin_D = A3;     
const int buttonPin_E = A4;
const int buttonPin_F = A5;
const int buttonPin_G = A6;
const int buttonPin_H = A7;
String board_ID = "null";
int buttonState_A = 0;         
int buttonState_B = 0; 
int buttonState_C = 0;
int buttonState_D = 0;     
int buttonState_E = 0;
int buttonState_F = 0;
int buttonState_G = 0;
int buttonState_H = 0;
//board_ID: end


// Need to include power regulator stuff here later, but not now for testing Board 5 only





void setup() {
  Serial.begin(9600);  
  
  //board_5: start
  //R1
  pinMode(Board_5_Switch2_In4, OUTPUT);
  //R2
  pinMode(Board_5_Switch2_In3, OUTPUT);
  //R3
  pinMode(Board_5_Switch1_In1, OUTPUT);
  //C1
  pinMode(Board_5_Switch2_In1, OUTPUT);
  //C2
  pinMode(Board_5_Switch2_In2, OUTPUT);
  //board_5: end
  
  //board_ID: start
  pinMode(buttonPin_A, INPUT);  
  pinMode(buttonPin_B, INPUT); 
  pinMode(buttonPin_C, INPUT);
  pinMode(buttonPin_D, INPUT);  
  pinMode(buttonPin_E, INPUT); 
  pinMode(buttonPin_F, INPUT);
  pinMode(buttonPin_G, INPUT);  
  pinMode(buttonPin_H, INPUT); 
  //board_ID: end
  
  // Need to include power regulator stuff here later, but not now for testing Board 5 only

}

void loop() {
  // put your main code here, to run repeatedly:

}
