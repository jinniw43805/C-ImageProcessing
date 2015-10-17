#include "function.h"
#include <math.h>

byte* image = readBmpFile("Result_noise.bmp");


int main(){
	

	printf("Height : %d\n",height);
	printf("Width : %d\n",width);
	
	byte* result;
	int x,y;
    int sum;
	int array[3][3]={-1,0,1,-1,0,1,-1,0,1};
	result=new byte[width*height];
	
	for(int i=1;i<height-1;i++){
		for(int j=1;j<width-1;j++){
			x=0;
			y=0;
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					x+=image[(i-1+k)*width+(j-1+l)]*array[k][l];
					y+=image[(i-1+k)*width+(j-1+l)]*array[k][l];
				}
				
			}
			sum=sqrt(x*1.0*x + y*y*1.0);
		if(sum<0)
			sum=0;
		else if(sum>255)
			sum=255;
		result[i*width+j]=sum;
		}
		
	}
	writeBmpFile("result.bmp",result);
	free(image);
	free(result);
	system("pause");	

}

