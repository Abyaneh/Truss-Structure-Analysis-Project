# Truss Structure Analysis

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Force Calculation Algorithm](#force-calculation-algorithm)
- [Input Files](#input-files)
- [Solution PDF](#solution-pdf)
- [How to Run the Project](#how-to-run-the-project)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This project focuses on analyzing forces on truss members by reading data from input files containing lengths and forces on truss elements such as FA, FB, LA, and LB. It reads case numbers based on a condition linked to the student ID, calculates the maximum forces, and outputs them in a formatted manner.

[Back to Top](#table-of-contents)
## Features
- Calculates forces for truss elements based on input data.
- Filters case numbers according to a specific modulus condition.
- Outputs the maximum force acting on the truss structure.
- Handles input/output operations from external files.

[Back to Top](#table-of-contents)
## Project Structure
- **Final_Project.cpp**: The main code file that performs force calculations.
- **solution.pdf**: A document that contains manual calculations for comparison with the program output.

[Back to Top](#table-of-contents)
## Force Calculation Algorithm
The program reads truss data for elements FA, FB, and applied forces LA, LB from input files. For each case:
1. Case numbers that satisfy the condition `(case number % 10 == Student ID % 10)` are processed.
2. Forces are calculated for the elements, and the maximum resultant force is reported as:
   
$$
F_{\text{max}} = \sqrt{F_x^2 + F_y^2}
$$

In this formula:

$$
F_{\text{max}} \quad : \quad \text{maximum force}
$$

$$
F_{\text{x}} \quad : \quad \text{force acting on the object along the x-axis}
$$

$$
F_{\text{y}} \quad : \quad \text{force acting on the object along the y-axis}
$$

   Example output:
   - **AC**: \(F_x = 12 \, kN\), \(F_y = 5 \, kN\)

#### Truss Structure
![Truss Structure](https://github.com/Abyaneh/Truss-Structure-Analysis-Project/blob/main/truss-structure-image.jpg)

##### You can see more detail in [Question pdf](https://github.com/Abyaneh/Truss-Structure-Analysis-Project/blob/main/Question.pdf)

[Back to Top](#table-of-contents)
## Input Files

The program reads from an input file ([input.txt](https://github.com/Abyaneh/Truss-Structure-Analysis-Project/blob/main/input.txt)) that contains force data (FA, FB) and length data (LA, LB).

[Back to Top](#table-of-contents)
## Manual Calculation
The [Manual Calculation.pdf](https://github.com/Abyaneh/Truss-Structure-Analysis-Project/blob/main/Manual%20Calculation.pdf) file contains a manual calculation example for validating the program's results.

[Back to Top](#table-of-contents)
## How to Run the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/Abyaneh/Truss-Structure-Analysis-Project/tree/main
   ```
2. Compile the C++ code:
   ```bash
   g++ Final_Project.cpp -o truss_analysis
    ```
3. Run the Compiled Program:
    ```bash
   ./truss_analysis
   ```

[Back to Top](#table-of-contents)
## Contributing
Contributions are welcome! To contribute:
1. Fork this repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit (`git commit -m 'Add a new feature'`).
4. Push to your branch (`git push origin feature-branch`).
5. Open a pull request for review.

[Back to Top](#table-of-contents)

## License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/Abyaneh/rotten_and_fresh/blob/main/LICENSE) file for details.

[Back to Top](#table-of-contents)

