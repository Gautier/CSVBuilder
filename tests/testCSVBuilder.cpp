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

void testCSVBuilder::twoLines () {
    CSVBuilder *builder = new CSVBuilder;
    builder->push("a");
    builder->push("b");
    builder->push("c");
    builder->newLine();
    builder->push("d");
    builder->push("e");
    QVERIFY ("a,b,c\nd,e\n" == builder->build());
}

void testCSVBuilder::escQuote () {
    CSVBuilder *builder = new CSVBuilder;
    builder->push("a");
    builder->push("b");
    builder->push("c");
    builder->newLine();
    builder->push("\"Software is like sex: it's better when it's free.\" Linus Torvalds");
    builder->push("e");
    QVERIFY ("a,b,c\n\"\"\"Software is like sex: it's better when it's free.\"\" Linus Torvalds\",e\n" == builder->build());
}

void testCSVBuilder::escNewLine () {
    CSVBuilder *builder = new CSVBuilder;
    builder->push("a");
    builder->push("b");
    builder->push("c");
    builder->newLine();
    builder->push("For war\n is a drug");
    builder->push("e");
    QVERIFY ("a,b,c\n\"For war\n is a drug\",e\n" == builder->build());
}

void testCSVBuilder::escDelimiter () {
    CSVBuilder *builder = new CSVBuilder;
    builder->push("a");
    builder->push("b");
    builder->push("c");
    builder->newLine();
    builder->push("For war, is a drug");
    builder->push("e");
    QVERIFY ("a,b,c\n\"For war, is a drug\",e\n" == builder->build());
}

void testCSVBuilder::configureEscChar () {
    CSVBuilder *builder = new CSVBuilder(CSVBuilder::defaultDelimiter, '\'', CSVBuilder::defaultNewLine);
    builder->push("a");
    builder->push("b");
    builder->push("c");
    builder->newLine();
    builder->push("d'artagnan");
    builder->push("\"youpi\"");
    QVERIFY ("a,b,c\n'd''artagnan',\"youpi\"\n" == builder->build());
}

QTEST_MAIN(testCSVBuilder)
