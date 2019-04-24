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