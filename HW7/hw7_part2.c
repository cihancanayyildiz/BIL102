#include <stdio.h>

/*Verilen tarihleri dosyaya araligiyla birlikte yazmamizi saglayan fonksiyon.*/

void generate_date(char start_date[],char end_date[]){

	FILE * dates;

	dates = fopen("input_date.txt","w");	/*Yazdirma dosyamizi aciyoruz.*/


	/*Verilen tarihlerin integer degere donusturulmesi*/

	int first_day=(start_date[0]-'0')*10+start_date[1]-'0';
	int first_month=(start_date[3]-'0')*10+start_date[4]-'0';
	int first_year=(start_date[6]-'0')*1000+(start_date[7]-'0')*100+(start_date[8]-'0')*10+start_date[9]-'0';
	int end_day=(end_date[0]-'0')*10+end_date[1]-'0';
	int end_month=(end_date[3]-'0')*10+end_date[4]-'0';
	int end_year=(end_date[6]-'0')*1000+(end_date[7]-'0')*100+(end_date[8]-'0')*10+end_date[9]-'0';
	


	while(!(first_day==end_day && first_month==end_month && first_year==end_year)){/*Verilen tarihler birbirine esit olunca dongu duracak*/

		if(first_month==1 || first_month==3 || first_month==5 || first_month==7 || first_month==8 || first_month==10 || first_month==12){ /*31 ceken aylarin bulundugu if blogu.*/
			if(first_day==31){
				if(first_month<10){
					fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
				}
				else{
					fprintf(dates,"%d/%d/%d\n",first_day,first_month,first_year);
				}
				
				if(first_month==12){ /*Eger ay 12. aya geldiyse  ve gün son günse bir sonraki aya yani 1.aya gecilir ve yil artar.*/
					first_year++;
					first_month=1;
					first_day=1;
				}
				else{
					first_month++;
					first_day=1;
				}
			}
			
			else if(first_day<10){ /* Eger gunler 10dan kucukse basina 0 koymayi duzenliyoruz.*/
				if(first_month<10){
					fprintf(dates,"0%d/0%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
				else{
					fprintf(dates,"0%d/%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
			}
			else{
				if(first_month<10){ /* Eger gunler 10dan kucukse basina 0 koymayi duzenliyoruz.*/
					fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
				else{
					fprintf(dates,"%d/%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
			}
		}

		else if(first_month==4 || first_month==6 || first_month==9 || first_month==11 ){ /* 30 ceken aylarin bulundugu if blogu.*/
			
			if(first_day==30){
				
				if(first_month<10){
					fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
				}
				else{
					fprintf(dates,"%d/%d/%d\n",first_day,first_month,first_year);
				}
				
				first_month++;
				first_day=1;
			}
			
			else if(first_day<10){
				if(first_month<10){
					fprintf(dates,"0%d/0%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
				else{
					fprintf(dates,"0%d/%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
			}
			else{
				if(first_month<10){
					fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
				else{
					fprintf(dates,"%d/%d/%d\n",first_day,first_month,first_year);
					first_day++;
				}
			}
			
		}

		else if(first_month==2){ /*Subat ayi icin ayri bir if blogu */
			if(first_year%4==0){ /* Eger ayrik yilsa subat ayi 29 cekecek.*/
				if(first_day==29){
					fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
					first_month++;
					first_day=1;
				}
				else{
					if(first_day<10){
						fprintf(dates,"0%d/0%d/%d\n",first_day,first_month,first_year);
						first_day++;
						
					}
					else{
						fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
						first_day++;
					}
				}

			}
			else{
				if(first_day==28){
					fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
					first_month++;
					first_day=1;
				}
				else{
					if(first_day<10){
						fprintf(dates,"0%d/0%d/%d\n",first_day,first_month,first_year);
						first_day++;
						
					}
					else{
						fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
						first_day++;
					}
				}
			}
		}
	}
	
	if(first_day<10){
				if(first_month<10){
					fprintf(dates,"0%d/0%d/%d\n",first_day,first_month,first_year);
				}
				else{
					fprintf(dates,"0%d/%d/%d\n",first_day,first_month,first_year);
				}
	}
	else{
		if(first_month<10){
			fprintf(dates,"%d/0%d/%d\n",first_day,first_month,first_year);
		}
		else{
			fprintf(dates,"%d/%d/%d\n",first_day,first_month,first_year);
		}
	}

	fclose(dates);	
	
}

/*Verilen tarihleri gununu bulup istenen sekle soktugumuz fonksiyon yani part 2 nin 2. kismi.*/

void new_dates(){
	FILE *fin;
	FILE *fin2;

	int k=0,i,j;
	char line[1024];
	int day,month,year;
	int day_cal,result;
	int months[12];/*Aylarin ozel hesaplarini tuttugumuz array.*/
	char monthsname[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int days[7]={0,1,2,3,4,5,6};/*Cumartesi gunu 0 dan baslicak sekilde gunleri dizdigimiz array.*/
	char daysname[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};


	fin=fopen("new_dates.txt","w");
	fin2=fopen("input_date.txt","r");

	while(fgets(line,1024,fin2)!=NULL){
		
		day=(line[0]-'0')*10+line[1]-'0';
		month=(line[3]-'0')*10+line[4]-'0';
		year=(line[6]-'0')*1000+(line[7]-'0')*100+(line[8]-'0')*10+line[9]-'0';

		for(j=0;j<12;j++){

			/*Artik yil kontrolunu ve hesaplarini yaptigimiz if bloklari.*/
			if((year % 100 == 0) && (year % 400 != 0)){

				months[j]=3 + 2  * (((j+1) + 2) / (2 * (j+1))) + (5 * (j+1) + (j+1) / 9) / 2;
				months[j] %= 7;

			}
			else if(year%4==0){
				months[j]=3 + 1  * (((j+1) + 2) / (2 * (j+1))) + (5 * (j+1) + (j+1) / 9) / 2;
				months[j] %= 7;
			}
			else{
				months[j]=3 + 2  * (((j+1) + 2) / (2 * (j+1))) + (5 * (j+1) + (j+1) / 9) / 2;
				months[j] %= 7;
			}

		}


		/*Gun hesaplamasini yaptigimiz for dongusu.*/
		for(j=0;j<12;j++){
			if(month==j+1){
				day_cal = 1.25 * (year%100) + months[j] + day - 2 * ((year/100) % 4);
				day_cal %= 7;
				break;
			}
		}

		
		/*Buldugumuz gunleri dosyaya yazdirdigimiz for dongusu.*/
		for(i=0;i<7;i++){
			if(days[i]==day_cal){
				fprintf(fin,"%s,%s %d,%d\n",daysname[i],monthsname[month-1],day,year);
				break;
			}
		}

	}

	fclose(fin);	/*Actigimiz dosyalari kapatiyoruz.*/
	fclose(fin2);

}

int main(){
	/*Kullanicidan aldigimiz stringler.*/
	char str1[15];
	char str2[15];

	printf("Baslangic tarihini giriniz.(dd/MM/yyyy) \n"); 
	scanf("%s",str1);	/* Tarihler  dd/MM/yyyy formatinda girilmelidir.*/
	printf("Bitis tarihini giriniz. (dd/MM/yyyy)\n");
	scanf("%s",str2);	/* Tarihler  dd/MM/yyyy formatinda girilmelidir.*/

	generate_date(str1,str2);
	new_dates();

	return 0;
}
