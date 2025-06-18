#include <iostream>     // std::cout
#include <memory>       // std::shared_ptr, std::make_shared
#include <vector>       // std::vector
#include "ProcessBuilder.h"
#include "Observer.h"   // zaktualizowany include

int main() {
    // stworzenie buildera i przekazanie do directora
    std::shared_ptr<Builder> builder = std::make_shared<Builder>();
    ProcessDirector director;
    director.setBuilder(builder);

    // budowanie procesu
    std::shared_ptr<Process> process = director.buildDefaultProcess();

    // tworzenie observera
    std::shared_ptr<Observer> obs = std::make_shared<Observer>();
    process->attach(obs);

    // sekwencja sygnałów sterujących
    std::vector<double> u_seq = {1.0, 0.5, 0.0, -1.0};

    // wykonanie kroku process
    for (std::size_t i = 0; i < u_seq.size(); ++i) {
        double u = u_seq[i];
        std::cout << ">> Sterowanie u = " << u << "\n";
        process->step(u);
    }

    return 0;
}
