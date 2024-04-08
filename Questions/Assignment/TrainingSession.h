#ifndef TRAININGSESSION_H
#define TRAININGSESSION_H

#include <iostream>
#include "DateTime.h"
class TrainingSession
{
private:
    /* data */
    /* data */
    int m_duration;
    unsigned int m_student_present;

    std::string m_session_topic;
    DateTime *m_date_time;

public:
    TrainingSession(/* args */) = delete;
    TrainingSession(const TrainingSession &) = delete;
    TrainingSession(const TrainingSession &&) = delete;
    TrainingSession operator=(const TrainingSession &) = delete;
    TrainingSession operator=(const TrainingSession &&) = delete;
    TrainingSession(int duration, unsigned int student_present, std::string session_topic, DateTime *date_time);
    ~TrainingSession() { delete m_date_time; }

    int duration() const { return m_duration; }
    void setDuration(int duration) { m_duration = duration; }

    unsigned int studentCount() const { return m_student_present; }
    void setStudentCount(unsigned int student_present) { m_student_present = student_present; }

    std::string sessionTopic() const { return m_session_topic; }
    void setSessionTopic(const std::string &session_topic) { m_session_topic = session_topic; }

    DateTime *dateTime() const { return m_date_time; }

    friend std::ostream &operator<<(std::ostream &os, const TrainingSession &rhs);
};

#endif // TRAININGSESSION_H
