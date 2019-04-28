#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
		moves_to_reach_goal_ = -1;
		fitness_ = 0;
		is_dead_ = false;
		reached_goal_ = false;
		instructions_ = std::vector<Instruction>(kNumberOfInstructions);
		evaluated_path_ = std::vector<Point>();
		current_position_ = Point();
	}

	//TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Subject::Subject(Subject parents[]) {
	}

	float Subject::DistanceToGoal() {
		float deltaY = kGoalY - current_position_.y;
		float deltaX = kGoalX - current_position_.x;
		return std::sqrt(deltaY * deltaY + deltaX * deltaX);
	}

	float Subject::EvalFitness() {
		fitness_ = 0;
		fitness_ += 1 / DistanceToGoal();
		if (reached_goal_) {
			fitness_ += 1 / moves_to_reach_goal_;
		}
		return fitness_;
	}

	std::vector<Point> &Subject::EvalInstructions() {
		for (Instruction instruction : instructions_) {
			int force = instruction.force;
			int angle_degrees = instruction.angle;
			float angle_radians = angle_degrees / 180.0 * 3.14159;
			float deltaX = force * std::cos(angle_radians);
			float deltaY = force * std::sin(angle_radians);
			current_position_.x += deltaX;
			current_position_.y += deltaY;
			evaluated_path_.push_back(Point(current_position_));
		}

		return evaluated_path_;
	}

	float Subject::GetFitness() {
		return fitness_;
	}

	Point &Subject::GetPosition() {
		return current_position_;
	}

	void Subject::SetPosition(const Point &point) {
		current_position_ = point;
	}

	std::vector<Instruction> &Subject::GetInstructions() {
		return instructions_;
	}

	void Subject::SetInstructions(const std::vector<Instruction> instructions) {
		instructions_ = instructions;
	}
}