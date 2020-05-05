/* Recovers the JPEG files from a raw data*/

#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    // check for correct number of input arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    
    // infile name
    char *infile = argv[1];
    
    // open input file
    FILE *inptr = fopen(infile, "r");
    // check if inputfile can be opened
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    //block size of FAT file
    int blocksize = 512;
    int jpgcount = 0;
    uint8_t ptr[blocksize];
    char filename[7];
    FILE *outptr[55];
    // loop through infile until the EOF
    while (fread(&ptr, blocksize, 1, inptr) == 1)
    {
        // check the initial bytes of the block for first JPEG
        if(jpgcount == 0 && ptr[0] == 0xff && ptr[1]==0xd8 && ptr[2]==0xff && (ptr[3] & 0xf0) == 0xe0)
        {
            jpgcount++;
            sprintf(filename, "%03i.jpg", jpgcount-1);
            outptr[jpgcount-1] = fopen(filename, "w");
            // write the first block
            fwrite(&ptr, blocksize, 1, outptr[jpgcount-1]);
        }
        // if not the first jpeg
        else if(jpgcount > 0 && ptr[0] == 0xff && ptr[1]==0xd8 && ptr[2]==0xff && (ptr[3] & 0xf0) == 0xe0)
        {
            jpgcount++;
            fclose(outptr[jpgcount-2]);
            sprintf(filename, "%03i.jpg", jpgcount-1);
            // open first file to write
            outptr[jpgcount-1] = fopen(filename, "w");
            // write the first block
            fwrite(&ptr, blocksize, 1, outptr[jpgcount-1]);
        }
        // if there is a file already opened, continue writing
        else if (jpgcount > 0)
        {
            fwrite(&ptr, blocksize, 1, outptr[jpgcount-1]);
        }
    }
    fclose(inptr);
    fclose(outptr[jpgcount-1]);
    
}