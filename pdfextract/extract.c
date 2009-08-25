#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define PDF pdftk

int main(int argc, char const* argv[]){
	FILE *fi;
	char buf[1000],fname[100],*s,tmp[1000];
	int start,end,i;

	if (argc<2){
		printf("Usage: %s filename list [page_offset]\n",argv[0]);
		return 0;
	}
	if (!strcmp(argv[1],"--help")){
		printf("Usage: %s filename list [page_offset]\n",argv[0]);
		printf("Page offset is by default 0.\n");
		return 0;
	}

	if (!(fi=fopen("pdftk.exe","r"))){
		printf("Cannot not find pdftk.\n");
		return 0;
	}
	fclose(fi);
	if (!(fi=fopen(argv[1],"r"))){
		printf("Error: Cannot open pdf file.\n");
		return 0;
	}
	fclose(fi);
	if (!(fi=fopen(argv[2],"r"))){
		printf("Errpr: Cannot open csv file.\n");
		return 0;
	}

	fgets(buf,1000,fi);
	while (!feof(fi)){
		if (!fgets(buf,1000,fi)) break;
		s=strtok(buf,",");
		strcpy(fname,s);
		s=strtok(0,",");
		sscanf(s,"%d",&start);
		s=strtok(0,",");
		sscanf(s,"%d",&end);
		strcpy(tmp,argv[1]);
		tmp[strlen(tmp)-4]='\0';
		sprintf(buf,"pdftk.exe \"%s\" cat %d-%d output \"%s, %s.pdf\"",argv[1],start,end,tmp,fname);
		printf("Extracting: %s\n",fname);
		//printf("%s\n",buf);
		system(buf);

	}
	fclose(fi);
	return 0;
}

