#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const char *shift(int *argc,char ***argv){
    assert(*argc>0);
    const char *result=(*argv)[0];
    (*argc)--;
    (*argv)++;
    return result;
}

void print_env(int argc, char *argv[]){
    for(int i=0;i<argc;i++){
        printf("%s ",argv[i]);
    }
    
    printf("\n");
}

int main(int argc, char *argv[]){


    shift(&argc,&argv); //skip program name

    if (argc <= 1){
        fprintf(stderr,"Usage: png2 <file_path.png> <name>\n");
        exit(1);
    }

    const char *file_path = shift(&argc,&argv);
    const char *name = shift(&argc,&argv);

    int width,height,n;
    width=height=n=0;
    //force convert to 4 bytes  rgba data
    uint32_t *data = (uint32_t*)stbi_load(file_path,&width,&height,&n,4);

    printf("#ifndef PNG_%s_H\n",name);
    printf("#define PNG_%s_H\n",name);
    printf("size_t %s_width = %d\n",name,width);
    printf("size_t %s_height = %d\n",name,height);
    printf("uint32_t %s_data[] = {",name);
    for(size_t i=0; i<(size_t)(width*height);i++){
        printf("0x%x, ",data[i]);
    }

    printf("};\n");
    printf("#endif // PNG_%s_H\n",name);

    printf("\n");
    return 0;
}