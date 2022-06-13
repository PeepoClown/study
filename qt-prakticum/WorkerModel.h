#ifndef WORKERMODEL_H
#define WORKERMODEL_H

#include "Worker.h"
#include <QTableView>
#include <QVector>

class WorkerModel : public QAbstractTableModel
{
Q_OBJECT

public:
    WorkerModel(QObject *parent = nullptr);
    ~WorkerModel() noexcept;
    WorkerModel(const WorkerModel &wm);
    WorkerModel& operator= (const WorkerModel &wm);

    int rowCount(const QModelIndex &index) const override;
    int columnCount(const QModelIndex &index) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role) const override;

    void append(const Worker &worker);
    void remove(int index);
    void update(size_t id, double price, const QString &customer, bool isGift);

    QVector<Worker>& getData();

private:
    QVector<Worker> _data;

};

#endif // WORKERMODEL_H
