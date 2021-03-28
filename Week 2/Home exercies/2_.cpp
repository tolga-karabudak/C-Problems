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





int main()
{
	student stdnts[75];
	exams sum={0}, avg, per = {0.25, 0.35, 0.4};
	int max_std;
	
	FILE *inp, *output;
	
	inp=fopen("grades.txt","r");
	if(inp==NULL)
		printf("File can not opened!!\n");
	else
	{
		output=fopen("overall.txt","w");
		for(int i=0;i<4;i++)
		{
			fscanf(inp,"%d %lf %lf %lf",&stdnts[i].id, &stdnts[i].points.mt1, &stdnts[i].points.mt2, &stdnts[i].points.final);
			stdnts[i].overall=overall_grd(&stdnts[i],&per);
			fprintf(output,"%d  student point is %2.2lf\n",stdnts[i].id,stdnts[i].overall);
		}
		
		for(int i=0;i<4;i++)
		{
			sum.mt1+=stdnts[i].points.mt1;
			sum.mt2+=stdnts[i].points.mt2;
			sum.final+=stdnts[i].points.final;
		}
		avg.mt1=sum.mt1/4;
		avg.mt2=sum.mt2/4;
		avg.final=sum.final/4;
		fprintf(output,"Avg of Midterm1 : %.2lf \n",avg.mt1);
		fprintf(output,"Avg of Midterm2 : %.2lf \n",avg.mt2);
		fprintf(output,"Avg of Final : %.2lf \n",avg.final);
		for(int i=0;i<4;i++)
		{
			max_std=i;
			if(stdnts[i+1].overall>stdnts[i].overall)
				max_std=i+1;
		}
		fprintf(output,"Maximum overall grade = %0.2f\n",stdnts[max_std].overall);
		fprintf(output,"Student with ID %d got that grade.\n",stdnts[max_std].id);
		
	}
	fclose(inp);
	fclose(output);
	
	
	
	
}
