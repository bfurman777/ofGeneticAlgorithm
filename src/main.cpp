#include "ofMain.h"
#include "ofApp.h"

#define DISPLAY_MODE OF_WINDOW // Can be OF_WINDOW or OF_FULLSCREEN


int main() {
	ofSetupOpenGL(640, 480, DISPLAY_MODE);
	ofSetFrameRate(16);
	ofRunApp(new geneticAlgorithm::geneticAlgorithmRunner());
}
