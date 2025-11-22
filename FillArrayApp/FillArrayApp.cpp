//tu bylem
#include <iostream>
#include <array>
#include <exception>
#include <iomanip>
#include "..\FillArrayLib\FillArray.h"

int main()
{
    size_t rows, columns;
    do
    {
        std::cout << "Number of rows:";
        std::cin >> rows;
        std::cout << "Number of columns:";
        std::cin >> columns;

        std::array<std::array<int, maxRows>, maxColumns> array;
        try
        {
            fillArray_SE_DIAG_UP(array, rows, columns);
            displayArray(std::cout, array, rows, columns);
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
        }
    } while (rows != 0 || columns != 0);
}
