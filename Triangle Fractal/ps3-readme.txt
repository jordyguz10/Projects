/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Jordy Guzman Alcaraz

Hours to complete assignment: 6 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assigned task was to create a Triangle Fractal using the SFML library,
and to do it with a Recursive function. I feel that I successfully
accomplished the task by creating two recursive functions and by displaying
the triangle fractal on the screen. The program takes two command-line 
arguements, one is the side of the first triangle base, the second is
the depth of the recursion.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
One of the data structures I used for this program were vectors. I
created a vector that holds every triangle that is needed based
on the recursion level that is inputed in the command-line. The function
fTree() then recursively sets the color, size, what point to draw from,
for each triangle in the vector. Triangle[0] is the base triangle.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

sf::Transform t;
float middlePoint = static_cast<float> (Screen) / 2.f;
t.rotate(2.5, {middlePoint, middlePoint});

I decided to make my Triangle Fractal rotate about the middle point, which
happens to be the middle of the screen. I did this by declaring a sf::Transform
that is used when window.draw() is called. This sf::Transform tells the 
shape that is being drawn that is should rotate about the middle point.

------------------------------------------------------------------------------------

for (int i = 0; i < TotalTri; i++) {
    window.draw(*drawTri[i], t);
}

Since I used a vector for all of my triangles, I decided to use the draw() 
function that I made for the Triangle class to draw each triangle. "t"
it the sf::Transform that tells the shape that is being drawn from
drawTri[i] to rotate.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned that using recursive functions can be used to draw items in SFML
and that using a recursive function saves time by not having to draw many 
loops.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Class Discord, StackOverflow, SFML Website

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
Figuring out how to draw a new triangle from the First Base triangle 
took me a while. I used sf::Vector2f to get each point of the triangle.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 I added Color to the tree and added some rotating animation. For color
 I made the triangles red, green, and blue depending on the point they
 are drawn from. The first base triangle is the only triangle that isn't
 colored. For rotation, I made the entire triangle fractal rotate about
 the center point of the screen