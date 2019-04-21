**Week 1**

| Date    | Notes                                                        |
| ------- | ------------------------------------------------------------ |
| 4/17/19 | More futile attempts to import ofxBox2D. The projectGenerator says ofxBox2D was imported successfully, but the compiler does not recognize any functions. |
| 4/16/19 | Created a high-level pseudocode outline of functions on OneNote (a screenshot was added to the git repo). Added all needed functions, structs, and classes to the header files in the project. Reorganized the filesystem. |
| 4/14/19 | After reimporting the project 4 times, and rearranging the filesystem, I fixed the linking error between ofxBox2D and the local project. It turns out importing the project through projectGenerator moves files out of the src directory. These files needed to be moved back manually. |
| 4/13/19 | I'm having problems linking ofxBox2D to the local project: the project doesn't recognize imported openframeworks, src or addon folders. I tried using the projectGenerator, moving the files manually, and copy-pasting files from a working project. |
| 4/9/19  | Ran a ball-gravity physics example simulation in C++         |



**FEATURES TO ADD:**

- Genetic Algorithm with physics
- Get from starting point to end point
- Random force and direction
- Best genetics pass on through weighted parent algorithm (single parent?)
- Display each generation 
- Obstacles  
- Speed up viewing  (sliders?)
- Toggle visuals for processing speed 
- Resize window
