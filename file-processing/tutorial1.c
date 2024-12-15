//file processing:
//stdio.h kütüphanesi üzerinden gerçekleştirilir

//text dosya açarken kullanılan modlar:

//"r":  
//okumak için dosyayı açar
//dosya yoksa hata verir
//"w":  
//yazmak için dosyayı açar
//dosya yoksa oluşturur
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
    FILE *file1 = fopen("filename.txt","w");
    FILE *file2 = fopen("filename.bin","wb");

    if(file1 == NULL){
        printf("dosya acilamadi \n");
        return 1;
    }
    if(file2 == NULL){
        printf("dosya acilamadi \n");
        return 1;
    }

    int age = 25;
    int salary = 5000;
    fprintf(file1,"hello! \n");
    fprintf(file1,"age: %d\n",age);
    fprintf(file1,"salary: %d\n",salary);
    //dosyaya yazar

    char text[] = "dosya islemleri";
    fputs(text,file1);
    //dosyaya yazar

    fputc('\n',file1);
    fputc('w',file1);
    //dosyaya yazar

    int numbers[] = {10, 20, 30, 40, 50};
    fwrite(numbers,sizeof(int),5,file2);
    //dosyaya yazar

    fclose(file1);
    fclose(file2);
    
    return 0;
}