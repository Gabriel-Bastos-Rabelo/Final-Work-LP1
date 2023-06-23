# Readme: Efficient Parcel Delivery

## About

Final project of the programming language I subject at the Federal University of Maranhão. In this work our group was responsible for developing an algorithm for the knapsack problem, a classic optimization problem, for this problem we used a solution with a recursive structure.

This is a quick guide to explain how to use the "Efficient Parcel Delivery" application made in C. The program solves the classic Traveling Salesman Problem, in which a delivery person needs to find the most efficient route among several cities, delivering all parcels, and returning to their starting point.

## How to Use

1. Clone the repository: 
bash
$ git clone https://github.com/Gabriel-Bastos-Rabelo/Final-Work-LP1.git 
or https://github.com/GabrielBeloDev/Final-Work-LP1.git

2. Navigate into the project directory: `cd efficient-parcel-delivery`
3. Compile the source code: `gcc main.c -o delivery`
4. Run the program with the input file: `./delivery input.txt`

## Input File Format

The input file should be a text file (.txt) containing the distances between all cities in an adjacency matrix. Each line represents a city, and each space-separated number represents the distance to another city. For example:


5
0 10 8 9 7
10 0 5 6 8
8 5 0 7 6
9 6 7 0 10
7 8 6 10 0


In this example, the distance from city 1 to city 2 is 2, and the distance from city 3 to city 4 is 8.

## Program Output

The program will print out the sequence of cities that the delivery person should visit to obtain the most efficient route. The output will be a list of space-separated numbers, where each number represents the index of the city in the input file. The starting point is always city 0.

For example, a possible output could be: `0 1 3 2 0`, which means that the delivery person should start at city 0, then go to city 1, then to city 3, then to city 2, and finally return to city 0.

## Problem

<h1 align="center"><img src="https://i.postimg.cc/tCWRSjc6/Captura-de-tela-de-2023-06-21-09-50-18.png"/></h1>

## How to Contribute

If you found a bug or would like to suggest a new feature, feel free to open an issue or a pull request!

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.