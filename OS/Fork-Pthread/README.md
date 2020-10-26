
**Fork()** <br/>
```
int main(int argc , char* argv[]){
	pid_t pid;
	printf("Process fork!!\n");	
	pid = fork();

	int signal;
	if(pid<0){
		printf("Fork Failed!");
		return 1;
	}
	else if(pid==0){
		printf("Child process executes Test program!!\n");
		printf("Hello I'm parent process , my pid = %d\n\n",getppid());
		execvp(argv[1],argv);
	}
	else{
		wait(&signal);
		printf("Receving the SIHCHLD signal\n\n");
		if(WIFEXITED(signal)!=0){//Normal Exit
			printf("Normal termination with exit status = %d\n\n",WEXITSTATUS(signal));
		}
		else{//Abnormal Exit
			check_signal(WTERMSIG(signal));
		}
	}
	
	return 0;
}
```