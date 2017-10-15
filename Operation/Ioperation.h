#pragma once
#include <memory>


class IOperation
{
    virtual std::shared_ptr<IOperation> operator+(std::shared_ptr<IOperation>);
    virtual std::shared_ptr<IOperation> operator-(std::shared_ptr<IOperation>);
    virtual std::shared_ptr<IOperation> operator*(std::shared_ptr<IOperation>);
    virtual std::shared_ptr<IOperation> operator/(std::shared_ptr<IOperation>);
};