//file processing:
//stdio.h kütüphanesi üzerinden gerçekleştirilir

//text dosya açarken kullanılan modlar:

//"r":  
//okumak için dosyayı açar
//dosya yoksa hata verir
//"w":  
//yazmak için dosyayı açar
//dosya varsa dosyanın içeriğini siler
//"a":  
//eklemek için dosyayı açar
//dosya yoksa oluşturur

//binary dosya açarken kullanılan modlar:

//"rb":  
//okumak için dosyayı açar
//dosya yoksa hata verir
//"wb":  
//yazmak için dosyayı açar
//dosya varsa dosyanın içeriğini siler
//"ab":  
//eklemek için dosyayı açar
//dosya yoksa oluşturur

//fopen():
//dosyayı açar

//fclose():
//dosyayı kapatır

//feof():
//dosyanın sonuna gelinip gelinmediğini kontrol eder

//fprintf():
//dosyaya text yazar

//fgetc():
//dosyadan text karakter okur

//fgets():
//dosyadan text satır okur

//fwrite():
//dosyaya binary yazar

//fread():
//dosyadan binary okur

#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt","w");
    //dosyayı yazma modunda açma

    if(file == NULL){
        printf("dosya acilamadi \n");
        return 1;
    }
    //dosya açılamadıysa hata verir

    fprintf(file,"hello world! \n");
    fprintf(file,"hiiii! \n");
    fprintf(file,"hello! \n");
    //dosyaya yazar

    fclose(file);
    //dosyayı kapatır
    
    return 0;
}