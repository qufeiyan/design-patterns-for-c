#include <stdio.h>

#include "inc\Composite.h"

int main() {
    printf("Message from the orcs: \n");

    LetterComposite *orcMessage = newMessenger()->messageFromOrcs();
    orcMessage->print(orcMessage);

    LetterComposite *elfMessage = newMessenger()->messageFromElves();
    elfMessage->print(elfMessage);
    
    delSentence((Sentence*)orcMessage);
    delSentence((Sentence*)elfMessage);
    return 0;
}
