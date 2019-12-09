// LED 1 => Pin 38
// LED 20 => Pin 39
// LED 14 => Pin 40
// LED 15 => Pin 41
// LED 16 => Pin 42
// LED 17 => Pin 43
// LED 18 => Pin 44
// LED 19 => Pin 45
// LED 21 => Pin 46

int leds[37] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46};
int numberOfLeds = 37;

int penis[11] = {11, 43, 24, 25, 26, 32, 33, 12, 13, 8, 9};
int heart[10] = {6, 11, 44, 24, 30, 31, 26, 39, 13, 7};
int smiley[9] = {11, 12, 24, 25, 27, 32, 46, 40, 8};

int *motifs[3] = {penis, heart, smiley};
int lengthOfMotifs[3] = {11, 10, 9};
int numberOfMotifs = 3;
int currentMotif = 0;



void setup() {
  turnOffLeds();

  // pinMode(47, INPUT); // This is our input button
}


void turnOffLeds() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}


void showMotif(int motif[], int lengthOfMotif, bool active=true) {

  if (active) {
    for(int i = 0; i < lengthOfMotif; i++) {
      digitalWrite(motif[i], HIGH);
    }
  } else {
      for(int i = 0; i < (sizeof(motif)/sizeof(motif[0])); i++) {
      digitalWrite(motif[i], LOW);
    }
  }
}


void nextMotif() {
  if (currentMotif == numberOfMotifs - 1) {
    currentMotif = 0;
  } else {
    currentMotif += 1;
  }
}


void loop() {
  showMotif(motifs[currentMotif], lengthOfMotifs[currentMotif]);
  delay(2000);
  turnOffLeds();
  nextMotif();


  // if (digitalRead(47) == LOW) {
  //   buttonPressed = true;
  // }
  // if (buttonPressed){
  //   nextMotif();
  //   buttonPressed = false;
  // }
}
