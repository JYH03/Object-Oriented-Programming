// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <iostream>

#include <cmath>
#include <cstdlib>

using namespace std;

class Sale

{

  private:
    double Price;

  public:
    Sale();

    Sale(double thePrice);

    virtual ~Sale();

    double GetPrice();

    virtual double Bill();

    double Savings(Sale &Other);

    bool operator<(Sale &Other);
};

Sale::Sale() : Price(0) {}

Sale::Sale(double thePrice) : Price(thePrice) {}

Sale::~Sale() {}

double Sale::GetPrice()

{

    return Price;
}

double Sale::Bill()

{

    return Price;
}

double Sale::Savings(Sale &Other)

{

    return this->Bill() - Other.Bill();
}

bool Sale::operator<(Sale &Other)

{

    return this->Bill() < Other.Bill();
}

class DiscountSale : public Sale

{

  private:
    double Discount;

  public:
    DiscountSale();

    DiscountSale(double thePrice, double theDiscount);

    ~DiscountSale();

    double GetDiscount();

    void SetDiscount(double newDiscount);

    double Bill() override;

    double Savings(DiscountSale &Other);

    bool operator<(DiscountSale &Other);
};

DiscountSale::DiscountSale() : Sale(), Discount(0) {}

DiscountSale::DiscountSale(double thePrice, double theDiscount)
    : Sale(thePrice), Discount(theDiscount) {}

DiscountSale::~DiscountSale() {}

double DiscountSale::GetDiscount()

{

    return Discount;
}

void DiscountSale::SetDiscount(double newDiscount)

{

    Discount = newDiscount;
}

double DiscountSale::Bill()

{

    return (1.0 - Discount / 100.0) * GetPrice();
}

double DiscountSale::Savings(DiscountSale &Other)

{

    return this->Bill() - Other.Bill();
}

bool DiscountSale::operator<(DiscountSale &Other)

{

    return this->Bill() < Other.Bill();
}

int main()

{

    cout << "==============================" << endl;

    cout << "Price Compare Program" << endl;

    cout << "==============================" << endl;

    double price1, price2, discount;

    char discountPercent[64];

    cout << "Insert item1 price: $";

    if (!(cin >> price1))
        return 1;

    cout << "Insert item2 price: $";

    if (!(cin >> price2))
        return 1;

    cout << endl

         << "------------------------------" << endl;

    cout << "Insert discount percent: ";

    cin.width(64);
    if (!(cin >> discountPercent))
        return 1;

    cout << "------------------------------" << endl;

    char *end = nullptr;
    discount = std::strtod(discountPercent, &end);
    if (end == discountPercent)
        return 1;
    if (*end == '%')
        ++end;
    if (*end || !std::isfinite(discount) || discount < 0 || discount > 100 ||
        !std::isfinite(price1) || !std::isfinite(price2) || price1 < 0 || price2 < 0)
        return 1;

    Sale item1(price1);

    Sale item2(price2);

    cout << "Result:" << endl;

    if (item1 < item2)

    {

        DiscountSale discountedItem(item1.GetPrice(), discount);

        Sale *pDItem = &discountedItem;

        cout << "Discount price of item1 is cheaper." << endl;

        cout << "Saving discount price is $" << item1.Savings(*pDItem) << endl;

    }

    else

    {

        DiscountSale discountedItem(item2.GetPrice(), discount);

        Sale *pDItem = &discountedItem;

        cout << "Discount price of item2 is cheaper." << endl;

        cout << "Saving discount price is $" << item2.Savings(*pDItem) << endl;
    }

    return 0;
}
