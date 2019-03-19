#include <stdio.h>

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current){
	int i;

	if(expected_val==current && cursor==arr_len-1){	/*If we reached the expected value and we are at the end of the array then we returning the operations.*/
		
		return operations;

	}

	else if (expected_val!=current && cursor==arr_len-1) {	/*If we couldnt reached the exptected value and we are at the end of the array.We are doing empty last member of operations and returning back.*/

		operations[cursor-1]=' ';
		return operations;
	}

	
	
	operations[cursor]='+';
	find_operations(arr,expected_val,operations,arr_len,cursor+1,current+arr[cursor+1]);

	if(expected_val==current+arr[cursor+1] && cursor!=0){	/*If we reached the expected value and the cursor is not zero then we are returning one more back.*/
		operations[cursor]='+';
		return operations;
	}

	if(operations[arr_len-2]!=' '){	/*If the last member of operations is not empty and we are returning one more back.*/
		return operations;
	}
	
	operations[cursor]='-';
	find_operations(arr,expected_val,operations,arr_len,cursor+1,current-arr[cursor+1]);

	if(expected_val==current-arr[cursor+1] && cursor!=0){	/*If we reached the expected value and the cursor is not zero then we are returning one more back.*/
		operations[cursor]='-';
		return operations;
	}
	if(operations[arr_len-2]!=' '){	/*If the last member of operations is not empty and we are returning one more back.*/
		return operations;
	}
	

	operations[cursor]='*';
	find_operations(arr,expected_val,operations,arr_len,cursor+1,current*arr[cursor+1]);

	if(expected_val==current*arr[cursor+1] && cursor!=0){	/*If we reached the expected value and the cursor is not zero then we are returning one more back.*/
		
		operations[cursor]='*';
		return operations;
	}
	if(operations[arr_len-2]!=' '){	/*If the last member of operations is not empty and we are returning one more back.*/
		
		return operations;
	}

	
	if(cursor==0){	/*If we are at the end of the function and  we couldnt reach the expected value then we are returning back (arr_len-1) empty string.*/

		for(i=0;i<arr_len-1;i++){
			operations[i]=' ';
		}
		return operations;
	}

}

int main()
{
	int i;
	int arr[6]={25,12,6,10,32,8};	/*Initializing the array.*/
	int expected_val=44;		
	char operations[5];			
	size_t arr_len=6;

	printf("Array : ");
	for(i=0;i<arr_len;i++){
		printf("%d ",arr[i]);
	}

	printf("\nExpected Value : %d ",expected_val);

	printf("\noperations :%s\n",find_operations(arr,expected_val,operations,arr_len,0,arr[0]));

	return 0;
}
