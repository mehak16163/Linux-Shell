//implementation of cat command 
// -n option and -E option
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc , char * argv[]){
	int append_doll=0;
	int append_num=0;
	for(int i=0;i<argc;i++){
		char (*arg)[40] = argv[i];
		int len = strlen(arg[0]);
		if (arg[0][0]=='\"' &&	 arg[0][len-1]!='\"'){//checking for corner cases.
			printf("Please give correct options.\n");
			return 0;
		}
	}
	char (*arg)[20] = argv[1];
	if (arg[0][0]=='\"'){
		if (arg[0][1]=='-' && arg[0][2]=='n' ){//checking for options
			if (arg[0][4]=='\0')
				append_num = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}

		}
		else if (arg[0][1]=='-' && arg[0][2]=='E' ){
			if (arg[0][4]=='\0')
				append_doll = 1;
			else{
				printf("please enter correct options.\n");
				return 0;}
		}
	}
	else{
		if (arg[0][0]=='-' && arg[0][1]=='n' ){
			if (arg[0][2]=='\0')
				append_num = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}


		}
		else if (arg[0][0]=='-' && arg[0][1]=='E'){
			if (arg[0][2]=='\0')
				append_doll = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}
		}
	}
		int line =1;
		if (append_num){
			printf("1. ");
		}
		FILE *fptr;
		char *filename;
		char  ch;
		int j=0;
		if (append_num || append_doll)
			j=2;
		else j=1;
		for (j;j<argc;j++){
		char (*arg)[10]=argv[j];
		filename = arg[0];
		fptr = fopen(filename,"r");
		if (fptr==NULL){
			printf("Please enter the correct file name.\n");
			return 0;
		}
		ch = fgetc(fptr);
		
    	while (ch != EOF){
    		if(ch=='\n'){
    			line++;
    			if (append_num){
    				printf("%c%i. ",ch,line);
    			}
    			else if(append_doll){
    				printf("$%c",ch);
    			}
    			else
    				printf("%c",ch);
    		}
			else
				printf ("%c", ch);	
        	ch = fgetc(fptr);
    	}
    	fclose(fptr);
    }
	return 0;
}