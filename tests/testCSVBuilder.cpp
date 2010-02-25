#include <QtTest/QtTest>

#include "CSVBuilder.hpp"
#include "testCSVBuilder.hpp"


void testCSVBuilder::oneLine () {
    CSVBuilder *builder = new CSVBuilder;
    builder->push("a");
    builder->push("b");
    builder->push("c");
    QVERIFY (builder->currentLine() == "a,b,c");
}

QTEST_MAIN(testCSVBuilder)
