// EntitiesManager.cpp
#include "EntitiesManager.h"

#include <fstream>

#include "../../../libs/CheckInput.h"
#include "../../../libs/TerminalController.h"

std::vector <Process> EntitiesManager::processes{Process("Компиляция", true, "2026-05-12"),
    Process("Резервное копирование", false, "2026-05-12"),
    Process("Обновление системы", true, "2026-05-12")};

std::vector <CompetitiveSport> EntitiesManager::competitiveSports {CompetitiveSport("FIFA", 16, true),
    CompetitiveSport("FIDE", 0,  false),
    CompetitiveSport("IESF", 16, false)};

std::vector <HumanActivity> EntitiesManager::humanActivities {HumanActivity("Рисование", true, "2026-05-12", 1,  false, "творчество"),
    HumanActivity("Командный забег", true, "2026-05-13", 20, true,  "спорт"),
    HumanActivity("Лекция", false, "2026-05-14", 50, false, "обучение")};

std::vector <Game> EntitiesManager::games {Game("Шахматы", true, "2026-05-12", 2, false, "соревнование", 2, 2, "FIDE rules"),
    Game("Покер", false, "2026-05-13", 6, false, "развлечение", 2, 9, "Texas Hold'em"),
    Game("Баскетбол 3x3", false, "2026-05-14", 6, true, "соревнование", 4, 6, "FIBA 3x3")
};
std::vector <Esports> EntitiesManager::esports {
    Esports("The International 2025", true, "2026-10-01",
            10, true, "соревнование", 2, 10, "Valve rules",
            "Dota 2", "PC", 40000000.0,
            "IESF", 16, false),
    Esports("ESL One Cologne", false, "2026-07-15",
            10, true, "соревнование", 2, 10, "HLTV rules",
            "CS2", "PC", 1000000.0,
            "ESIC", 16, false),
    Esports("Worlds 2025", true, "2026-11-05",
            10, true, "соревнование", 2, 10, "Riot rules",
            "League of Legends", "PC", 2300000.0,
            "GEF", 17, false)
};

void EntitiesManager::addEntity(const int type) {
    TerminalController::clearTerminal();

    std::cout << "Сколько записей хотите добавить (введите -1 для выхода): ";
    const int n = CheckInput::inputIndex();

    if (n == -1) {
        TerminalController::waitForClick();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (type == PROCESS) {
            std::string processName;
            std::cout << "Введите название процесса: ";
            std::getline(std::cin, processName);

            std::cout << "Процесс запущен (да - 1, нет - 0): ";
            bool isTrue;
            while (true) {
                int answer = CheckInput::inputInt();
                if (answer == 1) {
                    isTrue = true;
                    break;
                }

                if (answer == 0) {
                    isTrue = false;
                    break;
                }

                std::cout << "Неверный ответ" << std::endl << "Повторите ввод: " << std::flush;
            }

            std::string processDate;
            while (true) {
                std::cout << "Введите год начала процесса: ";
                int year = CheckInput::inputYear();

                std::cout << "Введите месяц начала процесса: ";
                int month = CheckInput::inputMonth();

                std::cout << "Введите день начала процесса: ";
                int day = CheckInput::inputDay(year, month);

                processDate += std::to_string(year) + '-' + (month < 10 ? "0" + to_string(month) : to_string(month)) + '-' +
                    (day < 10 ? "0" + to_string(day) : to_string(day));

                if (Date::isValidFormat(processDate)) {
                    break;
                }

                std::cout << "Дата неверно введена. Повторите ввод." << std::endl;
                processDate.clear();
            }

            const Process p = Process(processName, isTrue, processDate);
            processes.push_back(p);
        }

        if (type == HUMAN_ACTIVITY) {
            std::string processName;
            std::cout << "Введите название процесса: ";
            std::getline(std::cin, processName);

            std::cout << "Введите количество участников: ";
            int amount = CheckInput::inputInt();

            std::string purpose;
            std::cout << "Введите цель процесса: ";
            std::getline(std::cin, purpose);

            std::cout << "Процесс запущен (да - 1, нет - 0): ";
            bool isRunning;
            while (true) {
                int answer = CheckInput::inputInt();
                if (answer == 1) {
                    isRunning = true;
                    break;
                }

                if (answer == 0) {
                    isRunning = false;
                    break;
                }

                std::cout << "Неверный ответ" << std::endl << "Повторите ввод: " << std::flush;
            }

            std::cout << "Требует физической нагрузки (да - 1, нет - 0): ";
            bool requiresPhysics;
            while (true) {
                int answer = CheckInput::inputInt();
                if (answer == 1) {
                    requiresPhysics = true;
                    break;
                }

                if (answer == 0) {
                    requiresPhysics = false;
                    break;
                }

                std::cout << "Неверный ответ" << std::endl << "Повторите ввод: " << std::flush;
            }

            std::string processDate;
            while (true) {
                std::cout << "Введите год начала процесса: ";
                int year = CheckInput::inputYear();

                std::cout << "Введите месяц начала процесса: ";
                int month = CheckInput::inputMonth();

                std::cout << "Введите день начала процесса: ";
                int day = CheckInput::inputDay(year, month);

                processDate += std::to_string(year) + '-' + (month < 10 ? "0" + to_string(month) : to_string(month)) + '-' +
                    (day < 10 ? "0" + to_string(day) : to_string(day));

                if (Date::isValidFormat(processDate)) {
                    break;
                }

                std::cout << "Дата неверно введена. Повторите ввод." << std::endl;
                processDate.clear();
            }

            const HumanActivity p = HumanActivity(processName, isRunning, processDate, amount, requiresPhysics, purpose);
            humanActivities.push_back(p);
        }

        if (type == GAME) {
            std::string processName;
            std::cout << "Введите процесса: ";
            std::getline(std::cin, processName);

            std::cout << "Введите минимальное количество игроков: ";
            int minAmount = CheckInput::inputInt();

            std::cout << "Введите максимальное количество игроков: ";
            int maxAmount = CheckInput::inputInt();

            std::string rules;
            std::cout << "Введите правила: ";
            std::getline(std::cin, rules);

            Game g = Game(processName, false, "", 0, false, "", minAmount, maxAmount, rules);
            games.push_back(g);
        }

        if (type == ESPORTS) {
            std::string processName;
            std::cout << "Введите название процесса: ";
            std::getline(std::cin, processName);

            std::string gameName;
            std::cout << "Введите название киберспортивной игры: ";
            std::getline(std::cin, gameName);

            std::string platform;
            std::cout << "Введите платформу: ";
            std::getline(std::cin, platform);

            std::string federation;
            std::cout << "Введите федерацию: ";
            std::getline(std::cin, federation);

            std::cout << "Призовой фонд: ";
            double prize = CheckInput::inputDouble();

            std::cout << "Количество участников: ";
            int participantsCount = CheckInput::inputInt();

            std::cout << "Минимальный возраст: ";
            int minAge = CheckInput::inputInt();

            std::cout << "Олимпийский вид спорта (да - 1, нет - 0): ";
            bool isOlympic;
            while (true) {
                int answer = CheckInput::inputInt();
                if (answer == 1) {
                    isOlympic = true;
                    break;
                }

                if (answer == 0) {
                    isOlympic = false;
                    break;
                }

                std::cout << "Неверный ответ" << std::endl << "Повторите ввод: " << std::flush;
            }

            std::string processDate;
            while (true) {
                std::cout << "Введите год начала процесса: ";
                int year = CheckInput::inputYear();

                std::cout << "Введите месяц начала процесса: ";
                int month = CheckInput::inputMonth();

                std::cout << "Введите день начала процесса: ";
                int day = CheckInput::inputDay(year, month);

                processDate += std::to_string(year) + '-' + (month < 10 ? "0" + to_string(month) : to_string(month)) + '-' +
                    (day < 10 ? "0" + to_string(day) : to_string(day));

                if (Date::isValidFormat(processDate)) {
                    break;
                }

                std::cout << "Дата неверно введена. Повторите ввод." << std::endl;
                processDate.clear();
            }

            const Esports e = Esports(processName, true, processDate, participantsCount,
                    false, "", 0, 0, "", gameName, platform, prize, federation, minAge, isOlympic);
            esports.push_back(e);
        }

        if (type == COMPETITIVE_SPORT) {
            std::string federation;
            std::cout << "Введите название федерации: ";
            std::getline(std::cin, federation);

            std::cout << "Введите минимальный возраст: ";
            int minAge = CheckInput::inputInt();

            std::cout << "Олимпийский вид спорта (да - 1, нет - 0): ";
            bool isOlympic;
            while (true) {
                int answer = CheckInput::inputInt();
                if (answer == 1) {
                    isOlympic = true;
                    break;
                }

                if (answer == 0) {
                    isOlympic = false;
                    break;
                }

                std::cout << "Неверный ответ" << std::endl << "Повторите ввод: " << std::flush;
            }

            const CompetitiveSport c = CompetitiveSport(federation, minAge, isOlympic);
            competitiveSports.push_back(c);
        }
        std::cout << std::endl;
    }
}

void EntitiesManager::showEntities(const int type) {
    while (true) {
        TerminalController::clearTerminal();
        if (type == PROCESS) {
            std::cout << "╔══════════════════════════════════╗\n"
                  << "║       Массив: Process            ║\n"
                  << "╚══════════════════════════════════╝\n";

            for (Process& p : processes) {
                p.print();
                std::cout << std::endl;
            }
            std::cout << std::endl;

        }

        if (type == HUMAN_ACTIVITY) {
            std::cout << "╔══════════════════════════════════╗\n"
                  << "║     Массив: HumanActivity        ║\n"
                  << "╚══════════════════════════════════╝\n";

            for (HumanActivity& h : humanActivities) {
                h.print();
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        if (type == GAME) {
            std::cout << "╔══════════════════════════════════╗\n"
                  << "║        Массив: Game              ║\n"
                  << "╚══════════════════════════════════╝\n";

            for (Game& g : games) {
                g.print();
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }


        if (type == ESPORTS) {
            std::cout << "╔══════════════════════════════════╗\n"
                  << "║        Массив: Esports           ║\n"
                  << "╚══════════════════════════════════╝\n";

            for (Esports& e : esports) {
                e.matchReport();
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        if (type == COMPETITIVE_SPORT) {
            std::cout << "Введите возраст, который хотите проверить для вида спорта: ";
            int testAge = CheckInput::inputInt();

            std::cout << "╔══════════════════════════════════╗\n"
                    <<   "║    Массив: CompetitiveSport      ║\n"
                      << "╚══════════════════════════════════╝\n";

            for (CompetitiveSport& c : competitiveSports) {
                c.print();
                std::cout << "  | Допуск для возраста " << testAge << ": "
                          << (c.isEligible(testAge) ? "допущен" : "не допущен")
                          << std::endl;
            }

            std::cout << std::endl;
        }

        std::cout << "Нажмите C, если хотите добавить запись. Или другую клавишу для выхода." << std::flush;
        const char button = TerminalController::getch();
        if (button == 'c') {
            addEntity(type);
        } else {
            break;
        }
    }
}