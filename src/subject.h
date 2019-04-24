#pragma once

#include "ofMain.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

namespace geneticAlgorithm {

	static const int kNumberOfSubjectsInPopulation = 25;
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
	static const int kSubjectRadius = 7;

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
		Point position_;
		std::vector<Instruction> instructions_;
		int moves_to_reach_goal_;
		float fitness_;
		bool is_dead_;
		bool reached_goal_;

	public:
		Subject();  // create a random subject
		Subject(Subject parents[]);  // combining the Instructions from some parents into a single subject, with a chance to mutate
		float DistanceToGoal();
		float EvaluateFitness();  // calulate the fitness score, store it locally on this class object
		float GetFitness();
		Point &GetPosition();
		void SetPosition(const Point &point);
		std::vector<Instruction> &GetInstructions();
	};

}