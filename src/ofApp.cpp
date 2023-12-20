#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofDisableArbTex();
    shader.load("shadersGL3/shader");
    if(img.load("10-step-grey-with-guides.png")) {
        img.getTexture();
        plane.set(3840,1200, 10, 10);
        plane.mapTexCoords(0, img.getHeight(),img.getWidth(),0);
    }
}

void ofApp::update() {
 
}

void ofApp::draw() {
    // bind our texture. in our shader this will now be tex0 by default
    // so we can just go ahead and access it there.
    img.getTexture().bind();
    shader.begin();
    shader.setUniform1f("center", mouseX/1000.);
    shader.setUniform1f("gamma", mouseY/1000.);
    shader.setUniform1f("fade", mouseY/1000.);
    shader.setUniform2f("resolution", 2048, 786);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    plane.draw();
    ofPopMatrix();
    shader.end();
    img.getTexture().unbind();

   
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'f') ofToggleFullscreen();
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
