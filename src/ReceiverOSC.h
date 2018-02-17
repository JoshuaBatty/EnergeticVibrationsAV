//
//  ReceiverOSC.hpp
//  EnergeticVibrationsAV
//
//  Created by Joshua Batty on 9/2/18.
//
//

#pragma once 

#include "ofMain.h"
#include "ofxOsc.h"

#define NUM_CHAIRS 21
#define OSC_PORT 8000

class ReceiverOSC{
public:
    
    ReceiverOSC();
    void update();
    vector<int> get_chair_states();
    vector<float> get_vibration_speeds();
    
private:
    ofxOscReceiver receiver;
    vector<int> chair_states;
    vector<float> vibration_hz;
};