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

	void Population::EvalGeneration() {
		for (Subject& subject : subjects_) {
			subject.EvalInstructions();
		}
	}

	std::vector<Point> &Population::GetNextPoints() {
		if (current_instruction_ >= kNumberOfInstructions) {
			NextGeneration();
			return std::vector<Point>{};
		}
		std::vector<Point> points;
		for (Subject &subject : subjects_) {
			points.push_back(Point(subject.GetPosition()));
		}
		++current_instruction_;
		return points;
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

