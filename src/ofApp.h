#pragma once

#include "ofMain.h"
#include "population.h"
#include "subject.h"

#include <iostream>

namespace geneticAlgorithm {

	class geneticAlgorithmRunner : public ofBaseApp {
	private:
		void reset();
		Population population;

	public:
		// Setup function
		void setup();

		// Functions called every frame
		void update();
		void draw();

		// User action functions
		void keyPressed(int key);

		// Initialize steps in setup
		void InitConstants();
	};

}
