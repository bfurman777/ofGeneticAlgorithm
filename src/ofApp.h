#pragma once

#include "ofMain.h"
#include "population.h"
#include "subject.h"
#include "constants.h"
#include "ofxJSON.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

namespace geneticAlgorithm {

	class geneticAlgorithmRunner : public ofBaseApp {
	private:
		Population population_;
		int instruction_index_;
		std::vector<Point> points_to_draw;  // the current frame's generation of subjects to draw

	public:
		// Setup function
		void setup();

		// Functions called every frame
		void update();
		void draw();

		// User action functions
		void keyPressed(int key);

		// JSON parsing
		ofxJSONElement ParseJSON(std::string filename);  // finds the file in the bin/data folder
		void SetConstants(const ofxJSONElement &json);  // sets variables from a json, or default values if JSON doesn't have the values
	};

}
