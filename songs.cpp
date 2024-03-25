#include "songs.h"
#include "led.h"
int currIndex = 0;
bool paused = true;
// Song *songlist;

// void setSongList() {
//   // // int soviet_melody[] = { G4, C5, G4, A4, B4, E4, E4,
//   // //                         A4, G4, F4, G4, C4, C4,
//   // //                         D4, D4, E4, F4, F4, G4, A4, B4, C5, D5,
//   // //                         E5, D5, C5, D5, B4, G4,
//   // //                         C5, B4, A4, B4, E4, E4,
//   // //                         A4, G4, F4, G4, C4, C4,
//   // //                         C5, B4, A4, G4, B4, C5, D5,
//   // //                         E5, D5, C5, B4, C5, D5, G4, G4, B4, C5, D5,
//   // //                         C5, B4, A4, G4, A4, B4, E4, E4, G4, A4, B4,
//   // //                         C5, A4, B4, C5, A4, B4, C5, A4, C5, F5,
//   // //                         F5, E5, D5, C5, D5, E5, C5, C5,
//   // //                         D5, C5, B4, A4, B4, C5, A4, A4,
//   // //                         C5, B4, A4, G4, C4, G4, A4, B4, C5, END_MELODY };
//   // // int soviet_duration[] = { 8, 4, 6, 16, 4, 8, 8,
//   // //                           4, 6, 16, 4, 8, 8,
//   // //                           4, 8, 8, 4, 8, 8, 4, 8, 8, 2,
//   // //                           4, 6, 16, 4, 8, 8,
//   // //                           4, 6, 16, 4, 8, 8,
//   // //                           4, 6, 16, 4, 6, 16,
//   // //                           4, 6, 16, 8, 8, 8, 8,
//   // //                           2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
//   // //                           2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
//   // //                           4, 6, 16, 4, 6, 16, 4, 8, 8, 2,
//   // //                           2, 8, 8, 8, 8, 3, 8, 2,
//   // //                           2, 8, 8, 8, 8, 3, 8, 2,
//   // //                           4, 6, 16, 4, 4, 2, 4, 4, 1, END_DURATION };
//   // // Song soviet_anthem(
//   // //   soviet_melody, soviet_duration);

//   // // const int usa_melody[] = { F4, D4, B3, D4, F4, B4, D5, C5, B4, D4, E4, F4, F4, F4,
//   // //                            D5, C5, B4, A4, G4, A4, B4, B4, F4, D4, B3, F4, D4,
//   // //                            B3, D4, F4, B4, D5, C5, B4, D4, E4, F4, F4, F4,
//   // //                            D5, C5, B4, A4, G4, A4, B4, B4, F4, D4, B3, D5, D5,
//   // //                            D5, E5, F5, F5, E5, D5, C5, D5, E5, E5, E5,
//   // //                            D5, C5, B4, A4, G4, A4, B4, D4, E4, F4, F4,
//   // //                            B4, B4, B4, A4, G4, G4, G4, C5, E5, D5, C5, B4,
//   // //                            B4, A4,
//   // //                            F4, F4, B4, C5, D5, E5,
//   // //                            F5, B4, C5, D5, E5, C5, B4, END_MELODY };
//   // // const int usa_duration[] = { 6, 16, 4, 4, 4, 2, 6, 16, 4, 4, 4, 2, 8, 8,
//   // //                              6, 8, 4, 2, 8, 8, 4, 4, 4, 4, 4, 6, 16,
//   // //                              4, 4, 4, 2, 6, 16, 4, 4, 4, 2, 8, 8,
//   // //                              6, 8, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8,
//   // //                              4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 4,
//   // //                              6, 8, 4, 2, 8, 8, 4, 4, 4, 2, 4,
//   // //                              4, 4, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8,
//   // //                              4, 2,
//   // //                              8, 8, 6, 8, 8, 8,
//   // //                              2, 6, 6, 3, 5, 4, 2, END_DURATION };
//   // // const Song usa_anthem(usa_melody, usa_duration);

//   // const int sk_melody[] = {
//   //   D4, G4, FS4, E4, G4, D4, B3, D4, G4, A4, B4, C5, B4, A4,
//   //   D5, C5, B4, A4, G4, FS4, E4, D4, B3, D4, G4, A4, A4, B4, G4,
//   //   FS4, G4, A4, FS4, B4, C5, D5, B4, A4, G4, FS4, G4, A4,
//   //   D5, C5, B4, A4, G4, FS4, E4, D4, B3, D4, G4, A4, A4, B4, G4, END_MELODY
//   // };
//   // const int sk_duration[] = {
//   //   4, 3, 4, 4, 4, 4, 4, 4, 4, 8, 8, 3, 8, 1,
//   //   3, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 8, 8, 4, 1,
//   //   3, 4, 4, 4, 3, 8, 4, 4, 4, 4, 4, 4, 1,
//   //   3, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 8, 8, 4, 1, END_DURATION
//   // };
//   // const Song sk_anthem(sk_melody, sk_duration);

//   // // int nk_melody[] = {
//   // //   A4, D5, D5, D5, CS5, B4, A4, G4, FS4, A4, B4, B4, B4, CS5, D5, E5, A4, A4, A4, FS5, FS5, G5, G5, FS5, E5, E5, B4, B4, B4, CS5, CS5, CS5, CS5, B4, CS5,
//   // //   D5, A4, FS5, FS5, G5, FS5, E5, E5, B4, B4, B4, E5, E5, FS5, E5, D5, CS5, B4, A4, FS4, G4, A4, A4, A4, B4, CS5, D5, E5, FS5, B4,
//   // //   G5, FS5, FS5, E5, B4, CS5, D5, A4, FS5, FS5, G5, FS5, E5, E5, B4, B4, B4, E5, E5, FS5, E5, D5, CS5, B4, A4, FS4, G4, A4, A4, A4, B4, CS5,
//   // //   D5, E5, FS5, B4, G5, FS5, FS5, E5, B4, CS5, D5, END_MELODY
//   // // };
//   // // int nk_duration[] = {
//   // //   4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 8, 8, 8, 8, 3, 8, 4, 4, 3, 8, 8, 8, 8, 8,
//   // //   1, 4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8, 3, 8, 4, 4,
//   // //   3, 8, 8, 8, 8, 8, 1, 4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8,
//   // //   3, 8, 4, 4, 3, 8, 8, 8, 8, 8, 1, END_DURATION
//   // // };
//   // // Song nk_anthem(nk_melody, nk_duration);

//   // songlist = new Song[1]{ sk_anthem  };

// }
void setPausePin(int pin) {
  pausePin = pin;
}
void pause() {
  paused = !paused;
  return;
}
void pausing() {
  // int i = 0;
  while (paused) {
    Serial.println("pasued");
    // i+=1;
  }
}
void play(int buzzerPin) {
  size_t melodyLength = songlist[currIndex].getMelodyLength();
  int *melody = songlist[currIndex].melody;
  // Serial.println("melodyLength");
  // Serial.println(melodyLength);
  size_t durationLength = songlist[currIndex].getDurationLength();
  int *noteDurations = songlist[currIndex].duration;

  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    pausing();
    int noteDuration = 2000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    int ledcontrol = thisNote % 3; 
    if (ledcontrol == 0) {
      controlLED(0);
    } else if (ledcontrol ==1) {
      controlLED(1);
    } else {
      controlLED(2);
    }
    pausing();
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    pausing();
    noTone(buzzerPin);
    // Serial.println("keep going");
    // Serial.println(thisNote);
  }
  Serial.println("song done");
  next();
}
void next() {
  currIndex = (currIndex + 1) % (sizeof(songlist) / sizeof(songlist[0]));
  // Serial.println("new");
  // Serial.println(currIndex);
}