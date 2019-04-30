#pragma once

#include "ofMain.h"

namespace geneticAlgorithm {

	// population constants
	const int kNumberOfInstructions = 200;
	const int kNumberOfSubjectsInPopulation = 111;
	const int kMutationChance = 5;  // percent

	// positional constants
	const int kStartingX = 80;
	const int kStartingY = 240;
	const int kGoalX = 560;
	const int kGoalY = 240;
	const int kSubjectRadius = 11;

	// instruction constants
	const int kMinForce = 0;
	const int kMaxForce = 20;
	const int kMinAngle = 0;
	const int kMaxAngle = 360;

	// fitness constants
	const float kDistanceScalar = 1.5;
	const float kNumberOfStepsScalar = 10000;
}