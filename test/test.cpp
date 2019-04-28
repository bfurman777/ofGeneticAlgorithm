#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/subject.h"
#include "../src/population.h"

#include <iostream>

using namespace geneticAlgorithm;

TEST_CASE("Test Point Struct") {
	SECTION("Default Constructor") {
		Point point;
		REQUIRE(point.x == kStartingX);
		REQUIRE(point.y == kStartingY);
	}
	SECTION("Parameters in Constructor") {
		Point point(7, 3);
		REQUIRE(point.x == 7);
		REQUIRE(point.y == 3);
	}
}

TEST_CASE("Test Instruction Struct") {
	SECTION("Default Constructor") {
		Instruction instruction;
		REQUIRE(instruction.force >= kMinForce);
		REQUIRE(instruction.force <= kMaxForce);
		REQUIRE(instruction.angle >= kMinAngle);
		REQUIRE(instruction.angle <= kMaxAngle);
	}
	SECTION("Parameters in Constructor") {
		Instruction instruction(77, 42);
		REQUIRE(instruction.force == 77);
		REQUIRE(instruction.angle == 42);
	}
	SECTION("== Operator Overload True") {
		Instruction instruction1(77, 42);
		Instruction instruction2(77, 42);
		REQUIRE((instruction1 == instruction2));
	}
	SECTION("== Operator Overload False") {
		Instruction instruction1(77, 42);
		Instruction instruction2(69, 42);
		REQUIRE(!(instruction1 == instruction2));
	}
	SECTION("!= Operator Overload True") {
		Instruction instruction1(88, 42);
		Instruction instruction2(69, 37);
		REQUIRE((instruction1 != instruction2));
	}
	SECTION("!= Operator Overload False") {
		Instruction instruction1(27, 76);
		Instruction instruction2(27, 76);
		REQUIRE(!(instruction1 != instruction2));
	}
	SECTION("Default Constructor is Random") {
		// compare 3 random instructions, at least 2 should be different
		Instruction instructs[3];
		for (Instruction i : instructs) {
			std::cout << i.force << std::endl;
		}
		REQUIRE((
			instructs[0] != instructs[1]
			|| instructs[1] != instructs[2]
			|| instructs[2] != instructs[0]
		));
	}
}

TEST_CASE("Test Subject Class") {
	SECTION("Distance to Goal") {
		Subject subject;
		Point point(kGoalX - 3, kGoalY - 4);
		subject.SetPosition(point);
		REQUIRE(subject.DistanceToGoal() == 5);
	}
	SECTION("Closer Subject to Goal has Higher Fitness Score") {
		Subject weak_subject;
		Point far_point(kGoalX - 50, kGoalY - 50);
		weak_subject.SetPosition(far_point);
		Subject strong_subject;
		Point close_point(kGoalX - 15, kGoalY - 15);
		strong_subject.SetPosition(close_point);
		REQUIRE(weak_subject.EvalFitness() < strong_subject.EvalFitness());
	}
	SECTION("EvalFunction updates Position") {
		/*
		Subject subject;
		Instruction instruction(1, 0);  // force 1 at 0 degrees (right 1 unit)
		std::vector<Instruction> instructions{ instruction };
		subject.SetInstructions(instructions);
		subject.EvalInstruction(0);
		REQUIRE(subject.GetPosition().x == kStartingX + 1);
		REQUIRE(subject.GetPosition().y == kStartingY);
		//*/
	}
}

TEST_CASE("Test Population Class") {
	SECTION("Fittest Subject") {
		std::vector<Subject> subjects(2);
		Point far_point(kGoalX - 50, kGoalY - 50);
		subjects[0].SetPosition(far_point);
		Point close_point(kGoalX - 15, kGoalY - 15);
		subjects[1].SetPosition(close_point);
		Population population(subjects);
		REQUIRE(population.FittestSubjectIndex() == 1);
	}
}


//TODO
//Add test that best subject improves or stays the same