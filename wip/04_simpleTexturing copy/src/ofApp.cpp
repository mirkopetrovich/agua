#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    
    fbo.allocate(1920,1200,GL_RGBA32F),
    fbo.begin();
    ofClear(0,0,0,0);
    fbo.end();
    
    fbo2.allocate(1920,1200,GL_RGBA32F),
    fbo2.begin();
    ofClear(0,0,0,0);
    fbo2.end();
    
	ofDisableArbTex();
	if(ofIsGLProgrammableRenderer()){
		shader.load("shadersGL3/shader");
	}else{
		shader.load("shadersGL2/shader");
	}

	if(img.load("10-step-grey-with-guides.png")) {
		img.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
	}

	plane.set(3840,1200, 10, 10);
	plane.mapTexCoords(0, 0, img.getWidth(), img.getHeight());
}


//--------------------------------------------------------------
void ofApp::update() {
    fbo.begin();
    drawFbo();
    fbo.end();
    fbo2.begin();
    drawFbo2();
    fbo2.end();
	
}

//--------------------------------------------------------------

void ofApp::drawFbo() {
    
    // bind our texture. in our shader this will now be tex0 by default
    // so we can just go ahead and access it there.
    img.getTexture().bind();
    
    // start our shader, in our OpenGL3 shader this will automagically set
    // up a lot of matrices that we want for figuring out the texture matrix
    // and the modelView matrix
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

void ofApp::drawFbo2() {
    
    // bind our texture. in our shader this will now be tex0 by default
    // so we can just go ahead and access it there.
    img.getTexture().bind();
    
    // start our shader, in our OpenGL3 shader this will automagically set
    // up a lot of matrices that we want for figuring out the texture matrix
    // and the modelView matrix
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


void ofApp::draw() {
   
    fbo.draw(0,0);
}

void ofApp::draw2(ofEventArgs &args) {
    
    fbo2.draw(0,0);
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
