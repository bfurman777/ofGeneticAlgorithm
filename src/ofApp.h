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
		// Setup functions
		void setup();

		// Functions called every frame
		void update();
		void draw();

		// User action functions
		void keyPressed(int key);

		// Initialize things in setup
		void InitResources();
	};

}
