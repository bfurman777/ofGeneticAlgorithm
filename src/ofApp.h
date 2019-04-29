#pragma once

#include "ofMain.h"
#include "population.h"
#include "subject.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

namespace geneticAlgorithm {
	/*
	int kStartingX = 80;
	int kStartingY = 240;
	int kGoalX = 560;
	int kGoalY = 240;
	int kNumberOfInstructions = 500;
	int kNumberOfSubjectsInPopulation = 77;
	int kMinForce = 0;
	int kMaxForce = 20;
	int kMinAngle = 0;
	int kMaxAngle = 360;
	int kMutationChance = 0.05;
	int kSubjectRadius = 11;
	//*/

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
	};

}
