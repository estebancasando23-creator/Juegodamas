#include "estebaninterfaz.h"
#include <cstdlib>
#include <ctime>

void mostrarTitulo() {
    std::cout << "\n=====================================\n";
    std::cout << "       DAMAS INTERNACIONALES\n";
    std::cout << "=====================================\n";
}

void mostrarMenu() {
    mostrarTitulo();
    std::cout << "1. Jugar\n";
    std::cout << "2. Reglas\n";
    std::cout << "0. Salir\n";
    std::cout << "Opcion: ";
}

void mostrarReglas() {
    std::cout << "\n=== Reglas de Damas Internacionales ===\n";
    std::cout << "- El tablero tiene 10x10 casillas.\n";
    std::cout << "- Cada jugador inicia con 20 fichas.\n";
    std::cout << "- Solo se mueven por casillas negras.\n";
    std::cout << "- Para capturar, se salta sobre una pieza rival.\n";
    std::cout << "- Al llegar al extremo opuesto, una ficha se corona como Dama.\n";
    std::cout << "=======================================\n";
}

void mostrarGanador(const std::string& nombre) {
    std::cout << "\n=====================================\n";
    std::cout << "          ¡Felicidades!\n";
    std::cout << "   Ganador: " << nombre << "\n";
    std::cout << "=====================================\n";
}

void mostrarEmpate() {
    std::cout << "\n=====================================\n";
    std::cout << "             ¡Empate!\n";
    std::cout << "=====================================\n";
}

void pausar() {
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// ===== Lógica del juego =====
void jugarPartida() {
    std::string jugador1, jugador2;
    int puntaje1, puntaje2;

    std::cout << "Ingrese nombre del jugador 1: ";
    std::cin >> jugador1;
    std::cout << "Ingrese nombre del jugador 2: ";
    std::cin >> jugador2;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    puntaje1 = std::rand() % 10;
    puntaje2 = std::rand() % 10;

    std::cout << jugador1 << ": " << puntaje1
              << " - " << jugador2 << ": " << puntaje2 << "\n";

    if (puntaje1 > puntaje2)
        mostrarGanador(jugador1);
    else if (puntaje2 > puntaje1)
        mostrarGanador(jugador2);
    else
        mostrarEmpate();

    pausar();
}

void menuPrincipal() {
    int opcion = -1;
    while (opcion != 0) {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                jugarPartida();
                break;
            case 2:
                mostrarReglas();
                pausar();
                break;
            case 0:
                std::cout << "\nSaliendo del juego...\n";
                break;
            default:
                std::cout << "\nOpcion invalida.\n";
        }
    }
}
