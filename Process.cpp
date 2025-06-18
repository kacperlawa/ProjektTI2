#include "Process.h"
#include <algorithm>

Process::Process()
  : mA{{{0,0},{0,0}}}, mB{0,0}, mX{0,0} //zerowanie wszystkich elementów
{}

void Process::step(double u) {
    Vec2 next{};
    for (int i = 0; i < 2; ++i) {
        next[i] = mB[i] * u;
        for (int j = 0; j < 2; ++j) {
            next[i] += mA[i][j] * mX[j];
        }
    }
    mX = next;
    notify();
}

Process::Vec2 Process::state() const {
    return mX;
}

void Process::attach(std::shared_ptr<IObserver> obs) {
    mObservers.push_back(obs);
}

void Process::detach(std::shared_ptr<IObserver> obs) {
    mObservers.erase(
      std::remove(mObservers.begin(), mObservers.end(), obs),
      mObservers.end()
    );
}

void Process::notify() {
    for (auto& obs : mObservers) {
        obs->update(*this);
    }
}
