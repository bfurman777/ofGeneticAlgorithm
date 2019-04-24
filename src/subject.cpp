#include "subject.h"

namespace geneticAlgorithm {

	Subject::Subject() {
		moves_to_reach_goal_ = -1;
		fitness_ = 0;
		is_dead_ = false;
	}

	//TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Subject::Subject(Subject parents[]) {
	}

	float Subject::DistanceToGoal() {
		return 1.0;
	}

	void Subject::EvaluateFitness() {
		
	}

	int Subject::GetFitness() {
		return fitness_;
	}

	Point *Subject::GetPosition() {
		return &position_;
	}

	Instruction *Subject::GetInstructions() {
		return instructions_;
	}

}