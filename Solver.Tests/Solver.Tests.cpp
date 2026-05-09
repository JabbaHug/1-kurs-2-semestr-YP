#include "CppUnitTest.h"
#include "../Solver/Point.h"
#include "../Solver/Color.h"
#include "../Solver/LineStyle.h"
#include "../Solver/Line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
	TEST_CLASS(SolverTests)
	{
	public:
		
        TEST_METHOD(Color_Constructor)
        {
            Color color(100, 150, 200);

            Assert::IsTrue(true);
        }

        TEST_METHOD(LineStyle_DefaultConstructor)
        {
            LineStyle style;

            Assert::IsTrue(style.getType() == "solid");
        }

        TEST_METHOD(LineStyle_Constructor)
        {
            Color color(255, 0, 0);

            LineStyle style(
                color,
                LineStyle::LineType::Dash,
                3
            );

            Assert::IsTrue(style.getType() == "dash");
        }

        TEST_METHOD(Line_Constructor)
        {
            Point first(0, 0);
            Point second(1, 1);

            Line line(first, second);

            Assert::IsTrue(true);
        }

        TEST_METHOD(Line_Constructor_WithStyle)
        {
            Point first(0, 0);
            Point second(1, 1);

            Color color(0, 255, 0);
            LineStyle style(color, LineStyle::LineType::Dot, 5);

            Line line(first, second, style);

            Assert::IsTrue(true);
        }

        TEST_METHOD(Line_Output)
        {
            Point first(0, 0);
            Point second(1, 1);

            Color color(2, 254, 254);
            LineStyle style(color, LineStyle::LineType::Dot, 10);

            Line line(first, second, style);

            std::ostringstream out;
            out << line;

            std::string result = out.str();

            Assert::IsTrue(result.find("Линия:") != std::string::npos);
            Assert::IsTrue(result.find("Первая точка:") != std::string::npos);
            Assert::IsTrue(result.find("Вторая точка:") != std::string::npos);
            Assert::IsTrue(result.find("Тип линии: dot") != std::string::npos);
            Assert::IsTrue(result.find("Толщина линии: 10") != std::string::npos);
            Assert::IsTrue(result.find("Цвет линии: RGB(2, 254, 254)") != std::string::npos);
        }

        TEST_METHOD(Line_Read)
        {
            std::istringstream input("0 0 1 1 2 254 254 3 10");

            Line line = Line::read(input);

            std::ostringstream out;
            out << line;

            std::string result = out.str();

            Assert::IsTrue(result.find("Тип линии: dot") != std::string::npos);
            Assert::IsTrue(result.find("Толщина линии: 10") != std::string::npos);
            Assert::IsTrue(result.find("Цвет линии: RGB(2, 254, 254)") != std::string::npos);
        }
	};
}
