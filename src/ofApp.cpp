#include "ofApp.h"

using namespace geneticAlgorithm;

void geneticAlgorithmRunner::setup() {
	ofSetWindowTitle("Genetic Algorithm Simulator");
	srand(static_cast<unsigned>(time(0))); // Seed random with current time
	population_ = Population();
	instruction_index_ = -1;
	subject_locations_to_draw_ = population_.EvalGeneration();
	//for (auto v : subject_locations_to_draw_) {
	//	std::cout << v.size();
	//}
}

void geneticAlgorithmRunner::update() {
	if (instruction_index_ >= kNumberOfInstructions) {
		population_.NextGeneration();
		return;
	}
	++instruction_index_;
	std::this_thread::sleep_for(std::chrono::milliseconds(7));
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
	for (Point& subject_location : subject_locations_to_draw_[instruction_index_]) {
		std::cout << subject_location.x << '\n';
		//ofDrawCircle(subject_location.x, subject_location.y, kSubjectRadius);
	}
}

void geneticAlgorithmRunner::keyPressed(int key) {
	return;
}

void geneticAlgorithmRunner::reset() {

}