#include "Controller/SixthLabMenu.h"

#include <iostream>
#include "Entities/Process.h"
#include "Entities/CompetitiveSport.h"
#include "Entities/HumanActivity.h"
#include "Entities/Game.h"
#include "Entities/Esports.h"

int main() {

// ── 1. Массив Process ──────────────────────────────
    std::cout << "╔══════════════════════════════════╗\n"
              << "║       Массив: Process            ║\n"
              << "╚══════════════════════════════════╝\n";

    Process processes[3] = {
        Process("Компиляция",            "2026-05-12 09:00"),
        Process("Резервное копирование", "2026-05-12 10:00"),
        Process("Обновление системы",    "2026-05-12 11:00")
    };

    for (int i = 0; i < 3; i++) {
        processes[i].start();
        processes[i].print();
    }
    processes[1].stop();
    std::cout << "После stop():\n";
    processes[1].print();
    std::cout << "\n";


    // ── 2. Массив CompetitiveSport ─────────────────────
    std::cout << "╔══════════════════════════════════╗\n"
              << "║    Массив: CompetitiveSport      ║\n"
              << "╚══════════════════════════════════╝\n";

    CompetitiveSport sports[3] = {
        CompetitiveSport("FIFA", 16, true),
        CompetitiveSport("FIDE", 0,  false),
        CompetitiveSport("IESF", 16, false)
    };

    int testAge = 15;
    for (int i = 0; i < 3; i++) {
        sports[i].print();
        std::cout << "  Допуск для возраста " << testAge << ": "
                  << (sports[i].isEligible(testAge) ? "допущен" : "не допущен")
                  << "\n";
    }
    std::cout << "\n";


    // ── 3. Массив HumanActivity ────────────────────────
    std::cout << "╔══════════════════════════════════╗\n"
              << "║     Массив: HumanActivity        ║\n"
              << "╚══════════════════════════════════╝\n";

    HumanActivity activities[3] = {
        HumanActivity("Рисование", false, "2026-05-12", 1,  false, "творчество"),
        HumanActivity("Командный забег", true, "2026-05-13", 20, true,  "спорт"),
        HumanActivity("Лекция", true, "2026-05-14", 50, false, "обучение")
    };

    for (int i = 0; i < 3; i++) {
        activities[i].start();
        activities[i].print();
    }
    std::cout << "\n";


    // ── 4. Массив Game ─────────────────────────────────
    std::cout << "╔══════════════════════════════════╗\n"
              << "║        Массив: Game              ║\n"
              << "╚══════════════════════════════════╝\n";

    Game games[3] = {
        Game("Шахматный турнир", true, "2026-05-12", 2, false,"соревнование",2,2, "FIDE rules"),
        Game("Покерный вечер", true, "2026-05-13", 6, false,"развлечение", 2,9, "Texas Hold'em"),
        Game("Баскетбол 3x3", false, "2026-05-14", 6, true, "соревнование",4,6, "FIBA 3x3")
    };

    for (int i = 0; i < 3; i++) {
        games[i].print();
    }
    // Проверка допустимости числа игроков
    std::cout << "Можно ли 10 игроков в покер? "
              << (games[1].isValidCount(10) ? "да" : "нет") << "\n";
    std::cout << "\n";


    // ── 5. Массив Esports ──────────────────────────────
    std::cout << "╔══════════════════════════════════╗\n"
              << "║        Массив: Esports           ║\n"
              << "╚══════════════════════════════════╝\n";

    Esports tournaments[3] = {
        Esports("The International 2025", false, "2026-10-01",
                10, false, "соревнование",2,10,"Valve rules",
                "Dota 2","PC",40000000.0,
                "IESF",16,false),
        Esports("ESL One Cologne", true, "2026-07-15",
                10, true, "соревнование",2,10,"HLTV rules",
                "CS2","PC",1000000.0,
                "ESIC",16,false),
        Esports("Worlds 2025", false, "2026-11-05",
                10, true, "соревнование",2,10,"Riot rules",
                "League of Legends","PC",2300000.0,
                "GEF",17,false)
    };

    for (int i = 0; i < 3; i++) {
        tournaments[i].matchReport();
    }

    // Фильтрация: только крупные турниры (призовой > $5M)
    std::cout << "Крупные турниры (призовой > $5 000 000):\n";
    for (int i = 0; i < 3; i++) {
        if (tournaments[i].getPrizePool() > 5000000.0)
            std::cout << "  → " << tournaments[i].getProcessName()
                      << " ($" << tournaments[i].getPrizePool() << ")\n";
    }

    // Проверка допуска для разных возрастов
    std::cout << "\nПроверка допуска участников:\n";
    int ages[3] = {14, 16, 20};
    for (int a : ages) {
        std::cout << "  Возраст " << a << " на The International: "
                  << (tournaments[0].isEligible(a) ? "допущен" : "не допущен")
                  << "\n";
    }

    return 0;
}