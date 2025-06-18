#ifndef PROCESS_H
#define PROCESS_H

#include <array>
#include <vector>
#include <memory>

class IObserver;

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(std::shared_ptr<IObserver> obs) = 0;
    virtual void detach(std::shared_ptr<IObserver> obs) = 0;
    virtual void notify() = 0;
};

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const class Process& subject) = 0;
};

class Process : public ISubject {
public:
    using Mat2x2 = std::array<std::array<double,2>,2>;
    using Vec2   = std::array<double,2>;

    Process();
    void step(double u);
    Vec2 state() const;

    //rejestracja i powiadomiene
    void attach(std::shared_ptr<IObserver> obs) override;
    void detach(std::shared_ptr<IObserver> obs) override;
    void notify() override;

    Mat2x2 mA;
    Vec2   mB;
    Vec2   mX;

    std::vector<std::shared_ptr<IObserver>> mObservers; //lista subskrybentów

};

#endif // PROCESS_H
