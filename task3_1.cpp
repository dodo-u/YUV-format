#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE *original = NULL;
	FILE *target_file = NULL;
	original = fopen("PeopleOnStreet_1280x720_30_Original.yuv", "rb"); 
	target_file = fopen("_odd.yuv", "wb");   
	
	int resolution_size = 1280 * 720; 
	unsigned char* frame = (unsigned char*)malloc(resolution_size); 

	for (int frame_num = 0; frame_num < 30; frame_num++) {
		
        memset(frame, 0, resolution_size);
        fread(frame, sizeof(unsigned char), resolution_size, original);
        fwrite(frame, sizeof(unsigned char), resolution_size, target_file);
        
        fread(frame, sizeof(unsigned char), resolution_size/2, original);
    
		
	}
	
	free(frame);
	fclose(original);
	fclose(target_file);
	return 0;
}