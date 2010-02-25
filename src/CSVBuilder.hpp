#ifndef CSVBUILDER_HPP
#define CSVBUILDER_HPP

#include <QtCore>

class CSVBuilder : public QObject {
    Q_OBJECT
    public:
        CSVBuilder();
        ~CSVBuilder();

        QString currentLine();
        QString build();
        void push(QString cell);
        void newLine();

    private:
        QStringList *mCurrentLine;
        QList<QStringList*> *mLines;

        static const QChar defaultDelimiter;
        static const QChar escapeChar;
        static const char *defaultNewLine;
};


#endif
