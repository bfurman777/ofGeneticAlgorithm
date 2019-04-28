#pragma once

#include "ofMain.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

namespace geneticAlgorithm {

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
		std::vector<Point> evaluated_path_;
		int moves_to_reach_goal_;
		float fitness_;
		bool is_dead_;
		bool reached_goal_;

	public:
		Subject();  // create a random subject
		Subject(Subject parents[]);  // combining the Instructions from some parents into a single subject, with a chance to mutate
		float DistanceToGoal();
		float EvalFitness();  // calulate the fitness score, store it locally on this class object
		void EvalInstruction(int index);
		float GetFitness();
		Point &GetPosition();
		void SetPosition(const Point &point);
		std::vector<Instruction> &GetInstructions();
		void SetInstructions(const std::vector<Instruction> instructions);
	};

}