\# APC — Arbitrary Precision Calculator



\## Overview

A C-based calculator that performs arithmetic on integers 

of any size using doubly linked lists.



\## Objective

The objective of this project is to implement an Arbitrary 

Precision Calculator in C that handles numbers of any size 

beyond standard integer limits. Each digit is stored as a 

node in a doubly linked list, enabling addition, subtraction, 

multiplication and division with carry/borrow handling.



\## Features

\- Addition with carry handling

\- Subtraction with borrow handling

\- Long multiplication with shift and add

\- Division using repeated subtraction

\- Supports negative numbers

\- Handles numbers of any size



\## Files

| File | Description |

|------|-------------|

| `apc.h` | Dlist struct and function declarations |

| `addition.c` | Digit-by-digit addition with carry |

| `subtraction.c` | Subtraction with borrow handling |

| `multiplication.c` | Long multiplication with shift and add |

| `division.c` | Division using repeated subtraction |

| `print\_list.c` | Print result linked list |

| `main.c` | Argument parsing and operator dispatch |



\## Compilation

```bash

gcc main.c addition.c subtraction.c multiplication.c division.c print\_list.c -o apc

```



\## Usage

```bash

./apc 12345678901234567890 + 98765432109876543210

./apc 99999999999 \* 99999999999

./apc 100000000000 / 3

```



\## Tech Stack

\- Language: C

\- Concepts: Doubly linked list, Carry/borrow arithmetic, Sign handling

