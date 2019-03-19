#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Determining structs.*/
typedef struct{
	char **Map;
	int width;
	int height;
	int Flower_X;
	int Flower_Y;
}Forest;

typedef struct{
	int Coord_X;
	int Coord_Y;
	int Water_Bottle_Size;	
}Botanist;


/*Function for initialize */
void init_game (Forest *forest, Botanist *botanist){
	int i,j;
	FILE * fp;
	fp = fopen("init.txt","r");

	fscanf(fp,"%d",&botanist->Water_Bottle_Size);
	fscanf(fp,"%d,",&forest->height);	/*rows.*/
	fscanf(fp,"%d\n",&forest->width);	/*columns.*/

	/*Allocating memory for 2D char array.*/
	forest->Map = malloc(forest->height*sizeof(Forest*));
	for(i=0;i<forest->height;i++) forest->Map[i] = malloc(forest->width*sizeof(Forest));
	/*Allocating memory for 2D char array.*/


	/*Initializing the board.*/
	for(i=0;i<forest->height;i++){

		for(j=0;j<forest->width;j++){

			fscanf(fp,"%c,",&forest->Map[i][j]);
		}
		fscanf(fp,"\n");
	}

	/*Finding the location of flower and botanist.*/
	for(i=0;i<forest->height;i++){
		for(j=0;j<forest->width;j++){
			if(forest->Map[i][j]=='F'){
				forest->Flower_X=i;
				forest->Flower_Y=j;
			}

			else if(forest->Map[i][j]=='B'){
				botanist->Coord_X=i;
				botanist->Coord_Y=j;
			}
		}
	}
	
	
	fclose(fp);	/*Closing the file.*/
}

/*Function for print the map.*/
void print_Map (Forest *forest){
	int i,j;
	for(i=0;i<forest->height;i++){
		for(j=0;j<forest->width;j++){
			printf("%c ",forest->Map[i][j]);
		}
		printf("\n");
	}
	
}

/*Move function.*/
void search(Forest *forest,Botanist *botanist){

	int random=1+rand()%4;	/*Generating the random num.*/
	
	if(botanist->Water_Bottle_Size==0 && botanist->Coord_X==forest->Flower_X && botanist->Coord_Y==forest->Flower_Y){	/*If he has no water and he get the flower at the same time.*/
		print_Map(forest);
		printf("\n%d",botanist->Water_Bottle_Size);
		printf("\nI have found it on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
		return;
	}

	else if(botanist->Water_Bottle_Size==0){	/*If the water is exhausted.*/
		print_Map(forest);
		printf("\nHelp! I am on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
		return;
	}
	if(botanist->Coord_X==forest->Flower_X && botanist->Coord_Y==forest->Flower_Y){	/*If he finds the flower.*/
		print_Map(forest);
		printf("\nI have found it on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
		return;
	}

	if(random==1){	/*If the random num is equal to 1 then moving down */
		
		if(botanist->Coord_X+1 < forest->height && (forest->Map[botanist->Coord_X+1][botanist->Coord_Y]==' ' || forest->Map[botanist->Coord_X+1][botanist->Coord_Y]=='F')){
			if(forest->Map[botanist->Coord_X+1][botanist->Coord_Y]=='F'){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_X++;
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	

			}
			else{
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_X++;
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	
			}
				
		}	
	}
	
	if(random==2){	/*If the random num is equal to 2 then moving up*/
		
		if(botanist->Coord_X-1 >= 0 && (forest->Map[botanist->Coord_X-1][botanist->Coord_Y]==' ' || forest->Map[botanist->Coord_X-1][botanist->Coord_Y]=='F')){
			if(forest->Map[botanist->Coord_X-1][botanist->Coord_Y]=='F'){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_X--;
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	

			}
			else{
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_X--;
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	
			}
		}
	}
	
	if(random==3){	/*If the random num is equal to 3 then moving right */
		
		if(botanist->Coord_Y+1 < forest->width && (forest->Map[botanist->Coord_X][botanist->Coord_Y+1]==' ' || forest->Map[botanist->Coord_X][botanist->Coord_Y+1]=='F')){
			if(forest->Map[botanist->Coord_X][botanist->Coord_Y+1]=='F'){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_Y++;
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	

			}
			else{
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_Y++;
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	
			}
		}
	}
	if(random==4){	/*If the random num is equal to 4 then moving left*/

		if(botanist->Coord_Y-1 >=0  &&  (forest->Map[botanist->Coord_X][botanist->Coord_Y-1]==' ' || forest->Map[botanist->Coord_X][botanist->Coord_Y-1]=='F')){
			if(forest->Map[botanist->Coord_X][botanist->Coord_Y-1]=='F'){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_Y--;
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	

			}
			else{
				forest->Map[botanist->Coord_X][botanist->Coord_Y]=' ';
				botanist->Coord_Y--;
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				botanist->Water_Bottle_Size--;
				search(forest,botanist);
				return;	
			}	
		}
	}
	
	search(forest,botanist);	/*Calling the function again.*/
	
}

int main(){
	
	Botanist botanist;
	Forest forest;
	
	srand(time(NULL));

	init_game(&forest,&botanist);
	
	print_Map(&forest);

	printf("\nSearching . . .\n\n");

	search(&forest,&botanist);
	
	
	return 0;
	
}
