#include<stdio.h>
#define MAX 100

typedef struct{
	double mt1, mt2, final;
}exams;
typedef struct{
	
	int id;
	exams points;
	double overall;
}student;

double overall_grd(student *std,exams *per)
{	
	return((std->points.mt1*per->mt1)+(std->points.mt2*per->mt2)+(std->points.final*per->final));
}
double avg_exams(student std1[MAX], int number,int ex)
{	double avg=0;	
	if(ex==1)
	{
		for(int i=0;i<number;i++)
		{
			avg+=(*(std1+i)).points.mt1;
		}
	}
	else if(ex==2)
	{
		for(int i=0;i<number;i++)
		{
			avg+=(*(std1+i)).points.mt2;
		}
	}
	else if(ex==3)
	{
		for(int i=0;i<number;i++)
		{
			avg+=(*(std1+i)).points.final;
		}
	}
	return avg/number;
}
int max_grd(student std1[MAX],int number)
{
	int max=0;
	for(int i=0;i<number;i++)
	{
		if((*(std1+i+1)).overall>(*(std1+i)).overall)
			max=i+1;
	}
	return max;
}
int main()
{
	int number;
	printf("Write student number: ");
	scanf("%d",&number);
	student stdnts[number];
	exams sum={0}, avg, per = {0.25, 0.35, 0.4};	
	FILE *inp, *output;
	
	inp=fopen("grades.txt","r");
	if(inp==NULL)
		printf("File can not opened!!\n");
	else
	{
		output=fopen("overall.txt","w");
		for(int i=0;i<number;i++)
		{
			fscanf(inp,"%d %lf %lf %lf",&stdnts[i].id, &stdnts[i].points.mt1, &stdnts[i].points.mt2, &stdnts[i].points.final);
			stdnts[i].overall=overall_grd(&stdnts[i],&per);
			fprintf(output,"%-5d  student point is %2.2lf\n",(stdnts+i)->id,(stdnts+i)->overall);
		}
	}	
	fprintf(output,"Avg of Midterm1 : %.2lf \n",avg_exams(stdnts,number,1));
	fprintf(output,"Avg of Midterm2 : %.2lf \n",avg_exams(stdnts,number,2));
	fprintf(output,"Avg of Final    : %.2lf \n",avg_exams(stdnts,number,3));
	fprintf(output,"Maximum overall grade = %.2lf\n",(stdnts+(max_grd(stdnts,number)))->overall);
	fprintf(output,"Student with ID %d got that grade.\n",(stdnts+max_grd(stdnts,number))->id);
	fclose(output);			
}
