#include "ofApp.h"

using namespace geneticAlgorithm;

void geneticAlgorithmRunner::setup() {
	std::cout << "W " << ofGetWindowWidth() << "   H " << ofGetWindowHeight() << '\n';
	ofSetWindowTitle("Genetic Algorithm Simulator");
	srand(static_cast<unsigned>(time(0))); // Seed random with current time
	InitResources();
	population = Population();
}

void geneticAlgorithmRunner::update() {

}

void geneticAlgorithmRunner::draw() {
	for (Subject subject : population.GetSubjects()) {
		ofDrawCircle(subject.GetPosition().x, subject.GetPosition().y, kSubjectRadius);
		//std::cout << subject.GetPosition().x << ' ' << subject.GetPosition().y << '\n';
	}
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