#include "function.h"
#include <math.h>

byte* image = readBmpFile("noise.bmp");
byte* result_image = image;
int aver(int,int);
int filiter=120;
int cal(int,int);
int main(){

	printf("Height : %d\n",height);
	printf("Width : %d\n",width);

	int aver_num;
	int count=0;
		for(int i = 1 ; i<height-1 ;i++)
			for(int j = 1 ; j< width-1 ;j++){
			     printf("return : %d , current :%d\n",cal(i,j),image[i*width+j]);
			     if( cal(i,j) - image[i*width+j] > filiter || image[i*width+j] -cal(i,j) > filiter) {
                    result_image[i*width+j] = cal(i,j);
                }else{
                    result_image[i*width+j] = image[i*width + j] ;
                }
            }
            //image[i*width+j] = cal(i,j);

	writeBmpFile("Result.bmp" , result_image );
	free( image );
	free(result_image);
	system("pause");
	return 0;
}


int aver(int b ,int c){
	int ans=0,i,j;
	int flag=0;
	for(i=b-1 ; i<=b+1 ; i++){
		for(j=c-1 ; j<=c+1 ; j++){

				flag++;
				ans+=image[i*width+j];

		}
	}

	printf("flag:%d\n",flag);
	//return round((ans/flag));

}
int cal(int i,int j){
    int result=0;
    int ccount=0;
    for (int row=i-1;row<=i+1;row++){
        for(int col=j-1;col<=j+1;col++){
            if(i==row&&j==col){
                //do nothing
            }else{
                //do cal
                ccount++;
                result+=image[row*width+col];
            }
        }
    }
    //printf("count:%d",ccount);
    return result/8;
}
