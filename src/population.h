#pragma once

#include "ofMain.h"
#include "subject.h"

namespace geneticAlgorithm {

	class Population {
	private:
		Subject subjects[kNumberOfSubjectsInPopulation];
		Subject *fittestSubject;
		Subject *fittestFromOldGeneration;

	public:
		void EvaluateFitness();  // evaluate all subjects and keep track of the fittest
		void NextGeneration();  // keep the fittestSubject, make new subjects by combining highly ranked subjects from this generation
		Subject *GetFittestSubject();
	};

}
