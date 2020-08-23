// #include "Audio.h"
// #include "usb_audio.h"

// #include "Arduino.h"

// // Outputs
// AudioOutputUSB           USB_Out_1;           //xy=652,236
// AudioOutputSPDIF3        spdif3_1;       //xy=674,308

// // Inputs
// AsyncAudioInputSPDIF3    spdif_async1(true, true, 100, 20); //dither = true, noiseshaping = true, anti-aliasing attenuation=100dB, minimum resampling filter length=20   //xy=408,225
// AudioInputUSB            USB_In_1;           //xy=408,299

// // Patches
// //SPDIF to USB
// AudioConnection          patchCord1(spdif_async1, 0, USB_Out_1, 0);
// AudioConnection          patchCord2(spdif_async1, 1, USB_Out_1, 1);

// // USB to SPDIF
// AudioConnection          patchCord3(USB_In_1, 0, spdif3_1, 0);
// AudioConnection         

// void setup()
// {
//   pinMode(LED_BUILTIN,OUTPUT);
// }

// void loop()
// {
//   digitalWriteFast(LED_BUILTIN,!digitalReadFast(LED_BUILTIN));
//   delay(500);
// }
