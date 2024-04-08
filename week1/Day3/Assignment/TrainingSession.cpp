#include "TrainingSession.h"

TrainingSession::TrainingSession(int duration,unsigned int student_present, std::string session_topic, DateTime *date_time)
:m_duration(duration),m_student_present(student_present),m_session_topic(session_topic),m_date_time(date_time)
{
}

std::ostream &operator<<(std::ostream &os, const TrainingSession &rhs) {
    os << "m_duration: " << rhs.m_duration
       << " m_student_present: " << rhs.m_student_present
       
       << " m_session_topic: " << rhs.m_session_topic
       << " m_date_time: " << *rhs.m_date_time;
    return os;
}
