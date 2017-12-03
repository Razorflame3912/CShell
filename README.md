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
 * char * strsepstr()<p>
 *Input*: char ** string, char * delim<p>
 *Output*: returns pointer to string with delim replaced with NULL<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Functions like strsep() but is able to take a string delimiter<p>
 
 
 * void exec_args()		
 *Input*: char * line<p>
 *Output*: executes arguments from line via forking when necessary<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Parses *line* for whitespace if necessary<p>
 &nbsp;&nbsp;&nbsp;&nbsp;If *line* contains "exit", program exits<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Else if *line* contains "cd", program changes directory using *chdir*<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Forks in order to run *execvp* on the arguments given in *line*<p>
 
 
 * void redirout()		
 *Input*: char * line<p>
 *Output*: runs > command via forking<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Takes a potential redirect command<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Parses string for > command<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Runs *exec_args()* for running > command<p>
 
 
 * void redirin()		
 *Input*: char * line<p>
 *Output*: runs < command via forking<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Takes a potential redirect command<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Parses string for < command<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Runs *exec_args()* for running < command<p>
 
 
 * void exec_pipe()		
 *Input*: char * line<p>
 *Output*: runs | command via forking<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Takes a potential pipe command<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Parses string for | command<p>
 &nbsp;&nbsp;&nbsp;&nbsp;If there is no | command, runs *multi_exec()* on *line*<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Simulates piping through the use of *redirout()* and *redirin()*<p>
 
 
 * void multi_exec()		
 *Input*: char * line<p>
 *Output*: parses line and runs the corresponding function<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Checks to see if *line* contains >, <, or |<p>
 &nbsp;&nbsp;&nbsp;&nbsp;Runs *strsepstr()* on *line* for semicolon dividers for multi-command input<p>
 

