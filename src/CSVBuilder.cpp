#include "CSVBuilder.hpp"

const QChar CSVBuilder::defaultDelimiter = ',';
const QChar CSVBuilder::defaultEscapeChar = '"';
const char* CSVBuilder::defaultNewLine = "\n";

CSVBuilder::CSVBuilder(QChar delimiter, QChar escapeChar, const char* newLine):
                        mDelimiter(delimiter), mEscapeChar(escapeChar),
                        mNewLine(newLine) {
    mCurrentLine = new QStringList;
    mLines = new QList<QStringList*>;
}

CSVBuilder::~CSVBuilder() {

}

void CSVBuilder::push(QString cell) {
    if(cell.contains(mEscapeChar) || cell.contains(mNewLine)
            || cell.contains(mDelimiter)) {
        mCurrentLine->append(cell.replace(mEscapeChar,
                                             QString(mEscapeChar) + mEscapeChar)
                                .prepend(mEscapeChar)
                                .append(mEscapeChar));
    } else {
        mCurrentLine->append(cell);
    }
}

QString CSVBuilder::currentLine() {
    return mCurrentLine->join(mDelimiter);
}

QString CSVBuilder::build() {
    if (!mCurrentLine->isEmpty()) {
        newLine();
    }
    QString final;
    foreach (QStringList *line, *mLines) {
        final.append(line->join(mDelimiter));
        final.append(mNewLine);
    }
    return final;
}

void CSVBuilder::newLine() {
    mLines->append(mCurrentLine);
    mCurrentLine = new QStringList;
}
