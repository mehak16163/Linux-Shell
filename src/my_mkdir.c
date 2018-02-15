//--version -v 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc , char *argv[]){
	int veb=0;
	int ver =0;
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
		if (arg[0][1]=='-' && arg[0][2]=='v' ){//checking for options
			if (arg[0][4]=='\0')
				veb = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}

		}
		else if (arg[0][1]=='-' && arg[0][2]=='-' ){
			if (arg[0][11]=='\0')
				ver= 1;
			else{
				printf("please enter correct options.\n");
				return 0;}
		}
	}
	else{
		if (arg[0][0]=='-' && arg[0][1]=='v' ){
			if (arg[0][2]=='\0')
				veb = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}


		}
		else if (arg[0][0]=='-' && arg[0][1]=='-'){
			if (arg[0][9]=='\0')
				ver = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}
		}
	}
	if(ver){
		printf("mkdir (GNU coreutils) 8.25\nCopyright (C) 2016 Free Software Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\nWritten by David MacKenzie.");
		printf("\n");
		return 0;
	}
	else{
		int j=1;
		if (veb)
			j++;
		for(j;j<argc;j++){
			char (*arg)[10]=argv[j];
			struct stat st = {0};
			if (stat(arg[0], &st) == -1) {
    			mkdir(arg[0], 0700);
			}
			if (veb){
				printf("mkdir: %s is created.\n",arg[0]);
			}
		}
	}
	return 0;
}