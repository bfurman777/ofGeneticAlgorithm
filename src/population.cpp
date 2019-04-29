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

	std::vector<std::vector<Point>> Population::EvalGeneration() {
		std::vector<std::vector<Point>> generation_points;
		for (Subject& subject : subjects_) {
			generation_points.push_back(subject.EvalInstructions());
		}
		return generation_points;
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

