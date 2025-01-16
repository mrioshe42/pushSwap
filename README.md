# Push_swap

A sorting algorithm project that sorts data using two stacks, with a limited set of operations. The goal is to sort the numbers in ascending order using the minimum possible number of moves.

## Overview
This program takes a set of integers as input and sorts them using two stacks (stack A and stack B) with a specific set of allowed operations. The challenge is to sort the numbers with the minimum number of operations possible.

## Features
- Stack manipulation algorithms
- Input validation and error handling
- Performance optimization
- Operation count minimization
- Multiple sorting strategies

## Allowed Operations
- `sa`: swap first two elements of stack A
- `sb`: swap first two elements of stack B
- `ss`: sa and sb at the same time
- `pa`: push first element from stack B to stack A
- `pb`: push first element from stack A to stack B
- `ra`: rotate stack A (first element becomes last)
- `rb`: rotate stack B (first element becomes last)
- `rr`: ra and rb at the same time
- `rra`: reverse rotate stack A (last element becomes first)
- `rrb`: reverse rotate stack B (last element becomes first)
- `rrr`: rra and rrb at the same time

## Usage

# Compile the program
make

# Run with a list of integers
./push_swap 4 67 3 87 23

