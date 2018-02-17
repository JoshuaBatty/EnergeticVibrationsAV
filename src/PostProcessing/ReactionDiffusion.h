//
//  ReactionDiffusion.hpp
//  vertexshaderart
//
//  Created by Joshua Batty on 20/9/17.
//
//

#pragma once
#include "ofMain.h"
#include "PingPong.h"

class ReactionDiffusion : public PingPong{
    
public:
    void setup();
    void set_source_texture(ofFbo& tex);
    void draw();
    void runSimulation();

    ofShader reaction_shader_bufA;
    ofShader reaction_shader_image;
    
    float intensity;
    float bleed_amount;
};
