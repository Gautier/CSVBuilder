#include "CSVBuilder.hpp"

const QChar CSVBuilder::defaultDelimiter = ',';
const QChar CSVBuilder::escapeChar = '"';
const char* CSVBuilder::defaultNewLine = "\n";

CSVBuilder::CSVBuilder() {
    mCurrentLine = new QStringList;
    mLines = new QList<QStringList*>;
}

CSVBuilder::~CSVBuilder() {

}

void CSVBuilder::push(QString cell) {
    if(cell.contains(escapeChar) || cell.contains(defaultNewLine)) {
        mCurrentLine->append(cell.replace(escapeChar,
                                             QString(escapeChar) + escapeChar)
                                .prepend(escapeChar)
                                .append(escapeChar));
    } else {
        mCurrentLine->append(cell);
    }
}

QString CSVBuilder::currentLine() {
    return mCurrentLine->join(defaultDelimiter);
}

QString CSVBuilder::build() {
    if (!mCurrentLine->isEmpty()) {
        newLine();
    }
    QString final;
    foreach (QStringList *line, *mLines) {
        final.append(line->join(defaultDelimiter));
        final.append(defaultNewLine);
    }
    return final;
}

void CSVBuilder::newLine() {
    mLines->append(mCurrentLine);
    mCurrentLine = new QStringList;
}
