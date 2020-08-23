#include "plotter.h"
#include "Audio.h" 
#include "Arduino.h"

#define DEBUG
#define PLOTWAVE  //uncomment this line to plot the waveform (Arduino IDE Serial Plotter)

// Outputs
AudioOutputSPDIF3        spdif3_1;       //xy=674,308
Plotter                  plotter;

// Inputs
AsyncAudioInputSPDIF3    spdif_async1(true, true, 100, 20, 80); //dither = true, noiseshaping = true, anti-aliasing attenuation=100dB, minimum resampling filter length=20   //xy=408,225


AudioSynthWaveform       waveform1;    

// waveform to SPDIF
AudioConnection          patchCord1(waveform1, 0, spdif3_1, 0);
AudioConnection          patchCord2(waveform1, 0, spdif3_1, 1);

// waveform to plotter
AudioConnection          patchCord3(spdif_async1, 0, plotter, 0);         

void setup()
{
  #ifdef DEBUG
    Serial.begin(115200);
    while (!Serial);
    #ifdef PLOTWAVE
        plotter.activate(true);
    #endif
  #endif
  AudioMemory(15); 
  waveform1.frequency(440);
  waveform1.amplitude(1);
}

void loop()
{
  #ifdef DEBUG
  #ifndef PLOTWAVE
    double bufferedTine=spdif_async1.getBufferedTime();
    Serial.print("buffered time [micro seconds]: ");
	Serial.println(bufferedTine*1e6,2);
    double f=spdif_async1.getInputFrequency();
	Serial.print("frequency: ");
	Serial.println(f);
  #endif
  #endif
  delay(500);
}
