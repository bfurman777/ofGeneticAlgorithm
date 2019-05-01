#include "constants.h"

namespace geneticAlgorithm {
	// population constants
	int kNumberOfInstructions = 200;
	int kNumberOfSubjectsInPopulation = 111;
	int kMutationChance = 5;  // percent

	// positional constants
	int kStartingX = 80;
	int kStartingY = 240;
	int kGoalX = 560;
	int kGoalY = 240;
	int kSubjectRadius = 11;

	// instruction constants
	int kMinForce = 0;
	int kMaxForce = 20;
	int kMinAngle = 0;
	int kMaxAngle = 360;

	// fitness constants
	float kDistanceScalar = 1.5;
	float kNumberOfStepsScalar = 10000;
	float kDeathDescalar = 2.5;

	// obstacles
	std::vector<ofRectangle> kObstacles = std::vector<ofRectangle>();
}