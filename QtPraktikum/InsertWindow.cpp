#include "InsertWindow.h"

InsertWindow::InsertWindow(QTableView *table, WorkerModel *model, QWidget *parent)
    : QWidget(parent), _table(table), _model(model)
{
    this->resize(400, 350);

    this->_idLabel = new QLabel("Id: ", this);
    this->_idLabel->setGeometry(50, 60, 70, 30);
    this->_idEdit = new QLineEdit(this);
    this->_idEdit->setGeometry(120, 60, 120, 30);

    this->_priceLabel = new QLabel("Price: ", this);
    this->_priceLabel->setGeometry(50, 120, 70, 30);
    this->_priceEdit = new QLineEdit(this);
    this->_priceEdit->setGeometry(120, 120, 120, 30);

    this->_customerLabel = new QLabel("Customer: ", this);
    this->_customerLabel->setGeometry(50, 180, 70, 30);
    this->_customerEdit = new QLineEdit(this);
    this->_customerEdit->setGeometry(120, 180, 120, 30);

    this->_isFlagLabel = new QLabel("isGift: ", this);
    this->_isFlagLabel->setGeometry(50, 240, 70, 30);
    this->_isFlagEdit = new QLineEdit(this);
    this->_isFlagEdit->setGeometry(120, 240, 120, 30);

    this->_submitBtn = new QPushButton("Submit", this);
    this->_submitBtn->setGeometry(300, 150, 80, 35);

    connect(this->_submitBtn, SIGNAL(released()), this, SLOT(onSubmitBtn()));
}

InsertWindow::~InsertWindow() noexcept
{
    delete this->_idLabel;
    delete this->_idEdit;
    delete this->_priceLabel;
    delete this->_priceEdit;
    delete this->_customerLabel;
    delete this->_customerEdit;
    delete this->_isFlagLabel;
    delete this->_isFlagEdit;
    delete this->_submitBtn;
}

void InsertWindow::onSubmitBtn()
{
    size_t id = this->_idEdit->text().toULong();

    try {
        this->_model->append(Worker(id, this->_priceEdit->text().toDouble(),
                                    this->_customerEdit->text(),
                                    static_cast<QVariant>(this->_isFlagEdit->text()).toBool()));
        this->_table->setModel(this->_model);

        this->_idEdit->clear();
        this->_priceEdit->clear();
        this->_customerEdit->clear();
        this->_isFlagEdit->clear();
        this->close();
    }
    catch (const std::exception &ex) {
        (new QErrorMessage(this)) -> showMessage(QString::fromUtf8(ex.what()));
    }
}
