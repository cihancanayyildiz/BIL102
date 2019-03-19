#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum { P,S,M,B,T,normal	/*Determining type of pieces.*/
}pieces;

typedef struct {	/*Struct for data of blocks.*/
	char text[20];
	int data;
	pieces type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

char strcopy(char *str1,char *str2){	/*Creating our own strcpy function.*/
	int i,j;
	for(i=0;str2[i]!='\0';i++);

	for(j=0;j<i;j++){
		str1[j]=str2[j];
	}
	str1[j]='\0';

	return *str1;

} 

void init_board(block board[][10]){	/*Initializing the board.*/
	
	int i,j,count=91;


	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i%2==0){
				board[i][j].data = count;
				sprintf(board[i][j].text,"%d",count);
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].jump_x=i;
				board[i][j].jump_y=j;
				count++;
			}
			if(i%2==1){
				board[i][j].data = count;
				sprintf(board[i][j].text,"%d",count);
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].jump_x=i;
				board[i][j].jump_y=j;
				count--;
			}
		}
		if(i%2==0){
			count -=11;
		}
		if(i%2==1){
			count -=9;
		}
	}

	strcopy(board[0][2].text,"T"); board[0][2].type=T; board[0][2].jump_x=1; board[0][2].jump_y=2;
	strcopy(board[0][7].text,"S{72}"); board[0][7].type=S; board[0][7].jump_x=2; board[0][7].jump_y=1;
	strcopy(board[0][8].text,"S{56}"); board[0][8].type=S; board[0][8].jump_x=4; board[0][8].jump_y=5;
	
	strcopy(board[1][1].text,"M{94}"); board[1][1].type=M; board[1][1].jump_x=0; board[1][1].jump_y=3;
	strcopy(board[1][5].text,"P"); board[1][5].type=P; board[1][5].jump_x=1; board[1][5].jump_y=5;
	strcopy(board[1][8].text,"B"); board[1][8].type=B; board[1][8].jump_x=1; board[1][8].jump_y=3;
	
	strcopy(board[2][2].text,"S{68}"); board[2][2].type=S; board[2][2].jump_x=3; board[2][2].jump_y=2;
	strcopy(board[2][5].text,"M{83}"); board[2][5].type=M; board[2][5].jump_x=1; board[2][5].jump_y=7;
	strcopy(board[2][8].text,"T"); board[2][8].type=T; board[2][8].jump_x=2; board[2][8].jump_y=3;
	
	strcopy(board[3][1].text,"M{77}"); board[3][1].type=M; board[3][1].jump_x=2; board[3][1].jump_y=6;
	strcopy(board[3][4].text,"B"); board[3][4].type=B; board[3][4].jump_x=2; board[3][4].jump_y=0;
	strcopy(board[3][7].text,"S{52}"); board[3][7].type=S; board[3][7].jump_x=4; board[3][7].jump_y=1;
	
	strcopy(board[4][3].text,"T"); board[4][3].type=T; board[4][3].jump_x=5; board[4][3].jump_y=1;
	strcopy(board[4][6].text,"M{77}"); board[4][6].type=M; board[4][6].jump_x=2; board[4][6].jump_y=6;
	strcopy(board[4][9].text,"S{44}"); board[4][9].type=S; board[4][9].jump_x=5; board[4][9].jump_y=6;
	
	strcopy(board[5][0].text,"B"); board[5][0].type=B; board[5][0].jump_x=4; board[5][0].jump_y=4;
	strcopy(board[5][2].text,"P"); board[5][2].type=P; board[5][2].jump_x=5; board[5][0].jump_y=2;
	strcopy(board[5][5].text,"S{22}"); board[5][5].type=S; board[5][5].jump_x=7; board[5][5].jump_y=8;
	
	strcopy(board[6][1].text,"M{52}"); board[6][1].type=M; board[6][1].jump_x=4; board[6][1].jump_y=1;
	strcopy(board[6][5].text,"B"); board[6][5].type=B; board[6][5].jump_x=5; board[6][5].jump_y=9;
	strcopy(board[6][9].text,"T"); board[6][9].type=T; board[6][9].jump_x=6; board[6][9].jump_y=4;
	
	strcopy(board[7][1].text,"B"); board[7][1].type=B; board[7][1].jump_x=6; board[7][1].jump_y=3;
	strcopy(board[7][5].text,"S{12}"); board[7][5].type=S; board[7][5].jump_x=8; board[7][5].jump_y=1;
	
	strcopy(board[8][2].text,"P"); board[8][2].type=P; board[8][2].jump_x=8; board[8][2].jump_y=2;
	strcopy(board[8][6].text,"M{28}"); board[8][6].type=M; board[8][6].jump_x=7; board[8][6].jump_y=2;
	
	strcopy(board[9][3].text,"M{11}"); board[9][3].type=M; board[9][3].jump_x=8; board[9][3].jump_y=0;
	strcopy(board[9][4].text,"S{1}"); board[9][4].type=S; board[9][4].jump_x=9; board[9][4].jump_y=9;

}

void display_board(block board[][10]){	/*Displaying the board.*/
	int i,j;

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(board[i][j].type==M || board[i][j].type==S){
				printf("%-5s",board[i][j].text);
			}
			else{
				printf("%-4s ",board[i][j].text);
			}
			

		}
		printf("\n");
	}

}

int play_the_game(block board[][10],block curr,int movecount,int dice){	/*Playing the game (MOVE FUNCTION) */

	/*
	printf("Current position Data: %d\n",curr.data);
	printf("Dice: %d\n ",dice);							If you want to print all data while playing  single game you can use this code .*/
	


	/*Looking for all possibilities*/
	if(dice+curr.data == 100){		
		curr.data = dice+curr.data;
		
		return movecount;
	}
	else if(dice+curr.data > 100){
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	
	else if(dice+curr.data == 6 ){	/*If we reached at S{1}*/
		curr.data=1;
		curr.pos_x=board[9][4].jump_x;
		curr.pos_y=board[9][4].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	
	else if(dice+curr.data == 7){	/*If we reached at M{11}*/
		curr.data=11;
		curr.pos_x=board[9][3].jump_x;
		curr.pos_y=board[9][3].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 13){	/*If we reached at the P*/
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 17){	/*If we reached at the M{28}*/
		curr.data=28;
		curr.pos_x=board[8][6].jump_x;
		curr.pos_y=board[8][6].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data ==25){	/*If we reached at the S{12}*/
		curr.data=12;
		curr.pos_x=board[7][5].jump_x;
		curr.pos_y=board[7][5].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 29){	/*If we reached at the B*/
		curr.data=34;
		curr.pos_x=board[7][1].jump_x; 
		curr.pos_y=board[7][1].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 32){	/*If we reached at the M{52}*/
		curr.data=52;
		curr.pos_x=board[6][1].jump_x; 
		curr.pos_y=board[6][1].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 36){	/*If we reached at the B*/
		curr.data=41;
		curr.pos_x=board[6][5].jump_x; 
		curr.pos_y=board[6][5].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 40){	/*If we reached at the T*/
		curr.data=35;
		curr.pos_x=board[6][9].jump_x; 
		curr.pos_y=board[6][9].jump_y;	
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 45){	/*If we reached at the S{22}*/
		curr.data=22;
		curr.pos_x=board[5][5].jump_x; 
		curr.pos_y=board[5][5].jump_y;	
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 48){	/*If we reached at the P*/	
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 50){	/*If we reached at the B*/
		curr.data=55;
		curr.pos_x=board[5][0].jump_x;
		curr.pos_y=board[5][0].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 54){	/*If we reached at the T*/
		curr.data=49;
		curr.pos_x=board[4][3].jump_x;
		curr.pos_y=board[4][3].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);	
	}
	else if(dice+curr.data == 57){	/*If we reached at the M{77}*/
		curr.data=77;
		curr.pos_x=board[4][6].jump_x;
		curr.pos_y=board[4][6].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 60){	/*If we reached at the S{44}*/
		curr.data=44;
		curr.pos_x=board[4][9].jump_x;
		curr.pos_y=board[4][9].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 63){	/*If we reached at the S{52}*/
		curr.data=52;
		curr.pos_x=board[3][7].jump_x;
		curr.pos_y=board[3][7].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 66){	/*If we reached at the B*/
		curr.data=71;
		curr.pos_x=board[3][4].jump_x;
		curr.pos_y=board[3][4].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 69){	/*If we reached at the M{77}*/
		curr.data=77;
		curr.pos_x=board[3][1].jump_x;
		curr.pos_y=board[3][1].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 73){	/*If we reached at the S{68}*/
		curr.data=68;
		curr.pos_x=board[2][2].jump_x;
		curr.pos_y=board[2][2].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 76){	/*If we reached at the M{83}*/
		curr.data=83;
		curr.pos_x=board[2][5].jump_x;
		curr.pos_y=board[2][5].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 79){	/*If we reached at the T*/
		curr.data=74;
		curr.pos_x=board[2][8].jump_x;
		curr.pos_y=board[2][8].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 82){	/*If we reached at the B*/
		curr.data=87;
		curr.pos_x=board[1][8].jump_x;
		curr.pos_y=board[1][8].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 85){	/*If we reached at the P*/
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 89){	/*If we reached at the M{94}*/
		curr.data=94;
		curr.pos_x=board[1][1].jump_x;
		curr.pos_y=board[1][1].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 93){	/*If we reached at the T*/
		curr.data=88;
		curr.pos_x=board[0][2].jump_x;
		curr.pos_y=board[0][2].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 98){	/*If we reached at the S{72}*/
		curr.data=72;
		curr.pos_x=board[0][7].jump_x;
		curr.pos_y=board[0][7].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else if(dice+curr.data == 99){	/*If we reached at the S{56}*/
		curr.data=56;
		curr.pos_x=board[0][8].jump_x;
		curr.pos_y=board[0][8].jump_y;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
	else{
		curr.data = dice + curr.data;
		play_the_game(board,curr,movecount+1,1+rand()%6);
	}
}

void two_player_game(block board[][10]){	/*Playing two player game*/

	block player1,player2;
	int player1count,player2count;
	player1.data=1; player2.data=2;
	player1.pos_x=9; player1.pos_y=9;
	player2.pos_y=9; player2.pos_y=9;

	player1count=play_the_game(board,player1,1,1+rand()%6);
	init_board(board);
	player2count=play_the_game(board,player2,1,1+rand()%6);

	if(player2count<player1count){
		printf("\tPlayer1 Move count: %d\n",player1count);
		printf("\tPlayer2 Move count: %d\n",player2count);
		printf("\tPlayer2 WON!\n");
	}
	else if(player1count<player2count){
		printf("\tPlayer1 Move count: %d\n",player1count);
		printf("\tPlayer2 Move count: %d\n",player2count);
		printf("\tPlayer1 WON!\n");
	}
	else{
		printf("\tPlayer1 Move count: %d\n",player1count);
		printf("\tPlayer2 Move count: %d\n",player2count);
		printf("\tDRAW!\n");
	}

}


int main(){

	int count=0,selection;
	srand(time(NULL));
	block board[10][10];
	block curr;

	curr.data=1;
	curr.pos_x=9;
	curr.pos_y=9;


	init_board(board);
	do{
		printf("1.Display the board.\n");
		printf("2.Play single game.\n");
		printf("3.Play two player game.\n");
		printf("0.Exit.\n");
		scanf("%d",&selection);

		switch(selection){
			case 1:	display_board(board);
					printf("\n");
					break;
			case 2:	printf("\tMove count : %d\n",play_the_game(board,curr,count+1,1+rand()%6));
					printf("\n");
					break;

			case 3: two_player_game(board);
					printf("\n");
					break;

		}
	}while(selection!=0);
	
	

	

	return 0;

	
}
