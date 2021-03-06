#include <stdio.h>

typedef enum {white_man, black_man, white_king, black_king, empty} piece; 

typedef enum {white = 10, black = 20} player; 


void init_board(piece board[][8]){ /*Initializing the normal board of Turkish Draughts*/
	
	int i,j;
	piece board_test[8][8] = {
	
	{empty,empty,empty,empty,empty,empty,empty,empty},
	{black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
	{black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
	{empty,empty,empty,empty,empty,empty,empty,empty},
	{empty,empty,empty,empty,empty,empty,empty,empty},
	{white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
	{white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
	{empty,empty,empty,empty,empty,empty,empty,empty}
	
	};
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j] = board_test[i][j];
		}
	}
		
}
void init_board_samplegame1(piece board[][8]){	/*initializing a famous game's board*/ 
	
	int i,j;
	piece board_test[8][8] = {
	
	{empty,empty,empty,empty,empty,empty,empty,empty},
	{empty,black_man,empty,empty,black_man,black_man,black_man,empty},
	{black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
	{empty,black_man,empty,black_man,black_man,empty,black_man,empty},
	{empty,white_man,white_man,empty,white_man,white_man,white_man,white_man},
	{empty,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
	{empty,empty,white_man,empty,white_man,empty,white_man,empty},
	{empty,empty,empty,empty,empty,empty,empty,empty}
	};
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j] = board_test[i][j];
		}
	}
	
}

void init_board_samplegame2(piece board[][8]){	/*initializing the given gif game's board*/ 
	int i,j;
	piece board_test[8][8] = {
	
	{empty,empty,empty,empty,empty,empty,empty,empty},
	{empty,empty,black_man,black_man,black_man,black_man,empty,empty},
	{empty,black_man,black_man,black_man,black_man,empty,black_man,black_man},
	{black_man,black_man,black_man,empty,empty,black_man,empty,black_man},
	{empty,empty,white_man,white_man,white_man,black_man,white_man,white_man},
	{white_man,white_man,white_man,white_man,white_man,empty,white_man,white_man},
	{empty,empty,white_man,white_man,white_man,white_man,empty,empty},
	{empty,empty,empty,empty,empty,empty,empty,empty}
	};
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j] = board_test[i][j];
		}
	}
	
}

int check_end_of_game(piece board[][8]){ /*Checking if the game has been completed or continues.*/
	int countw=0; /*Count of white mans*/
	int countb=0; /*Count of black mans*/
	int i,j;
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j] == white_man || board[i][j] == white_king){ /* If a cell has white countw increase by 1*/
				countw++;		
			}
			else if(board[i][j] == black_man || board[i][j] == black_king){ /*If a cell has black countb increase by 1*/
				countb++;
			}
		}
	}
	
	if(countw>0 && countb==0){
		return white;
	}
	else if(countb>0 && countw==0){
		return black;
	}
	else if(countb>0 && countw>0){
		return -1;
	}
	
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){ 
	
	int n=0,i,j;
	
	if(p==20){	/*If the black player's turn.*/
		
		if(board[from_x][from_y]==white){	/*If the player black is trying to move a piece that does not belong to him then returns -1*/
			return -1;
		}
		
		if(((from_x+1==to_x && from_y==to_y)||(from_x==to_x && from_y+1==to_y)||(from_x==to_x && from_y-1==to_y))&&(board[from_x][from_y]!=black_king)){	/*If the player wants to move 1 block forward.*/
		
			if(board[to_x][to_y]==empty){
				
				if(to_x==7){
					board[to_x][to_y]=black_king;
					board[from_x][from_y]=empty;
				}
				else{
					board[to_x][to_y]=black_man;
					board[from_x][from_y]=empty;
				}
				
			}
			
			else{
				return -2;
			}
		}
		
		
		else if(((from_x+2==to_x && from_y==to_y)||(from_x==to_x && from_y+2==to_y)||(from_x==to_x && from_y-2==to_y))&&(board[from_x][from_y]!=black_king)){	/*If the player wants to eat a white */
			
				if(to_x==7){
					board[to_x][to_y]=black_king;
					board[(from_x+to_x)/2][(from_y+to_y)/2]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				else{
					board[to_x][to_y]=black_man;
					board[(from_x+to_x)/2][(from_y+to_y)/2]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
			
		}
		
		else if(board[from_x][from_y]==black_king){	/*If the player wants to move black_king */
		
			for(i=1;i<8;i++){	/*Checking every block*/
				
				if((from_x+i==to_x && from_y==to_y)||(from_x==to_x && from_y+i==to_y)||(from_x==to_x && from_y-i==to_y)||(from_x-i==to_x && from_y==to_y)){	/*Checking every block forward*/
					
					if((from_x+i==to_x && from_y==to_y)){
						for(j=from_x;j<to_x;j++){
							if(board[j][to_y]==white_man||board[j][to_y]==white_king){
								board[j][to_y]=empty;
								board[to_x][to_y]=black_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[j][to_y]==black_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}
						}
						board[to_x][to_y]=black_king;
						board[from_x][from_y]=empty;
					}
					else if(from_x==to_x && from_y+i==to_y){	/*Checking right side of black_king */
						for(j=from_y;j<to_y;j++){
							if(board[to_x][j]==white_man||board[to_x][j]==white_king){
								board[to_x][j]=empty;
								board[to_x][to_y]=black_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[to_x][j]==black_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}	
						}
						board[to_x][to_y]=black_king;
						board[from_x][from_y]=empty;
					}
					else if(from_x==to_x && from_y-i==to_y){	/*Checking left side of black_king */
						for(j=from_y;j>to_y;j--){
							if(board[to_x][j]==white_man||board[to_x][j]==white_king){
								board[to_x][j]=empty;
								board[to_x][to_y]=black_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[to_x][j]==black_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}	
						}
						board[to_x][to_y]=black_king;
						board[from_x][from_y]=empty;
					}
					else if(from_x-i==to_x && from_y==to_y){	/*Checking back side of black_king*/
						for(j=from_x;j>=to_x;j--){
							if(board[j][to_y]==white_man||board[j][to_y]==white_king){
								board[j][to_y]=empty;
								board[to_x][to_y]=black_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[j][to_y]==black_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}
						}
						board[to_x][to_y]=black_king;
						board[from_x][from_y]=empty;
					}	
					
				}
			}
		}
	}
		
	else if(p==10){	/*If the white player's turn.*/
		
		if(board[from_x][from_y]==black){	/*If the player white is trying to move a piece that does not belong to him then returns -1*/
			return -1;
		}
		
		if(((from_x-1==to_x && from_y==to_y)||(from_x==to_x && from_y+1==to_y)||(from_x==to_x && from_y-1==to_y))&&(board[from_x][from_y]!=white_king)){	/*If the player wants to move 1 block forward.*/
		
			if(board[to_x][to_y]==empty){
				
				if(to_x==0){
					board[to_x][to_y]=white_king;
					board[from_x][from_y]=empty;
				}
				else{
					board[to_x][to_y]=white_man;
					board[from_x][from_y]=empty;
				}
				
			}
			
			else{
				return -2;
			}
		}
		
		else if(((from_x-2==to_x && from_y==to_y)||(from_x==to_x && from_y+2==to_y)||(from_x==to_x && from_y-2==to_y))&&(board[from_x][from_y]!=white_king)){	/*If the player wants to eat a black */
			
				if(to_x==0){
					board[to_x][to_y]=white_king;
					board[(from_x+to_x)/2][(from_y+to_y)/2]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				else{
					board[to_x][to_y]=white_man;
					board[(from_x+to_x)/2][(from_y+to_y)/2]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
			
		}
		
		else if(board[from_x][from_y]==white_king){	/*If the player wants to move white_king */
		
			for(i=1;i<8;i++){	/*Checking every block*/
				
				if((from_x+i==to_x && from_y==to_y)||(from_x==to_x && from_y+i==to_y)||(from_x==to_x && from_y-i==to_y)||(from_x-i==to_x && from_y==to_y)){	/*Checking every block forward*/
					
					if((from_x+i==to_x && from_y==to_y)){
						for(j=from_x;j<to_x;j++){
							if(board[j][to_y]==black_man){
								board[j][to_y]=empty;
								board[to_x][to_y]=white_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[j][to_y]==white_man||board[to_x][to_y]==white_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}
						}
						board[to_x][to_y]=white_king;
						board[from_x][from_y]=empty;
					}
					else if(from_x==to_x && from_y+i==to_y){	/*Checking right side of white_king */
						for(j=from_y;j<to_y;j++){
							if(board[to_x][j]==black_man){
								board[to_x][j]=empty;
								board[to_x][to_y]=white_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[to_x][j]==white_man||board[to_x][to_y]==white_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}	
						}
						board[to_x][to_y]=white_king;
						board[from_x][from_y]=empty;
					}
					else if(from_x==to_x && from_y-i==to_y){	/*Checking left side of white_king */
						for(j=from_y;j>to_y;j--){
							if(board[to_x][j]==black_man){
								board[to_x][j]=empty;
								board[to_x][to_y]=white_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[to_x][j]==white_man||board[to_x][to_y]==white_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}	
						}
						board[to_x][to_y]=white_king;
						board[from_x][from_y]=empty;
					}
					else if(from_x-i==to_x && from_y==to_y){	/*Checking back side of black_king*/
						for(j=from_x;j>=to_x;j--){
							if(board[j][to_y]==black_man){
								board[j][to_y]=empty;
								board[to_x][to_y]=white_king;
								board[from_x][from_y]=empty;
								break;
							}
							else if(board[j][to_y]==white_man||board[to_x][to_y]==white_man){	/*If the black_king has a black on his way then he can't move the to_x to_y*/
								return -2;
							}
						}
						board[to_x][to_y]=white_king;
						board[from_x][from_y]=empty;
					}	
					
				}
			}
		}
		
	}
		
	
}
void display_board(piece board[][8]){	/*Printing the current board*/
	
	piece slot;
		
	for (int i = 0; i < 8; ++i)
	{
	for (int j = 0; j < 8; ++j)
		{
			slot = board[i][j];
			switch(slot){
				case black_man:printf("b");
				break;
				case white_man:printf("w");
				break;
				case empty:printf("-");
				break;
				case black_king:printf("B");
				break;
				case white_king:printf("W");
			}
		}

		printf("\n");
	}
	
	printf("\n");
}
void sample_game_1(piece board[][8]){	/*Playing Simple game 1 */
	
	init_board_samplegame1(board);	display_board(board);
	
	printf("Game starting...\n");
	
	move(board,2,2,3,2,black);	display_board(board);
	move(board,4,2,2,2,white);	display_board(board);
	move(board,2,0,3,0,black);	display_board(board);
	move(board,2,2,2,0,white);	display_board(board);
	move(board,3,0,4,0,black);	display_board(board);
	move(board,2,2,2,0,white);	display_board(board);
	move(board,4,1,2,1,white);	display_board(board);
	move(board,2,1,0,1,white);	display_board(board);
	move(board,2,7,3,7,black);	display_board(board);
	move(board,4,7,2,7,white);	display_board(board);
	move(board,2,5,3,5,black);	display_board(board);
	move(board,4,5,2,5,white);	display_board(board);
	move(board,2,5,0,5,white);	display_board(board);
	move(board,3,3,4,3,black);	display_board(board);
	move(board,5,3,3,3,white);	display_board(board);
	move(board,3,3,1,3,white);	display_board(board);
	move(board,1,3,1,5,white);	display_board(board);
	move(board,1,5,1,7,white);	display_board(board);
	move(board,4,0,5,0,black);	display_board(board);
	move(board,2,7,2,5,white);	display_board(board);
	move(board,2,5,2,3,white);	display_board(board);
	move(board,5,0,6,0,black);	display_board(board);
	move(board,4,4,2,4,white);	display_board(board);
	move(board,6,0,7,0,black);	display_board(board);
	move(board,4,6,2,6,white);	display_board(board);
	move(board,7,0,0,0,black);	display_board(board);
	move(board,0,0,0,3,black);	display_board(board);
	move(board,0,3,6,3,black);	display_board(board);
	move(board,6,3,6,1,black);	display_board(board);
	move(board,6,1,2,1,black);	display_board(board);
	move(board,2,1,2,5,black);	display_board(board);
	move(board,2,5,6,5,black);	display_board(board);
	move(board,6,5,6,2,black);	display_board(board);
	move(board,6,2,2,2,black);	display_board(board);
	move(board,2,2,2,7,black);	display_board(board);
	move(board,2,7,6,7,black);	display_board(board);
	move(board,6,7,6,4,black);	display_board(board);
	move(board,6,4,0,4,black);	display_board(board);
	move(board,0,4,0,7,black);	display_board(board);
	move(board,0,7,5,7,black);	display_board(board);
	move(board,5,7,5,5,black);	display_board(board);
	check_end_of_game(board);
	
	
}
void sample_game_2(piece board[][8]){	/*Playing simple game 2*/

	init_board_samplegame2(board);	display_board(board);
	
	printf("Game starting..\n");
	
	move(board,5,1,4,1,white);	display_board(board);
	move(board,3,1,5,1,black);	display_board(board);
	move(board,4,3,3,3,white);	display_board(board);
	move(board,4,5,4,3,black);	display_board(board);
	move(board,4,3,4,1,black);	display_board(board);
	move(board,3,3,3,1,white);	display_board(board);
	move(board,3,1,1,1,white);	display_board(board);
	move(board,1,2,1,0,black);	display_board(board);
	move(board,5,3,4,3,white);	display_board(board);
	move(board,5,1,5,3,black);	display_board(board);
	move(board,5,3,5,5,black);	display_board(board);
	move(board,5,5,7,5,black);	display_board(board);
	move(board,4,3,3,3,white);	display_board(board);
	move(board,2,3,4,3,black);	display_board(board);
	move(board,5,6,5,5,white);	display_board(board);
	move(board,7,5,4,5,black);	display_board(board);
	move(board,4,5,4,4,white);	display_board(board);
	move(board,4,4,4,2,white);	display_board(board);
	move(board,4,2,4,0,white);	display_board(board);
	move(board,4,0,2,0,white);	display_board(board);
	move(board,2,0,0,0,white);	display_board(board);
	check_end_of_game(board);

}

int main(){

	piece board[8][8];
	
	int selection;
	
	do{
		printf("Enter a selection.\n");
		printf("1.Sample Game #1\n");
		printf("2.Sample Game #2\n");
		printf("0.Exit\n");
		scanf("%d",&selection);
		switch(selection){
			
			case 1:	sample_game_1(board);
					break;
			case 2:	sample_game_2(board);
					break;
			case 0:	break;
			
		}
	}while(selection!=0);
	
	return 0;
	
}
