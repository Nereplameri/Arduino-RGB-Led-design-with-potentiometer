int R_PIN = 3;
int G_PIN = 5;
int B_PIN = 6;

int potR = 0 ;
int potG = 0 ;
int potB = 0 ;

float ratio = (float) 1023 / 255;

int valueR = 0;
int valueG = 0;
int valueB = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);

  Serial.begin(9600);

  analogWrite(R_PIN, 255);
  analogWrite(G_PIN, 255);
  analogWrite(B_PIN, 255);
}

void loop() {
  potR = analogRead(A0);
  potG = analogRead(A1);
  potB = analogRead(A2);

  if (potR < 10){
    potR = 0;
  }

  if (potG < 10){
    potG = 0;
  }

  if (potB < 10){
    potB = 0;
  }
  
  Serial.println(potR);
  valueR = 255 - potR / ratio;
  valueG = 255 - potG / ratio;
  valueB = 255 - potB / ratio;

  
  analogWrite(R_PIN, valueR);
  analogWrite(G_PIN, valueG);
  analogWrite(B_PIN, valueB);
}
