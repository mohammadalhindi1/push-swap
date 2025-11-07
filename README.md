# Push_swap

**Push_swap** is an algorithmic project focused on sorting a stack of integers using a limited set of operations and two stacks — **A** and **B**.  
The main objective is to sort the numbers in ascending order with the **fewest possible moves**.

## 🧠 Project Overview
The program receives a list of integers as arguments and uses specific operations to sort them:
- **sa / sb / ss** – swap the first two elements of a stack  
- **pa / pb** – push the top element from one stack to another  
- **ra / rb / rr** – rotate the stack (first element becomes last)  
- **rra / rrb / rrr** – reverse rotate the stack (last element becomes first)

The challenge is to find the most efficient algorithm to minimize the total number of moves.

## ⚙️ Features
- Works with both small and large data sets  
- Uses optimized sorting algorithms (e.g., *radix sort*, *chunk-based sorting*)  
- Fully written in **C** following the Norm rules  
- Includes input validation and error handling  

## 💡 Example
```bash
$ ./push_swap 3 2 1
sa
rra

**From Mohammad Alhindi**
───────────────────────────────
© 2025 Mohammad Alhindi — All Rights Reserved  
Reusing or copying this code without permission is not cool — be original.
───────────────────────────────
