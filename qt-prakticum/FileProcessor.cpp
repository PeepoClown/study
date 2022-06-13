#include "FileProcessor.h"

FileProcessor::FileProcessor(const QString &fileName)
    : _fileName(fileName)
{ }

FileProcessor::~FileProcessor() noexcept
{ }

FileProcessor::FileProcessor(const FileProcessor &fp)
{ *this = fp; }

FileProcessor& FileProcessor::operator= (const FileProcessor &fp)
{
    this->_fileName = fp._fileName;
    return (*this);
}

const QString& FileProcessor::getFileName() const
{ return (this->_fileName); }

void FileProcessor::setFileName(const QString &fileName)
{ this->_fileName = fileName; }

void FileProcessor::writeToFile(QVector<Worker>& vec)
{
    QFile file(this->_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        throw std::runtime_error("Can't open file " + this->_fileName.toStdString());

    QJsonArray jsonArray;
    for (const auto &i : vec) {
        QJsonObject tmpObj;
        tmpObj["id"] = QString::number(i.getId());
        tmpObj["price"] = i.getPrice();
        tmpObj["customer"] = i.getCustomer();
        tmpObj["isGift"] = i.getIsGift();
        jsonArray.push_back(tmpObj);
    }
    QJsonDocument jsonDoc(jsonArray);
    file.write(jsonDoc.toJson());
    file.close();
}

void FileProcessor::readFromFile()
{
    this->_data.clear();
    QFile file(this->_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Can't open file " + this->_fileName.toStdString());

    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonArray jsonArray = jsonDoc.array();
    for (const auto &i : jsonArray) {
        Worker tmpWorker;
        tmpWorker.setCustomer(i.toObject().value("customer").toString());
        tmpWorker.setId(i.toObject().value("id").toString().toUtf8().toUShort());
        tmpWorker.setIsGift(i.toObject().value("isGift").toBool());
        tmpWorker.setPrice(i.toObject().value("price").toDouble());
        this->_data.push_back(tmpWorker);
    }
}

QVector<Worker>& FileProcessor::getData()
{ return (this->_data); }
