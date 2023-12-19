#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){


	ofGLWindowSettings settings;
    settings.setGLVersion(3,2);
    
    settings.setSize(1920,1200);
    settings.setPosition(glm::vec2(300,0));
    settings.windowMode = OF_FULLSCREEN;
    auto proyector_1 = ofCreateWindow(settings);
    
    settings.setSize(1920,1200);
    settings.setPosition(glm::vec2(1921,0));
    
    // uncomment next line to share main's OpenGL resources with gui
    //settings.shareContextWith = proyector_1;
    
	auto proyector_2 = ofCreateWindow(settings);
    
    auto mainApp = make_shared<ofApp>();
    ofAddListener(proyector_2->events().draw,mainApp.get(),&ofApp::draw2);

	ofRunApp(proyector_1, mainApp);
	ofRunMainLoop();

}
