/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>

#include "hw4_lib.h"
#include "hw4_io.h"


/*

** Testing degree-3 polynomial and degree-4 polynomial..
** Bu fonksiyonu kullanarak polinomlari cagirabilir ve yazdirabilirsiniz.

*/

/*
void test_polynomial(){

	double a0,a1,a2,a3,a4;


	read_polynomial3(&a0,&a1,&a2,&a3);
	write_polynomial3(a0,a1,a2,a3);

	printf("\n");

	read_polynomial4(&a0,&a1,&a2,&a3,&a4);
	write_polynomial4(a0,a1,a2,a3,a4);

	printf("\n");


}
*/

/*

**Testing integral calculations..
**Bu fonksiyonu tek katli integral test etmek icin mainde cagirip kullanabilirsiniz.

*/

/*
void test_first_integral(){

	double integral1;
	double f(double x) { return x*x; } 

	integral1 = integral(f,1,4,1000); 
	printf("Tek katli integralin sonucu : %f\n",integral1);


}



/*

**Testing integral calculations..
**Bu fonksiyonu cift katli integrali test etmek icin mainde cagirip kullanabilirsiniz.

*/

/*
void test_double_integral(){
	double double_integral;
	double f(double x,double y) {return x*y;}

	double_integral = integral2(f,1,4,2,5,1000);
	printf("Cift katli integralin sonucu : %f\n",double_integral);

}



/*
** Testing derivative calculations..
**
*/

void test_compare_derivatives() {
	double f(double x) { return x*x; }	/*Bu fonksiyonların icindekiler modifiye ederek kendi fonksiyonlarinizda test edebilirsiniz.*/
	double d1(double x) { return 2.0*x; }
	double d2(double x) { return 2.0; }
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);/*Derivatives fonksiyonunun içinde türevleri yazdırdığım ve 
																	bu derivatives fonksiyonunu compare_derivatives de cagirdigim icin turevleri ekrana yazdiriyorum.*/

	printf("%f %f\n",e1,e2);
}
/*


/*
** main function for testing the functions...
**
*/

int main(void) {

	test_compare_derivatives();

	return (0);
} /* end main */
