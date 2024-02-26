#ifndef INDEX_SEQUENCE_H
#define INDEX_SEQUENCE_H

#include "../int_list.h"


IntList* getIndexSequence(char *input, int initialOffset);
IntList* getIndexSequenceAndOffset(char *input, int initialOffset, int* finalOffset);


#endif
