#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
		moves_to_reach_goal_ = -1;
		fitness_ = 0;
		is_dead_ = false;
		reached_goal_ = false;
		instructions_ = std::vector<Instruction>(kNumberOfInstructions);
		evaluated_path_ = std::vector<Point>(kNumberOfInstructions);
		position_ = Point();
		std::cout << kStartingX << '\n';
	}

	//TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Subject::Subject(Subject parents[]) {
	}

	float Subject::DistanceToGoal() {
		float deltaY = kGoalY - position_.y;
		float deltaX = kGoalX - position_.x;
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

	void Subject::EvalInstruction(int index) {
		int force = instructions_[index].force;
		int angle_degrees = instructions_[index].angle;
		float angle_radians = angle_degrees / 180.0 * 3.14159;
		float deltaX = force * std::cos(angle_radians);
		float deltaY = force * std::sin(angle_radians);
		position_.x += deltaX;
		position_.y += deltaY;
	}

	float Subject::GetFitness() {
		return fitness_;
	}

	Point &Subject::GetPosition() {
		return position_;
	}

	void Subject::SetPosition(const Point &point) {
		position_ = point;
	}

	std::vector<Instruction> &Subject::GetInstructions() {
		return instructions_;
	}

	void Subject::SetInstructions(const std::vector<Instruction> instructions) {
		instructions_ = instructions;
	}
}