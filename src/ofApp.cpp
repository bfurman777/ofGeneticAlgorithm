#include "ofApp.h"

using namespace geneticAlgorithm;

void geneticAlgorithmRunner::setup() {
	ofSetWindowTitle("Genetic Algorithm Simulator");
	srand(static_cast<unsigned>(time(0))); // Seed random with current time
	InitResources();
	population = Population();
}

void geneticAlgorithmRunner::update() {
	population.EvalNextInstruction();
}

void geneticAlgorithmRunner::draw() {
	// blue circle representing each subject
	ofSetColor(45, 126, 255);
	for (Subject& subject : population.GetSubjects()) {
		ofDrawCircle(subject.GetPosition().x, subject.GetPosition().y, kSubjectRadius);
	}
	// green square representing the goal 
	ofSetColor(0, 206, 79);
	ofDrawRectangle(kGoalX - kSubjectRadius, kGoalY - kSubjectRadius, kSubjectRadius*2, kSubjectRadius*2);
}

void geneticAlgorithmRunner::keyPressed(int key) {
	return;
}

void geneticAlgorithmRunner::reset() {
	InitResources();
}

void geneticAlgorithmRunner::InitResources() {
	return;
}