//
//  AlphaTrails.hpp
//  EnergeticVibrationsAV
//
//  Created by Joshua Batty on 4/10/17.
//
//

#pragma once
#include "ofMain.h"
#include "PingPong.h"

class AlphaTrails : public PingPong{
    
public:
    void setup();
    void set_source_texture(ofFbo& tex);
    void draw();
    void runSimulation();
    
    ofShader shader_bufA;
    ofShader shader_image;
};
