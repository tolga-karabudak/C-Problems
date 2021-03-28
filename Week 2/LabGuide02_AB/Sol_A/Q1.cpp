//CENG104 LG02/A - Author: Evren

#include <stdio.h>

#define SIZE 10
#define prof 0.3
#define jury 0.5
#define grd 0.2

typedef struct {
	int englishProficiency, jurygrd, graduateExam;
} grades_t;

typedef struct {
	int id;
	grades_t gr;
	double overall;
} applicantsOfCENG;

int readFile(FILE *fp, applicantsOfCENG *app);
void calculate(applicantsOfCENG *app, int count);
void display(applicantsOfCENG *app, int count);
void findPassFail(applicantsOfCENG *app, int count);


int main()
{
	FILE *fp = fopen("applicants.txt", "r");
	applicantsOfCENG app[SIZE];
	int count;

	if (fp == NULL)
		printf("The file students.txt couldn't be opened.\n");
	else
	{
		count = readFile(fp, app);

		fclose(fp);

		calculate(app, count);

		display(app, count);

		findPassFail(app, count);
	}

	return 0;
}

int readFile(FILE *fp, applicantsOfCENG *stu)
{
	int count = 0;

	while (fscanf(fp, "%d %d %d %d", &(stu + count)->id, &(stu + count)->gr.englishProficiency, &(stu + count)->gr.jurygrd, &(stu + count)->gr.graduateExam) != EOF)
	{
		(stu + count)->overall = 0;
		count++;
	}

	return count;
}

void calculate(applicantsOfCENG *app, int count)
{
	for (int i = 0; i < count; i++)
		(app + i)->overall = (app + i)->gr.englishProficiency * prof + (app + i)->gr.jurygrd * jury + (app + i)->gr.graduateExam * grd;
}

void display(applicantsOfCENG *app, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Applicant ID: %d\n\nScores:\n", (app + i)->id);
		printf("Applicant English Proficiency: %d\n", (app + i)->gr.englishProficiency);
		printf("Applicant Jury: %d\n", (app + i)->gr.jurygrd);
		printf("Applicant Graduate Examination: %d\n", (app + i)->gr.graduateExam);
		printf("Applicant Overall: %0.1f\n\n", (app + i)->overall);
	}
}

void findPassFail(applicantsOfCENG *app, int count)
{
	double avg = 0;
	int i, countSuccess = 0, countFailure = 0;

	for (i = 0; i < count; i++)
		avg += (app + i)->overall;

	avg /= count;

	for (i = 0; i < count; i++)
		if ((app + i)->overall > avg)
			countSuccess++;
		else
			countFailure++;

	printf("Average is %0.1f\nNumber of the applicants who pass is %d\nNumber of the applicants who fail is %d\n", avg, countSuccess, countFailure);
}