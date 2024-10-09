<img src="https://i.imgur.com/y2bQtnZ.png" width="150" height="150" alt="Logo" />

# 42-Philosophers
## Overview
**Philosophers** is a programming project from **42 School** that **simulates the classic "Dining Philosophers Problem"**. The goal of the project is to explore and implement threading, synchronization, and resource sharing in C. In this problem, a group of philosophers alternates between thinking, eating, and sleeping. They share forks (resources) for eating, and must avoid deadlock (where no philosopher can eat) and starvation (where a philosopher cannot eat indefinitely).

## Getting started
This project is compatible on Linux and macOS.
> If you are on macOS, make sure you have installed **Xcode Command Line Tools**.
1. Clone this repository
```bash
git clone https://github.com/extrymes/42-Philosophers.git
cd 42-Philosophers/philo
```
2. Compile and launch the program
```bash
make
./philo <nb_philos> <time_to_die> <time_to_eat> <time_to_sleep> [<must_eat>]
```
- `nb_philos`: Number of philosophers and forks (at least 1).
- `time_to_die`: Time (in milliseconds) a philosopher can live without eating.
- `time_to_eat`: Time (in milliseconds) a philosopher spends eating.
- `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
- `must_eat`: (Optional) The number of times each philosopher must eat before the simulation ends.

## Contributing
We welcome contributions from everyone! Whether you're fixing bugs, adding new features, improving documentation, or simply sharing your ideas, your input is greatly appreciated.

Thanks for visiting and happy coding!
