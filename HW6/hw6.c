#include <stdio.h>

/*Function for finding size of line..*/
int find_size_of_line(char line[]){
	
	int size ;
	
	for(size=0;line[size]!='\0';size++);
	
	return size;
	
}

/*Function for reversing a line .*/
void reverse_line(char line[], int line_lenght){
	
	int index;
	int right_index=line_lenght-1;
	char temp;
	
	for(index=0;index<right_index;index++,right_index--){
		temp=line[index];
		line[index]=line[right_index];
		line[right_index]=temp;
	}
	
}

/*Encrypting function.*/
void encrypt_open_msg(){
	char line[1024];
	
	FILE * fin;	/*Opening two file .*/
	FILE * fin2; /*One is for writing and the other one is for reading.*/
	int key,i,size;
	
	fin = fopen("open_msg.txt", "r");
	fin2 = fopen("secret_msg.txt","w");

	printf("Enter a key between 1 and 26:");
	scanf("%d",&key);

	while(fgets(line,1024,fin)!=NULL){/*Using fgets function for getting line.*/
									  /*If the line is empty then loop stops.*/

		size = find_size_of_line(line);
		reverse_line(line,size);

		for(i=0;i<size;i++){
			if(!(line[i]>=97 && line[i]<=122)){
				if(line[i]==32){ /*In asci "32" is blank.If the character is blank then we
									encrypting it to  "_".*/
					line[i]=95;	/*In asci "95" is "_";*/

				}
				else if(line[i]==46){/*In asci "46" is dot.If the character is dot then we
									encrypting it to star .*/

					line[i]=42;/*In asci "42" is star.*/

				}

			}
			else{
				line[i]=line[i]-key;/*We are going back in ASCI with this key.*/
				if(line[i]<97){/*If we reached the "a" then we are adding 26 to reach end of the alphabet.*/
					line[i]+=26;
				}
			}
		}
		fprintf(fin2,"%s",line);/*Writing encrypted message in to secret_msg.txt*/
		printf("%s",line);/*Displaying line on the screen.*/
		
	}
	fclose(fin);	/*Closing files.*/
	fclose(fin2);
}

/*We do the exact opposite of the above.Decrypting the msg.*/
void decrypt_secret_msg(){
	
	char line[1024];
	
	FILE * fin;
	FILE * fin2;
	int key,i,size;
	
	fin = fopen("secret_msg.txt","r");
	fin2 = fopen("open_msg.txt","w");

	printf("Enter a key between 1 and 26:");
	scanf("%d",&key);

	while(fgets(line,1024,fin)!=NULL){

		size = find_size_of_line(line);
		reverse_line(line,size);

		for(i=0;i<size;i++){
			if(!(line[i]>=97 && line[i]<=122)){
				if(line[i]==95){
					line[i]=' ';
				}
				else if(line[i]==42){
					line[i]=46;
				}
				
			}
			else{
				line[i]=line[i]+key; /*We are adding the key to go forward.*/
				if(line[i]>122){
					line[i]-=26;/*If we reached the end of the line then we extract 26 to reach head of the line.*/
				}
			}
		}
		fprintf(fin2,"%s",line);/*Writing in to open_msg.txt*/
		printf("%s",line);

	}
	fclose(fin);	/*Closing files.*/
	fclose(fin2);
}

void menu(){
	int selection;
	do{
		printf("1.Encrypt\n");
		printf("2.Decrypt\n");
		printf("0.Exit\n\n");
		printf("Choice: ");
		scanf("%d",&selection);
		switch(selection){
			case 1:encrypt_open_msg();
				   printf("\n");
				   break;
			case 2:decrypt_secret_msg();
				   printf("\n");
				   break;
		}
	}while(selection!=0);	
}

int main(){
	
	menu();
	
	return 0;
}