#include "DeleteWindow.h"

DeleteWindow::DeleteWindow(QTableView *table, WorkerModel *model, QWidget *parent)
    : QWidget(parent), _table(table), _model(model)
{
    this->resize(350, 200);

    this->_chooseLabel = new QLabel("Choose record id: ", this);
    this->_chooseLabel->setGeometry(30, 50, 120, 35);
    this->_items = new QComboBox(this);
    this->_items->setGeometry(175, 50, 150, 35);

    this->_submitBtn = new QPushButton("Submit", this);
    this->_submitBtn->setGeometry(150, 120, 80, 35);

    QVector<Worker> vec = this->_model->getData();
    for (const auto &i : vec) {
        this->_items->addItem(QString::number(i.getId()));
    }

    connect(this->_submitBtn, SIGNAL(released()), this, SLOT(onSubmitBtn()));
}

DeleteWindow::~DeleteWindow() noexcept
{
    delete this->_chooseLabel;
    delete this->_items;
    delete this->_submitBtn;
}

void DeleteWindow::onSubmitBtn()
{
    try {
        this->_model->remove(this->_items->currentText().toInt());
        this->_table->setModel(this->_model);
        this->close();
    }
    catch (const std::exception &ex) {
        (new QErrorMessage(this)) -> showMessage(QString::fromUtf8(ex.what()));
    }
}
