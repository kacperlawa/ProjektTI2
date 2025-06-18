#include "Observer.h"
#include <iostream>

// wypisanie aktualnego stanu procesu
void Observer::update(const Process& subject) {
    Process::Vec2 x = subject.state();
    std::cout << "Nowy stan x = ["
              << x[0] << ", " << x[1] << "]\n";
}
