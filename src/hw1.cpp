/**********************************************************************
 * 
 * This program accepts user input for the radius of a circle. It then
 * returns to the user the radius and perimeter of a circle with the
 * user's defined radius.
 *
 * @author Nicholas English
 * @version 1.0
 * @date 1/17/2018
 *
 *********************************************************************/

/* Include statements */
#include <iostream>
#include <string>

/* Define statements */
#define PI 3.14 

int main(void) {

    /* Variables */
    /** User defined radius of a cirlce  */
    float radius;

    /** Holds the area of a circle with the user's defined radius */
    float area;

    /** Holds the perimeter of a circle with the user's defined
        radius */
    float perimeter;

    /* Intro to code */
    std::cout << "\n This program is used take in user input and";
    std::cout << " outputs the area and perimeter of the circle.";

    /* Asks for the radius of a circle */
    std::cout << "\n\n Please enter the radius of the circle:  ";
    std::cin >> radius;

    /* Calculations */
    area = PI * radius * radius;
    perimeter = 2 * PI * radius; 

    /* Print out results */
    std::cout << "\n The perimeter is " << perimeter;
    std::cout << "\n The area is " << area;

    /* End of file reached */
    std::cout << "\n\n\n";
    return 0;
}
