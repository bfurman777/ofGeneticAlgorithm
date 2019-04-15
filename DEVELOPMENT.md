4/15/19:
- The project broke when modifying some functions. After removing code to reach a barebones state, the project still didn't compile. After looking at the files in the file explorer, it turns out the main.cpp file in the src folder wasn't seen by the Visual Studio project solution. Dragging main.cpp into the solution file explorer linked the files correctly, fixing the problem.

4/14/19:
- After reimporting the project 4 times, and rearranging the filesystem, I fixed the linking error between ofxBox2D and the local project. It turns out importing the project through projectGenerator moves files out of the src directory. These files needed to be moved back manually.

4/13/19:
- I'm having problems linking ofxBox2D to the local project: the project doesn't recognize imported openframeworks, src or addon folders. I tried using the projectGenerator, moving the files manually, and copy-pasting files from a working project.

4/9/19:  
- Ran a ball-gravity physics simulation in C++


FEATURES TO ADD:
Genetic Algorithm with physics  
Get from starting point to end point  
Random force and direction  
Best genetics pass on through weighted parent algoritm (single parent?)  
Display each generation  
Speed up viewing  
Toggle visuals for processing speed  
Obstacles  
Resize window
