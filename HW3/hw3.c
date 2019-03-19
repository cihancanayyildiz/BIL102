#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* This function gets inputs from user.It checks if the entery is within the operands [mini,maxi].*/

int getInt(int mini,int maxi){
	int selection_of_horse,count=0;
	do{
		scanf("%d",&selection_of_horse);
		if(selection_of_horse>=mini && selection_of_horse<=maxi){
			return selection_of_horse;
		}
		
		else {
			printf("Please enter another input:");
			count++;
		}
		
	}while(count!=0);	
	
}

/* This function generates a random number between min and max values. */

int numberGeneratorBetweenRange(int min, int max){
	
	int randomnum,i;
		
	randomnum = min + rand()%(max-min+1);
	
	return randomnum;
		
}

void horseRacingGame() {
	int  horse_count,horse_number,randomtime;
	int  i,j,min=100000,count=0; 
	srand(time(NULL));  /*Function that allows us to generate random numbers every time */
	horse_count = numberGeneratorBetweenRange(3,5); /* Generating random horse count.*/
	printf("Number of Horse : %d\n",horse_count); 
	
	printf("Horse Number: ");
	horse_number = getInt(1,horse_count); /*Getting input of horse number from user.*/
	printf("Racing starts...\n");
	
	for(i=1;i<=horse_count;i++){
		randomtime = numberGeneratorBetweenRange(10,20); /* Generating random horse time.*/
		printf("Horse %d :",i);

		for(j=0;j<randomtime;j++){
			printf("-");			
		}
		printf("\n");

		if(randomtime<min && randomtime>0){
			min = randomtime;			/* determining of minimum random time value.*/
			count = i;
		}		
	}

	if(count == horse_number){
		printf("You win!! Winner is horse %d\n",horse_number);
	}
	else{
		printf("You lose!! Winner is horse %d\n",count);
	}
	printf("\n\n");

}

void countOccurrence(){
	int bigNumber,searchNumber,count1=1,occurrence=0,temp;

	printf("Enter bigNumber: ");
	scanf("%d",&bigNumber);		/*Getting bigNumber input from user.*/
	printf("Enter searchNumber: ");
	scanf("%d",&searchNumber); 	/*Getting searchNumber input from user.*/

	temp = searchNumber;	    /*Holding searchNumber at a temp .*/

	do{
		count1 = count1 * 10;	/*This loop allows us to produce decimals according to the number of digits we are looking for*/

	}while(temp = temp / 10); /*We divide the temp by 10 until  it can't   be divided .*/
	

	do{
		if(bigNumber%count1 == searchNumber){	/*Searching for searchNumber and if we get it then occurrence count will increase by 1.*/
			occurrence++;
		}
		
	}while(bigNumber = bigNumber / 10); /*We divide the bigNumber by 10 until it can't be divided.*/


	printf("Occurrence: %d \n\n",occurrence);

}

void triangleOfSequences(){
	int i,j,rows;
	srand(time(NULL)); /*Function that allows us to generate random numbers every time */
	rows = numberGeneratorBetweenRange(2,10);

	for(i=1;i<=rows;i++){
		for(j=1;j<=i;j++){
		
			printf("%d ",i*j); /* Multiplication of i to j and displaying its result.*/
		
		}
		
		printf("\n");
		
	}
	printf("\n\n");
}

void menu(){
	
	int selection;
	do{
		printf("1.Horse Racing Game\n");
		printf("2.Occurrence Counter\n");
		printf("3.Triangle Of Sequences\n");
		printf("0.Exit\n\n");
		printf("Enter your selection: ");
		scanf("%d",&selection);
		printf("\n");

		switch(selection){
			case 1 : horseRacingGame();
					 break;

			case 2 : countOccurrence();
					 break;

			case 3 : triangleOfSequences();
					 break;

			case 0 : break;
			
		}
	}while(selection!=0);

}

int main(){
	
	menu();

	return 0;
	
}

