#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // enlarge n times
    int n = atoi(argv[1]);
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // define outfile's new infoheaders
    BITMAPINFOHEADER binew = bi;
    
    binew.biHeight = n*bi.biHeight;
    binew.biWidth = n*bi.biWidth;

    // determine new padding for outfile
    int newpadding = (4 - (binew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    binew.biSizeImage = ((sizeof(RGBTRIPLE)*binew.biWidth)+newpadding)*abs(binew.biHeight);
    
    BITMAPFILEHEADER bfnew = bf;
    bfnew.bfSize  = binew.biSizeImage + sizeof(BITMAPFILEHEADER)+ sizeof (BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfnew, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&binew, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int y=0; y<n;y++){
        
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
                // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                // Resize horizontally
            for(int x = 0; x < n; x++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
        }
        // then add padding
        for (int k = 0; k < newpadding; k++)
        {
            fputc(0x00, outptr);
        }
        // reset the file pointer back to the beginning of the line
        fseek(inptr, -sizeof(RGBTRIPLE)*bi.biWidth, SEEK_CUR);
        }
        // put the file pointer to the next line, passing over the padding, if any
        fseek(inptr, sizeof(RGBTRIPLE)*bi.biWidth+padding, SEEK_CUR);

        
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
