const int ENA = 2;
const int ENB = 3;
const int s0 = 7;  
const int s1 = 6;  
const int s2 = 5;  
const int s3 = 4;  
const int out = 8;
int red = 0;  
int green = 0;  
int blue = 0;
char t;
void speed_control(int,int);
int color_sensor_function();
void color();
void setup() {
pinMode (ENA, OUTPUT);
pinMode (ENB, OUTPUT);
pinMode(13,OUTPUT); 
pinMode(12,OUTPUT); 
pinMode(11,OUTPUT); 
pinMode(10,OUTPUT); 
Serial.begin(9600); 
pinMode(s0, OUTPUT);  
pinMode(s1, OUTPUT);  
pinMode(s2, OUTPUT);  
pinMode(s3, OUTPUT);  
pinMode(out, INPUT);
digitalWrite(s0, HIGH);  
digitalWrite(s1, HIGH);
}
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
if(t == 'F'){ 
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
else if(t == 'B'){ 
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}
else if(t == 'R'){ 
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}
else if(t == 'L'){
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
else if(t == 'S'){    
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
int CS=color_sensor_function();
if(CS==4) {
  speed_control(255,255);
  Serial.println(255);
}
if(CS==1) {
  speed_control(250,250);
  Serial.println(250);
}
if(CS==2) {
  speed_control(175,175);
  Serial.println(175);
}
if(CS==3) {
  speed_control(135,135);
  Serial.println(135);
}
delay(100);
}
void speed_control(int a,int b) {
  analogWrite(ENA, a);
  analogWrite(ENB, b);
}
int color_sensor_function() 
{  
  color();
  if (red < blue && red < green && red < 20) return 3; //red
  if (blue < red && blue < green) return 1;//blue
  if (green < red && green < blue) return 2;//green
  return 4;
 }  
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
