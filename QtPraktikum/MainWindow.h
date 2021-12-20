#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "FileProcessor.h"
#include "WorkerModel.h"
#include "InsertWindow.h"
#include "UpdateWindow.h"
#include "DeleteWindow.h"
#include <QMainWindow>
#include <QTableView>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QFileDialog>

#include <iostream>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() noexcept override;

    void renderTable();

public slots:
    void onAddBtn();
    void onUpdBtn();
    void onDelBtn();
    void onSaveBtn();
    void onSelectFileBtn();

private :
    const static size_t _winWidth = 1080;
    const static size_t _winHeight = 950;

    QVector<Worker> _data;
    FileProcessor   *_fp;
    QLabel          *_tableTitle;
    QTableView      *_table;
    WorkerModel     *_tableModel;
    QPushButton     *_addBtn,
                    *_updBtn,
                    *_delBtn,
                    *_saveBtn;
    InsertWindow    *_insWin;
    DeleteWindow    *_delWin;
    UpdateWindow    *_updWin;
    QPushButton     *_selectFileBtn;
    QString         _filename;

};

#endif // MAINWINDOW_H
