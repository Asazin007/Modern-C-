#include "Functionalities.h"
#include "EmptyContainerException.hpp"
std::vector<Talents *> talent;
std::vector<TrainingSession *> sessions;
void fillSession()
{
    sessions.push_back(new TrainingSession(9, 30, "smart pointer", new DateTime("21", Month::FEBRUARY, "2024", "8", "30")));
}
void fillTalents()
{
    talent.push_back(new Talents("Yuvraj Jangid",
                                 "219679",
                                 Grade::B,
                                 new Employee("Shreya Shikshi", "154845", new Employee("Nidhi", "133293", nullptr))));
}
void CreateObject(Container &data)
{
    fillSession();
    fillTalents();
    data.push_back(
        new TrainingBatch(
            new ID(Country::IN, 24, 1, Track::CPP, 1, Location::P, LEVEL::BT),
            34, "Harshit", sessions,
            new Employee("Shreya Shikshi", "154845",
                         new Employee("Nidhi", "133293", nullptr)),
            talent));
}

void DeleteObject(Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty\n");
    }

    for (TrainingBatch *batch : data)
    {

        delete batch;
    }
}
