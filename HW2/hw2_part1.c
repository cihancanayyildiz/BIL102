#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	int i,count=0,selection,num,num2,Agrades=0,Bgrades=0,Cgrades=0,Dgrades=0,Fgrades=0,indexmin,indexmax,min=100000,max=0;
	double sum=0,average;
	char maxgrade,mingrade;
	srand(time(NULL)); /* A function for generating random numbers.*/
	
	
	/* A loop for getting input from user. */
while(count==0){
	
	/*Getting inputs from user.*/
	printf("Please enter a number between 3 and 50:");
	scanf("%d",&num);

	if(num<3 || num>50){
		
		printf("Not in range!!!\n");

	}

	else{
		
		for(i=0;i<num;i++){

			num2 = rand()%101; /* Generating random numbers and assigning it to num2 */
			printf("%d ",num2);

			/* In this if else statement , determining letter grade.*/
			if(num2<60){
				Fgrades++;
			}
			else if(num2>=60 && num2<70){
				Dgrades++;
			}
			else if(num2>=70 && num2<80){
				Cgrades++;
			}
			else if(num2>=80 && num2<90){
				Bgrades++;
			}
			else{
				Agrades++;
			}

			/* In this if else statement , determining max and min letters */
			if(num2<min && num2>=0){
				min = num2;
				indexmin=i+1;
			}
			if(num2>max && num2>=0){
				max = num2;
				indexmax=i+1;
			}
		
			sum=sum+num2; /* with this assingment we will get student average grade.*/

		}
		/* In this if else statement , determining letter grade of most successful student.*/
		if(max<60){
			maxgrade = 'F';
		}
		else if(max>=60 && max<70){
			maxgrade = 'D';
		}
		else if(max>=70 && max<80){
			maxgrade = 'C';
		}
		else if(max>=80 && max<90){
			maxgrade = 'B';
		}
		else{
			maxgrade = 'A';
		}
		
		/*In this if else statement , determining letter grade of most unsuccessful student note.*/
		if(min<60){
			mingrade = 'F';
		}
		else if(min>=60 && min<70){
			mingrade = 'D';
		}
		else if(min>=70 && min<80){
			mingrade = 'C';
		}
		else if(min>=80 && min<90){
			mingrade = 'B';
		}
		else{
			mingrade = 'A';
		}
		
		
		average = sum/num; /*Calculating average grade.*/
		count++; /* if the num that  we get from user is  between 3 and 50 we must finish the loop by incrementing value of count.*/
	}
	
}

	/* do while loop for showing the menu after every selection */
	do{
		
	/* Displaying a menu */
	printf("\nStudent Score Calculator Menu For %d Student\n",num);			
	printf("1) Most Successful Student\n");								
	printf("2) Most Unsuccessful Student \n");
	printf("3) Letter Grade Statistics\n");
	printf("4) Calculate Average\n");
	printf("5) Show all Data\n");
	printf("\t\t\tMake Selection:");
	scanf("%d",&selection);
	printf("\n");

	/* Switch case statement for menu */
	switch(selection){
		case 1: printf("Most successfully student : \n");		
				printf("Index = %d \n",indexmax);				// In this case , we are displaying most succesfull student info.
				printf("Score : %d \n",max);
				printf("Letter Grade : %c \n",maxgrade);
				break;
				
		case 2: printf("Most unsuccessfully student : \n");
				printf("Index = %d \n",indexmin);				// In this case , we are displaying most unsuccesfull student info.
				printf("Score : %d \n",min);
				printf("Letter Grade : %c \n",mingrade);
				break;
				
		case 3: printf("Letter Grade Statistics: \n");
				printf("%d student got letter grade 'A'\n",Agrades);
				printf("%d student got letter grade 'B'\n",Bgrades);
				printf("%d student got letter grade 'C'\n",Cgrades);	// In this case , we are listing the number of students for each letter grade.
				printf("%d student got letter grade 'D'\n",Dgrades);
				printf("%d student got letter grade 'F'\n",Fgrades);
				break;
				
		case 4: printf("The average Score of %d Student is %.2lf\n",num,average);	// In this case , we are displaying average grade.
				break;
		
		case 5: printf("Most successfully student : \n");
				printf("Index = %d \n",indexmax);					
				printf("Score : %d \n",max);		
				printf("Letter Grade : %c \n\n",maxgrade);

				printf("Most unsuccessfully student : \n");
				printf("Index = %d \n",indexmin);
				printf("Score : %d \n",min);										// In the case 5 , we are showing all four options data.
				printf("Letter Grade : %c \n\n",mingrade);

				printf("Letter Grade Statistics: \n");
				printf("%d student got letter grade 'A'\n",Agrades);
				printf("%d student got letter grade 'B'\n",Bgrades);
				printf("%d student got letter grade 'C'\n",Cgrades);
				printf("%d student got letter grade 'D'\n",Dgrades);
				printf("%d student got letter grade 'F'\n\n",Fgrades);

				printf("The average Score of %d Student is %.2lf\n",num,average);
				break;
				
		case -1: break;		
		
		default:printf("False Selection!!!\n");

	}
	}while(selection!=-1); /* If the user enter -1 on menu selection the loop will finish.*/
	
	return 0;
}








