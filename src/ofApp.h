#pragma once

#include "ofMain.h"

namespace geneticAlgorithm {

	class geneticAlgorithmRunner : public ofBaseApp {
	private:
		void reset();

	public:
		// Function used for one time setup
		void setup();
		void initResources();

		// Main event loop functions called on every frame
		void update();
		void draw();

		// Event driven functions, called on appropriate user action
		void keyPressed(int key);
	};

}
