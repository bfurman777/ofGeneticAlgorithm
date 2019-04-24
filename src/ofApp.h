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

		// Functions called every frame
		void update();
		void draw();

		// User action functions
		void keyPressed(int key);

		// Initialize things in setup
		void InitResources();
		void InitBox2D();
	};

}
