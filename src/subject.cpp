#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
		moves_to_reach_goal_ = -1;
		fitness_ = 0;
		is_dead_ = false;
		reached_goal_ = false;
		instructions_ = std::vector<Instruction>(kNumberOfInstructions);
		position_ = Point();
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
		//std::cout << "Angle deg, rad: " << angle_degrees << ' ' << angle_radians << '\n';
		std::cout << "POS BEFORE: " << position_.x << ' ' << position_.y << '\n';
		//std::cout << "DELTAS: " << deltaX << ' ' << deltaY << '\n';
		position_ = Point(position_.x + static_cast<int>(std::round(deltaX)), position_.y + static_cast<int>(std::round(deltaY)));
		std::cout << "POS AFTER: " << position_.x << ' ' << position_.y << '\n';
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