int mot1=5;     //initialising motors
int mot2=6;
int mot3=9;
int mot4=10;

int exleft_sensor = A4;     //initialising the 5 IR sensors
int left_sensor = A3;
int centre_sensor = A2;
int right_sensor = A1;
int exright_sensor = A0;


void setup() {
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  pinMode(mot3, OUTPUT);
  pinMode(mot4, OUTPUT);
  
  pinMode(exleft_sensor, INPUT);
  pinMode(left_sensor, INPUT);
  pinMode(centre_sensor, INPUT);
  pinMode(right_sensor, INPUT);
  pinMode(exright_sensor, INPUT);
  
    
}

   
   void go_straight()
   {
     analogWrite(mot1,240);
     analogWrite(mot2,0);
     analogWrite(mot3,240);
     analogWrite(mot4,0);
   }
   void l_turn_left()
   {
     analogWrite(mot1,150);
     analogWrite(mot2,0);
     analogWrite(mot3,240);
     analogWrite(mot4,0);
   }
   void turn_left()
   {
     analogWrite(mot1,0);
     analogWrite(mot2,0);
     analogWrite(mot3,120);
     analogWrite(mot4,0);
   }
   void l_turn_right()
   {
     analogWrite(mot1,240);
     analogWrite(mot2,0);
     analogWrite(mot3,150);
     analogWrite(mot4,0);
   }
   void turn_right()
   {
     analogWrite(mot1,120);
     analogWrite(mot2,0);
     analogWrite(mot3,0);
     analogWrite(mot4,0);
   }
   void stop_it()
   {
     analogWrite(mot1,0);
     analogWrite(mot2,0);
     analogWrite(mot3,0);
     analogWrite(mot4,0);
   }


void loop() {
   Serial.begin(9600);
   
   int a = digitalRead(exleft_sensor);
   int b = digitalRead(left_sensor);
   int c = digitalRead(centre_sensor);
   int d = digitalRead(right_sensor);
   int e = digitalRead(exright_sensor);
   
   if((a == 0) && (b == 0) && (c == 1) && (d == 0) && (e == 0))
   {
    go_straight(); 
   }
   if((a == 0) && (b == 1) && (c == 1) && (d == 0) && (e == 0))
   {
     l_turn_left();
   }
   if((a == 1) && (b == 1) && (c == 1) && (d == 0) && (e == 0))
   {
     turn_left();
   }
   if((a == 0) && (b == 0) && (c == 1) && (d == 1) && (e == 0))
   {
     l_turn_right();
   }
   if((a == 0) && (b == 0) && (c == 1) && (d == 1) && (e == 1))
   {
     turn_right();
   }
   if((a == 1) && (b == 1) && (c == 1) && (d == 1) && (e == 1))
   {
     stop_it();
   }
}
