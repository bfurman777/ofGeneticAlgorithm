#pragma once

#include "ofMain.h"
#include "constants.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

namespace geneticAlgorithm {

	const float kDegreesToRadians = 3.14159 / 180.0;
	const float kHitboxScalar = 2 / 3;  // scales the hitbox rectange inside of the circular subject

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
		bool CollidedWithObstacle();  // check all obstacles for collisions
		Point &GetPosition();
		void SetPosition(const Point &point);
		std::vector<Instruction> &GetInstructions();
		Point &GetEvaluatedPointAt(int i);
		void SetInstructions(const std::vector<Instruction> instructions);
	};

}