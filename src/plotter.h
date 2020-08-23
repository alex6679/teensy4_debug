
#ifndef plotter_h_
#define plotter_h_

#include "Arduino.h"
#include "AudioStream.h"

class Plotter : public AudioStream
{
public:
	Plotter(void) : AudioStream(8, inputQueueArray){};
	void activate(bool on);
	virtual void update(void);

private:
	audio_block_t *inputQueueArray[8];
	bool _on=false;
};

#endif