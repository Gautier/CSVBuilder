#ifndef CSVBUILDER_HPP
#define CSVBUILDER_HPP

#include <QtCore>

class CSVBuilder : public QObject {
    Q_OBJECT
    public:
        CSVBuilder(QChar delimiter = CSVBuilder::defaultDelimiter,
                    QChar escapeChar = CSVBuilder::defaultEscapeChar,
                    const char* newLine = CSVBuilder::defaultNewLine);
        ~CSVBuilder();

        QString currentLine();
        QString build();
        void push(QString cell);
        void newLine();

        static const QChar defaultDelimiter;
        static const QChar defaultEscapeChar;
        static const char *defaultNewLine;

    private:
        QStringList *mCurrentLine;
        QList<QStringList*> *mLines;

        const QChar mDelimiter;
        const QChar mEscapeChar;
        const char *mNewLine;
};


#endif
