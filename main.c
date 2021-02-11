#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *in;
	FILE *out;
	char line[200];
	char outFile[200] = {};
	// read file
	if (!(in = fopen("./selisih.in", "r"))) {
		printf("Canot read the file \n");
	} else {
		while (!feof(in)) {
			fgets(line, sizeof(line), in);
			char *lineData = strtok(line, " ");
			int loopIndex = 0;
			char *lineArray[2];
			while (lineData != NULL) {
				if (lineData != NULL) {
					lineArray[loopIndex] = lineData;
					loopIndex++;
				}
				lineData = strtok(NULL, " ");
			}
			int diffData = abs(atoi(lineArray[0]) - atoi(lineArray[1]));
			sprintf(outFile, "%s %d\n", (outFile[0] ? outFile : ""), diffData);
		}
	}
	fclose(in);
	// write file
	if (!(out = fopen("selisih.out", "w"))) {
		printf("Canot write the file\n");
	} else {
		fprintf(out, "%s", outFile);
	}
	fclose(out);
	printf("Process has done :)");
	return 0;
}