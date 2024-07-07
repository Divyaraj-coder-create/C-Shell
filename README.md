# CosmoShell: The Command Line Interface for the Digital Cosmos

## Introduction

Welcome to CosmoShell, a specialized command-line interface designed to transform everyday computing tasks into an exciting exploration of the digital cosmos. Whether you're an experienced navigator or a novice explorer, CosmoShell combines power and simplicity to make you feel like you're controlling a spacecraft within the digital universe of your operating system.

## Getting Started

### Prerequisites

Before beginning your cosmic journey, ensure your spacecraft is equipped with a C compiler, serving as your universal translator for cosmic code.

### Building Your Spaceship

1. Clone the cosmic blueprints:

```
bash git clone https://github.com/theculguy0099/CosmoShell.git cd CosmoShell
```

2. Ignite the cosmic engines:


```
bash make ./a.out
```


### Entering the Cosmos

Upon activation, you'll encounter the cosmic prompt, your starting point for every command:

```
<Username@SystemName:~>
```


You are now prepared to navigate the digital universe! Utilize the commands outlined in the "Features" section to explore your system like never before.

Remember, dear astronaut: in the vast expanse of CosmoShell, every directory is a new solar system, and every file is a star awaiting discovery. Your journey through the command line cosmos commences now!

### Ad astra per codica! (To the stars through code!)

## Features

### 1. Command Chaining (`;` separated commands)

Execute multiple commands in a single line by separating them with a semicolon `;`. For example: `ls; echo "Hello, Space!"; hostname`.

### 2. Background Processes (`&` terminated commands)

Run processes in the background by appending an ampersand `&` at the end of the command. For example: `vim &`.

### 3. Warp Command

Navigate the file system quickly using the `warp [DIR]` command. Replace `[DIR]` with a directory path to move to that location.

### 4. Peek Command

Inspect the contents of directories using the `peek [OPTIONS]... [DIR]...` command. Options include `-a` for showing all files, including hidden ones, and `-l` for displaying detailed information.

### 5. Pastevents Command

Review your command history with the `pastevents execute [0<=index<=14]` command. This allows you to revisit previously executed commands.

### 6. Seek Command

Search for files or directories using the `seek <flags> <search> <target_directory>` command. Flags include `-d` for directories only, `-f` for files only, and `-e` for executing a single file or directory found.

### 7. System Commands

Execute standard system commands within CosmoShell, capturing and displaying the process ID (PID) of background processes.

### 8. Proclore Command

Analyze the status of processes with the `proclore [pid]` command. This provides information about the specified process, including its PID, status, group, and memory usage.

### 9. Input/Output Redirection

Redirect input and output using `<`, `>`, and `>>` operators. For example, `cat < kt.txt > new.txt` copies content from `kt.txt` to `new.txt`.

### 10. Piping

Pipe the output of one command to another using the `|` operator. For example, `cat < new.txt | wc -l > kt.txt` counts lines in `new.txt` and writes the result to `kt.txt`.

### 11. Activities

List all processes running in the shell with the `activities` command, providing details such as command name, PID, and state.

### 12. Signals

Control processes using keyboard shortcuts like `Ctrl - C` to interrupt a process, `Ctrl - D` to log out, and `Ctrl - Z` to pause a process.

### 13. Ping

Send signals to processes with the `ping [pid] [signal_number]` command. For example, `ping [PID] 9` sends the SIGKILL signal to terminate a process.

### 14. Fg and Bg

Bring a background process to the foreground with `fg [pid]` or send a foreground process to the background with `bg [pid]`.

### 15. Neonate

Create new processes at intervals with the `neonate -n N` command, stopping with a keypress of `x`.

### 16. iMan: Intergalactic Manual

Access documentation for commands with the `iMan` command, fetching and displaying man pages from an online source.

### 17. Finish

Exit the shell with the `finish` command.

## Assumptions

This version of CosmoShell assumes:
1. Input sizes up to 1024 bytes.
2. Each command is less than 1000 characters.
3. Paths are less than 1000 characters.
4. In the `pastevents` command, commands containing `pastevents` won't be stored in history.
5. The `proclore` command runs as a sudo user if the PID corresponds to a system command.
6. History is stored in a `.txt` file in the executable's directory.

