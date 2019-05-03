## Genetic Algorithm Simulator  

A Genetic Algorithm is an algorithm that improves its model on a task after running many "generations" of simulations.  
My project is a simulation is one where a computer-controlled "subject" is a dot on a 2D playing field. The subject's goal is to reach a goal area.

## What happens in each Generation?

Each generation starts with a starting point and a goal point. A pool of many different subjects are spawned on the starting point. Each subject has its "genes", which is a set of instructions. Each instruction is a number and a direction representing the applied force. For example, an instruction could be 20 Newtons in the 45 degrees direction. Initially, all subjects have random instructions.

A generation will consist of N frames. Each frame, every subject will apply its instruction upon itself. The subjects do not interact with each other. After N frames, each subject will get a fitness score according to how well it performed, based on distance to the goal and number of frames taken to reach the goal. For example, a subject who finished 10 units away from the goal has a higher score than someone who finished 27 units away.  

At the end of each generation, the best subjects have children. These children copy their parent's instructions, but have a small percent chance of randomly changing the instruction. These children are sent into the next generation of the simulation with the best subject of the old generation. After many generations, the subjects will become very good at the task.  

## What do I see?

Each generation has a bunch of blue circular dots representing subjects.   

There is a dark blue dot, representing the previous generation's fittest subject.   

There is a red dot, representing the current generation's best subject. This is the same as the dark blue dot if there is no improvement this generation.

There is a orange square representing the start and a green square representing the goal.

## Controls

SPACE	-	Skips to the next generation

i		-	Toggle show_only_improvement mode

## External Library

This project uses ofxJSON to read JSON files. JSON files contain data of all of the constants and obstacles, which can be used to run different simulations.