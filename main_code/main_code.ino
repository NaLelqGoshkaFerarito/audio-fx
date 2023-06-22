//check matlab code for more info
int x,y;
int sine, input;
unsigned long i = 1; //counter

//flanger global varialbes
int del = 15; //values up to ~50
int range = 12;
float sf = 0.3125;
int prev[62];

//modulator setup
float f_mod = 1; //values up to ~5
float alpha = 0.5;


void setup() {
  for(int j = 0; j < 62; ++j){
    prev[j] = analogRead(34);
  }
}

void loop() {
  f_mod = map(analogRead(36), 0, 4095, 1, 5);
  del = map(analogRead(35), 0, 4095, 1, 50);
  sine = analogRead(39);
  input = analogRead(12);
  x = 1 + alpha*sine*f_mod*input;
  y = x + prev[61 - (del + (int)(range*sin(2*3.14*i*sf)*0.00011))];

  prev[61] = y;
  for(int j = 0; j < 60; ++j){
    prev[j] = prev[j + 1];
  }
  i++;
}
