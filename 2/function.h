#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

BITMAPFILEHEADER  fileHeader;     //BMP檔頭結構
BITMAPINFOHEADER  infoHeader;     //BMP資料結構
RGBQUAD rgb[256];      //調色盤
byte *readFileData;    //圖片資料
int height;   //圖的高 
int width;    //圖的寬 

void writeBmpFile(char *fileName, byte *writeFileData)
{
    FILE *file = fopen(fileName, "wb");//開啟file
   
    fwrite((byte*)&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);//寫入BITMAPFILEHEADER
    fwrite((byte*)&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);//寫入BITMAPINFOHEADER
    fwrite((byte*)&rgb, sizeof(rgb), 1, file);//寫入調色盤 
    fwrite((byte*)writeFileData, sizeof(byte)*(infoHeader.biHeight)*(infoHeader.biWidth), 1, file);//寫入Image data

    fclose(file);    //關閉file3
}

byte *readBmpFile(char *fileName)
{
    FILE *file = fopen(fileName, "rb");//開啟file

    fread((byte*)&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);//讀取BITMAPFILEHEADER
    fread((byte*)&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);//讀取BITMAPINFOHEADER
    fread((byte*)&rgb, sizeof(rgb), 1, file);//讀取調色盤 
    
    readFileData = (byte*)malloc(sizeof(byte)*infoHeader.biHeight*infoHeader.biWidth);//malloc fileData
    fread(readFileData,sizeof(byte)*(infoHeader.biHeight)*(infoHeader.biWidth),1,file);//讀取Image1 data         

	height = infoHeader.biHeight;//設定圖的高
	width = infoHeader.biWidth;//設定圖的寬
    
	fclose(file);//關閉file

	return readFileData;
}
