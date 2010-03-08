#include "CSVArrayBuilder.hpp"

CSVArrayBuilder::CSVArrayBuilder(QChar delimiter, QChar escapeChar,
        const char* newLine) : maxCol(0), maxLine(0) {
    builder = new CSVBuilder(delimiter, escapeChar, newLine);
}

CSVArrayBuilder::~CSVArrayBuilder() {
    delete builder;
}

void CSVArrayBuilder::put (int line, int col, QString data) {
    if (line > maxLine) maxLine = line;
    if (col > maxCol) maxCol = col;
    lines[line][col] = data;
}

QString CSVArrayBuilder::build() {
    QList<int> linesIndex = lines.keys();

    for (int i = 0; i <= maxLine; i++) {
        if (!linesIndex.contains(i)) {
            for (int j = 0; j <= maxCol; j++) {
                builder->push("");
            }
            builder->newLine();
            continue;
        }
        for (int j = 0; j <= maxCol; j++) {
            builder->push(lines[i][j]);
        }
        builder->newLine();
    }

    return builder->build();
}
