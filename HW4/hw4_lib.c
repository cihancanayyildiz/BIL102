/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>
#include <math.h>

/*
**Bu fonksiyon ile tek katli integralimizi hesapliyoruz ve degerini donduruyoruz.
*/

double integral(double f(double x),double xs, double xe, double delta){
	
	int i;
	double bound;
	double dx = (xe - xs) / delta; /* Buradaki dx verilen egrinin altinda olusan dikdortgenlerin araligini belirtmektedir.*/
								   /* Ornegin ; fonksiyon 2 ile 5 x degerleri arasinda olursa ve deltamiz 3 olursa.(Burada delta alan altinda kac tane dikdortgen oldugudur.)
								   /* Bu durumda dx = (5-2) / 3 = 1 'den olusan dikdortgenlerin x eksenindeki araliklari 1 cikar.*/
	double function_value;
	double sum_of_integral=0;

	for(i=0;i<delta;i++){ /*Delta arttikca dikdortgen sayisi articaktir ve sonuca daha cok yakinlasacagiz.*/
		
		bound = xs + i*dx; /* Bound degeri ise fonksiyona gondericegimiz x degeridir.*/
						   /* Yani eger xs 2 ise 2+0*dx ile ilk x degerimiz 2'dir.Sonrasinda i=1 oldugunda xs degerimiz 2+1*dx(1) = 3 cikar.
						   /* Buradan anlicagimiz uzere her dongu dondugunde fonksiyona araliktaki farkli x degerini yollayacagiz.*/

		function_value = f(bound); /*Buldugumuz bound degerini fonksiyona yolluyoruz.*/
		sum_of_integral += function_value * dx ; /*Buldugumuz fonksiyon degeriyle dx i yani dikdortgenin araligini carptigimizda  o dikdortgenin alanina ulasiyoruz.*/
		
	}
	
	return sum_of_integral;	 /*Integral degerimizi donduruyoruz*/
}

/*
**Bu fonksiyon ile cift katli integralimizi hesapliyoruz ve degerini donduruyoruz.
*/

double integral2(double f(double x,double y),double xs, double xe, double ys ,double ye , double delta){
	

	int i,j;
	double dx = (xe-xs)/delta; /*Tek katli integraldekinden biraz farkli olarak dx icin yani x araligi icin bi dx tanimliyoruz.*/
	double dy = (ye-ys)/delta; /*Y araligi icin ise bir dy tanimliyoruz.*/
	double area = dx * dy ; /*Ve burada artik alan degil hacim hesabina girecegimiz icin bu dx*dy carpimlarini cift integral hesabi icin tutmaliyiz.*/
	double sum=0,value2,value1;

	for(i = 0; i < delta; i++) {
		value2 = ys + i*dy; /*Her dongude y araligini i ye gore tanimliyoruz.*/
	    for(j = 0; j < delta; j++) {	/*Icerideki dongude  x e gore integrali alarak ic integrali buluyoruz ve bunu bi toplamda tutuyoruz.*/
	    	value1 = xs + j*dx; /*Tek katli integralde anlattigimiz gibi fonksiyona gondericegimiz x degerini buluyoruz. */
	    	sum += f(value1,value2); /*Fonksiyona x ve y degerlerinin araliklarini yolluyoruz.*/
	    }
	}
	sum = sum * area; /* Sonuc olarakta basta tuttugumuz area degiskeniyle elde ettigimiz sum i carptigimizda cift katli integralimizin sonucuna ulasiyoruz.*/
	 
	return sum; /*Sum degerini yani cift katli integralimizin sonucunu donduruyoruz.*/

}

/*
**Bu fonksiyon ile turev hesapliyoruz.
*/

int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
	
	if(eps==0){ /*Odevde istendigi gibi epsilon degeri 0 oldugunda -1 degeri donduruyoruz.*/
		return -1;
	}
	
	else{ 
	
		*d1 = (f(x+eps) - f(x-eps)) / (2 * eps); //Odevde verilen turev fonksiyonlarini uyguluyoruz..
		
		*d2 = (f(x+eps)- (2*f(x)) + f(x-eps)) / (eps * eps); //Odevde verilen turev fonksiyonlarini uyguluyoruz..
	
	}

	printf("Formulle olusan turev sonucları :  %f  %f \n",*d1,*d2);
	
	
	
}

/*
**Bu fonksiyon ile turev hesaplarini karsilastiriyoruz.
*/

int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
	
	double der1,der2; /* Verilen turev formuluyle elde ettigimiz degerler.*/
	double actual_der1,actual_der2; /*Kendi elimizle turevini aldigimiz fonksiyonlarla elde ettigimiz degerler.*/
	
	
	if(eps==0){ /*Odevde istendigi gibi epsilon degeri 0 oldugunda -1 degeri donduruyoruz.*/

		printf("Epsilon can't be 0. \n");
		return -1;

	}
	
	else{
	
	
	derivatives(f,x,eps,&der1,&der2); /*Turev formuluyle degerlerimizi elde ediyoruz.*/

	actual_der1 = d1(x); //Kendi degerlerimizi elde ediyoruz..
	actual_der2 = d2(x); 
	
	*e1 = fabs(der1 - actual_der1); //1.turevler arasi farki buluyoruz.
	
	*e2 = fabs(der2 - actual_der2); //2.turevler arasi farki buluyoruz.
	
	}
	
	
}
