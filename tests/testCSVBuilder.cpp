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

void testCSVBuilder::newLine () {
    CSVBuilder *builder = new CSVBuilder;
    builder->push("a");
    builder->push("b");
    builder->push("c");
    builder->newLine();
    builder->push("d");
    builder->push("e");
    QVERIFY (builder->currentLine() == "d,e");
}

QTEST_MAIN(testCSVBuilder)
