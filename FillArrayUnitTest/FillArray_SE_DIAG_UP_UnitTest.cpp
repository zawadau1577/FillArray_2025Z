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
	TEST_CLASS(FillArray_SE_DIAG_UP_UnitTest)
	{
	public:
		TEST_METHOD(fillArray_SE_DIAG_UP_0x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray_SE_DIAG_UP(array,0,0); });
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_0x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray_SE_DIAG_UP(array,0,3); });
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_3x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray_SE_DIAG_UP(array,3,0); });
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_21x21)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray_SE_DIAG_UP(array,21,21); });
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_0x21)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray_SE_DIAG_UP(array,0,21); });
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_21x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray_SE_DIAG_UP(array,21,0); });
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_1x1)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 1 }
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 1, 1);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_1x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 1, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_2x1)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  2},
					{  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 2, 1);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_2x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  4,  3},
					{  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 2, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_2x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  6,  5,  3},
					{  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 2, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_3x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  6,  5},
					{  4,  3},
					{  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 3, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_3x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  9,  8,  6},
					{  7,  5,  3},
					{  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 3, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_3x6)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 18, 17, 15, 12,  9,  6},
					{ 16, 14, 11,  8,  5,  3},
					{ 13, 10,  7,  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 3, 6);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_3x7)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 21, 20, 18, 15, 12,  9,  6},
					{ 19, 17, 14, 11,  8,  5,  3},
					{ 16, 13, 10,  7,  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 3, 7);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_6x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 18, 17, 15},
					{ 16, 14, 12},
					{ 13, 11,  9},
					{ 10,  8,  6},
					{  7,  5,  3},
					{  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 6, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_7x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 21, 20, 18},
					{ 19, 17, 15},
					{ 16, 14, 12},
					{ 13, 11,  9},
					{ 10,  8,  6},
					{  7,  5,  3},
					{  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 7, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_4x4)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 16, 15, 13, 10},
					{ 14, 12,  9,  6},
					{ 11,  8,  5,  3},
					{  7,  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 4, 4);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_4x6)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 24, 23, 21, 18, 14, 10},
					{ 22, 20, 17, 13,  9,  6},
					{ 19, 16, 12,  8,  5,  3},
					{ 15, 11,  7,  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 4, 6);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_SE_DIAG_UP_4x7)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 28, 27, 25, 22, 18, 14, 10},
					{ 26, 24, 21, 17, 13,  9,  6},
					{ 23, 20, 16, 12,  8,  5,  3},
					{ 19, 15, 11,  7,  4,  2,  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray_SE_DIAG_UP(array, 4, 7);
			Assert::AreEqual(expected, array);
		}
	};
}
