#include <array>
#include <exception>
#include "CppUnitTest.h"
#include "../FillArrayLib/FillArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<std::array<std::array<int, maxColumns>, maxRows>>(const std::array<std::array<int, maxColumns>, maxRows>& t)
{
	std::wstring result;
	result += L"{";
	for (auto& row : t)
	{
		result += L"{";
		for (auto& v : row)
		{
			result += ToString(v);
			result += L",";
		}
		result += L"},";
	}
	result += L"}";
	return result;
}

namespace FillArrayUnitTest
{
	TEST_CLASS(FillArrayUnitTest)
	{
	public:
		TEST_METHOD(fillArray_0x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray(array,0,0); });
		}
		TEST_METHOD(fillArray_0x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray(array,0,3); });
		}
		TEST_METHOD(fillArray_3x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray(array,3,0); });
		}
		TEST_METHOD(fillArray_21x21)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray(array,21,21); });
		}
		TEST_METHOD(fillArray_0x21)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray(array,0,21); });
		}
		TEST_METHOD(fillArray_21x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray(array,21,0); });
		}
		TEST_METHOD(fillArray_1x1)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 1 }
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 1, 1);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_1x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 1, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_2x1)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1},
					{  2}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 2, 1);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_2x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2},
					{  3,  4}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 2, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_2x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3},
					{  4,  5,  6}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 2, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2},
					{  3,  4},
					{  5,  6}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 3, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3},
					{  4,  5,  6},
					{  7,  8,  9}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 3, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x6)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3,  4,  5,  6},
					{  7,  8,  9, 10, 11, 12},
					{ 13, 14, 15, 16, 17, 18}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 3, 6);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x7)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3,  4,  5,  6,  7},
					{  8,  9, 10, 11, 12, 13, 14},
					{ 15, 16, 17, 18, 19, 20, 21}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 3, 7);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_6x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3},
					{  4,  5,  6},
					{  7,  8,  9},
					{ 10, 11, 12},
					{ 13, 14, 15},
					{ 16, 17, 18}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 6, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_7x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3},
					{  4,  5,  6},
					{  7,  8,  9},
					{ 10, 11, 12},
					{ 13, 14, 15},
					{ 16, 17, 18},
					{ 19, 20, 21}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 7, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_4x4)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3,  4},
					{  5,  6,  7,  8},
					{  9, 10, 11, 12},
					{ 13, 14, 15, 16}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 4, 4);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_4x6)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3,  4,  5,  6},
					{  7,  8,  9, 10, 11, 12},
					{ 13, 14, 15, 16, 17, 18},
					{ 19, 20, 21, 22, 23, 24}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 4, 6);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_4x7)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2,  3,  4,  5,  6,  7},
					{  8,  9, 10, 11, 12, 13, 14},
					{ 15, 16, 17, 18, 19, 20, 21},
					{ 22, 23, 24, 25, 26, 27, 28}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray(array, 4, 7);
			Assert::AreEqual(expected, array);
		}
	};
}
