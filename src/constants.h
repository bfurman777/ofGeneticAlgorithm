#pragma once

#include "ofMain.h"
#include <vector>

namespace geneticAlgorithm {
	// population constants
	extern int kNumberOfInstructions;
	extern int kNumberOfSubjectsInPopulation;
	extern int kMutationChance;  // percent

	// positional constants
	extern int kStartingX;
	extern int kStartingY;
	extern int kGoalX;
	extern int kGoalY;
	extern int kSubjectRadius;

	// instruction constants
	extern int kMinForce;
	extern int kMaxForce;
	extern int kMinAngle;
	extern int kMaxAngle;
	
	// fitness constants
	extern float kDistanceScalar;
	extern float kNumberOfStepsScalar;

	// obstacles
	extern std::vector<ofRectangle> kObstacles;
}