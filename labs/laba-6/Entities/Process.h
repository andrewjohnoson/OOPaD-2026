// Process.h
#ifndef OOPAD_2026_PROCESS_H
#define OOPAD_2026_PROCESS_H

#include "../../../libs/Date.h"
#include <string>
using namespace std;

class Process {
protected:
    string processName;
    bool isRunning;
    Date startDate;
public:
    Process() : processName(""), isRunning(false), startDate(Date()) {};
    Process(const string &processName = "", bool isRunning = false, const string &startDate = "") : processName(processName), isRunning(isRunning), startDate(startDate) {};
    Process(const Process &p) : processName(p.processName), isRunning(p.isRunning), startDate(p.startDate) {};
    virtual ~Process() = default;

    Date getStartDate() const;
    bool getIsRunning() const;
    string getProcessName() const;

    void setProcessName(const string &);
    void setIsRunning(bool);
    void setStartDate(const std::string &);

    void start();
    void stop();

    virtual void print();
};


#endif //OOPAD_2026_PROCESS_H