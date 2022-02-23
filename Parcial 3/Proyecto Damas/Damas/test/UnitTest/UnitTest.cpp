#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			void test_function()
			{
				IS_TRUE(!function1(0));
				IS_TRUE(!function1(5));
				IS_TRUE(function1(10));
			}
		}

		TEST_METHOD(TestMethod)
		{
			void test_function1()
			{
				IS_TRUE(!function1(false));
				IS_TRUE(!function3(true));
				IS_TRUE(function2(10));
			}
		}

		TEST_METHOD(TestMethod)
		{
			void test_function1()
			{
				IS_TRUE(!function1(0));
				IS_TRUE(!function4(NULL));
				IS_TRUE(function1(10));
			}
		}

		TEST_METHOD(TestMethod)
		{
			void test_function()
			{
				IS_TRUE(!function1(0));
				IS_TRUE(!function1(5));
				IS_TRUE(function1(10));
			}
		}

		TEST_METHOD(TestMethod)
		{
			void test_function1()
			{
				IS_TRUE(!function1(false));
				IS_TRUE(!function3(true));
				IS_TRUE(function2(10));
			}
		}

	};
}
