# LabReport02-Sorting

A C programming lab assignment that implements **Merge Sort** and **Quick Sort** to arrange integer records in ascending order and compare their performance based on element comparisons.

## Lab Experiment

**Implementation of Merge Sort and Quick Sort Algorithms with Comparison Counting and Merging of Sorted Arrays.**

## Objectives

- Sort the given array in ascending order using Merge Sort.
- Sort the given array in ascending order using Quick Sort.
- Count and compare the element comparisons made by both algorithms.
- Merge a new sorted array with the existing sorted array without sorting the entire collection again.

## Problem Description

The program takes two batches of integer records as input. The first batch contains N unsorted integers, and the second batch contains M integers already sorted in ascending order.

The program sorts the original records using Merge Sort and Quick Sort. It also counts the element comparisons performed by both algorithms. Finally, it combines the sorted original records with the new sorted records to create an updated array.

For Quick Sort, the last element is used as the pivot.

## Technologies Used

- **Language:** C
- **Editor:** Visual Studio Code
- **Compiler:** GCC
- **Version Control:** Git and GitHub

## Algorithms Used

### 1. Merge Sort
Divides the array into smaller parts and merges them in ascending order. It counts the element comparisons during merging.

### 2. Quick Sort
Uses the last element as the pivot and partitions the array around it. It counts the element comparisons during partitioning.

### 3. Merging Two Sorted Arrays
Combines the existing sorted array and the new sorted array into one ascending array without sorting the entire collection again.

## Input Format

The program reads input from a file named `input.txt`.

- **First line:** Two integers N and M.
- **Second line:** N integers in any order.
- **Third line:** M integers sorted in ascending order.

### Sample Input 1

```text
8 4
7 2 9 1 5 3 4 6
0 2 8 10
```

### Sample Output 1

```text
Merge Sort: 1 2 3 4 5 6 7 9
Quick Sort: 1 2 3 4 5 6 7 9
Merge Comparisons: 16
Quick Comparisons: 15
Updated Array: 0 1 2 2 3 4 5 6 7 8 9 10
```

### Sample Input 2

```text
8 3
1 2 3 4 5 6 7 8
2 4 10
```

### Sample Output 2

```text
Merge Sort: 1 2 3 4 5 6 7 8
Quick Sort: 1 2 3 4 5 6 7 8
Merge Comparisons: 12
Quick Comparisons: 28
Updated Array: 1 2 2 3 4 4 5 6 7 8 10
```

## Time Complexity

| Algorithm / Operation | Time Complexity |
|---|---|
| Merge Sort | O(N log N) |
| Quick Sort | O(N²) |
| Merging Two Sorted Arrays | O(N + M) |

## How to Run

1. Clone the repository:

```bash
git clone https://github.com/SkSabuj-Web/-LabReport02-Sorting.git
```

2. Open the project folder in VS Code.

3. Compile the C program:

```bash
gcc LabReport02-Sorting.c -o sorting
```

4. Run the program:

```bash
./sorting
```

For Windows PowerShell:

```powershell
.\sorting.exe
```

Make sure `input.txt` is in the same folder from which the program is executed.

## Project Structure

```text
LabReport02-Sorting/
│
├── LabReport02-Sorting.c
├── input.txt
└── README.md
```

## Author

**Sajib Khan Sabuj**

GitHub: [SkSabuj-Web](https://github.com/SkSabuj-Web)

---

*Lab Report 02 – Sorting Algorithms*
