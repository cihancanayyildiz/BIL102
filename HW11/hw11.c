#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 30


//Initializing the structs..
typedef struct customers{	
	char name[STR_LEN];
	char surname[STR_LEN];
	int age;
	char gender[STR_LEN];
	struct customers *next;
}Customers;

typedef struct room{
	int number;
	int capacity;
	int floor;
	Customers *customer_next;
	struct room *next;
}Room;


void print_list(Room *head){ //Print fuction.

	int count;

	while(head!=NULL){
		printf("Room %d(Floor %d - capacity %dx)\n",head->number,head->floor,head->capacity);
		if(head->customer_next==NULL){
			printf("-> Empty\n");
		}
		else{
			printf("-> %s %s (%d-%s)\n",head->customer_next->name,head->customer_next->surname,head->customer_next->age,head->customer_next->gender);
			head->customer_next = head->customer_next->next;
			while(head->customer_next!=NULL){
				printf("-> %s %s (%d-%s)\n",head->customer_next->name,head->customer_next->surname,head->customer_next->age,head->customer_next->gender);
				head->customer_next = head->customer_next->next;
			}
		}
		head=head->next;
		printf("\n");
	}
}


void init_rooms(Room *firstr){	//Initializing the rooms from room.txt

	FILE *fp;

	int i;
	char buff[1024];
	fp = fopen("rooms.txt","r");
	
	while(fgets( buff , 1024 , fp ) !=NULL){

		sscanf(buff,"%d,%d,%d",&firstr->number,&firstr->capacity,&firstr->floor);

		if(firstr->number!=408){	//We are creating this if because we shouldnt create a new node after last node.
			firstr->next= (Room*)malloc(sizeof(Room));
			firstr = firstr->next;

		}
	}

	fclose(fp);
}

void init_customers(Room *iterator){	//Initializing the customers from customers.txt

	FILE *fp2;
	int i,j,temp;
	
	char buff[1024];
	
	while(iterator->next!=NULL){

	fp2 = fopen("customers.txt","r");	//opening the file.
	
		while(fgets ( buff, 1024 , fp2 ) != NULL){
			sscanf(buff,"%d,",&temp);	//holding a temp.
			if(temp==iterator->number){
				Customers *new = (Customers*)malloc(sizeof(Customers));
				sscanf(buff,"%d,%[^ ,] %[^ ,],%d,%s",&temp,new->name,new->surname,&new->age,new->gender);
				new->next = NULL;
				Customers *tmp = iterator->customer_next;	//creating a new temp and linking it with customer_next..
				iterator->customer_next = new;	//and linking customer to new.
				new->next = tmp;	// and new next is linking to temp.

			}
		}
	iterator= iterator->next;	
	fclose(fp2);	// closing it after every loop.
	}
}

void add_room_to_end(Room *iterator,int room_number,int room_capacity,int room_floor){	//Creating a room and adding it to end.

	while(iterator->next!=NULL){	//if the next one null then stops.

		iterator = iterator->next;

	}
		iterator->next = (Room*)malloc(sizeof(Room));	//creating a new node.
		iterator->next->number = room_number;
		iterator->next->capacity = room_capacity;	//Initializing it..
		iterator->next->floor = room_floor;
		iterator->next->customer_next = NULL;
		iterator->next->next=NULL;

}

void add_room_after_room_number(Room *iterator,int room_to_add_number,int number,int room_capacity,int room_floor){	//Creating a room after given room number

	while(iterator->number!=room_to_add_number){	// If we reach at the given room number then we stop.

		if(iterator->next==NULL){
			iterator->next = (Room*)malloc(sizeof(Room));
			iterator->next->number = number;
			iterator->next->capacity = room_capacity;
			iterator->next->floor = room_floor;
			iterator->next->customer_next = NULL;
			iterator->next->next=NULL;
			printf("%d\n",iterator->number);
			return;
		}

		iterator = iterator->next;

	}

		Room *temp = (Room*)malloc(sizeof(Room));	//Creating a new node for it.

		temp->next = iterator->next;	//Linking it to iterator->next.

		iterator->next = temp;	//And linking iterator->next to temp.

		temp->number = number;
		temp->floor = room_floor;
		temp->capacity = room_capacity;
		temp->customer_next = NULL;
	
}

Customers *add_customer_to_end(Customers *iterator,char name[STR_LEN],char surname[STR_LEN],int age,char gender[STR_LEN]){	//Creating a customer list.

	Customers *head;
	head = iterator;

	if(iterator==NULL){	//First customer.

		iterator = (Customers*)malloc(sizeof(Customers));
		strcpy(iterator->name,name);
		strcpy(iterator->surname,surname);
		iterator->age = age;
		strcpy(iterator->gender,gender);
		iterator->next = NULL;
		return iterator;

	}
	
	while(iterator->next!=NULL){	//Then the others..
		iterator = iterator->next;
	}

	iterator->next = (Customers*)malloc(sizeof(Customers));
	strcpy(iterator->next->name,name);
	strcpy(iterator->next->surname,surname);
	iterator->next->age = age;
	strcpy(iterator->next->gender,gender);
	iterator->next->next = NULL;

	return head;
	

}

void link_customers_to_room(Customers *iterator,Room *iterator2,int room_number){	//Linking the customers to room

	while(iterator2!=NULL){
		if(iterator2->number == room_number){
			break;
		}
		iterator2 = iterator2->next;

	}

	if(iterator2->customer_next == NULL){
		iterator2->customer_next = iterator;
	}

	else{	
		
		iterator2->customer_next->next->next= iterator;
	
	}

}

Room *remove_room(Room *iterator,int room_number){	//Removing the given room number

	Room *head = iterator;

	if(iterator->number == room_number){
		return iterator->next;
	}

	while(iterator->next->number!=room_number){
		iterator = iterator->next;
	}

	iterator->next = iterator->next->next;

	return head;

}

void show_vacancy(Room *iterator){	//Shows the available rooms.

	printf("available rooms : ");

	while(iterator!=NULL){	// If iterator equal to NULL then the loop stops.
		
		if(iterator->customer_next==NULL){
			printf("%d ",iterator->number);
		}

		iterator = iterator->next;

	}
	printf("\n");

}

void get_by_floor(Room *iterator,int given_floor_number){	//Shows the rooms that have given floor number

	printf("%d-storey rooms : ",given_floor_number);

	while(iterator!=NULL){	// If iterator equal to NULL then the loop stops.
		
		if(iterator->floor==given_floor_number){
			printf("%d ",iterator->number);
		}

		iterator = iterator->next;

	}
	printf("\n");

}

int main(){

	Room *head_room;
	Customers *head_customer;

	head_customer=NULL;
	head_room = NULL;
	head_room = (Room*)malloc(sizeof(Room));

	//Initializing..
	init_rooms(head_room);	
	init_customers(head_room);

	//add_room_to_end(head_room,409,4,4);	//You can create a room to end with this func.

	//add_room_after_room_number(head_room,101,111,4,4);	//You can create a room after given room number.

	//head_room = remove_room(head_room,103);	//You can remove a room with this func.

	//show_vacancy(head_room);	//You can see the avaiable rooms with this func.

	//get_by_floor(head_room,4);	//You can list the rooms with the given floor number.


	head_customer = add_customer_to_end(head_customer,"cihan","ayyildiz",20,"MALE");	// You can create a customer.
	head_customer = add_customer_to_end(head_customer,"furkan","ayyildiz",18,"MALE");	// You can create a customer and link them.

	link_customers_to_room(head_customer,head_room,408);	//You can add a customer list to a room.

	print_list(head_room);	//You can print the list with this func.
	
	free(head_room);
}
