#include<stdio.h>

/* This function finds first digit of number.
 * num : the number we received from the user.
 */
 
int finding_digit(int num){
	int digit;
	
	digit = num % 10;	
							
	return digit;								
 										
}

int main(){
	int num,fifth_digit,fourth_digit,third_digit,second_digit,first_digit;

	printf("Enter a number : ");
	scanf("%d",&num);
	printf("\n");


	/* Finding digits of number that between 10000 and 98760.Five-digit numbers.*/
	if(num>=10000 && num<=98760){
		first_digit = finding_digit(num);
		num = num / 10;
		second_digit = finding_digit(num);
		num = num / 10;
		third_digit = finding_digit(num);
		num = num / 10;
		fourth_digit = finding_digit(num);
		num = num / 10;
		fifth_digit = finding_digit(num);

		printf("The fifth digit is %d\n",fifth_digit);
		printf("The fourth digit is %d\n",fourth_digit);
		printf("The third digit is %d\n",third_digit);
		printf("The second digit is %d\n",second_digit);
		printf("The first digit is %d\n",first_digit);

	}
	
	/* Finding digits of number that between 1000 and 10000.Four-digit numbers.*/
	else if(num>=1000 && num<10000){
		first_digit = finding_digit(num);
		num = num / 10;
		second_digit = finding_digit(num);
		num = num / 10;
		third_digit = finding_digit(num);
		num = num / 10;
		fourth_digit = finding_digit(num);

		printf("The fourth digit is %d\n",fourth_digit);
		printf("The third digit is %d\n",third_digit);
		printf("The second digit is %d\n",second_digit);
		printf("The first digit is %d\n",first_digit);


	}

	/* Finding digits of number that between 100 and 1000.Three-digit numbers.*/
	else if(num>=100 && num<1000){
		first_digit = finding_digit(num);
		num = num / 10;
		second_digit = finding_digit(num);
		num = num / 10;
		third_digit = finding_digit(num);

		printf("The third digit is %d\n",third_digit);
		printf("The second digit is %d\n",second_digit);
		printf("The first digit is %d\n",first_digit);

	}

	/* Finding digits of number that between 23 and 100.Two-digit numbers.*/
	else if(num>=23 && num<100){
		first_digit = finding_digit(num);
		num = num / 10;
		second_digit = finding_digit(num);

		printf("The second digit is %d\n",second_digit);
		printf("The first digit is %d\n",first_digit);

	}

	else{
		printf("This  number is not between 23 and 98760 \n");
	}

	return 0;

}
