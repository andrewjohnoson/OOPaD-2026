#ifndef OOPAD_2026_HUMANACTIVITY_H
#define OOPAD_2026_HUMANACTIVITY_H

#include "Process.h"

class HumanActivity : public Process {
protected:
    int participantCount;
    bool requiresPhysical;
    string purpose;
public:
    HumanActivity() : Process("", false, ""), participantCount(0), requiresPhysical(false), purpose("") {}
    HumanActivity(const std::string &, bool, const std::string &, int, bool, const std::string &);
    HumanActivity(const HumanActivity &human_activity) : Process(human_activity), participantCount(human_activity.participantCount),
                requiresPhysical(human_activity.requiresPhysical), purpose(human_activity.purpose) {};

    ~HumanActivity() = default;

    int getParticipantCount() const;
    bool getRequires_physical() const;
    string getPurpose() const;

    void setParticipantCount(int participant_count);
    void setRequiresPhysical(bool requires_physical);
    void setPurpose(const string &purposeStr);

    std::string getDescription() const;
    void print() override;
};


#endif //OOPAD_2026_HUMANACTIVITY_H