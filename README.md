# Dining Philosophers Problem

This project is an implementation of the Dining Philosophers Problem using C. The solution aims to avoid deadlock and ensure all philosophers can eat.

# User Manual 
the project contains the following files:
- [main.c](main.c): The main source code file in addition of the functions.
- [headerfile.h](headerfile.h): The header file containing function prototypes and definitions.
- [Makefile](Makefile): The Makefile used to compile the project.
  
[headerfile.h](headerfile.h)

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Makefile](#makefile)
- [Contributing](#contributing)

## Installation

To install this project, you need to clone the repository.

```bash
git clone https://github.com/aitgouraine.youssef/Dining-_Philosophers_Problem.git
```

enter the repository with the commande  ```cd Dining-_Philosophers_Problem```

## usage
before execution the program the user can modify some variables to influence bihaviour of the dining philosophers table
in the [headerfile.h](headerfile.h) you can modify the next variables defined as macros:
```C
#define N 6 // Number of philosophers
#define max_time_no_eating 2 //decrease if you want to test the starvation
#define sleeping_time 2 //increase to make the starvation happen
```

