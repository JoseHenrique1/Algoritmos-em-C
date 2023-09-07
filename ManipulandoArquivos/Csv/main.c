#include <stdio.h>
void main() {
  //nome do arquivo ccsv
  const char *filename = "arquivo.csv";

  //abre e escreve no csv
  FILE *csvFile = fopen(filename, "w");

  //escreve no inicio do arquivo
  fprintf(csvFile, "Nome,Idade,Cidade\n");
  fprintf(csvFile, "José,19,Bom Jesus\n");
  fprintf(csvFile, "Tatiany,18,Cajazeiras\n");
  fprintf(csvFile, "Eloisa,18,Cajazeiras\n");

  //fecha arquivo csv
  fclose(csvFile);
}
