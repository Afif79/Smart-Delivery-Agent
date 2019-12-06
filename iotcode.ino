int trigPin = 9;
int echoPin = 10;
// connect motor controller pins to Arduino digital pins
// motor one
int enA = 5;
int in1 = 3;
int in2 = 4;
// motor two
int enB = 6;
int in3 = 8;
int in4 = 7;
int left_ir_val;
int right_ir_val;

const int left_ir = 12;
const int right_ir = 11;
  
void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void forward()
{
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
//// set speed to 200 out of possible range 0~255
  analogWrite(enB,200);
  //delay(2000);
 // now turn off motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW); 
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
// // now change motor directions
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW); 
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, HIGH);
//  delay(2000);
}
void right()
{
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
//// set speed to 200 out of possible range 0~255
  analogWrite(enB,255);
  delay(2000);
}
void left()
{
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
//// set speed to 200 out of possible range 0~255
  analogWrite(enB,255);
}
void stops()
{ 
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB,0);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  delay(10);
 
left_ir_val = digitalRead(left_ir);
right_ir_val = digitalRead(right_ir);


 if((distance<=80)) 
  {
    stops();    
    Serial.print("d");
    delay(400);
  }
   else if(right_ir_val == HIGH && left_ir_val == LOW)
 {
      left();
      Serial.print("n");
      delay(400);
   }
   else if(right_ir_val == LOW && left_ir_val == HIGH)
   {
      right();
      Serial.print("n");
      delay(400);
   }
   else if(right_ir_val == LOW && left_ir_val == LOW)
   {
      forward();
      Serial.print("n");
      delay(400);
    }
     else if(right_ir_val == HIGH && left_ir_val == HIGH)
   {
      stops();
      Serial.print("n");
      delay(400);
    }
}