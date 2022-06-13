#include "Worker.h"

Worker::Worker(size_t id, double price, const QString &customer,
               bool isGift)
    : _id(id), _price(price), _customer(customer), _isGift(isGift)
{ }

Worker::~Worker() noexcept
{ }

Worker::Worker(const Worker &worker)
{ *this = worker; }

Worker& Worker::operator=(const Worker &worker)
{
    this->_id = worker._id;
    this->_price = worker._price;
    this->_customer = worker._customer;
    this->_isGift = worker._isGift;
    return (*this);
}

size_t Worker::getId() const
{ return (this->_id); }

double Worker::getPrice() const
{ return (this->_price); }

const QString& Worker::getCustomer() const
{ return (this->_customer); }

bool Worker::getIsGift() const
{ return (this->_isGift); }

void Worker::setId(size_t id)
{ this->_id = id; }

void Worker::setPrice(double price)
{ this->_price = price; }

void Worker::setCustomer(const QString &customer)
{ this->_customer = customer; }

void Worker::setIsGift(bool isGift)
{ this->_isGift = isGift; }
