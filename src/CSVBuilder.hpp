#ifndef CSVBUILDER_HPP
#define CSVBUILDER_HPP

#include <QtCore>

class CSVBuilder : public QObject {
    Q_OBJECT
    public:
        CSVBuilder();
        ~CSVBuilder();

        QString currentLine();
        void push(QString cell);

    private:
        QStringList *mCurrentLine;
        QList<QStringList*> *mLines;

        static const QChar defaultDelimiter;
        static const QChar escapeChar;
        static const char *defaultNewLine;
};


#endif
