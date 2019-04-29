#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
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
		if (evaluated_path_.size() == 0) {
			EvalInstructions();
		}
		float fitness = 0;
		fitness += 1 / DistanceToGoal();  // closer to goal = more steps
		if (reached_goal_) {  // less steps = more score
			fitness += 1 / evaluated_path_.size();
		}
		return fitness;
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
			if (DistanceToGoal() < kSubjectRadius) {
				reached_goal_ = true;
				break;
			}
		}

		return evaluated_path_;
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