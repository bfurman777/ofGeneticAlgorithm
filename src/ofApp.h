#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"


namespace geneticAlgorithm {

	class geneticAlgorithmRunner : public ofBaseApp {
	private:
		void reset();

	public:
		// Setup functions
		void setup();
		void initResources();

		// Functions called every frame
		void update();
		void draw();

		// User action functions
		void keyPressed(int key);
	};

}
