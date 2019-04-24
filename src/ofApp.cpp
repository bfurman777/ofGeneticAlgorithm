#include "ofApp.h"
#include "population.h"
#include "subject.h"

#include <iostream>

using namespace geneticAlgorithm;

// Setup method
void geneticAlgorithmRunner::setup() {
	ofSetWindowTitle("Genetic Algorithm Simulator");

	srand(static_cast<unsigned>(time(0))); // Seed random with current time

	InitResources();
}

/* TODO Docs */
void geneticAlgorithmRunner::update() {
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
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);

	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createBounds();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
}