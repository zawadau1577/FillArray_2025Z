#include <array>
#include <ostream>
#include <iomanip>
#include <exception>
#include "FillArray.h"



void fillArray(std::array<std::array<int, maxColumns>, maxRows> & array, size_t rows, size_t columns)
{
	if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
		throw std::invalid_argument("Invalid array size.");
	int value = 1;
	for (size_t row = 0; row < rows; ++row)
		for (size_t column = 0; column < columns; ++column)
			array[row][column] = value++;
}

void fillArray_SE_DIAG_UP(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{
	if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
		throw std::invalid_argument("Invalid array size.");

	int number = 1;

	for (size_t i = 0; i < std::min(rows, columns) - 1; ++i)
	{
		size_t startColumn = columns - 1 - i;
		for (size_t column = startColumn; column < columns; ++column)
		{
			size_t row = rows - (column - startColumn) - 1;
			array[row][column] = number++;
		}
	}

	if (rows > columns)
	{
		size_t startRow = rows;
		do
		{
			--startRow;
			for (size_t column = 0, row = startRow; column < columns; ++column, --row)
			{
				array[row][column] = number++;
			}
		} while (startRow >= columns);
		/* this version doesn`t work - signed, unsigned comparision ( -1L > 0UL value of this condition is true)
		for (int startRow = rows - 1; startRow >= columns - 1;--startRow)
		{
			for (size_t column = 0, row = startRow; column < columns; ++column, --row)
			{
				array[row][column] = number++;
			}
		}*/
	}
	else
	{
		for (int startColumn = columns - rows; startColumn >= 0; --startColumn)
		{
			for (int row = rows - 1, column = startColumn; row >= 0; --row, ++column)
				array[row][column] = number++;
		}
	}

	for (int startRow = std::min(rows, columns) - 2; startRow >= 0; --startRow)
	{
		for( int row = startRow; row >= 0; --row)
		{
			int  column = startRow - row;
			array[row][column] = number++;
		}
	}
}

void displayArray(std::ostream& stream, std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{
	for (size_t row = 0; row < rows; ++row)
	{
		for (size_t column = 0; column < columns; ++column)
			stream << std::setw(4) << array[row][column];
		stream << std::endl;
	}
}