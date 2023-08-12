/**
author: Brennan Mitchell
course: CSc 352
description: This program takes an input file where the first
line is the key, and the following lines are messages to encrypt.
The program then encrypts the lines using the Beaufort Cypher,
and uses the first line as the key to the cypher.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 char key[128];
 char translate[128];
 char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 fgets(key, 127, stdin);
 int length = 0;
 while(fgets(translate, 127, stdin) != NULL)  {
 	int i = 0;
 	while (translate[i] != '\0') { 
		if (translate[i] == ' ' || translate[i] == '\n') {
			i++;
			continue;
		}  else {
			if (key[length] == '\n') {
				length = 0;
			}
			char curKey = key[length];
			char curTrans = translate[i];
			int alphaIndex = curKey - curTrans;
			if (alphaIndex < 0) {
				alphaIndex = 26 + alphaIndex;
			}
			translate[i] = alphabet[alphaIndex];
			length++;
		}
		i++;
	 }
 	printf("%s", translate);
 	}
 return 0;
}
