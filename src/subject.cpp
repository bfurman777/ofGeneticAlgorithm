#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
		moves_to_reach_goal_ = -1;
		fitness_ = 0;
		is_dead_ = false;
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

	void Subject::EvaluateFitness() {
		
	}

	int Subject::GetFitness() {
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

}