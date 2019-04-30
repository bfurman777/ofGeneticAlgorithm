#include "ofApp.h"

using namespace geneticAlgorithm;

void geneticAlgorithmRunner::setup() {
	ofSetWindowTitle("Genetic Algorithm Simulator");
	srand(static_cast<unsigned>(time(0))); // Seed random with current time
	population_ = Population();
	population_.EvalInstructions();
}

void geneticAlgorithmRunner::update() {
	points_to_draw = population_.GetPointsAtNextFrame();
}

void geneticAlgorithmRunner::draw() {
	// orange square representing the start 
	ofSetColor(255, 173, 58);
	ofDrawRectangle(kStartingX - kSubjectRadius, kStartingY - kSubjectRadius, kSubjectRadius * 2, kSubjectRadius * 2);

	// green square representing the goal 
	ofSetColor(0, 206, 79);
	ofDrawRectangle(kGoalX - kSubjectRadius, kGoalY - kSubjectRadius, kSubjectRadius * 2, kSubjectRadius * 2);

	// blue circle representing each subject
	ofSetColor(45, 126, 255);
	for (Point point : points_to_draw) {
		ofDrawCircle(point.x, point.y, kSubjectRadius);
	}
	// dark blue circle representing fittest subject from last generation
	ofSetColor(0, 0, 255);
	ofDrawCircle(points_to_draw[0].x, points_to_draw[0].y, kSubjectRadius);

	// red circle representing fittest subject from this generation
	ofSetColor(255, 0, 0);
	int i = population_.FittestSubjectIndex();
	ofDrawCircle(points_to_draw[i].x, points_to_draw[i].y, kSubjectRadius);
}

void geneticAlgorithmRunner::keyPressed(int key) {
	population_.NextGeneration();
}
