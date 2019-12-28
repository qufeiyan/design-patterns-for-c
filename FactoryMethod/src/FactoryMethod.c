//
// Created by Elena on 2019/12/26.
//

#include "malloc.h"
#include "stdio.h"
#include "../inc/FactoryMethod.h"

static inline void askQuestions(){
    printf("Asking about design patterns!\n");
}
Developer *createDeveloper(void){
    Developer *obj = malloc(sizeof(Developer));
    obj->interviewer.askQuestion = askQuestions;
    return obj;
}
void deleteDeveloper(Developer *obj){
    free(obj);
}


static inline void askQuestions_(){
    printf("Asking about community building!\n");
}
CommunityExecutive *createCommunityExecutive(void){
    CommunityExecutive *obj = malloc(sizeof(CommunityExecutive));
    obj->interviewer.askQuestion = askQuestions_;
    return obj;
}
void deleteCommunityExecutive(CommunityExecutive *obj){
    free(obj);
}

static inline void takeInterview(HiringManager *obj){
    Interviewer *interviewer = obj->makeInterviewer();
    interviewer->askQuestion();
}

Interviewer *makeInterviewerForDevelopmentManager(){
    return (Interviewer *)createDeveloper();
}

DevelopmentManager *createDevelopmentManager(){
    DevelopmentManager *obj = malloc(sizeof(DevelopmentManager));
    obj->hiringManager.makeInterviewer = makeInterviewerForDevelopmentManager;
    obj->hiringManager.takeInterview = takeInterview;
    return obj;
}
void deleteDevelopmentManager(DevelopmentManager *obj){
    free(obj);
}

Interviewer *makeInterviewerForMarketingManager(){
    return (Interviewer *)createCommunityExecutive();
}
MarketingManager *createMarketingManager(){
    MarketingManager *obj = malloc(sizeof(MarketingManager));
    obj->hiringManager.takeInterview = takeInterview;
    obj->hiringManager.makeInterviewer = makeInterviewerForMarketingManager;
    return obj;
}
void deleteMarketingManager(MarketingManager *obj){
    free(obj);
}



