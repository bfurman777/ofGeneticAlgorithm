#include "population.h"

namespace geneticAlgorithm {
	Population::Population() {
		subjects_ = std::vector<Subject>(kNumberOfSubjectsInPopulation);
		current_instruction_ = 0;
	}

	Population::Population(std::vector<Subject> new_subjects) {
		subjects_ = new_subjects;
		current_instruction_ = 0;
	}

	void Population::NextGeneration() {
		current_instruction_ = 0;
		EvalInstructions();
	}

	void Population::EvalInstructions() {
		if (current_instruction_ >= kNumberOfInstructions) {
			return;
		}
		for (Subject& subject : subjects_) {
			subject.EvalInstructions();
		}
		++current_instruction_;
	}

	std::vector<Point> Population::GetPointsAtNextFrame() {
		if (current_instruction_ >= kNumberOfInstructions) {
			std::cout << "next generation time" << std::endl;
			NextGeneration();
		}
		std::vector<Point> next_points_to_show;
		for (Subject& subject : subjects_) {
			next_points_to_show.push_back(subject.GetEvaluatedPointAt(current_instruction_));
		}
		++current_instruction_;
		return next_points_to_show;
	}

	int Population::FittestSubjectIndex() {
		int fittest_index = 0;
		for (int i = 1; i < subjects_.size(); ++i) {
			if (subjects_[i].EvalFitness() > subjects_[fittest_index].EvalFitness()) {
				fittest_index = i;
			}
		}
		return fittest_index;
	}

	std::vector<Subject> &Population::GetSubjects() {
		return subjects_;
	}
}

