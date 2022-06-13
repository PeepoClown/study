#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H

#include "WorkerModel.h"
#include <QWidget>
#include <QTableView>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QErrorMessage>

class UpdateWindow : public QWidget
{
Q_OBJECT

public:
    explicit UpdateWindow(QTableView *table, WorkerModel *model, QWidget *parent = nullptr);
    ~UpdateWindow() noexcept override;

public slots:
    void onSubmitBtn();

private:
    QTableView  *_table;
    WorkerModel *_model;
    QPushButton *_submitBtn;
    QComboBox   *_idItems;
    QLineEdit   *_priceEdit,
                *_customerEdit,
                *_isFlagEdit;
    QLabel      *_idLabel,
                *_priceLabel,
                *_customerLabel,
                *_isFlagLabel;

};


#endif // UPDATEWINDOW_H
