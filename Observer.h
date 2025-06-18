#ifndef OBSERVER_H
#define OBSERVER_H

#include "Process.h"
// obserwator wypisujący aktualny stan do konsoli
class Observer : public IObserver {
public:
    void update(const Process& subject) override;
};

#endif // OBSERVER_H
