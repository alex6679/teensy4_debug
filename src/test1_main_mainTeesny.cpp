#include "plotter.h"
#include "Audio.h" 
#include "Arduino.h"

#define DEBUG

// Outputs
AudioOutputSPDIF3        spdif3_1;       //xy=674,308
Plotter                  plotter;

// Inputs
AsyncAudioInputSPDIF3    spdif_async1(false, false, 100, 20); //dither = true, noiseshaping = true, anti-aliasing attenuation=100dB, minimum resampling filter length=20   //xy=408,225


AudioSynthWaveform       waveform1;    

// waveform to SPDIF
AudioConnection          patchCord1(waveform1, 0, spdif3_1, 0);
AudioConnection          patchCord2(waveform1, 0, spdif3_1, 1);

// waveform to plotter
AudioConnection          patchCord3(waveform1, 0, plotter, 0);         

void setup()
{
  #ifdef DEBUG
    Serial.begin(115200);
    while (!Serial);
    plotter.activate(true);
  #endif
  AudioMemory(15); 
  waveform1.frequency(440);
  waveform1.amplitude(0.9);
}

void loop()
{
 
}
