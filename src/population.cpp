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

	}

	void Population::EvalInstructions() {
		if (current_instruction_ >= kNumberOfInstructions) {
			return;
		}
		for (Subject& subject : subjects_) {
			std::cout << std::endl;
			for (Point p : subject.EvalInstructions()) {
				std::cout << p.x << ' ';
			}
		}
		++current_instruction_;
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

