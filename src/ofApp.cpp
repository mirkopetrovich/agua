#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofDisableArbTex();
    shader.load("shadersGL3/shader");
    waterMovie.load("movies/agua.mp4");
    waterMovie.play();
    
    gui.setup();
    gui.add(center.set("centro", 0.0, 0, 0.1));
    gui.add(gamma.set("gamma", 0.0, 0.0, 1.0));
    gui.add(fade.set("fade", 0.0, 0.0, 0.1));
}

void ofApp::update() {
    waterMovie.update();
}

void ofApp::draw() {
    shader.begin();
    shader.setUniformTexture("tex0", waterMovie.getTexture(), 1);
    shader.setUniform1f("center", center);
    shader.setUniform1f("gamma", gamma);
    shader.setUniform1f("fade", fade);
    shader.setUniform2f("resolution", 3840, 1200);
    waterMovie.draw(0,0);
    shader.end();
   
    gui.draw();
    
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
