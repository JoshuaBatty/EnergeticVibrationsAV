//
//  Primitives.cpp
//  vertexshaderart
//
//  Created by Joshua Batty on 13/9/17.
//
//

#include "Primitives.h"


//--------------------------------------------------------------
void Primitives::setup(){
    
    icoSphere.set(1.0,1.0);
    sphere.set(1.0, 4);
    cone.set(1.0, 2.0, 4, 4);
    cylinder.set(1.0,2.0,4,4);
    box.set(1.0,1.0,1.0);
    
    idle_idx = 1;
    active_idx = 1;
    
    init();

}

//--------------------------------------------------------------
void Primitives::load_model(string path){
    model.loadModel(path);
    //you can create as many rotations as you want
    //choose which axis you want it to effect
    //you can update these rotations later on
    // these rotation set the model so it is oriented correctly
    model.setRotation(0, 90, 1, 0, 0);
    model.setRotation(0, 90, 0, 1, 0);
    model.setScale(0.9, 0.9, 0.9);
    model.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
}


//--------------------------------------------------------------
void Primitives::init(){
    primitives.clear();
    primitives.push_back(icoSphere);
    primitives.push_back(sphere);
    primitives.push_back(cone);
    primitives.push_back(cylinder);
    primitives.push_back(box);
    primitives.push_back(optimisedBox.getOptimisedBox());
    
    for(auto &p: primitives){
        p.enableNormals();
    }

    idle_primitive_mesh = primitives[idle_idx].getMesh();// ofBoxPrimitive(1, 1, 1).getMesh();
    active_primitive_mesh = primitives[active_idx].getMesh();
    
}


//--------------------------------------------------------------
void Primitives::draw_idle_mesh(){
//    idle_primitive_mesh.drawInstanced(OF_MESH_FILL, NUM_INSTANCES);
    idle_primitive_mesh.drawInstanced(OF_MESH_FILL, NUM_INSTANCES);
}

//--------------------------------------------------------------
void Primitives::draw_active_mesh(){
//    active_primitive_mesh.drawInstanced(OF_MESH_WIREFRAME, NUM_INSTANCES);
    active_primitive_mesh.drawInstanced(OF_MESH_WIREFRAME, NUM_INSTANCES);
}

//--------------------------------------------------------------
void Primitives::randomise_mesh_resolution(){
    sphere.setResolution((int)ofRandom(4,48));
    icoSphere.setResolution((int)ofRandom(0,5));
    cone.setResolution((int)ofRandom(4,20), (int)ofRandom(1,9), (int)ofRandom(0,3));
    cylinder.setResolution((int)ofRandom(4,20), (int)ofRandom(1,9), (int)ofRandom(0,4));
    box.setResolution((int)ofRandom(1,10));
    
    init();
}

//--------------------------------------------------------------
void Primitives::randomise_objects(){
    int random = (int)ofRandom(primitives.size());
    idle_idx = random;
    active_idx = random;
    idle_primitive_mesh = primitives[idle_idx].getMesh();
    active_primitive_mesh = primitives[active_idx].getMesh();
}

//--------------------------------------------------------------
int Primitives::get_index(){
    return idle_idx;
}
