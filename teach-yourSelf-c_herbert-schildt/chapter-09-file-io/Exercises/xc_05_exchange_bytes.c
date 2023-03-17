#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2, *ftemp;
    char ch;
    char *temp_file = "temp_binary.jpg";

    // see if correct command line argument
    if (argc != 3) {
        printf("Useage: exchange <file 1> <file 2>\n");
        return 1;
    }


    // storge file 2 binay into temp file
    // open file 2 in reading mode
    if ((fp2 = fopen(argv[2], "rb")) == NULL) {
        printf("Cannot open the file 2 in reading mode.\n");
        return 1;
    }
     // open temp file in writing mode
    if ((ftemp = fopen(temp_file, "wb")) == NULL) {
        printf("Cannot open tempfile in Writing mode.\n");
        return 1;
    }
    // copy binary file 2 into temp
    while (!feof(fp2)) {
        ch = fgetc(fp2);
        if (ferror(fp2)) {
            printf("Error Reading file 2.\n");
            return 1;
        }
        if (!feof(fp2))
            fputc(ch, ftemp);
        if (ferror(ftemp)) {
            printf("Error Writing into temp file.\n");
            return 1;
        }
    }
    // closing file 2 in reading mode
    if (fclose(fp2) == EOF) {
        printf("Cannot closing the file 2 in reading mode.\n");
        return 1;
    }
    // closing temp file in writing mode
    if (fclose(ftemp) == EOF) {
        printf("Cannot closing temp file in writing mode.\n");
        return 1;
    }


    // Copy the file 1 binary into file 2
    // open file 1 in reading mode
    if ((fp1 = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open the file 1 in reading mode.\n");
        return 1;
    }
    // open file 2 in writing mode
    if ((fp2 = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open the file 2 in writing mode.\n");
        return 1;
    }

    // copy file 1 binary into file 2
    while (!feof(fp1)) {
        ch = fgetc(fp1);
        if (ferror(fp1)) {
            printf("Error reading the file 1.\n");
            return 1;
        }
        if (!feof(fp1))
            fputc(ch, fp2);
        if (ferror(fp2)) {
            printf("Error Writing file 1 into file 2.\n");
            return 1;
        }
    }
    // closing file 1 in reading mode
    if (fclose(fp1) == EOF) {
        printf("Cannot closing the file 1 in reading mode.\n");
        return 1;
    }
    // closing file 2 in writing mode
    if (fclose(fp2) == EOF) {
        printf("Cannot closing the file 2 in writing mode.\n");
        return 1;
    }


    // copy temp into file 1
    //open temp file in reading mode
    if ((ftemp = fopen(temp_file, "rb")) == NULL) {
        printf("Cannot open temp file in reading mode.\n");
        return 1;
    }
    // open file 1 in writing mode
    if ((fp1 = fopen(argv[1], "wb")) == NULL) {
        printf("Cannot open file 1 in writing mode.\n");
        return 1;
    }
    // copy temp file binary into file 1
    while (!feof(ftemp)) {
        ch = fgetc(ftemp);
        if (ferror(ftemp)) {
            printf("Error Reading the temp file.\n");
            return 1;
        }
        if (!feof(ftemp))
            fputc(ch, fp1);
        if (ferror(fp1)) {
            printf("Error Writing temp binary into file 1.\n");
            return 1;
        }
    }
    // closing temp file in reading mode
    if (fclose(ftemp) == EOF) {
        printf("Cannot closing temp file in reading mode.\n");
        return 1;
    }
    // closing file 1 in writing mode
    if (fclose(fp1) == EOF) {
        printf("Cannot closing file 1 in writing mode.\n");
        return 1;
    }

    remove(temp_file);

    return 0;
}