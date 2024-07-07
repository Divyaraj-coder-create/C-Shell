	# Custom Linux Shell

	## Introduction

	Custom Linux Shell is a specialized command-line interface designed to enhance the efficiency and experience of performing routine computing tasks. It combines powerful functionality with an intuitive interface, making it accessible to both experienced developers and novice users. Custom Linux Shell provides a unique environment for managing and navigating your operating system, streamlining workflows and improving productivity.

	## Getting Started

	### Prerequisites

	Before beginning, ensure your system is equipped with a C compiler, which will serve as the translator for the code.

	### Building Your Environment

	1. Clone the project repository:

	```
	git clone https://github.com/Divyaraj-coder-create/C-Shell cd src
	```

	2. Compile the project:


	```
	make 
	./a.out
	```


	### Starting the Shell

	Upon activation, you'll encounter the command prompt, your starting point for every command:

	```
	<Username@SystemName:~>
	```

	You are now prepared to navigate your system! Utilize the commands outlined in the "Features" section to explore and manage your system efficiently.

	Remember, every directory is a new opportunity, and every file is a resource awaiting discovery. Your journey through the command line environment commences now!


	## Features

	### 1. Command Chaining (`;` separated commands)

	Execute multiple commands in a single line by separating them with a semicolon `;`. For example: 
```
ls; echo "Hello, Space!"; hostname
```
	### 2. Background Processes (`&` terminated commands)

	Run processes in the background by appending an ampersand `&` at the end of the command. For example: 
```
vim &
```
	### 3. Warp Command

	Navigate the file system quickly using the `warp [DIR]` command. Replace `[DIR]` with a directory path to move to that location. For Example:-
```
warp /home/user/Documents
```
	### 4. Peek Command

	Inspect the contents of directories using the `peek [OPTIONS]... [DIR]...` command. Options include `-a` for showing all files, including hidden ones, and `-l` for displaying detailed information. For Example :-

```
peek -la /var/log
```

	### 5. Pastevents Command

	Review your command history with the `pastevents execute [0<=index<=14]` command. This allows you to revisit previously executed commands. Foe Example:-
```
pastevents execute 3
```

	### 6. Seek Command

	Search for files or directories using the `seek <flags> <search> <target_directory>` command. Flags include `-d` for directories only, `-f` for files only, and `-e` for executing a single file or directory found.For Example :-

```
seek -df "example" /home
```

	### 7. System Commands

	Execute standard system commands within CosmoShell, capturing and displaying the process ID (PID) of background processes. For Example:-
```
ps aux
```

	### 8. Proclore Command

	Analyze the status of processes with the `proclore [pid]` command. This provides information about the specified process, including its PID, status, group, and memory usage. For Example:-
```
 proclore 12345
```

	### 9. Input/Output Redirection

	Redirect input and output using `<`, `>`, and `>>` operators. For example, `cat < kt.txt > new.txt` copies content from `kt.txt` to `new.txt`. For Example:-
```
cat < dm.txt > new.txt
```

	### 10. Piping

	Pipe the output of one command to another using the `|` operator. For example, `cat < new.txt | wc -l > kt.txt` counts lines in `new.txt` and writes the result to `kt.txt`. For Example :-
```
cat < new.txt | wc -l > kt.txt
```

	### 11. Activities

	List all processes running in the shell with the `activities` command, providing details such as command name, PID, and state. For Example:-
```
activities
```

	### 12. Signals

	Control processes using keyboard shortcuts like `Ctrl - C` to interrupt a process, `Ctrl - D` to log out, and `Ctrl - Z` to pause a process. For Example:-
```
 fg 1 bg 2
```

	### 13. Ping

	Send signals to processes with the `ping [pid] [signal_number]` command. For example, `ping [PID] 9` sends the SIGKILL signal to terminate a process. For Example:-
```
neonate -n 5
```

	### 14. Fg and Bg

	Bring a background process to the foreground with `fg [pid]` or send a foreground process to the background with `bg [pid]`. For Example:-
```
iMan ls
```

	### 15. Neonate

	Create new processes at intervals with the `neonate -n N` command, stopping with a keypress of `x`.

	### 16. iMan: 

	Access documentation for commands with the `iMan` command, fetching and displaying man pages from an online source.

	### 17. Exit

	Exit the shell with the `exit` command.

	## Assumptions

	This version of CosmoShell assumes:
	1. Input sizes up to 1024 bytes.
	2. Each command is less than 1000 characters.
	3. Paths are less than 1000 characters.
	4. In the `pastevents` command, commands containing `pastevents` won't be stored in history.
	5. The `proclore` command runs as a sudo user if the PID corresponds to a system command.
	6. History is stored in a `.txt` file in the executable's directory.

