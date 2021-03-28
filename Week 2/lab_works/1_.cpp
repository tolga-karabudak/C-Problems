#include<stdio.h>

#define max 10
typedef struct{
	int englishProficiency, jury, graduateExam;
	}grades_t;

typedef struct{
	int id;
	grades_t gr;
	double overall;
}applicantsOfCeng_t;


int readFile( FILE *inp, applicantsOfCeng_t *app)
{
	
	int x;
	int status= fscanf(inp,"%d",&x);
	int i=0;
	while(status!=EOF)
	{
		(app+i)->id=x;
		status= fscanf(inp,"%d",&x);
		(app+i)->gr.englishProficiency=x;
		status= fscanf(inp,"%d",&x);
		(app+i)->gr.jury=x;
		status= fscanf(inp,"%d",&x);
		(app+i)->gr.graduateExam=x;			
		status= fscanf(inp,"%d",&x);
		i++;
	}
	
	return i;
}

void calculate(applicantsOfCeng_t app[max],int kisi)
{
	for(int i=0;i<kisi;i++)
	{
		app[i].overall=((app+i)->gr.englishProficiency*0.3)+((app+i)->gr.jury*0.5)+((app+i)->gr.graduateExam*0.2);
	}
}
void display(applicantsOfCeng_t app[max],int kisi)
{
	for(int i=0;i<kisi;i++)
	{
		printf("\nApplican id: %d",(app+i)->id);
		printf("\nEnglish Proficiency: %d",(app+i)->gr.englishProficiency);
		printf("\nJury: %d",(app+i)->gr.jury);
		printf("\nGraduate Exam: %d",(app+i)->gr.graduateExam);
		printf("\nOverall: %.1lf\n",(app+i)->overall);
		printf("\n*****************\n");
	}
}
void findPassFail(applicantsOfCeng_t app[max],int kisi, double avg)
{
	int pass=0;
	int fail=0;
	for(int i=0;i<kisi;i++)
	{
		if((app+i)->overall>avg)
			pass++;
		else
			fail++;
			
	}
	printf("Number of the applicants who pass is: %d\n",pass);
	printf("Number of the applicants who fail is: %d",fail);
	
}

int main()
{
	FILE * inp;
	inp=fopen("applicants.txt","r");
	applicantsOfCeng_t app[max];
	double avg=0;
	int kisi_sayisi=readFile(inp,app);
	
	calculate(app,kisi_sayisi);
	display(app,kisi_sayisi);
	
	for(int i=0;i<kisi_sayisi;i++)
	{
		avg+=(app+i)->overall;
	}
	avg=avg/3;
	printf("Avarage is: %.1lf\n",avg);
	findPassFail(app,kisi_sayisi,avg);


	
	
	
	
	
}
