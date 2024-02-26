#include <stdio.h>
#include "../int_list.h"

IntList* getIndexSequence(char *input, int initialOffset) {
	int index;
	int bytesRead = 0, indexOffset = 0;

	IntList *indexListHead = NULL;

	sscanf(input+initialOffset, "%d%n", &index, &indexOffset);
	bytesRead += indexOffset+initialOffset;
	indexListHead = addValue(indexListHead, index-1);

	while (sscanf(input + bytesRead, ".%d%n", &index, &indexOffset) == 1) {
		indexListHead = addValue(indexListHead, index-1);
		bytesRead += indexOffset;
	}
	return indexListHead;
}

IntList* getIndexSequenceAndOffset(char *input, int initialOffset, int *finalOffset) {
	int index;
	int bytesRead = 0, indexOffset = 0;

	IntList *indexListHead = NULL;

	sscanf(input+initialOffset, "%d%n", &index, &indexOffset);
		bytesRead += indexOffset+initialOffset;
	indexListHead = addValue(indexListHead, index-1);

	while (sscanf(input + bytesRead, ".%d%n", &index, &indexOffset) == 1) {
		indexListHead = addValue(indexListHead, index-1);
		bytesRead += indexOffset;
	}
	*finalOffset = bytesRead;
	return indexListHead;
}
