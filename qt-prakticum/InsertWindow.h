#ifndef INSERTWINDOW_H
#define INSERTWINDOW_H

#include "WorkerModel.h"
#include <QWidget>
#include <QTableView>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>

class InsertWindow : public QWidget
{
Q_OBJECT

public:
    explicit InsertWindow(QTableView *table, WorkerModel *model, QWidget *parent = nullptr);
    ~InsertWindow() noexcept override;

public slots:
    void onSubmitBtn();

private:
    QTableView  *_table;
    WorkerModel *_model;
    QPushButton *_submitBtn;
    QLineEdit   *_idEdit,
                *_priceEdit,
                *_customerEdit,
                *_isFlagEdit;
    QLabel      *_idLabel,
                *_priceLabel,
                *_customerLabel,
                *_isFlagLabel;

};

#endif // INSERTWINDOW_H
