#include "population.h"

namespace geneticAlgorithm {
	Population::Population() {
		subjects_ = std::vector<Subject>(kNumberOfSubjectsInPopulation);
		current_instruction_ = 0;
		generation_number_ = 0;
	}

	Population::Population(std::vector<Subject> new_subjects) {
		subjects_ = new_subjects;
		current_instruction_ = 0;
	}

	void Population::NextGeneration() {

		std::vector<Subject> pop = GetSubjects();
		for (int i = 0; i < pop.size(); ++i) {
			Subject s = pop[i];
			std::cout << "#" << i << " @ " << s.GetPosition().x << ", " << s.GetPosition().y << "    Dist To Goal: " << s.DistanceToGoal() << "    Fitness: " << s.EvalFitness() << '\n';
		}
		std::cout << "Fittest: " << FittestSubjectIndex() << '\n';

		std::this_thread::sleep_for(std::chrono::milliseconds(3777));



		current_instruction_ = 0;
		Subject fittest_subject = Subject(subjects_[FittestSubjectIndex()]);
		std::vector<Subject> old_subjects = subjects_;
		std::cout << "Old Fittest (before clearing): " << fittest_subject.GetPosition().x << ", " << fittest_subject.GetPosition().y << '\n';
		subjects_ = std::vector<Subject>();
		std::cout << "Old Fittest: " << fittest_subject.GetPosition().x << ", " << fittest_subject.GetPosition().y << '\n';
		subjects_.push_back(fittest_subject);
		std::cout << "Inserted Old Fittest: " << subjects_[0].GetPosition().x << ", " << subjects_[0].GetPosition().y << '\n';
		for (int i = 1; i < kNumberOfSubjectsInPopulation; ++i) {
			std::vector<Subject> parents;
			parents.push_back(fittest_subject);
			subjects_.push_back(Subject(parents));
		}
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

