# Dining Philosophers Problem

This project is an implementation of the Dining Philosophers Problem using C. The solution aims to avoid deadlock and ensure all philosophers can eat.
The entire project report is in the PDF file : [report](Rapport_du_Projet_du_Diner_Des_Philosophes.pdf)

# User Manual 
the project contains the following files:
- [main.c](main.c): The main source code file in addition of the functions.
- [headerfile.h](headerfile.h): The header file containing function prototypes and definitions.
- [Makefile](Makefile): The Makefile used to compile the project.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Execution](#Execution)

## Installation

To install this project, you need to clone the repository.

```bash
git clone https://github.com/aitgouraine.youssef/Dining-_Philosophers_Problem.git
```

enter the repository with the commande  ```cd Dining-_Philosophers_Problem```

## usage
before execution the program ,the user can modify some variables to influence the bihaviour of the dining philosophers table:
in the [headerfile.h](headerfile.h) you can modify the next variables defined as macros:
```C
#define N 6 // Number of philosophers
#define max_time_no_eating 2 //decrease if you want to test the starvation
#define sleeping_time 2 //increase to make the starvation happen
```

## Execution
Once you have the project on your local machine and you set the parameters you want, you can use the [Makefile](Makefile) to compile and run the program:

-to compile the program use the command ```make``` the compiler will recognize the Makefile and execute it, this command will generate an executable file named 
*dining_table* , you can change this name simply by modifying the variable ```C TARGET = dining_table ``` in the Makefile.

-to run the program use the command ```./dining_table```.

-if you want to remove the files created you can execute the following command ```make clean``` , this command will delete all the files except the source code.
*here is a demo on how the use the make file*

> **⚠ Important:**
> The Makefile provided in this repository is designed to work on **Linux** or **Kali Linux**, which are Unix-like operating systems. It may not function correctly on other operating systems as the program work with the pthread library which is not a build-in library and difficult to install, and the makefile contain some unix commands.
