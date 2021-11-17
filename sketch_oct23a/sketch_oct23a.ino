int valMove = 0;
int valLight = 0;
const int photoSensor = A0;
const int pirSensor = 12;
const int Relay = 5;

void setup(void)
{ 
  Serial.begin(115200);
  pinMode(Relay, OUTPUT);
}


int check(int valLight,int valMove){
  int a,b;
  valLight<300 ? a=0 : a=1;
  valMove==HIGH ? b=1 : b=0;
  Serial.print(a);
  Serial.print(" ");
  Serial.println(b);
  return a+b;
  
}
void loop() 
{
  valMove = digitalRead(pirSensor); 
  valLight = analogRead(photoSensor);
  if(check(valLight,valMove)==2){
    Serial.println("gelap dan bergerak");
    Serial.println(valLight);
    Serial.println(valMove);
    digitalWrite(Relay, LOW);
    delay(10000);
  }
  digitalWrite(Relay, HIGH);
 }
