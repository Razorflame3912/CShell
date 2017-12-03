# Project 01: CShell
## By: Mansour Elsharawy and Herman Lin


### Features

 * Forks to execute commands
 * Multi-command input
 * Basic redirection
 * Basic piping

### Attempted

 * Multiple redirection 
 * Piping using popen()

### Bugs

 * When piping (e.g. ls | wc), a second output is printed

### Files & Function Headers

**shell.c**
 * char * strsepstr()				
 *Input*: char ** string, char * delim				
 *Output*: returns pointer to string with delim replaced with NULL				
 &nbsp;&nbsp;&nbsp;&nbsp;Functions like strsep() but is able to take a string delimiter				
 
 
 * void exec_args()		
 *Input*: char * line				
 *Output*: executes arguments from line via forking when necessary				
 &nbsp;&nbsp;&nbsp;&nbsp;Parses *line* for whitespace if necessary				
 &nbsp;&nbsp;&nbsp;&nbsp;If *line* contains "exit", program exits				
 &nbsp;&nbsp;&nbsp;&nbsp;Else if *line* contains "cd", program changes directory using *chdir*				
 &nbsp;&nbsp;&nbsp;&nbsp;Forks in order to run *execvp* on the arguments given in *line*				
 
 
 * void redirout()		
 *Input*: char * line				
 *Output*: runs > command via forking				
 &nbsp;&nbsp;&nbsp;&nbsp;Takes a potential redirect command				
 &nbsp;&nbsp;&nbsp;&nbsp;Parses string for > command				
 &nbsp;&nbsp;&nbsp;&nbsp;Runs *exec_args()* for running > command				
 
 
 * void redirin()		
 *Input*: char * line				
 *Output*: runs < command via forking				
 &nbsp;&nbsp;&nbsp;&nbsp;Takes a potential redirect command				
 &nbsp;&nbsp;&nbsp;&nbsp;Parses string for < command				
 &nbsp;&nbsp;&nbsp;&nbsp;Runs *exec_args()* for running < command				
 
 
 * void exec_pipe()		
 *Input*: char * line				
 *Output*: runs | command via forking				
 &nbsp;&nbsp;&nbsp;&nbsp;Takes a potential pipe command				
 &nbsp;&nbsp;&nbsp;&nbsp;Parses string for | command				
 &nbsp;&nbsp;&nbsp;&nbsp;If there is no | command, runs *multi_exec()* on *line*				
 &nbsp;&nbsp;&nbsp;&nbsp;Simulates piping through the use of *redirout()* and *redirin()*				
 
 
 * void multi_exec()		
 *Input*: char * line				
 *Output*: parses line and runs the corresponding function				
 &nbsp;&nbsp;&nbsp;&nbsp;Checks to see if *line* contains >, <, or |				
 &nbsp;&nbsp;&nbsp;&nbsp;Runs *strsepstr()* on *line* for semicolon dividers for multi-command input				
 

