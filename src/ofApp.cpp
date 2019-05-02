#include "ofApp.h"

using namespace geneticAlgorithm;

void geneticAlgorithmRunner::setup() {
	ofSetWindowTitle("Genetic Algorithm Simulator");
	srand(static_cast<unsigned>(time(0))); // Seed random with current time
	SetConstants(ParseJSON(ofSystemTextBoxDialog("JSON to load?")));
	population_ = Population();
	population_.EvalInstructions();
	show_only_improvement_ = true;
}

void geneticAlgorithmRunner::update() {
	points_to_draw = population_.GetPointsAtNextFrame();
}

void geneticAlgorithmRunner::draw() {
	if (show_only_improvement_) {
		if (!population_.HadImprovement()) {
			ofSetColor(0, 0, 0);
			std::string generation_text = "Searching for improvement...";
			ofDrawBitmapString(generation_text, kGenerationLabelOffset, kGenerationLabelOffset);
			population_.NextGeneration();
			return;
		}
	}

	// orange square representing the start 
	ofSetColor(255, 173, 58);
	ofDrawRectangle(kStartingX - kSubjectRadius, kStartingY - kSubjectRadius, kSubjectRadius * 2, kSubjectRadius * 2);

	// green square representing the goal 
	ofSetColor(0, 206, 79);
	ofDrawRectangle(kGoalX - kSubjectRadius, kGoalY - kSubjectRadius, kSubjectRadius * 2, kSubjectRadius * 2);

	// purple rectangles representing obstacles
	ofSetColor(223, 55, 255);
	for (ofRectangle obstacle : kObstacles) {
		ofDrawRectangle(obstacle);
	}

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

	// black text showing generation number
	ofSetColor(0, 0, 0);
	std::string generation_text = "Generation # " + std::to_string(population_.GetPopulationNumber());
	if (show_only_improvement_) {
		generation_text += "\nOnly showing improvements";
	}
	ofDrawBitmapString(generation_text, kGenerationLabelOffset, kGenerationLabelOffset);
}

void geneticAlgorithmRunner::keyPressed(int key) {
	if (key == ' ') {
		population_.NextGeneration();
	}
	if (key == 'i') {
		show_only_improvement_ = !show_only_improvement_;
	}
	
}

ofxJSONElement geneticAlgorithmRunner::ParseJSON(std::string file) {
	ofxJSONElement result;
	if (result.open(file)) {
		return result;
	} else {
		return ofxJSONElement();
	}
}

void geneticAlgorithmRunner::SetConstants(const ofxJSONElement &json) {
	if (!json["kNumberOfInstructions"].empty()) {
		kNumberOfInstructions = json["kNumberOfInstructions"].asInt();
	}
	if (!json["kNumberOfSubjectsInPopulation"].empty()) {
		kNumberOfSubjectsInPopulation = json["kNumberOfSubjectsInPopulation"].asInt();
	}
	if (!json["kMutationChance"].empty()) {
		kMutationChance = json["kMutationChance"].asInt();
	}
	if (!json["kNumberOfParents"].empty()) {
		kNumberOfParents = json["kNumberOfParents"].asInt();
	}
	if (!json["kStartingX"].empty()) {
		kStartingX = json["kStartingX"].asInt();
	}
	if (!json["kStartingY"].empty()) {
		kStartingY = json["kStartingY"].asInt();
	}
	if (!json["kGoalX"].empty()) {
		kGoalX = json["kGoalX"].asInt();
	}
	if (!json["kGoalY"].empty()) {
		kGoalY = json["kGoalY"].asInt();
	}
	if (!json["kSubjectRadius"].empty()) {
		kSubjectRadius = json["kSubjectRadius"].asInt();
	}
	if (!json["kMinForce"].empty()) {
		kMinForce = json["kMinForce"].asInt();
	}
	if (!json["kMaxForce"].empty()) {
		kMaxForce = json["kMaxForce"].asInt();
	}
	if (!json["kMinAngle"].empty()) {
		kMinAngle = json["kMinAngle"].asInt();
	}
	if (!json["kMaxAngle"].empty()) {
		kMaxAngle = json["kMaxAngle"].asInt();
	}
	if (!json["kDistanceScalar"].empty()) {
		kDistanceScalar = json["kDistanceScalar"].asFloat();
	}
	if (!json["kNumberOfStepsScalar"].empty()) {
		kNumberOfStepsScalar = json["kNumberOfStepsScalar"].asFloat();
	}
	if (!json["kDeathDescalar"].empty()) {
		kDeathDescalar = json["kDeathDescalar"].asFloat();
	}
	if (!json["obstacles"].empty()) {
		auto obstacles = json["obstacles"];
		for (auto obstacle : obstacles) {
			kObstacles.push_back(
				ofRectangle(
					obstacle["x"].asInt(),
					obstacle["y"].asInt(),
					obstacle["width"].asInt(),
					obstacle["height"].asInt()
				)
			);
		}
		
	}
}
