#ifndef PROCESSBUILDER_H
#define PROCESSBUILDER_H

#include "Process.h"
#include <memory>

// interfejs buildera
class ProcessBuilder {
public:
    virtual ~ProcessBuilder() = default;
    virtual void setMatrixA(const Process::Mat2x2& A) = 0;
    virtual void setVectorB(const Process::Vec2& B) = 0;
    virtual void setInitialState(const Process::Vec2& x0) = 0;
    virtual std::shared_ptr<Process> getResult() = 0;
};

class Builder : public ProcessBuilder {
public:
    Builder();
    void reset(); //tworzy nowy process
    void setMatrixA(const Process::Mat2x2& A) override; //ustawia parametry
    void setVectorB(const Process::Vec2& B) override;
    void setInitialState(const Process::Vec2& x0) override;
    std::shared_ptr<Process> getResult() override; //zwraca obiekt i resetuje builder

private:
    std::shared_ptr<Process> process;
};

// kieruje pzrebiegiem budowy
class ProcessDirector {
public:
    void setBuilder(std::shared_ptr<ProcessBuilder> b); //implementacja process builder
    std::shared_ptr<Process> buildDefaultProcess();

private:
    std::shared_ptr<ProcessBuilder> builder;
};

#endif // PROCESSBUILDER_H
