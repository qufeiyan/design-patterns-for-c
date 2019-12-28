#include <stdio.h>
#include "inc/FactoryMethod.h"


int main() {
    printf("Hello, World!\n");

    DevelopmentManager *devManager = createDevelopmentManager();
    devManager->hiringManager.takeInterview(&devManager->hiringManager);

    devManager = createMarketingManager();
    devManager->hiringManager.takeInterview(&devManager->hiringManager);

    return 0;
}
