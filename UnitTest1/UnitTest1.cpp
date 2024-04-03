#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/HashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestInsertAndGet)
		{
			HashTable<std::string, int> hashTable;

			hashTable.insert("One", 1);
			hashTable.insert("Two", 2);
			hashTable.insert("Three", 3);

			Assert::AreEqual(1, hashTable.get("One"));
			Assert::AreEqual(2, hashTable.get("Two"));
			Assert::AreEqual(3, hashTable.get("Three"));
		}

		TEST_METHOD(TestContainsAndRemove)
		{
			HashTable<std::string, int> hashTable;
			hashTable.insert("One", 1);
			hashTable.insert("Two", 2);
			hashTable.insert("Three", 3);

			Assert::IsTrue(hashTable.contains("One"));
			Assert::IsTrue(hashTable.contains("Two"));
			Assert::IsTrue(hashTable.contains("Three"));
			Assert::IsFalse(hashTable.contains("Four"));

			hashTable.remove("One");
			Assert::IsFalse(hashTable.contains("One"));
			Assert::IsTrue(hashTable.contains("Two"));
			Assert::IsTrue(hashTable.contains("Three"));
		}
	};
}
