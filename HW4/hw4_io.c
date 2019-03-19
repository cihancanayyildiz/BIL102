/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include <stdio.h>


/*
**Bu fonksiyon ile yazdiracagimiz 3. dereceden polinomun katsayilarini kullanicidan aliyoruz.
*/
int read_polynomial3(double * a0, double * a1, double * a2, double * a3){
	
	printf("Please enter 4 number for a degree-3 polynomial (a0,a1,a2,a3)\n"); /*a0 ilk katsayimiz olarak basliyor.*/
	
	scanf("%lf%lf%lf%lf",a0,a1,a2,a3);
	
}

/*
**Bu fonksiyon ile yazdıracağımız 4. dereceden polinomun katsayilarini kullanicidan aliyoruz.
*/

int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){
	
	printf("Please enter 5 number for a degree-4 polynomial (a0,a1,a2,a3,a4)\n"); /*a0 ilk katsayimiz olarak basliyor.*/
	
	scanf("%lf%lf%lf%lf%lf",a0,a1,a2,a3,a4);
	
	
}


/*
**Bu fonksiyon ile 3. dereceden polinomu yazdiriyoruz.
*/
void write_polynomial3(double a0, double a1, double a2, double a3){
	
	double array[4]={a0,a1,a2,a3}; /*Butun katsayilarimizi bir arrayde tutuyoruz.*/

	int i , power = 3; /*Kuvvetimiz en fazla 3 olcagi icin kuvvetimizi 3 ten baslatiyoruz.*/
	
	for (i = 0; i < 4; i++)
    {
    
        if (power < 0) 
        
        {
            break; /* Eger kuvvet 0 in altina duserse yani polinom biterse donguden cikariyoruz.*/
        }
        

        /*Eger kuvvet 0 olursa yani sabit sayidaysak*/
        else if(power==0){

        	if(array[i]>0){ /*Eger o katsayimiz pozitifse */
        		if(array[i]-(int)array[i]==0){  /*Eger katsayimiz ile katsayimizin int'e castlenmis halinin farki 0 ise yani sayimizin kusurati yoksa.*/
        			
        			printf("+%.0lf",array[i]);	/*Sayinin kusurat kismi olmadan .0lf formati ile yazdiririz.*/
        		
        		}
        		else{
        			printf("+%.1lf",array[i]);  /*Eger fark 0 dan farkli ise sayimizin kusurati var demektir bu durumda kusuratli kismi .1lf formatiyla yazdiririz.*/
				}
        	
        	}

        	else if (array[i]<0){		/*Yukardaki islemlerin aynisini katsayimiz negatifkende yapariz.*/
        		
        		if(array[i]-(int)array[i]==0){
        			
        			printf("%.0lf",array[i]);
        		
        		}
        		else{
        			printf("%.1lf",array[i]);
				}
			}


			else{
				/*Eger sayimiz 0 a esitse ekrana hic bi sey yazdirmayiz yani bu else slotu bos kalmalidir.*/
			}

        	break; /* Sonuc olarakta power=0 durumunda oldugumuz icin bu islemleri yaptiktan sonra donguden cikariz ve polinom tamamlanir.*/
		}

		
		else{ /*Eger power 0 dan buyukse bu else slotuna gireriz yani polinomun bastan sona yazilma kismina baslariz.*/
		
        if (array[i] > 0){ /*Eger katsayimiz 0 dan buyukse*/
        	
        	if(power==3){
        		/*Power=3 durumunda ilk katsayiyi yani 3. dereceden kuvvetin oldugu katsayiyi yazdiriyoruz.Burada katsayimiz pozitif basina '+' isareti gelmemeli o yuzden burada hic bisey yazdirmiyoruz.*/
			}

			else{
			
            	printf("+"); /*Power=3 olmadigi zamanlar ise '+' isaretini yazdiriyoruz.*/
            
        	}
            
        }
    
        if (array[i]==1){ /*Eger katsayimiz 1 'e esitse.*/
        	
        	if(power==1){ 
			
				printf("x"); /*Kuvvet 1 ise sadece x yazdirmaliyiz.*/
				power--; /*Kuvveti 1 azaltiyoruz.*/
				
			}
			else{  
		
				printf("x^%d",power--); /*Eger kuvvet 1 den farkliysa x^power formatinda yazdiriyoruz ve ardindan kuvveti azaltiyoruz.*/
				
			}	
		}
		
		else if(array[i]==-1){ /*Eger katsayimiz -1'e esitse.*/

			if(power==1){
				
				printf("-x"); /*Kuvvet 1 ise ve katsayimiz -1 ise sadece -x yazdirmaliyiz.*/
				power--; /* Kuvveti 1 azaltiyoruz.*/
				
			}
			else{  
			  
				printf("-x^%d",power--); /*Eger kuvvet -1 den farkliysa -x^power formatinda yazdiriyoruz ve ardindan kuvveti azaltiyoruz.*/
				
			}
			
			
		}
		
		else if(array[i] == 0){ 
       		
       		power--; /*Eger katsayimiz 0 ise  hic bisey yazdirmayip sadece kuvveti 1 azaltip diger elemana geciyoruz.*/
       		
		}
		
		else{ /*Eger katsayimiz 0 dan kucukse -1,0 veya 1 degilse bu else slotuna giriyoruz.*/
			
			if(power==1){ /*Kuvvetimiz eger 1 ise */

				if(array[i]-(int)array[i]==0){ /*Eger katsayimiz ile katsayimizin int'e castlenmis halinin farki 0 ise yani sayimizin kusurati yoksa.*/
					printf("%.0lfx", array[i]); /*Sayinin kusurat kismi olmadan .0lf formati ile yazdiririz.*/
					power--;
				}

				else {
					printf("%.1lfx", array[i]); /*Eger fark 0 dan farkli ise sayimizin kusurati var demektir bu durumda kusuratli kismi .1lf formatiyla yazdiririz.*/
					power--;
				}
				
				
				
			} /*Kuvvetimiz 1 den farkli ise.*/
			else{  
			  	if(array[i]-(int)array[i]==0){ /*Buradaki cast islemide yukaridaki islemlerimizle aynidir.*/
					printf("%.0lfx^%d", array[i], power--);
				}

				else{
					printf("%.1lfx^%d", array[i], power--);
				}
				
			}
		
		}
	}
		
}
    
}

/*
**Bu fonksiyon ile 4. dereceden polinomu yazdiriyoruz.
*/
void write_polynomial4(double a0, double a1, double a2, double a3, double a4){
	
	double array[5]={a0,a1,a2,a3,a4}; /*Butun katsayilarimizi bir arrayde tutuyoruz.*/
	int i , power = 4; /*Kuvvetimiz en fazla 4 olcagi icin kuvvetimizi 4 ten baslatiyoruz.*/
	
	for (i = 0; i < 5; i++)
    {
    
		
        if (power < 0)
        
        {
            break; /* Eger kuvvet 0 in altina duserse yani polinom biterse donguden cikariyoruz.*/
        }
        
        else if(power==0){ /*Eger kuvvet 0 olursa yani sabit sayidaysak*/

        	if(array[i]>0){ /*Eger o katsayimiz pozitifse */
        		if(array[i]-(int)array[i]==0){ /*Eger katsayimiz ile katsayimizin int'e castlenmis halinin farki 0 ise yani sayimizin kusurati yoksa.*/
        			
        			printf("+%.0lf",array[i]); /*Sayinin kusurat kismi olmadan .0lf formati ile yazdiririz.*/
        		
        		}
        		else{
        			printf("+%.1lf",array[i]); /*Eger fark 0 dan farkli ise sayimizin kusurati var demektir bu durumda kusuratli kismi .1lf formatiyla yazdiririz.*/
				}
        	
        	}
        	else if (array[i]<0){ /*Yukardaki islemlerin aynisini katsayimiz negatifkende yapariz.*/
        		
        		if(array[i]-(int)array[i]==0){
        			
        			printf("+%.0lf",array[i]);
        		
        		}
        		else{
        			printf("+%.1lf",array[i]);
				}
			}

			else{
				/*Eger sayimiz 0 a esitse ekrana hic bi sey yazdirmayiz yani bu else slotu bos kalmalidir.*/
				
			}
        	break; /* Sonuc olarakta power=0 durumunda oldugumuz icin bu islemleri yaptiktan sonra donguden cikariz ve polinom tamamlanir.*/
		}
		
		else{ /*Eger power 0 dan buyukse bu else slotuna gireriz yani polinomun bastan sona yazilma kismina baslariz.*/
		
        
        if (array[i] > 0){ /*Eger katsayimiz 0 dan buyukse*/
        	
        	if(power==4){
        		/*Power=4 durumunda ilk katsayiyi yani 4. dereceden kuvvetin oldugu katsayiyi yazdiriyoruz.Burada katsayimiz pozitif basina '+' isareti gelmemeli o yuzden burada hic bisey yazdirmiyoruz.*/
			}
			else{
			
            	printf("+"); /*Power=4 olmadigi zamanlar ise '+' isaretini yazdiriyoruz.*/
            
        	}
            
        }
    
        if (array[i]==1){ /*Eger katsayimiz 1 'e esitse.*/
        	
        	if(power==1){
			
				printf("x"); /*Kuvvet 1 ise sadece x yazdirmaliyiz.*/
				power--; /* Kuvveti 1 azaltiyoruz.*/
				
			}
			else{  
		
				printf("x^%d",power--); /*Eger kuvvet 1 den farkliysa x^power formatinda yazdiriyoruz ve ardindan kuvveti azaltiyoruz.*/
				
			}
        	
        	
		}
		
		else if(array[i]==-1){ /*Eger katsayimiz -1 'e esitse.*/

			if(power==1){
				
				printf("-x"); /*Kuvvet -1 ise sadece -x yazdirmaliyiz.*/
				power--; /* Kuvveti 1 azaltiyoruz.*/
				
			}
			else{  
			  
				printf("-x^%d",power--); /*Eger kuvvet -1 den farkliysa -x^power formatinda yazdiriyoruz ve ardindan kuvveti azaltiyoruz.*/
				
			}
			
			
		}
		
		else if(array[i] == 0){
       		
       		power--; /*Eger katsayimiz 0 ise  hic bisey yazdirmayip sadece kuvveti 1 azaltip diger elemana geciyoruz.*/
       		
		}
		
		else{ /*Eger katsayimiz 0 dan kucukse -1,0 veya 1 degilse bu else slotuna giriyoruz.*/
			
			if(power==1){ /*Kuvvetimiz eger 1 ise */
				if(array[i]-(int)array[i]==0){ /*Eger katsayimiz ile katsayimizin int'e castlenmis halinin farki 0 ise yani sayimizin kusurati yoksa.*/
					printf("%.0lfx", array[i]); /*Sayinin kusurat kismi olmadan .0lf formati ile yazdiririz.*/
					power--;
				}
				else {
					printf("%.1lfx", array[i]); /*Eger fark 0 dan farkli ise sayimizin kusurati var demektir bu durumda kusuratli kismi .1lf formatiyla yazdiririz.*/
					power--;
				}
				
				
				
			}
			else{  /*Kuvvetimiz 1 den farkli ise.*/
			  	if(array[i]-(int)array[i]==0){ /*Buradaki cast islemide yukaridaki islemlerimizle aynidir.*/
					printf("%.0lfx^%d", array[i], power--);
				}
				else{
					printf("%.1lfx^%d", array[i], power--);
				}
				
			}
		
		}
	}
		
}
	

}
	
