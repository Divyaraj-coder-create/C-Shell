# Description
## Welcome to my custom made Terminal !<br>
The custom made Terminal acts like Linux-based terminal.
The project to create Terminal implements following custom functions : <br>
## Functions :
### warp
The warp command works as the cd of the bash terminal. It changes the directory of the user to defined path (relative or absolute). It can handle multiple change of directories sequentially saperated by space.
### peek
The command shows the files and directories in a directory. This works without any flags, -l ,-a, -al ,-la ,-a -l, -l -a. The output with l flags shows the output with the number of memory bytes (in kB) used by the files and directories combined.
### pastevents commands
Pastevents command comprised of :
- *pastevents* : This command lists last 15 commands run.
- *pastevents purge* : This command clears the pastevents list.
- *pastevents execute* : This command takes in the number of the recent command run. That command is run on terminal again.
### system commands
- *foreground* - Runs the command in the foreground. If process takes greater than 2 seconds then the time taken by the process will be printed in the prompt.
- *background* - Runs the command in the background. If process completly then the command exited normally else if any interrupt is encountered, the command exited abnormally will be printed. 
### proclore
Prints the process details of a specified process id(pid). Else the current process's details are printed.
### seek
The command searches for a specific named file/directory in the subtree of a directory. This can be searched by applying flags aas filter for searching only files and only directories with -f and -d flags. The command also provides -e flag. This flag detects if only one result of requested filter is present or not. If -f along with -e is used, and only one file is detected, the file path is printed along with the contents of the file. Similarly for the directory requested with -d -e, warp into that directory is done. 
### activities
Prints all the process id's that are spawned by this terminal that are currently running or were running a short while ago.
### ping
Send the signals to processes. It also handles the *CTRL + C* , *CTRL + D* and *CTRL + Z* signals.
### fg and bg
- *fg* - Change the state of the process to foreground. if pid is not available then it will print the error message.
- *bg* - Change the state of the stopped process to background. if pid is not available then it will print the error message.
### neonate
neonate will print the recently created process pid at every time_arg seconds. if key *'x'* is pressed then it will stop printing and terminate the process.
### iMan
It will print the *Manual page* of the command. If the command is not available then it will print the error message. The man page is fetch from the website "man.he.net".

### exit
The command exits from the terminal with *safe exit message*.

## Assumptions :
*General Assumptions*
- The custom functions cannot be run in background.
- "exit" must be written to end terminal otherwise or ctrl + D keys can be pressed but only on terminal.
- Invalid commands that are part of full command will be individually terminated with an error. 
- The user is assumed to know the correct format of input; errors thrown don't explain the correct format of input.
- Atleast one space is expected between two words or symbols like *|* or *;* or *&* etc.
- Multiple press of *Ctrl + Z* on blank terminal might glitch to \n process. This is an edge condition and is expected to be a GLITCH.
<br>

*Warp*
- In warp, the directory of the shell invocation in considered as "~" or home. Absolute _/home_ will lead to home of the system.
- Any paths that are outside the subtree of the directory invocation is shown in absolute.
<br>

*Peek*
- In peek, if no flags are entered the default result will have file/directory names as output like in terminal.
- The output will be sorted accorting to case sensitive order. Eg, README *higher than* a.out.
<br>

*Pastevents Commands*
- In the pastevents, the strings containing "pastevents" is not added to the list of commands.
- The *pastevents execute* is replaced by the respective command. It will execute the command at specified location and append it if its not the last line of the file. However , this command may not give desired outputs incase of multiple commands separated by ;
- Everything that is not a vaid command is also stored.
<br>

*Proclore*
- The virtual memory will be printed in Bytes.
- Processes with process status other than R,*R+*,*S*,*S+*, or Z will also be printed with respective process status, eg. T.
- Foreground processes are given status with added '+' at the end.
<br>

*Seek*
- -d and -f flags cannot be entered simultaneously.
- if -e is invoked and no other flags are invoked, only output will be change directory to only directory found or print contents of only file found or nothing.
- The name of the folder or file shall be given without its extension (**a** and not *a.out*).
<br>

*Activities*
- The *sorting* is considered for command_names. 
- Use of *Ctrl + D* is only possible with prompt is loaded and input is being accepted. Doing so while another foreground process is running will not affect the process.

*I/O redirection*
- It is assumed the '<' and '>' / '>>' is a valid user entry. The order must be preserved and checked by user.

*Piping*
- For command like cd / warp piping is not applicable.

*iMan*
- In case an invalid command is entered "iMan Divyaraj" , The error from website will be printed (not printed explicitly in C)

*

<br>

## Procedure To Run :
- Clone the repository.
- Run the command *make* in the terminal.
- Run the command *./a.out* in the terminal.
- The custom terminal will be loaded :

<username:~ >

- The terminal is ready to accept commands.
- The terminal can be exited by typing *exit* or pressing *Ctrl + D*.

## References
- [Google](https://www.google.com/) for idea about good implementations.
- [StackOverflow](https://stackoverflow.com/) for various queries.
```
```
The project is made under [Prof. Karthik Vaidyanathan](https://github.com/karthikv1392).<br>
<br>
Project Made By,<br>
[Divyarajsinh mahida](https://github.com/serc-courses/mini-project-1-Divyaraj-coder-create)<br>
2022101085<br>