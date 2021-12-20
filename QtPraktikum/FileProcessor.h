#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "Worker.h"
#include <QVector>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>

class FileProcessor
{
public:
    explicit FileProcessor(const QString &fileName = "default.json");
    ~FileProcessor() noexcept;
    FileProcessor(const FileProcessor &fp);
    FileProcessor& operator= (const FileProcessor &fp);

    const QString& getFileName() const;
    void setFileName(const QString &fileName);

    void writeToFile(QVector<Worker>& vec);
    void readFromFile();
    QVector<Worker>& getData();

private:
    QString         _fileName;
    QVector<Worker> _data;

};

#endif // FILEPROCESSOR_H
