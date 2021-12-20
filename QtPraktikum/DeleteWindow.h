#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include "WorkerModel.h"
#include <QWidget>
#include <QTableView>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QErrorMessage>

class DeleteWindow : public QWidget
{
Q_OBJECT

public:
    explicit DeleteWindow(QTableView *table, WorkerModel *model, QWidget *parent = nullptr);
    ~DeleteWindow() noexcept override;

public slots:
    void onSubmitBtn();

private:
    QTableView  *_table;
    WorkerModel *_model;
    QPushButton *_submitBtn;
    QComboBox   *_items;
    QLabel      *_chooseLabel;

};

#endif // DELETEWINDOW_H
