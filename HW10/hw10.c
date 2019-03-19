#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{	/*Linked List olusturmak icin olusturdugumuz struct yapisi.*/
	int val;
	struct node * next;
}Node;


int isPrime(int num){	/*Gelen sayinin asal olup olmadigini donduren fonksiyon.*/

	int i;

	if(num==0){	/*Sayi 0 sa asal degildir.Sayilarimiz arasinda 0 yok ama yinede kontrolunu yaptik.*/
		return 0;
	}

	for(i=2;i<num;i++){
		if(num%i==0){
			return 0;
		}
	}

	return 1;
}

void read_Array(int *arr){	/*Bu fonksiyon sayesinde bir array icin yer ayirip o arrayi data.txtdeki sayilarla dolduruyoruz.*/
							/*Daha sonra bu sayilardan asal olanlari output_prime_dynamic_array.txt dosyasina yazdiriyoruz.*/
	FILE *fp;
	fp = fopen("data.txt","r");
	int i;
	double written_time;

	arr = (int*)malloc(1000000*sizeof(int));	/*Array icin yer ayiriyoruz.*/

	clock_t start = clock();	/*Yazma suresini hesaplmak icin saati baslatiyoruz.(Written Time)*/

	for(i=0;i<1000000;i++)
		fscanf(fp,"%d,00\n",&arr[i]);	/*Arrayin elemanlarini data.txtden dolduruyoruz.*/

	clock_t end = clock();	/*Yazma suresi hesabı icin saat duruyor.*/


	fclose(fp);

	
	FILE *fp2;
	fp2 = fopen("output_prime_dynamic_array.txt","w");	/*Yazmak icin dosyamizi aciyoruz.*/
	
	double time;
	clock_t before = clock();
	clock_t end1,end2,end3;
	
	for(i=0;i<1000000;i++){
		if(isPrime(arr[i])==1){	/*Sayi asalsa dosyaya yaziyoruz.*/
			fprintf(fp2,"%d,00\n",arr[i]);
		}
		if(i==500000){	/*500.000 e gelince zamani olcuyoruz.*/
			end1 = clock();
			
		}
		if(i==750000){	/*750.000 e gelince zamani olcuyoruz.*/
			end2 = clock();
		}
	}
	end3 = clock();	/*1.000.000 icin zamani tutuyoruz.*/

	
	written_time = (double)(end - start)/CLOCKS_PER_SEC;	/*Arrayin dosyaya yazdirilma zamanini hesapliyoruz.*/
	printf("Dinamik array icin sayilarin yazdirilma zamani(written time) : %.2lf milisaniye\n",written_time*1000);
	fprintf(fp2,"Dinamik array icin sayilarin yazdirilma zamani(written time) : %.2lf milisaniye\n",written_time*1000);
	
	time = (double)(end1-before)/CLOCKS_PER_SEC;
	printf("Dinamik array icin 1 ile 500.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	fprintf(fp2,"Dinamik array icin 1 ile 500.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	
	time = (double)(end2-before)/CLOCKS_PER_SEC;
	printf("Dinamik array icin 1 ile 750.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	fprintf(fp2,"Dinamik array icin 1 ile 750.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	
	time = (double)(end3-before)/CLOCKS_PER_SEC;
	printf("Dinamik array icin 1 ile 1.000.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	fprintf(fp2,"Dinamik array icin 1 ile 1.000.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	
	fclose(fp);	/*Dosyalari kapatiyoruz.*/
	fclose(fp2);

	free(arr);

	
}

void read_Linkedlist(Node *head){	/*Bu fonksiyon sayesinde bir linked list yapisi olusturuyoruz ve bu linked list i data.txtdeki sayilarla dolduruyoruz.*/
									/*Bu sayilardan asal olanlari output_prime_LinkedList.txt dosyasina yazdiriyoruz.*/
	FILE *fp;
	fp = fopen("data.txt","r");	/*Data.txt den okumak icin dosyayi aciyoruz.*/
	int i;
	
	
	head = (Node*)malloc(sizeof(Node));	/*Memoryde head icin yer ayiriyoruz.*/

	Node *current = head;	/*Bir iterator yani linked listte gezmemizi sagliyan pointer yapisi olusturuyoruz ve head i buna atiyoruz.*/

	double written_time;
	clock_t start = clock();

	for(i=0;i<1000000;i++){	/*Linked list  yapisinin sirayla elemanlarini dolduruyoruz.*/
		fscanf(fp,"%d,00\n",&current->val);
		current->next = (Node*)malloc(sizeof(Node));
		current = current->next;
		current->next = NULL;
	}

	clock_t end = clock();

	FILE *fp2;
	fp2 = fopen("output_prime_LinkedList.txt","w");	/*Yazmak icin dosyamizi aciyoruz.*/

	double time;
	i=1;
	clock_t before = clock();
	clock_t end1,end2,end3;

	while(head!=NULL){
		if(isPrime(head->val)==1){	/*Eger deger asalsa dosyaya yaziyoruz.*/
			fprintf(fp2,"%d,00\n",head->val);
		}
		if(i==500000){
			end1=clock();
		}
		if(i==750000){
			end2=clock();
		}
		head=head->next;
		i++;
	}

	end3 = clock();

	written_time = (double)(end - start)/CLOCKS_PER_SEC;	/*Yazdirilma vaktini hesapliyoruz.*/
	printf("Linked List icin sayilarin yazdirilma zamani(written time) : %.2lf milisaniye\n",written_time*1000);
	fprintf(fp2,"Linked List icin sayilarin yazdirilma zamani(written time) : %.2lf milisaniye\n",written_time*1000);
	
	time = (double)(end1-before)/CLOCKS_PER_SEC;
	printf("Linked List icin 1 ile 500.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	fprintf(fp2,"Linked List icin 1 ile 500.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	
	time = (double)(end2-before)/CLOCKS_PER_SEC;
	printf("Linked List icin 1 ile 750.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	fprintf(fp2,"Linked List icin 1 ile 750.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	
	time = (double)(end3-before)/CLOCKS_PER_SEC;
	printf("Linked List icin 1 ile 1.000.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);
	fprintf(fp2,"Linked List icin 1 ile 1.000.000 arasi zaman hesabi : %.2lf milisaniye\n",time*1000);

	fclose(fp);	/*Dosyalari kapatiyoruz.*/
	fclose(fp2);

}
 
int main(){

	int *arr;
	Node *head;


	read_Linkedlist(head);	
	printf("\n");
	read_Array(arr);
	

	return 0;
	
}
