//-R and -u
#include <stdio.h>
#include <time.h>
#include <string.h>
void format(char *arr[]){
	printf("%s, %s %s %s %s +0530\n",arr[0],arr[2],arr[1],arr[4], arr[3]);
}
void utc(char *arr[]){
	for (int i=0;i<4;i++){
		printf("%s ",arr[i]);
	}
	printf("UTC ");
	printf("%s\n",arr[4]);
}
int main(int argc , char *argv[]) {
    time_t t = time(NULL);
    struct tm *tm1 = gmtime(&t);
    char b[64];
    strftime(b, sizeof(b), "%c", tm1);
    char *argm[10];
    int k=0;
    char * comm;
    comm = strtok(b," ");
    while(k<10 && comm!=NULL){
		argm[k]=comm;
		comm = strtok(NULL," ");
		k++;
	}
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
	char *argu[10];
	int i=0;
	char *command; 
	command = strtok(s," ");
	while(i<10 && command!=NULL){
		argu[i]=command;
		command = strtok(NULL," ");
		i++;
	}
	if (argc==1){
		for (int i=0;i<4;i++){
			printf("%s ",argu[i]);
		}
		printf("IST ");
		printf("%s\n",argu[4]);

	}
	else if (argc>2){
		printf("please enter correct options.\n");
		return 0;
	}	
	else{
		char (*arg)[20] = argv[1];
		int len = strlen(arg[0]);
		if (arg[0][0]=='\"' &&	 arg[0][len-1]!='\"'){//checking for corner cases.
			printf("Please give correct options.\n");
			return 0;
		}
		else{
			if (arg[0][0]=='\"'){
				if (arg[0][1]=='-' && arg[0][2]=='R'){
					if (arg[0][4]=='\0')
						format(argu);
					else
					{
						printf("Please enter correct options.\n");
						return 0;
					}
				}
				else if (arg[0][1]=='-' && arg[0][2]=='u'){
					if (arg[0][4]=='\0')
					 utc(argm);
					else
					{
						printf("Please enter correct options.\n");
						return 0;
					}
				}
				else{
					printf("please enter correct options.\n");
				}
			}
			else{
				if (arg[0][0]=='-' && arg[0][1]=='R'){
					if (arg[0][2]=='\0')
						format(argu);
					else
					{
						printf("Please enter correct options.\n");
						return 0;
					}
				}
				else if (arg[0][0]=='-' && arg[0][1]=='u'){
					if (arg[0][2]=='\0')
						utc(argm);
					else
					{
						printf("Please enter correct options.\n");
						return 0;
					}
				}
				else{
					printf("please enter correct options.\n");
				}
			}
		}
	}
}