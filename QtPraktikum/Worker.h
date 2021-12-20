#ifndef WORKER_H
#define WORKER_H

#include <QString>

class Worker
{
public:
    explicit Worker(size_t id = 0, double price = 0.0, const QString &customer = "",
                    bool isGift = false);
    ~Worker() noexcept;
    Worker(const Worker &worker);
    Worker& operator= (const Worker &worker);

    size_t getId() const;
    double getPrice() const;
    const QString& getCustomer() const;
    bool getIsGift() const;

    void setId(size_t id);
    void setPrice(double price);
    void setCustomer(const QString &customer);
    void setIsGift(bool isGift);

private:
    size_t  _id;
    double  _price;
    QString _customer;
    bool    _isGift;

};

#endif // WORKER_H
