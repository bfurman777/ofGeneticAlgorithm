#pragma once

#include "ofMain.h"
#include "subject.h"

#include <vector>

namespace geneticAlgorithm {

	class Population {
	private:
		std::vector<Subject> subjects_;

	public:
		Population();  // create a random population
		Population(std::vector<Subject> new_subjects);  // create a population from a vector of subjects
		void NextGeneration();  // keep this fittestSubject in the first index of the next subjects_ vector, make new subjects by combining highly ranked subjects from this generation
		int FittestSubjectIndex();
		std::vector<Subject> &GetSubjects();
	};

}
