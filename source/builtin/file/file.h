// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

long cGetFileSize(char *filename)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)  
    {
        printf("\nERROR: while trying to read text file '%s': ", filename);
        printf("unknown file\n");
        exit(1);
    }

    if (fseek(fp, 0, SEEK_END) < 0) 
    {
        printf("\nERROR: while reading text file '%s': ", filename);
        printf("failed to read the entire file\n");
        fclose(fp);
        exit(1);
    }

    long size = ftell(fp);

    fclose(fp);
    return size;
}

// function cReadFile does NOT include extra byte for the NULL/terminator character
void cReadFile(char *filename, char *buffer, long fileSize) 
{        
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("\nERROR: while trying to read text file '%s': ", filename);
        printf("unknown file\n");
        exit(1);
    }

    // Read the entire file into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, fp);
    if (bytesRead != (size_t) fileSize) 
    {
        printf("\nERROR: while reading text file '%s': ", filename);
        printf("failed to read the entire file\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
}

///////////////////////////////////////////////////////////////////////////////

String readTextFile(String *filename)
{
    if (filename->size == 0) {    
        printf("\nERROR: cannot read text file: file name is blank\n");
        exit(1);     
    }

    // c filename
    char cFilename[filename->size + 1];
    memcpy(cFilename, filename->data, filename->size);
    cFilename[filename->size] = 0;
    
    long fileSize = cGetFileSize(cFilename);

    char *buffer = malloc(fileSize);
    
    cReadFile(cFilename, buffer, fileSize);

    // checking if is good string
    for (long index = 0; index < fileSize; index++)
    {
        if (buffer[index] > 31) { continue; }
        if (buffer[index] == '\n') { continue; }
        if (buffer[index] == '\r') { continue; }
        if (buffer[index] == '\t') { continue; }
        
        printf("\nERROR: while reading text file '%s': ", cFilename);
        printf("found invalid character (code %d) at position %li\n", buffer[index], index);
        exit(1);    
    }
    
    String string = { fileSize, buffer };
    
    return string;
}

