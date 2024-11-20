# get_next_line

**get_next_line** is a function that reads a line from a file descriptor, handling buffered input efficiently. It is a project from the 42 curriculum that implements a simple way to retrieve one line at a time from a file or standard input.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Testing](#testing)

## Introduction

**get_next_line** reads one line at a time from a file or standard input. It is designed to handle large files efficiently without loading the entire file into memory. The function handles the buffer and returns a dynamically allocated string containing the line read from the file descriptor.

This project is part of the 42 curriculum, providing a hands-on opportunity to explore file I/O and buffer management in C.

## Features

- Reads a line from a file descriptor.
- Handles dynamic memory allocation for each line read.
- Reads from standard input or a file.
- Efficiently handles multiple lines by reading from a buffer.

## Installation

To use **get_next_line**, clone the repository and compile the source files:

```bash
git clone https://github.com/abboudje/get_next_line.git
cd get_next_line
make
```

## Testing

You can test the function with a simple program, as shown in the main.c file. To run the test, execute the following command:
```bash
make run_test
