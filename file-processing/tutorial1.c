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
//yeni dosya oluşturur

//dosya açılabilirse file pointer döner
//dosya açılamazsa NULL döner

//fclose():
//dosyayı kapatır

//feof():
//dosyanın sonuna gelinip gelinmediğini kontrol eder

//okuma:
//fgetc
//fgets
//fgetw
//fread
//fscanf

//yazma:
//fputc
//fputs
//fputw
//fwrite
//fprintf

//fgetc():
//dosyadan text karakter okur

//fgets():
//dosyadan text satır okur

//fgetw():
//dosyadan sayı okur

//fread():
//dosyadan binary okur

//fscanf():
//dosyadan text string okur

//fputc():
//dosyaya text karakter yazar

//fputs():
//dosyaya text satır yazar

//fputw():
//dosyaya sayı yazar

//fwrite():
//dosyaya binary yazar

//fprintf():
//dosyaya text string yazar

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