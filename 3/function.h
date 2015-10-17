#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

BITMAPFILEHEADER  fileHeader;     //BMP���Y���c
BITMAPINFOHEADER  infoHeader;     //BMP��Ƶ��c
RGBQUAD rgb[256];      //�զ�L
byte *readFileData;    //�Ϥ����
int height;   //�Ϫ��� 
int width;    //�Ϫ��e 

void writeBmpFile(char *fileName, byte *writeFileData)
{
    FILE *file = fopen(fileName, "wb");//�}��file
   
    fwrite((byte*)&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);//�g�JBITMAPFILEHEADER
    fwrite((byte*)&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);//�g�JBITMAPINFOHEADER
    fwrite((byte*)&rgb, sizeof(rgb), 1, file);//�g�J�զ�L 
    fwrite((byte*)writeFileData, sizeof(byte)*(infoHeader.biHeight)*(infoHeader.biWidth), 1, file);//�g�JImage data

    fclose(file);    //����file3
}

byte *readBmpFile(char *fileName)
{
    FILE *file = fopen(fileName, "rb");//�}��file

    fread((byte*)&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);//Ū��BITMAPFILEHEADER
    fread((byte*)&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);//Ū��BITMAPINFOHEADER
    fread((byte*)&rgb, sizeof(rgb), 1, file);//Ū���զ�L 
    
    readFileData = (byte*)malloc(sizeof(byte)*infoHeader.biHeight*infoHeader.biWidth);//malloc fileData
    fread(readFileData,sizeof(byte)*(infoHeader.biHeight)*(infoHeader.biWidth),1,file);//Ū��Image1 data         

	height = infoHeader.biHeight;//�]�w�Ϫ���
	width = infoHeader.biWidth;//�]�w�Ϫ��e
    
	fclose(file);//����file

	return readFileData;
}
