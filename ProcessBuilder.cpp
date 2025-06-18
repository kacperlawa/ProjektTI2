#include "ProcessBuilder.h"

Builder::Builder() {
    reset();
}

// tworzy nową instancję Process i przypisuje do process
void Builder::reset() {
    process = std::make_shared<Process>();
}

// ustawia macierz A
void Builder::setMatrixA(const Process::Mat2x2& A) {
    process->mA = A;
}

// ustawia wektor B
void Builder::setVectorB(const Process::Vec2& B) {
    process->mB = B;
}

// ustawia stan początkowy x0
void Builder::setInitialState(const Process::Vec2& x0) {
    process->mX = x0;
}

// zwraca proces i resetuje builder
std::shared_ptr<Process> Builder::getResult() {
    std::shared_ptr<Process> result = process;
    reset();
    return result;
}

// pozwala korzystać z dowolnej implementacji interfejsu buildera
void ProcessDirector::setBuilder(std::shared_ptr<ProcessBuilder> b) {
    builder = b;
}

std::shared_ptr<Process> ProcessDirector::buildDefaultProcess() {
    Process::Mat2x2 A = {{{-5.0, 0.0}, {0.0, -4.0}}}; // ustala domyślne parametry
    Process::Vec2    B = {1.0, 2.0};
    Process::Vec2    x0 = {0.0, 0.0};

    builder->setMatrixA(A); // zwraca obiekt
    builder->setVectorB(B);
    builder->setInitialState(x0);
    return builder->getResult();
}
