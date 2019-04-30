#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
		is_dead_ = false;
		reached_goal_ = false;
		instructions_ = std::vector<Instruction>(kNumberOfInstructions);
		evaluated_path_ = std::vector<Point>();
		current_position_ = Point();
		steps_to_reach_goal_ = 0;
	}

	Subject::Subject(std::vector<Subject> &parents) {
		is_dead_ = false;
		reached_goal_ = false;
		instructions_ = std::vector<Instruction>();
		evaluated_path_ = std::vector<Point>();
		current_position_ = Point();
		steps_to_reach_goal_ = 0;

		for (int i = 0; i < kNumberOfInstructions; ++i) {
			// chose a random parent's instructions, or a small chance to randomize the instruction
			if (rand() % 100 <= kMutationChance) {
				instructions_.push_back(Instruction());
			}
			int parent_chosen = rand() % parents.size();
			instructions_.push_back(parents[parent_chosen].instructions_[i]);
		}
	}

	Subject::Subject(const Subject &to_copy) {
		is_dead_ = to_copy.is_dead_;
		reached_goal_ = to_copy.reached_goal_;
		instructions_ = to_copy.instructions_;
		evaluated_path_ = to_copy.evaluated_path_;
		current_position_ = to_copy.current_position_;
		steps_to_reach_goal_ = to_copy.steps_to_reach_goal_;
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
		fitness += kDistanceScalar / DistanceToGoal();  // closer to goal = higher score
		if (reached_goal_) {  
			fitness *= kReachedGoalScalar;  // reaching goal scales your fitness up
			fitness += kNumberOfStepsScalar / steps_to_reach_goal_;  // less steps = more score
		}
		return fitness;
	}

	std::vector<Point> &Subject::EvalInstructions() {
		if (evaluated_path_.size() >= kNumberOfInstructions) {
			return evaluated_path_;
		}
		for (Instruction instruction : instructions_) {
			if (reached_goal_ || is_dead_) {
				evaluated_path_.push_back(Point(current_position_));
				continue;
			}
			int force = instruction.force;
			int angle_degrees = instruction.angle;
			float angle_radians = angle_degrees / 180.0 * 3.14159;
			float deltaX = force * std::cos(angle_radians);
			float deltaY = force * std::sin(angle_radians);
			current_position_.x += deltaX;
			current_position_.y += deltaY;
			evaluated_path_.push_back(Point(current_position_));
			++steps_to_reach_goal_;
			if (DistanceToGoal() < kSubjectRadius) {
				reached_goal_ = true;
				current_position_.x = kGoalX;
				current_position_.y = kGoalY;
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

	Point &Subject::GetEvaluatedPointAt(int i) {
		if (evaluated_path_.size() == 0) {
			EvalInstructions();
		}
		return evaluated_path_[i];
	}
}