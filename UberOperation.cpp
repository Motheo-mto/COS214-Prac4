#include "UberOperation.h"
#include <iostream>

void UberOperation::add(UberOperation *a)
{
    std::cout << "Add not supported by this operation" << std::endl;
}

void UberOperation::remove(UberOperation *r)
{
    std::cout << "Remove not supported by this operation" << std::endl;
}

UberOperation::~UberOperation()
{
}
