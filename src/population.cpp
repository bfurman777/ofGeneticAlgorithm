#include "population.h"

namespace geneticAlgorithm {
	Population::Population() {
		subjects_ = std::vector<Subject>(kNumberOfSubjectsInPopulation);
		current_instruction_ = 0;
		generation_number_ = 0;
		scaled_fitness_choice_vector_ = std::vector<float>();
	}

	Population::Population(std::vector<Subject> new_subjects) {
		subjects_ = new_subjects;
		current_instruction_ = 0;
		generation_number_ = 0;
		scaled_fitness_choice_vector_ = std::vector<float>();
	}

	void Population::NextGeneration() {
		Subject fittest_subject = Subject(subjects_[FittestSubjectIndex()]);
		std::vector<Subject> old_subjects = subjects_;
		subjects_ = std::vector<Subject>();
		subjects_.push_back(fittest_subject);
		for (int i = 1; i < kNumberOfSubjectsInPopulation; ++i) {
			std::vector<Subject> parents;
			for (int j = 0; j < kNumberOfParents; j++) {
				parents.push_back(FindFitParent());
			}
			subjects_.push_back(Subject(parents));
		}
		current_instruction_ = 0;
		++generation_number_;
		std::this_thread::sleep_for(std::chrono::milliseconds(77));
		std::cout << "Next Generation: " << generation_number_ << std::endl;
		EvalInstructions();
	}

	void Population::EvalInstructions() {
		for (Subject& subject : subjects_) {
			subject.EvalInstructions();
		}
		EvalFitnesses();
	}

	std::vector<float> &Population::EvalFitnesses() {
		float fitness_sum = 0;
		for (Subject& subject : subjects_) {
			fitness_sum += subject.EvalFitness();
			std::cout << fitness_sum << ", ";
			scaled_fitness_choice_vector_.push_back(fitness_sum);
		}
		std::cout << "\n\n";
		for (float f : scaled_fitness_choice_vector_) {
			//std::cout << f << ", ";
		}
		std::cout << "\n\n\n";
		return scaled_fitness_choice_vector_;
	}

	Subject &Population::FindFitParent() {
		float fitness_sum = scaled_fitness_choice_vector_.back();
		//random float from 0.0 to fitness_sum
		float choice = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / fitness_sum));
		for (int i = 0; i < scaled_fitness_choice_vector_.size(); ++i) {
			// loop through the ranges
			if (choice <= scaled_fitness_choice_vector_[i]) {
				return subjects_[i];
			}
		}
		return subjects_.back();  // this should never be reached
	}

	std::vector<Point> Population::GetPointsAtNextFrame() {
		if (current_instruction_ >= kNumberOfInstructions) {
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

	int Population::GetPopulationNumber() {
		return generation_number_;
	}
}

