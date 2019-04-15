#include "ofApp.h"
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
	initResources();
}

/* TODO Docs */
void geneticAlgorithmRunner::initResources() {
	return;
}
