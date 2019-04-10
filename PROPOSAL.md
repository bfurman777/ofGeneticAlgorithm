## Genetic Algorithm Simulator  
A Genetic Algorithm is an algorithm that improves its model on a task after running many "generations" of simulations.  
My proposed simulation is one where a computer-controlled "subject" is a dot on a 2D playing field. The subject's goal is to reach a goal area.

## What happens in each Generation?
Each generation starts with a starting point and a goal point. A pool of many different subjects are spawned on the starting point. Each subject has its "genes", which is a set of instructions. Each instruction is a number and a direction representing the applied force. For example, an instruction could be 50 Newtons in the Up direction. Initially, all subjects have random instructions.

A generation will consist of N frames. Each frame, every subject will apply its instruction upon itself. The subjects do not interact with eachother. After N frames, each subject will get a fitness score according to how well it performed, based on distance to the goal and number of frames taken to reach the goal. For example, a subject who finished 10 units away from the goal has a higher score than someone who finished 27 units away.  

At the end of each generation, the best subjects have children. These children copy their parent's instructions, but have a small percent chance of randomly changing the instruction. These children are sent into the next generation of simulation. After many generations, the subjects will become very good at the task.



Genetic Algorithm with physics  
Get from starting point to end point  
Random force and direction  
Best genetics pass on through weighted parent algoritm (single parent?)  
Display each generation  
Speed up viewing  
Toggle visuals for processing speed  
Obstacles  