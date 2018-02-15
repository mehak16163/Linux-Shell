//Implementation of ls command 
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
void reverse(char *arr[],int size){//for option -r
	for(int j = 0;j<=size;j++){
		printf("%s ",arr[j]);
	}
	printf("\n");
}

char * column(char *arr[] , int size){//for option -C
	for (int j=size;j>=0;j--){
		printf("%s\n",arr[j]);
	}
}
int compare_words(const void *p, const void *q) {//comparator for qsort
    return strcmp(*(const char**)q, *(const char**)p);
}

int main(int argc , char *argv[]){//takes argument from user
	DIR *d;
	struct dirent  *dir;
	int rev =0;
	int col = 0;
	for(int i=0;i<argc;i++){
		char (*arg)[20] = argv[i];
		int len = strlen(arg[0]);
		//printf("%", arg[i][0]);
		if (arg[0][0]=='\"' &&	 arg[0][len-1]!='\"'){//checking for corner cases.
			printf("Please give correct options.\n");
			return 0;
		}
	}
	if (argc!=1){
	char (*arg)[20] = argv[1];
	if (arg[0][0]=='\"'){
		if (arg[0][1]=='-' && arg[0][2]=='r' ){//checking for options
			if (arg[0][4]=='\0')
				rev = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}

		}
		else if (arg[0][1]=='-' && arg[0][2]=='C' ){
			if (arg[0][4]=='\0')
				col = 1;
			else{
				printf("please enter correct options.\n");
				return 0;}
		}
	}
	else{
		if (arg[0][0]=='-' && arg[0][1]=='r' ){
			if (arg[0][2]=='\0')
				rev = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}


		}
		else if (arg[0][0]=='-' && arg[0][1]=='C'){
			if (arg[0][2]=='\0')
				col = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}
		}
	}
}

	int op =0;
	if (rev){
		op++;
	}
	if (col){
		op++;
	}
	if (argc==op+1){
		char s[2] = {'.','\0'};
		d = opendir(s);
	}
	else
	{char* directory = argv[op+1];//getting the name of the directory.
	printf("%s\n",directory); 
	d = opendir(directory);}
	char *files[200]; 
	int j=0;
	if (d){
		while((dir = readdir(d))!=NULL ){//storing the names of files in the directory. 
			if (!strcmp(dir->d_name , "..") || !strcmp(dir->d_name,".")){
				continue;
			}
			files[j]= dir-> d_name;
			j++;
		}
		files[j]=NULL;
		closedir(d);
	}
	qsort(files, j-1, sizeof(char*), compare_words);//sorts the files lexographically
	
		if (rev){
			reverse(files , j-1);
		}
		else if (col){
			column(files , j-1);
		}
		else{//printing when no options are specified.
			for(int i=j-1;i>=0;i--){
				printf("%s ",files[i]);
			}
			printf("\n");
		}
	return 0;
}