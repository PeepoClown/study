#include "WorkerModel.h"

WorkerModel::WorkerModel(QObject *parent)
    : QAbstractTableModel(parent)
{ }

WorkerModel::~WorkerModel() noexcept
{ }

WorkerModel::WorkerModel(const WorkerModel &wm)
{ *this = wm; }

WorkerModel& WorkerModel::operator=(const WorkerModel &wm)
{
    this->_data = wm._data;
    return (*this);
}

int WorkerModel::rowCount(const QModelIndex &index) const
{ return (this->_data.size()); }

int WorkerModel::columnCount(const QModelIndex &index) const
{ return (4); }

QVariant WorkerModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return (QVariant());
    Worker worker = _data[index.row()];
    switch (index.column()) {
        case 0:
            return QString::fromUtf8(std::to_string(worker.getId()).c_str());
        case 1:
            return worker.getPrice();
        case 2:
            return worker.getCustomer();
        case 3:
            return worker.getIsGift();
        default:
            return (QVariant());
    }
}

QVariant WorkerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return (QVariant());
    switch (section) {
        case 0:
            return "Id";
        case 1:
            return "Price";
        case 2:
            return "Customer";
        case 3:
            return "IsGift";
        default:
            return (QVariant());
    }
}

void WorkerModel::append(const Worker &worker)
{
    beginInsertRows(QModelIndex(), this->_data.count(),
                    this->_data.count());
    bool isExist = false;
    for (const auto &i : this->_data) {
        if (i.getId() == worker.getId()) {
            isExist = true;
            break ;
        }
    }

    if (isExist)
        throw std::runtime_error("Insert fails. Index " +
                                 std::to_string(worker.getId()) + " already exist");

    this->_data.push_back(worker);
    endInsertRows();
}

void WorkerModel::remove(int index)
{
    beginInsertRows(QModelIndex(), this->_data.count(),
                    this->_data.count());
    bool isExist = false;
    for (const auto &i : this->_data) {
        if (i.getId() == (size_t)index) {
            isExist = true;
            break ;
        }
    }

    if (!isExist)
        throw std::runtime_error("Delete fails. Index " +
                                 std::to_string(index) + " doesn't exist");

    int idx = 0;
    while (idx < this->_data.size()) {
        if (this->_data[idx].getId() == index)
            break ;
        idx++;
    }
    this->_data.remove(idx);
    endInsertRows();
}

void WorkerModel::update(size_t id, double price, const QString &customer, bool isGift)
{
    bool isExist = false;
    size_t i = 0;
    for ( ; i < this->_data.size(); i++) {
        if (this->_data[i].getId() == id) {
            isExist = true;
            break ;
        }
    }

    if (!isExist)
        throw std::runtime_error("Update fails. Index " +
                                 std::to_string(id) + " doesn't exist");
    this->_data[i].setPrice(price);
    this->_data[i].setCustomer(customer);
    this->_data[i].setIsGift(isGift);
}

QVector<Worker>& WorkerModel::getData()
{ return (this->_data); }
