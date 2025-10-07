#pragma once
#include <array>

const size_t maxRows = 20;
const size_t maxColumns = 20;

void fillArray(std::array<std::array<int, maxColumns>, maxRows> & array, size_t rows, size_t columns);
void displayArray(std::ostream& stream, std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);

void fillArray_SE_DIAG_UP(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
