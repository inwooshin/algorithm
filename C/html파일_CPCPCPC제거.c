#include <stdio.h>
#include <string.h>

int main(void) {

	FILE* file = fopen("input.txt", "r");
	FILE* nomark = fopen("nomarkers.txt", "w");
	FILE* marked_index = fopen("marked_index.txt", "w");

	char a_tmp[40] = { 0, }, b_tmp[40] = { 0, };
	char a[2000] = { 0, }, b[40] = { 0, };
	char all[3000] = { 0 , };
	char tmp = 0;

	int count = 0, cp_count = 0, Cbef = 0, upOn = 0, j;
	int first = 0, last = 0, on = 0, retry  = 0;


	while (fgets(a, 2000, file) != NULL) {
		printf("%s", a);
		for (int i = 0; sizeof(a); i++) {
			if (a[i] == '\0') break;
			if (i + 8 > 200) break;
			if (strncmp(&a[i], "CPCPCPC{", 8) == 0) {
				first = i + 8 + (200 * retry);

				for (j = i + 8; strncmp(&a[j], "CPCPCPC}", 8) != 0; j++){
					fprintf(nomark, "%c", a[j]);
					all[count] = a[j];
					count++;
				}

				last = j + 7 + (200 * retry);
				i = j + 7;
				all[count] = ' ';
				count++;
				fprintf(marked_index, "%d, %d\n", first, last);
			}
			else {
				fprintf(nomark, "%c", a[i]);
			}
			retry++;
		}
	}

	fclose(file);
	fclose(nomark);
	fclose(marked_index);
}