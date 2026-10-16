# Island

[Back to main README](../README.md)

To analyze satellite images, a geospatial company studies maps of remote ocean regions.
Each map is represented as a grid where land and water are identified.
In this exercice, you have to determine how many separate islands are present on a given map.
The map is represented as a 2D grid of characters :
	- '1' represents land
	- '0' represents water

An island is defined as a group of connected land cells.
Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
The grid is surrounded by water.

**The `main` function is the only one that must not contain any code because it will be replaced. All code in that function will be lost. However, you can use it as a sandbox, you are free to use the way you want while developing.**