#ifndef CSVARRAYBUILDER_HPP
#define CSVARRAYBUILDER_HPP

#include <QtCore>

#include "CSVBuilder.hpp"

class CSVArrayBuilder : public QObject {
    Q_OBJECT
    public:
        CSVArrayBuilder(QChar delimiter = CSVBuilder::defaultDelimiter,
                    QChar escapeChar = CSVBuilder::defaultEscapeChar,
                    const char* newLine = CSVBuilder::defaultNewLine);
        ~CSVArrayBuilder();

        void put(int line, int col, QString data);
        QString build();

    private:
        CSVBuilder *builder;
        int maxCol;
        int maxLine;

        QHash<int, QHash<int, QString> > lines;
};


#endif

