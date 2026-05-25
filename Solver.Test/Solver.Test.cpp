#include "CppUnitTest.h"
#include "../Solver/PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTest
{
	TEST_CLASS(PriorityQueueTest)
	{
	public:
		TEST_METHOD(PriorityQueue_InitializerList)
		{
			PriorityQueue queue = { 5, 1, 10, 3 };

			Assert::IsTrue(queue.getSize() == 4);
			Assert::IsTrue(queue.peekMin() == 1);
			Assert::IsTrue(queue.peekMax() == 10);
			Assert::IsTrue(queue.toString() == "[1, 3, 5, 10]");
		}

		TEST_METHOD(PriorityQueue_Push)
		{
			PriorityQueue queue;
			queue.push(7);
			queue.push(2);
			queue.push(9);

			Assert::IsTrue(queue.toString() == "[2, 7, 9]");
			Assert::IsTrue(queue[0] == 2);
			Assert::IsTrue(queue[2] == 9);
		}

		TEST_METHOD(PriorityQueue_PopMin)
		{
			PriorityQueue queue = { 4, 12, 1, 8 };

			Assert::IsTrue(queue.popMin() == 1);
			Assert::IsTrue(queue.toString() == "[4, 8, 12]");
		}

		TEST_METHOD(PriorityQueue_PopMax)
		{
			PriorityQueue queue = { 4, 12, 1, 8 };

			Assert::IsTrue(queue.popMax() == 12);
			Assert::IsTrue(queue.toString() == "[1, 4, 8]");
		}

		TEST_METHOD(PriorityQueue_Find_Contains_Remove)
		{
			PriorityQueue queue = { 5, 2, 9, 7 };

			Assert::IsTrue(queue.find(7) == 2);
			Assert::IsTrue(queue.contains(9));
			Assert::IsFalse(queue.contains(4));

			queue.remove(7);
			Assert::IsTrue(queue.toString() == "[2, 5, 9]");
		}

		TEST_METHOD(PriorityQueue_CopyConstructor)
		{
			PriorityQueue queue = { 3, 1, 6 };
			PriorityQueue copy(queue);

			queue.push(10);

			Assert::IsTrue(copy.toString() == "[1, 3, 6]");
			Assert::IsTrue(queue.toString() == "[1, 3, 6, 10]");
		}

		TEST_METHOD(PriorityQueue_Assignment)
		{
			PriorityQueue first = { 1, 2, 3 };
			PriorityQueue second = { 9, 8 };

			second = first;
			first.popMax();

			Assert::IsTrue(second.toString() == "[1, 2, 3]");
			Assert::IsTrue(first.toString() == "[1, 2]");
		}

		TEST_METHOD(PriorityQueue_MoveConstructor)
		{
			PriorityQueue queue = { 3, 1, 2 };
			PriorityQueue moved(std::move(queue));

			Assert::IsTrue(moved.toString() == "[1, 2, 3]");
			Assert::IsTrue(queue.isEmpty());
		}

		TEST_METHOD(PriorityQueue_Operators)
		{
			PriorityQueue queue = { 3, 1 };
			int value = 0;

			queue << 5;
			queue >> value;

			Assert::IsTrue(value == 5);
			Assert::IsTrue(queue.toString() == "[1, 3]");
		}

		TEST_METHOD(PriorityQueue_EmptyException)
		{
			PriorityQueue queue;

			Assert::ExpectException<std::runtime_error>([&queue]() { queue.peekMin(); });
			Assert::ExpectException<std::runtime_error>([&queue]() { queue.popMax(); });
		}
	};
}
