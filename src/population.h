#pragma once

#include "ofMain.h"
#include "subject.h"

#include <vector>

namespace geneticAlgorithm {

	class Population {
	private:
		std::vector<Subject> subjects_;
		int current_instruction_;
		int generation_number_;
		std::vector<float> scaled_fitness_choice_vector_; // each index is the current sum of all previous subject fitness scores - used as a cutoff value for randomly choosing parents

	public:
		Population();  // create a random population
		Population(std::vector<Subject> new_subjects);  // create a population from a vector of subjects
		void NextGeneration();  // keep this fittestSubject in the first index of the next subjects_ vector, make new subjects by combining highly ranked subjects from this generation
		void EvalInstructions();  // evaluate the instructions for this generation
		std::vector<float> &EvalFitnesses();  // evaluate the fitness of all subjects, and build a scaled fitness choice vector
		std::vector<Point> GetPointsAtNextFrame();  // between frames, get the next point to show for each subject
		int FittestSubjectIndex();
		std::vector<Subject> &GetSubjects();
		int GetPopulationNumber();
	};

}
