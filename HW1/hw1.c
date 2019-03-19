#include<stdio.h>
#include<math.h>
#define PI 3.14




/*We are calculating circle area and returning its value.We will use this function in all functions that we calculate the area of the circle.*/

double circle_area(double radius){

	double area;

	area = PI * pow(radius,2);

	return area;
}

/* In this function,We are calculating hypotenuse and returning its value.We will use this hypotenuse for calculating radius of smallest circle.*/

double calc_hypotenuse(int side1,int side2){

	double hypotenuse;

	hypotenuse = sqrt(pow(side1,2) + pow(side2,2));

	return hypotenuse;

}

/* As we said we are using hypotenuse value for calculating radius of smallest circle and returning its value.*/

double calc_radius_of_smallest_circle(int side1,int side2){

	double radius;
	double hypotenuse;

	hypotenuse = calc_hypotenuse(side1,side2);

	radius = hypotenuse / 2 ;

	return radius;

}

/* We are calculating radius of largest circle and returning its value  and we will use function for finding area of largest circle.*/

double calc_radius_of_largest_circle(int side1,int side2){

	double radius;

	if(side1<side2){

		radius = side1;

		radius = radius / 2;
	}

	else{

		radius = side2;

		radius = radius / 2;
	}

	return radius;

}

/* In this function, we are using circle_area and calc_radius_of_smallest_circle functions for finding area of smallest circle and returning its value. */

double calc_area_of_smallest_circle(int side1,int side2){

	double radius;
	double area_of_smallest_circle;

	radius = calc_radius_of_smallest_circle(side1,side2);

	area_of_smallest_circle = circle_area(radius);

	return area_of_smallest_circle;

}

/* In this function, we are using circle_area and calc_radius_of_largest_circle functions for finding area of largest circle and returning its value. */


double calc_area_of_largest_circle(int side1,int side2){

	double radius;
	double area_of_largest_circle;

	radius = calc_radius_of_largest_circle(side1,side2);

	area_of_largest_circle = circle_area(radius);

	return area_of_largest_circle;

}

/* In this function, We are calculating square area and returning its value.We will use this function in all functions that we calculate the area of the square.*/

double calc_area_of_square(int side){

	double square_area;

	square_area = pow(side,2);

	return square_area;

}

/* In this function , we will use calc_area_of_square function to find area of largest square and returning its value.*/

double calc_area_of_largest_square(int side1,int side2){

	double area_of_largest_square;
	double side;

	if(side1<side2){

		side = side1;

		
	}

	else{

		side = side2 ;

		
	}

	area_of_largest_square = calc_area_of_square(side);

	return area_of_largest_square;

}

/* In this function , we will use calc_area_of_square function to find area of smallest square and returning its value.*/

double calc_area_of_smallest_square(int side1,int side2){
	double area_of_smallest_square;
	double side;

	if(side1>side2){
		side = side1;
	}
	else {
		side = side2;
	}

	area_of_smallest_square = calc_area_of_square(side);

	return area_of_smallest_square;
}



/* In this function , we will print all result that we found.*/

void display_results(
	double largest_circle,
	double largest_square,
	double smallest_circle,
	double smallest_square){


	int side1,side2;
	

	printf("Enter first side for rectangle:\n");
	scanf("%d",&side1);
	printf("Enter second side for rectangle:.\n");
	scanf("%d",&side2);

	smallest_square = calc_area_of_smallest_square(side1,side2);
	smallest_circle = calc_area_of_smallest_circle(side1,side2);
	largest_square = calc_area_of_largest_square(side1,side2);
	largest_circle = calc_area_of_largest_circle(side1,side2);
	
	
	printf("The area of the largest circle that fits inside a rectangle : %.2lf\n",largest_circle);
	printf("The area of the largest square that fits inside a rectangle : %.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle : %.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle : %.2lf\n",smallest_square);
	

}

/* In main function, we are calling display_results function and it displays us all areas.*/
int main(){
	double largest_circle,largest_square,smallest_circle,smallest_square;

	display_results(largest_circle,largest_square,smallest_circle,smallest_square);

	return 0;
}
