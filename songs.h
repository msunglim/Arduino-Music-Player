#ifndef SONGS_H
#define SONGS_H
#include "notes.h"
#include <Arduino.h>

#define END_MELODY '\0'
#define END_DURATION 0

struct Song {
  int* melody;
  size_t melodyLength;
  int* duration;
  size_t durationLength;

  Song(int m[], int d[]) {
    melody = m;
    melodyLength = getsize(m);
    duration = d;
    durationLength = getsize(d);
  }
  //target is a pointer. increase it by size of its element, and compare a value at the pointer with the end marker.
  size_t getsize(int* target) {
    size_t size = 0;
    while (*target != END_MELODY and *target != END_DURATION) {
      size++;
      target++;
    }
    return size;
  }
  size_t getMelodyLength() {
    return melodyLength;
  }
  size_t getDurationLength() {
    return durationLength;
  }
};

// const int usa_melody[] = { F4, D4, B3, D4, F4, B4, D5, C5, B4, D4, E4, F4, F4, F4,
//                            D5, C5, B4, A4, G4, A4, B4, B4, F4, D4, B3, F4, D4,
//                            B3, D4, F4, B4, D5, C5, B4, D4, E4, F4, F4, F4,
//                            D5, C5, B4, A4, G4, A4, B4, B4, F4, D4, B3, D5, D5,
//                            D5, E5, F5, F5, E5, D5, C5, D5, E5, E5, E5,
//                            D5, C5, B4, A4, G4, A4, B4, D4, E4, F4, F4,
//                            B4, B4, B4, A4, G4, G4, G4, C5, E5, D5, C5, B4,
//                            B4, A4,
//                            F4, F4, B4, C5, D5, E5,
//                            F5, B4, C5, D5, E5, C5, B4, END_MELODY };
// const int usa_duration[] = { 6, 16, 4, 4, 4, 2, 6, 16, 4, 4, 4, 2, 8, 8,
//                              6, 8, 4, 2, 8, 8, 4, 4, 4, 4, 4, 6, 16,
//                              4, 4, 4, 2, 6, 16, 4, 4, 4, 2, 8, 8,
//                              6, 8, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8,
//                              4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 4,
//                              6, 8, 4, 2, 8, 8, 4, 4, 4, 2, 4,
//                              4, 4, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8,
//                              4, 2,
//                              8, 8, 6, 8, 8, 8,
//                              2, 6, 6, 3, 5, 4, 2, END_DURATION };
// const Song usa_anthem(usa_melody, usa_duration);

// const int sk_melody[] = {
//   D4, G4, FS4, E4, G4, D4, B3, D4, G4, A4, B4, C5, B4, A4,
//   D5, C5, B4, A4, G4, FS4, E4, D4, B3, D4, G4, A4, A4, B4, G4,
//   FS4, G4, A4, FS4, B4, C5, D5, B4, A4, G4, FS4, G4, A4,
//   D5, C5, B4, A4, G4, FS4, E4, D4, B3, D4, G4, A4, A4, B4, G4, END_MELODY
// };
// const int sk_duration[] = {
//   4, 3, 4, 4, 4, 4, 4, 4, 4, 8, 8, 3, 8, 1,
//   3, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 8, 8, 4, 1,
//   3, 4, 4, 4, 3, 8, 4, 4, 4, 4, 4, 4, 1,
//   3, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 8, 8, 4, 1, END_DURATION
// };
// const Song sk_anthem(sk_melody, sk_duration);

const int soviet_melody[] = { G4, C5, G4, A4, B4, E4, E4,
                              A4, G4, F4, G4, C4, C4,
                              D4, D4, E4, F4, F4, G4, A4, B4, C5, D5,
                              E5, D5, C5, D5, B4, G4,
                              C5, B4, A4, B4, E4, E4,
                              A4, G4, F4, G4, C4, C4,
                              C5, B4, A4, G4, B4, C5, D5,
                              E5, D5, C5, B4, C5, D5, G4, G4, B4, C5, D5,
                              C5, B4, A4, G4, A4, B4, E4, E4, G4, A4, B4,
                              C5, A4, B4, C5, A4, B4, C5, A4, C5, F5,
                              F5, E5, D5, C5, D5, E5, C5, C5,
                              D5, C5, B4, A4, B4, C5, A4, A4,
                              C5, B4, A4, G4, C4, G4, A4, B4, C5, END_MELODY };
const int soviet_duration[] = { 8, 4, 6, 16, 4, 8, 8,
                                4, 6, 16, 4, 8, 8,
                                4, 8, 8, 4, 8, 8, 4, 8, 8, 2,
                                4, 6, 16, 4, 8, 8,
                                4, 6, 16, 4, 8, 8,
                                4, 6, 16, 4, 6, 16,
                                4, 6, 16, 8, 8, 8, 8,
                                2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
                                2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
                                4, 6, 16, 4, 6, 16, 4, 8, 8, 2,
                                2, 8, 8, 8, 8, 3, 8, 2,
                                2, 8, 8, 8, 8, 3, 8, 2,
                                4, 6, 16, 4, 4, 2, 4, 4, 1, END_DURATION };
const Song soviet_anthem(
  soviet_melody, soviet_duration);

const int nk_melody[] = {
  A4, D5, D5, D5, CS5, B4, A4, G4, FS4, A4, B4, B4, B4, CS5, D5, E5, A4, A4, A4, FS5, FS5, G5, G5, FS5, E5, E5, B4, B4, B4, CS5, CS5, CS5, CS5, B4, CS5,
  D5, A4, FS5, FS5, G5, FS5, E5, E5, B4, B4, B4, E5, E5, FS5, E5, D5, CS5, B4, A4, FS4, G4, A4, A4, A4, B4, CS5, D5, E5, FS5, B4,
  G5, FS5, FS5, E5, B4, CS5, D5, A4, FS5, FS5, G5, FS5, E5, E5, B4, B4, B4, E5, E5, FS5, E5, D5, CS5, B4, A4, FS4, G4, A4, A4, A4, B4, CS5,
  D5, E5, FS5, B4, G5, FS5, FS5, E5, B4, CS5, D5, END_MELODY
};
const int nk_duration[] = {
  4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 8, 8, 8, 8, 3, 8, 4, 4, 3, 8, 8, 8, 8, 8,
  1, 4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8, 3, 8, 4, 4,
  3, 8, 8, 8, 8, 8, 1, 4, 3, 8, 4, 8, 8, 3, 8, 4, 4, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8, 3, 8, 4, 8, 8,
  3, 8, 4, 4, 3, 8, 8, 8, 8, 8, 1, END_DURATION
};
const Song nk_anthem(nk_melody, nk_duration);
//red team
const Song songlist[] = { soviet_anthem, nk_anthem };
//blue team
// const Song songlist[] = { usa_anthem, sk_anthem };
// extern Song* songlist;
extern int currIndex;
extern bool paused;
extern int pausePin;
// void setSongList();
void pause();
void play(int buzzerPin);
void next();
void setPausePin(int pin);
void pausing();
#endif