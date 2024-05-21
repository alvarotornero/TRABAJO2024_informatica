#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int hora;
    int NO2;
    float PM25;
    float PM10;
    char cal_aire[20];
} TMendezAlvaro;

typedef struct {
    int hora;
    float T;
    int HR;
} TEscuelasAguirre;

int main() {
    int TAM = 30;
    TMendezAlvaro vectorMendezAlvaro[TAM];
    TEscuelasAguirre vectorEscuelasAguirre[TAM];
    
    FILE *fichero;
    
    fichero = fopen("20122023_MendezAlvaro.txt", "r");
    
    if (fichero == NULL) {
        printf("\nError al abrir el archivo\n");
        return 0;
    }
            
    printf("Fichero de datos cargado exitosamente\n");
        
    int y = 0;
    while (fscanf(fichero, "%d %d %f %f %s", &vectorMendezAlvaro[y].hora, &vectorMendezAlvaro[y].NO2, &vectorMendezAlvaro[y].PM25, &vectorMendezAlvaro[y].PM10, vectorMendezAlvaro[y].cal_aire) != EOF) {
        printf("%d %d %.2f %.2f %s\n", vectorMendezAlvaro[y].hora, vectorMendezAlvaro[y].NO2, vectorMendezAlvaro[y].PM25, vectorMendezAlvaro[y].PM10, vectorMendezAlvaro[y].cal_aire);
        y++;
        if (y >= TAM) break; 
    }
    
    fclose(fichero);
    
    FILE *fichero2;
    
    fichero2 = fopen("20122023_EscuelasAguirre.txt", "r");
    
    if (fichero2 == NULL) {
        printf("\nError al abrir el archivo\n");
        return 0;
    }
            
    printf("Fichero de datos cargado exitosamente\n");
    
    int i = 0;
    while (fscanf(fichero2, "%d %f %d", &vectorEscuelasAguirre[i].hora, &vectorEscuelasAguirre[i].T, &vectorEscuelasAguirre[i].HR) != EOF) {
        printf("%d %.1f %d\n", vectorEscuelasAguirre[i].hora, vectorEscuelasAguirre[i].T, vectorEscuelasAguirre[i].HR);
        i++;
        if (i >= TAM) break; 
    }
    
    fclose(fichero2);
    
    return 0;
}

