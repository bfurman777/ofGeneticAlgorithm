#include "ofApp.h"
#include "population.h"
#include "subject.h"

#include <iostream>

using namespace geneticAlgorithm;

// Setup method
void geneticAlgorithmRunner::setup() {
	ofSetWindowTitle("Genetic Algorithm Simulator");

	srand(static_cast<unsigned>(time(0))); // Seed random with current time

	initResources();
}

/* TODO Docs */
void geneticAlgorithmRunner::update() {
	Instruction instruc;
	std::cout << " Angle: " << instruc.angle << " Force " << instruc.force << std::endl;
	return;
}

/* TODO Docs */
void geneticAlgorithmRunner::draw() {
	return;
}

/* TODO Docs */
void geneticAlgorithmRunner::keyPressed(int key) {
	return;
}

/* TODO Docs */
void geneticAlgorithmRunner::reset() {
	InitResources();
}

/* TODO Docs */
void geneticAlgorithmRunner::InitResources() {
	return;
}

/* TODO Docs */
void geneticAlgorithmRunner::InitBox2D() {
	return;
}