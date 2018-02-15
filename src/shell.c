#include <stdio.h>
#include <string.h>
#include <unistd.h>

int exit(char *ptr){
	while(*ptr == ' '){
		ptr++;
	}
	char *b = "exit";
	for(int i=0;i<4;i++){
		if (*b==*ptr){
			b++;
			ptr++;
			continue;
		}
		else {
			return 0;
		}
	}
	if (*ptr=='\0' || *ptr == ' '){
		return 1;
	}
	else
		return 0;
}
int cd(char *ptr){
	while(*ptr == ' '){
		ptr++;
	}
	char *b = "cd";
	for(int i=0;i<2;i++){
		if (*b==*ptr){
			b++;
			ptr++;
			continue;
		}
		else {
			return 0;
		}
	}
	if (*ptr=='\0' || *ptr == ' '){
		return 1;
	}
	else
		return 0;
}

int echo(char *ptr){
while(*ptr == ' '){
			ptr++;
		}
		char *b = "echo";
		for(int i=0;i<4;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int pwd(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "pwd";
		for(int i=0;i<3;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int history(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "history";
		for(int i=0;i<7;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int mkdir(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "mkdir";
		for(int i=0;i<5;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int rm(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "rm";
		for(int i=0;i<2;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int cat(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "cat";
		for(int i=0;i<3;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int ls(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "ls";
		for(int i=0;i<2;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int date(char *ptr){
	while(*ptr == ' '){
			ptr++;
		}
		char *b = "date";
		for(int i=0;i<4;i++){
			if (*b==*ptr){
				b++;
				ptr++;
				continue;
			}
			else {
				return 0;
			}
		}
		if (*ptr=='\0' || *ptr == ' '){
			return 1;
		}
		else
			return 0;
}
int main(){
	char *arg[20];
	FILE *hist;
	hist = fopen("history.txt","a");

	while (1){
		printf("%s $ ",get_current_dir_name());
		char *b[200];
		scanf("%[^\n]%*c",b );
		fprintf(hist,"%s\n",b);
		if (exit(b)){
            break;
		}
		else if (pwd(b)){
			printf("%s\n",get_current_dir_name());
			continue;
		}
		char *command; 
		command = strtok(b," ");
		int i=0;
		while(i<20 && command!=NULL){
			arg[i]=command;
			command = strtok(NULL," ");
			i++;
		}
		arg[i]=NULL;
		for(int j=0;j<strlen(arg[0]);j++){
			if(arg[0][j]=='\n'){
				arg[0][j]='\0';
			}
		}
		if (cd(arg[0])){
			chdir(arg[1]);
			continue;
		}
		else if (echo(arg[0])){
			if (i=1){
				printf("\n");
			}
			if(!strcmp("-e",arg[1])){
				for(int k=2;k<i;k++){
					char w[strlen(arg[k])];
					int y=0;
					for(int b=0;b<strlen(arg[k]);b++){
						if(arg[k][b]=='\\'){
							b++;
							if(b==strlen(arg[k])){
								printf("Please enter correct options.\n");
							}
							else{
								if(arg[k][b]=='n'){

									w[y]='\n';
									y++;
								}
								else if(arg[k][b]=='b'){
									if(y>0){
										y--;
										w[y]='\0';
									}
								}
								else if(arg[k][b]=='t'){
									w[y]='\t';
									y++;
								}
								else if(arg[k][b]=='\\'){
									w[y]='\\';
									y++;
								}

							}
						}
						else{
							w[y]=arg[k][b];
							y++;
						}
					}
					w[y]='\0';
					printf("%s ",w);
				}
				printf("\n");
				continue;
			}
			if (!strcmp("-n",arg[1])){
				for(int k=2;k<i;k++){
					if (k==i-1){
						printf("%s",arg[k]);
						continue;
					}
					printf("%s ",arg[k]);
				}
				continue;
			}
			else{
				for(int k=1;k<i;k++){
					printf("%s ",arg[k]);
				}
				printf("\n");
				continue;
			}
		}
		else if(history(arg[0]) && i!=1){
			if (!strcmp(arg[1],"-c")){
				fclose(hist);
				fclose(fopen("history.txt", "w"));
				hist = fopen("history.txt","a");
				continue;
			}
			else if (!strcmp(arg[1],"-r")){
				FILE *histo;
				histo = fopen(arg[2],"r");
				if (histo==NULL){
					printf("Please enter correct file name.\n");
				} 
				else{
					char ch;
					ch = fgetc(histo);
					while(ch!=EOF){
						fprintf(hist,"%c",ch);
						ch = fgetc(histo);
					}
				}
				continue;
			}
		}
			else if (history(arg[0])){
				int line =1;
				printf("%i. ",line);
				fclose(hist);
				FILE *histo ;
				histo = fopen("history.txt","r");
				char ch = fgetc(histo);
				while(ch!=EOF){
					if (ch=='\n'){
						char ch1 = fgetc(histo);
						if(ch1 !=EOF){
							line++;
							printf("%c%i. %c",ch , line,ch1);
						}
						else{
							printf("\n");
						}
					}
					else{
						printf("%c",ch);
					}
					ch = fgetc(histo);
				}
				fclose(histo);
				hist = fopen("history.txt","a");
				continue;

			}
		
		else if (fork()==0){
			if(mkdir(arg[0])){
				execvp("/home/mehak/Desktop/Semester-4/Operating Systems/HW/my_mkdir",arg);
				exit(0);
			}
			else if(rm(arg[0])){
				execvp("/home/mehak/Desktop/Semester-4/Operating Systems/HW/my_rm",arg);
				exit(0);
			}
			else if(ls(arg[0])){
				execvp("/home/mehak/Desktop/Semester-4/Operating Systems/HW/my_ls",arg);
				exit(0);
			}	
			else if(cat(arg[0])){
				execvp("/home/mehak/Desktop/Semester-4/Operating Systems/HW/my_cat",arg);
				exit(0);
			}
			else if(date(arg[0])){
				execvp("/home/mehak/Desktop/Semester-4/Operating Systems/HW/my_date",arg);
				exit(0);
			}		
		}
		else{
			wait(NULL);
		}
	}
	fclose(hist);
	return 0;
}