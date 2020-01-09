#include <stdio.h>
#include "inc\Chain.h"

int main() {
    printf("Hello, World!\n");

    OrcKing *king = newOrcKing();
    Request *request = newRequest(DEFEND_CASTLE,"defend catsle");
    king->makeRequest(king,request);
    delRequest(request);

    request = newRequest(TORTURE_PRISONER,"torture prisoner");
    king->makeRequest(king,request);
    delRequest(request);

    request = newRequest(COLLECT_TAX,"collect tax");
    king->makeRequest(king,request);

    delRequest(request);
    delOrcKing(king);
    return 0;
}
