#include <pitches.h>

int melody[] = {

 NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3,



NOTE_G3,NOTE_G3, NOTE_A3,NOTE_G3, NOTE_D4, NOTE_C4,



NOTE_G3, NOTE_G3, NOTE_G4,NOTE_E4,NOTE_C4, NOTE_B3, NOTE_A3,



NOTE_F4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_C4 



};

int noteDurations[] = {

  8,8,4,4,4,2,8,8,4,4,4,2,8,8,4,4,4,4,3,8,8,4,4,4,2

};



void setup() {

  pinMode(4,OUTPUT);

   for (int thisNote = 0; thisNote < 25; thisNote++) {

      int noteDuration = 1000 / noteDurations[thisNote];
  
      tone(3, melody[thisNote], noteDuration);
  
      int pauseBetweenNotes = noteDuration * 1.60;
  
      delay(pauseBetweenNotes);
  
      noTone(3);

  }

}



void loop() {

}


