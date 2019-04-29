#pragma once

#include "ofMain.h"
#include "subject.h"

#include <vector>

namespace geneticAlgorithm {

	class Population {
	private:
		std::vector<Subject> subjects_;
		int current_instruction_;

	public:
		Population();  // create a random population
		Population(std::vector<Subject> new_subjects);  // create a population from a vector of subjects
		void NextGeneration();  // keep this fittestSubject in the first index of the next subjects_ vector, make new subjects by combining highly ranked subjects from this generation
		std::vector<std::vector<Point>> EvalGeneration();  // evaluate all instructions on all Subjects. return a list of the points of all subjects; indexs=(row=instruction, column=subject)
		int FittestSubjectIndex();
		std::vector<Point> GetNextPoints();  // returns a vector of all the positions of the subjects at the current intstruction index
		std::vector<Subject> &GetSubjects();
	};

}
