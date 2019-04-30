#pragma once

#include "ofMain.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

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

	struct Point {
		int x;
		int y;

		Point() : x(kStartingX), y(kStartingY) {};
		Point(int x, int y) : x(x), y(y) {};
		Point(const Point &to_copy) : x(to_copy.x), y(to_copy.y) {};
	};

	struct Instruction {
		int force;
		int angle;

		Instruction() {	// Generate a random Instruction if no parameters.
			force = rand() % kMaxForce + kMinForce + 1;
			angle = rand() % kMaxAngle + kMinAngle + 1;
		};
		Instruction(int force, int angle) : force(force), angle(angle) {};

		bool operator==(const Instruction& other) {
			return force == other.force && angle == other.angle;
		}
		bool operator!=(const Instruction& other) {
			return !(*this == other);
		}
	};

	class Subject {
	private:
		Point current_position_;
		std::vector<Instruction> instructions_;
		std::vector<Point> evaluated_path_;
		bool is_dead_;
		bool reached_goal_;
		int steps_to_reach_goal_;

	public:
		Subject();  // create a random subject
		Subject(std::vector<Subject> &parents);  // combining the Instructions from some parents into a single subject, with a chance to mutate
		Subject(const Subject &to_copy);
		float DistanceToGoal();
		float EvalFitness();  // calulate the fitness score, store it locally on this class object
		std::vector<Point> &EvalInstructions();  // get the path of the subject for this generation
		Point &GetPosition();
		void SetPosition(const Point &point);
		std::vector<Instruction> &GetInstructions();
		Point &GetEvaluatedPointAt(int i);
		void SetInstructions(const std::vector<Instruction> instructions);
	};

}