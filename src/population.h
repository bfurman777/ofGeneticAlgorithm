#pragma once

#include "ofMain.h"
#include "subject.h"

namespace geneticAlgorithm {

	class Population {
	private:
		Subject subjects_[kNumberOfSubjectsInPopulation];
		Subject *fittestSubject_;
		Subject *fittestFromOldGeneration_;

	public:
		void EvaluateFitness();  // evaluate all subjects and keep track of the fittest
		void NextGeneration();  // keep the fittestSubject, make new subjects by combining highly ranked subjects from this generation
		Subject *GetFittestSubject();
	};

}
