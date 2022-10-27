#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE *original = NULL;
	FILE *target_file = NULL;
	original = fopen("_odd.yuv", "rb"); 
	target_file = fopen("_oddDownFrame.yuv", "wb");   
	
	int resolution_size = 1280 * 720; 
	unsigned char* frame = (unsigned char*)malloc(resolution_size); 
    unsigned char* pixel = (unsigned char*)malloc(1); 

    int t = 0;
    for (int raw_num = 0; raw_num < 720 * 30; raw_num++){
        if (t==0){
            int temp = 0;

            for(int pixel_num = 0; pixel_num < 1280; pixel_num++){
                memset(pixel, 0, 1);
                fread(pixel, sizeof(unsigned char), 1, original);

                if (temp==0){
                    fwrite(pixel, sizeof(unsigned char), 1, target_file);
                    temp = 1;
                }
                else{
                    temp = 0;
                }
            }
            t = 1;
        }
        else{
            for(int pixel_num = 0; pixel_num < 1280; pixel_num++){
                memset(pixel, 0, 1);
                fread(pixel, sizeof(unsigned char), 1, original);
            }
            t = 0;
        }
    }

	
	free(frame);
	fclose(original);
	fclose(target_file);
	return 0;
}