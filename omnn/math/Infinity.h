#pragma once
#include "ValuableDescendantContract.h"

namespace omnn{
namespace math {


class Infinity
        : public ValuableDescendantContract<Infinity>
{
    using base = ValuableDescendantContract<Infinity>;

protected:
    std::ostream& print(std::ostream& out) const override;

public:
    using base::base;

    Valuable operator -() const override;
    Valuable& operator +=(const Valuable& v) override;
    Valuable& operator *=(const Valuable& v) override;
    Valuable& operator /=(const Valuable& v) override;
    Valuable& operator %=(const Valuable& v) override;
    Valuable& operator --() override;
    Valuable& operator ++() override;
    Valuable& operator^=(const Valuable&) override;
    Valuable& d(const Variable& x) override;
    bool operator <(const Valuable& v) const override;
};

}}