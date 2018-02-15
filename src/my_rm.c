//implementation of rm command, -i and -v option. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc , char * argv[]){
	int ask = 0;
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
		if (arg[0][1]=='-' && arg[0][2]=='i' ){//checking for options
			if (arg[0][4]=='\0')
				ask = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}

		}
		else if (arg[0][1]=='-' && arg[0][2]=='v' ){
			if (arg[0][4]=='\0')
				ver = 1;
			else{
				printf("please enter correct options.\n");
				return 0;}
		}
	}
	else{
		if (arg[0][0]=='-' && arg[0][1]=='i' ){
			if (arg[0][2]=='\0')
				ask = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}


		}
		else if (arg[0][0]=='-' && arg[0][1]=='v'){
			if (arg[0][2]=='\0')
				ver = 1;
			else{
				printf("please enter correct options.\n");
				return 0;
			}
		}
	}
	int j=1;
	if (ver || ask)
		j=2;
	for (j;j<argc;j++){		
		char *filename;
		char (*arg)[20]=argv[j];
		filename = arg[0];
		if(ver){
			if(remove(filename)==0){
				printf("removed %s.\n",filename);
			}
			else{
				printf("%s does not exist.\n",filename);
			}
		}
		else if(ask){
			printf("Remove file %s?\n",filename);
			char ans[10];
			scanf("%s",ans);
			if (ans[0]=='y'){
				if(remove(filename)==0){
					printf("\n");
				}
				else{
					printf("%s does not exist.\n",filename);
				}
			}
		}
		else{
			if(remove(filename)!=0){
				printf("%s does not exist.\n",filename);
			}
		}
		
	}
	return 0;
}