/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13245413/fwrite-in-c-goin-in-a-infinite-loop
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct _Employee {
     char name[20];
	 char pre_pay_date[20];
	 char pol_end_date[20];
}Employee;


void updateRecords() {
	FILE *fq;
	Employee eme;
	long int recsize_eme;
	recsize_eme=sizeof(eme);
	int err = 0;
	int i = 0;

	fq=fopen("EME.DAT","rb+");
	if(fq==NULL)
	{
		fq=fopen( "EME.DAT","wb+");
		if(fq==NULL)
		{
			printf("Can't Open File");
			exit(EXIT_FAILURE);
		}
	}

	rewind(fq);
	while(fread(&eme, recsize_eme, 1, fq) == 1){
	
		// if-branch from original posting omitted - does not impact the issue
	
		printf("-------\n%s\n", eme.name);
		snprintf(eme.name, sizeof(eme.name), "Modified%i", i++);
		printf("%s\n", eme.name);

		printf("POS: %d\n", ftell(fq));
		err = fseek(fq,-recsize_eme,SEEK_CUR);
		printf("FSEEK Err: %d\n", err);

		printf("POS: %d\n", ftell(fq));
		err = fwrite(&eme,recsize_eme,sizeof(eme)/recsize_eme,fq);
		printf("FWRITE Err: %d\n", err);
		printf("POS: %d\n", ftell(fq));

		// Flush the IO buffers. Without this call, we are ending in an endless loop.
		fflush(fq);
	}
	fclose(fq);
}

void generateEMEFile() {
	FILE *fq;
	Employee eme;
	long int recsize_eme = sizeof(eme);
	int i = 0;

	fq = fopen("EME.DAT","wb+");
	if (fq == NULL) {
		printf("Can not open dat file for writing");
		return;
	}
	for (i = 0;  i < 5;  i++) {
	
		memset(&eme, 0, recsize_eme);
		snprintf(eme.name, sizeof(eme.name), "Entry%d", i);
		snprintf(eme.pre_pay_date, sizeof(eme.pre_pay_date), "11/%02d/2012", i);
		snprintf(eme.pol_end_date, sizeof(eme.pol_end_date), "11/%02d/2012", i + 10);
		fwrite(&eme,recsize_eme,sizeof(eme)/recsize_eme,fq);
	}
	fclose(fq);
}

int main() {
	generateEMEFile();
	updateRecords();
	return 0;
}
