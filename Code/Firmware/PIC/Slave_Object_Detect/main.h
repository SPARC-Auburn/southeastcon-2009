#ifndef MAIN_H
#define MAIN_H

#define SLAVE

void	high_isr 		(void);
void	high_vec 		(void);
void 	low_vec  		(void);
void 	low_isr  		(void);

void	poll_sonar		(void);

struct proc_status {
	unsigned ProcessInProgress			:1;
	unsigned sonar_poll_enabled			:1;
	
};

unsigned char current_proc;
unsigned char current_parameters[32];
unsigned char parameter_count;
