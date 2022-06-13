#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(MainWindow::_winWidth, MainWindow::_winHeight);

    this->_tableTitle = new QLabel("Records", this);
    QFont titleFont = this->_tableTitle->font();
    titleFont.setBold(true);
    titleFont.setPixelSize(30);
    this->_tableTitle->setFont(titleFont);
    this->_tableTitle->setGeometry(400, 40, 200, 40);
    this->_table = new QTableView(this);
    this->_table->setGeometry(150, 100, 600, 750);
    this->_tableModel = new WorkerModel();

    this->_addBtn = new QPushButton("Insert record", this);
    this->_addBtn->setGeometry(800, 300, 150, 50);
    this->_updBtn = new QPushButton("Update record", this);
    this->_updBtn->setGeometry(800, 380, 150, 50);
    this->_delBtn = new QPushButton("Delete record", this);
    this->_delBtn->setGeometry(800, 460, 150, 50);
    this->_saveBtn = new QPushButton("Save", this);
    this->_saveBtn->setGeometry(800, 540, 150, 50);
    this->_selectFileBtn = new QPushButton("Select", this);
    this->_selectFileBtn->setGeometry(800, 220, 150, 50);

    connect(this->_addBtn, SIGNAL(released()), this, SLOT(onAddBtn()));
    connect(this->_updBtn, SIGNAL(released()), this, SLOT(onUpdBtn()));
    connect(this->_delBtn, SIGNAL(released()), this, SLOT(onDelBtn()));
    connect(this->_saveBtn, SIGNAL(released()), this, SLOT(onSaveBtn()));
    connect(this->_selectFileBtn, SIGNAL(released()), this, SLOT(onSelectFileBtn()));

    this->_insWin = new InsertWindow(this->_table, this->_tableModel);
    this->_delWin = new DeleteWindow(this->_table, this->_tableModel);
    this->_updWin = new UpdateWindow(this->_table, this->_tableModel);

    this->_filename = "";
}

MainWindow::~MainWindow() noexcept
{
    delete this->_tableTitle;
    delete this->_table;
    delete this->_fp;
    delete this->_tableModel;
    delete this->_addBtn;
    delete this->_updBtn;
    delete this->_delBtn;
    delete this->_saveBtn;
    delete this->_selectFileBtn;
    if (this->_insWin != nullptr)
        delete this->_insWin;
    if (this->_insWin != nullptr)
        delete this->_delWin;
    if (this->_insWin != nullptr)
        delete this->_updWin;
}

void MainWindow::renderTable()
{
    this->_fp = new FileProcessor();
    this->_fp->readFromFile();
    this->_data = this->_fp->getData();
    for (const auto &i : this->_data) {
        this->_tableModel->append(i);
    }
    this->_table->setModel(this->_tableModel);
    for (size_t i = 0; i < this->_data.size(); i++) {
        this->_table->setColumnWidth(i, 150);
    }
}

void MainWindow::onAddBtn()
{
    if (this->_insWin != nullptr)
        delete this->_insWin;
    if (this->_filename.isEmpty()) {
        (new QErrorMessage(this)) -> showMessage(QString("Select file before processing"));
        return ;
    }
    this->_insWin = new InsertWindow(this->_table, this->_tableModel);
    this->_insWin->show();
}

void MainWindow::onUpdBtn()
{
    if (this->_updWin != nullptr)
        delete this->_updWin;
    if (this->_filename.isEmpty()) {
        (new QErrorMessage(this)) -> showMessage(QString("Select file before processing"));
        return ;
    }
    this->_updWin = new UpdateWindow(this->_table, this->_tableModel);
    this->_updWin->show();
}

void MainWindow::onDelBtn()
{
    if (this->_delWin != nullptr)
        delete this->_delWin;
    if (this->_filename.isEmpty()) {
        (new QErrorMessage(this)) -> showMessage(QString("Select file before processing"));
        return ;
    }
    this->_delWin = new DeleteWindow(this->_table, this->_tableModel);
    this->_delWin->show();
}

void MainWindow::onSaveBtn()
{
    if (this->_filename.isEmpty()) {
        (new QErrorMessage(this)) -> showMessage(QString("Select file before processing"));
        return ;
    }
    this->_fp->writeToFile(this->_tableModel->getData());
}

void MainWindow::onSelectFileBtn()
{
    this->_filename = QFileDialog::getOpenFileName(this, "Open Dialog", "");
    renderTable();
}
