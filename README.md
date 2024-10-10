# Truss Structure Analysis Project

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Force Calculation Algorithm](#force-calculation-algorithm)
- [Input Files](#input-files)
- [Technologies & Tools Used](#technologies--tools-used)
- [Solution PDF](#solution-pdf)
- [How to Run the Project](#how-to-run-the-project)
- [Team Members](#team-members)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This project focuses on analyzing forces on truss members by reading data from input files containing lengths and forces on truss elements such as FA, FB, LA, and LB. It reads case numbers based on a condition linked to the student ID, calculates the maximum forces, and outputs them in a formatted manner.

## Features
- Calculates forces for truss elements based on input data.
- Filters case numbers according to a specific modulus condition.
- Outputs the maximum force acting on the truss structure.
- Handles input/output operations from external files.

## Project Structure
- **Final_Project.cpp**: The main code file that performs force calculations.
- **solution.pdf**: A document that contains manual calculations for comparison with the program output.
  
## Force Calculation Algorithm
The program reads truss data for elements FA, FB, and applied forces LA, LB from input files. For each case:
1. Case numbers that satisfy the condition `(case number % 10 == Student ID % 10)` are processed.
2. Forces are calculated for the elements, and the maximum resultant force is reported as:
   
   \[
   F_{\text{max}} = \sqrt{F_x^2 + F_y^2}
   \]
   
   Example output:
   - **AC**: \(F_x = 12 \, kN\), \(F_y = 5 \, kN\)

## Input Files
The program reads from two input files:
1. **Forces.txt**: Contains force data (FA, FB).
2. **Lengths.txt**: Contains length data (LA, LB).

## Technologies & Tools Used
- C++ for force calculation logic.
- PDF for solution comparison.
  
## Solution PDF
The solution.pdf file contains a manual calculation example for validating the program's results.

## How to Run the Project
1. Clone the repository.
2. Compile the C++ code:
   ```bash
   g++ Final_Project.cpp -o truss_analysis
