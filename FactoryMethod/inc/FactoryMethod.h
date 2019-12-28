//
// Created by Elena on 2019/12/26.
//

#ifndef FACTORYMETHOD_FACTORYMETHOD_H
#define FACTORYMETHOD_FACTORYMETHOD_H
#endif //FACTORYMETHOD_FACTORYMETHOD_H

#include "stdio.h"

/**
 * @brief Consider the case of a hiring manager.
 * It is impossible for one person to interview for each of the positions.
 * Based on the job opening, she has to decide and delegate the interview
 * steps to different people.
 */

#define class typedef struct
#define interface typedef struct

#define private
#define public
/**
 * @brief Taking our hiring manager example above.
 * First of all we have an interviewer interface and some implementations for it
 */
interface Interviewer{
    public void (*askQuestion)(void);

}Interviewer;

#define implements_Interviewer
class Developer implements_Interviewer{
    Interviewer interviewer;
}Developer;
Developer *createDeveloper(void);
void deleteDeveloper(Developer *obj);


class CommunityExecutive implements_Interviewer{
    Interviewer interviewer;
}CommunityExecutive;

CommunityExecutive *createCommunityExecutive(void);
void deleteCommunityExecutive(CommunityExecutive *obj);

//. Now let us create our HiringManager
#define abstract
abstract class HiringManager{
    //Factory method
    Interviewer* (*makeInterviewer)(void);
    void (*takeInterview)(struct HiringManager *);
}HiringManager;

//. Now any child can extend it and provide the required interviewer

#define extends_HiringManager
class DevelopmentManager extends_HiringManager{
    HiringManager hiringManager;
}DevelopmentManager;
DevelopmentManager *createDevelopmentManager(void);
void deleteDevelopmentManager(DevelopmentManager *obj);

class MarketingManager extends_HiringManager{
    HiringManager hiringManager;
}MarketingManager;

MarketingManager *createMarketingManager(void);
void deleteMarketingManager(MarketingManager *obj);

