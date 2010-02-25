#ifndef TESTCSVBUILDER_HPP
#define TESTCSVBUILDER_HPP

#include <QtTest/QtTest>

class testCSVBuilder : public QObject
{
Q_OBJECT
    private slots:
        void oneLine();
        void newLine();
        void twoLines();
        void escQuote();
        void escNewLine();
        void escDelimiter();
        void configureEscChar();
};

#endif
