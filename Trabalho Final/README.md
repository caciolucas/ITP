## Coisas Importantes

### O que é cada arquivo?

 - *output.csv* (gerado pelo nosso script)
 - *saida.csv* (arquivo de saida esperada pros parametros do exemplo do doc do prjojeto)
 - *main.c* (o script)
 - *plot.py* (o script pra plotar)
 - *entrada.txt* (o arquivo de entrada dos valores de parametro, atualmente com os valores do exemplo) 

### Como executar o script

Inicialmente, compile-o em sua máquina, como no exemplo a baixo

```
gcc main.c -o main
```

Execute o arquivo compilado
```
main entrada.txt output.csv 500
```

 - *entrada.txt* - arquivo com os parâmetros
 - *output.csv* - arquivo de saída 
 - *500* - quantidade de horas
 