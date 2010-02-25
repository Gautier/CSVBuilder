#include "CSVBuilder.hpp"

const QChar CSVBuilder::defaultDelimiter = QChar(',');
const QChar CSVBuilder::escapeChar = '\'';
const char* CSVBuilder::defaultNewLine = "\n";

CSVBuilder::CSVBuilder() {
    mCurrentLine = new QStringList;
    mLines = new QList<QStringList*>;
}

CSVBuilder::~CSVBuilder() {

}

void CSVBuilder::push(QString cell) {
    mCurrentLine->append(cell);
}

QString CSVBuilder::currentLine() {
    return mCurrentLine->join(defaultDelimiter);
}
