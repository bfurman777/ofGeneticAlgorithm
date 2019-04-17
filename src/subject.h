#pragma once

#include "ofMain.h"

#include <stdlib.h>
#include <time.h>

namespace geneticAlgorithm {

	static const int kNumberOfInstructions = 500;
	static const int kStartingX = 0;
	static const int kStartingY = 0;
	static const int kGoalX = 100;
	static const int kGoalY = 100;
	static const int kMinForce = 0;
	static const int kMaxForce = 500;
	static const int kMinAngle = 0;
	static const int kMaxAngle = 360;
	static const int kMutationChance = 0.05;

	struct Point {
		int x;
		int y;

		Point() : x(kStartingX), y(kStartingY) {};
		Point(int x, int y) : x(x), y(y) {};
	};

	struct Instruction {
		int force;
		int angle;

		Instruction() {	// Generate a random Instruction if no parameters.
			srand(time(0)); 
			force = rand() % kMaxForce + kMinForce + 1;
			angle = rand() % kMaxAngle + kMinAngle + 1;
		};
		Instruction(int force, int angle) : force(force), angle(angle) {};
	};

	class Subject {
	private:
		Point position;
		Instruction instructions[kNumberOfInstructions];

	public:
		Subject();  // create a random subject
		Subject(Subject parents[]);	// combining the Instructions from some parents into a single subject, with a chance to mutate
		Point *GetPosition();
		Instruction *GetInstructions();
	};

}