// gcc -o fazua1.out fazua1.c
// rm -rf ./logs/
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>

void get_date(char * time_buf, int size);  // String with current date up to seconds
void create_dir();  // create log dir if it does not exist
char getch();  // turn off canonical mode and echo mode (not to wait for Enter)
int functional(bool time_flag);  // gets char and stores in arrays, also calls print to file when "S"
bool timer1ms();  // wait 1ms to create 1ms logs


char time_buf[50];  // Date in string

char log_1ms[100] = {0};  // Log entry written within 1ms
int ct_tmp = 0;  //  counter for log_1ms
char final_log[1000] = {0};  // Full log to be written in file
int final_counter = 0;  // counter for final_log

char key;  // Key pressed 
FILE * fPtr;  // File pointer
int ret=1;  // Exit condition

int main(int argc, char const *argv[])
{
	printf("start \n");
	bool asdf = true;
	create_dir();
	get_date(time_buf, sizeof(time_buf));
	int fd[2];

	pipe(fd);
	while(1)
	{

		int child_pid = fork();

		if(child_pid==0)
		{
			close(fd[0]);
			bool time_flag_pr1 = timer1ms(fd);
		    write(fd[1], &time_flag_pr1, sizeof(bool));
			close(fd[1]);
			exit(0);
			return 0;
		}
		else
		{
			int pid_dad = getpid();
			bool time_flag_pr0;
			close(fd[1]);
			read(fd[0], &time_flag_pr0, sizeof(bool));
			close(fd[0]);
			ret = functional(time_flag_pr0);
			if(ret==0)
			{	
				wait(NULL);
				return 0;
			}
		}

	}
	return 0;
}

// --------------------------------- //
int functional(bool time_flag)
{
	char key = getch();
	if (key==83) // ASCII for "S"
	{
		printf("saving in %s \n", time_buf);
		fPtr = fopen(time_buf, "w");
		fputs(final_log, fPtr);
		fclose(fPtr);
		return 0;
	}
	else
	{
		log_1ms[ct_tmp] = key;
		if (time_flag == true)
		{
			for (int i = 0; i < ct_tmp + 1; ++i)
			{
				final_log[final_counter] = log_1ms[i];
			}
			ct_tmp=0;
			time_flag=false;
			if (final_counter == 100)
		    {
		    	final_counter = 0;
		    }
		    else
		    {
		    	final_counter = final_counter + 1;
		    }
		}
		else
		{
			ct_tmp = ct_tmp + 1;
		}
	}
	return 1;
}

bool timer1ms()
{
	sleep(1);  //.1 for 1ms
	return true;
}

// --------------------------------- //
void get_date(char * time_buf, int size)
{
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	snprintf(time_buf, size, "./logs/%d-%02d-%02d_%02d:%02d:%02d.txt",
	 tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// --------------------------------- //
void create_dir()
{
	struct stat st = {0};

	if (stat("./logs", &st) == -1) {
	    mkdir("./logs", 0700);
	}

}

// --------------------------------- //
char getch()
{
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}
