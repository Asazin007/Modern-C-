#include "TrainingBatch.h"

TrainingBatch::~TrainingBatch()
{
    delete m_id;
    
    for (TrainingSession* &ts :m_sessions )
    {
        delete ts;
    }
    delete coordinator;
  
    for (Talents * &t :talents)
    {

        delete t;
    }
}

TrainingBatch::TrainingBatch(ID *id, unsigned int totalstudent, std::string trianername, std::vector<TrainingSession *> &sessions, Employee *coordinat, std::vector<Talents *> &talent)
    : m_id(id), total_student(totalstudent), m_trainername(trianername), m_sessions(sessions), coordinator(coordinat), talents(talent)
{
}
std::ostream &operator<<(std::ostream &os, const TrainingBatch &rhs) {
    os << "m_id: " << rhs.m_id
       << " total_student: " << rhs.total_student
       << " m_trainername: " << rhs.m_trainername<<std::endl
    
       << " coordinator: " << rhs.coordinator
       << " talents: ";
    return os;
}
