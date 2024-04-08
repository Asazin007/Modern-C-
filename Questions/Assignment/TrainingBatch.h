#ifndef TRAININGBATCH_H
#define TRAININGBATCH_H

#include <iostream>
#include <vector>
#include "ID.h"
#include "DateTime.h"
#include "Talents.h"
#include "TrainingSession.h"

class TrainingBatch
{
private:
    ID *m_id;
    unsigned int total_student;
    std::string m_trainername;
    std::vector<TrainingSession *> m_sessions;
    Employee *coordinator;

    std::vector<Talents *> talents;

public:
    TrainingBatch(/* args */) = delete;
    TrainingBatch(const TrainingBatch &) = delete;
    TrainingBatch(const TrainingBatch &&) = delete;
    TrainingBatch operator=(const TrainingBatch &) = delete;
    TrainingBatch operator=(const TrainingBatch &&) = delete;
    ~TrainingBatch();
    TrainingBatch(ID *id, unsigned int totalstudent, std::string trainername, std::vector<TrainingSession *> &sessions, Employee *coordinat, std::vector<Talents*> &talent);

    ID *id() const { return m_id; }

    unsigned int totalStudent() const { return total_student; }

    std::string trainername() const { return m_trainername; }

    std::vector<TrainingSession *> sessions() const { return m_sessions; }

    Employee *getCoordinator() const { return coordinator; }

    std::vector<Talents *> getTalents() const { return talents; }

    // std::vector<Employee *> getTalents() const { return talents; }

    friend std::ostream &operator<<(std::ostream &os, const TrainingBatch &rhs);
};

#endif // TRAININGBATCH_H
