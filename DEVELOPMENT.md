**Week 3**

| Date    | Notes                                                        |
| ------- | ------------------------------------------------------------ |
| 5/2/19  | Added animation-skipping shortcut that only shows animations of generations that show improvement. Added more JSON scenarios. |
| 5/1/19  | Added obstacle collisions that kill subjects. Re-evaluated fitness score calculations to discourage suicide amongst subjects. Added more JSON levels that also load in obstacles. Player can choose which JSON to load by typing in the file name of the JSON file. |
| 4/29/19 | Pulled out all constants into extern variables. Implemented ofxJSON library to load these variables from a JSON. Loading from a JSON updates these variables everywhere in the project. |
| 4/28/19 | Refactored code to work with pre-processing. Now a Generation can be viewed quickly with a variable delay between frames. However, there is a memory access violation at the end of a generation, where I got stuck debugging. |

**Week 2**

| Date    | Notes                                                        |
| ------- | ------------------------------------------------------------ |
| 4/24/19 | Implemented the full Population and Subject class, with tests. The population organizes a group of random Subjects, who have their sets of instructions. These instructions can be evaluated to change the Subjects' positions each loop, but there is a bug where the position change gets dropped. After some time, fixed the bug by using references to the Subjects. I also got a Read Access Violation error in Box2D. After looking deeper into Box2D, I came to the conclusion to drop Box2D from the project. It is too complicated for the physics task planned and I will not have enough time to finish the project if I continue with this library. Possible alternatives: JSON loading of simulations, JSON loading of settings, sound effects/music, and better graphics. Currently, I have a single-generation simulation running without physics. |
| 4/23/19 | Researched more specific examples of Box2D. Planned out how to use collision filtering to allow many subjects and increase efficiency.  Refactored some functions to work with a future Box2D implementation. Added some tests. |
| 4/21/19 | Finally fixed the ofxBox2D issue!!! Everything was imported successfully before - I just needed to add the correct header file of ofxBox2d.h inside of ofApp.h. Also, I implemented operator overloads for the Instruction struct. Added many test cases for the Point and Instruction structs, as well as helper functions. Catch2 would not run, but after some debugging, I figured out that you have to remove main.cpp, ofApp.cpp, and ofApp.h from the project before running the tests. |

**Week 1**

| Date    | Notes                                                        |
| ------- | ------------------------------------------------------------ |
| 4/17/19 | More futile attempts to import ofxBox2D. The projectGenerator says ofxBox2D was imported successfully, but the compiler does not recognize any functions. It looks like a specific header file might be missing. |
| 4/16/19 | Created a high-level pseudocode outline of functions on OneNote (a screenshot was added to the git repo). Added all needed functions, structs, and classes to the header files in the project. Reorganized the filesystem. |
| 4/14/19 | After reimporting the project 4 times, and rearranging the filesystem, I fixed the linking error between ofxBox2D and the local project. It turns out importing the project through projectGenerator moves files out of the src directory. These files needed to be moved back manually. |
| 4/13/19 | I'm having problems linking ofxBox2D to the local project: the project doesn't recognize imported openframeworks, src or addon folders. I tried using the projectGenerator, moving the files manually, and copy-pasting files from a working project. |
| 4/9/19  | Ran a ball-gravity physics example simulation in C++.        |
