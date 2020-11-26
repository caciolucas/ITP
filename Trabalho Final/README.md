
# Informações importantes

## Como executar o script

### Compilação
Inicialmente, compile-o em sua máquina, como no exemplo abaixo:

```
gcc main.c -o main
```

Em seguida execute o arquivo compilado passando como argumentos, respectivamente, o arquivo de entrada com os parâmetros do caso analisado, o nome do arquivo de saída que deverá ser gerado, e a quantidade de horas da simulação, por exemplo:

### Execução

```
main entrada.txt output.csv 500
```

Neste caso:

* `entrada.txt` (é o arquivo de entrada com os parâmetros do caso analisado);
* `output.csv` (é o arquivo de saída que deverá ser criado);
* `500` (é a quantidade de horas que a simulação terá);

## Arquivo de entrada

O arquivo de entrada deverá ser um arquivo de texto seguindo o formato a seguir:

```
S(0)=[valor]
I(0)=[valor]
R(0)=[valor]
h=[valor]
N_b=[valor]
T_b=[valor]
S_b0=[valor]
I_b0=[valor]
m_k=[valor]
n_k=[valor]
T_k=[valor]
tempo_T_b2=[valor]
T_b2=[valor]
tempo_T_k2=[valor]
T_k2=[valor]
```
Onde `valor` é o respectivo valor do parâmetro, como no exemplo a seguir:

```
S(0)=70
I(0)=2
R(0)=0
h=0.1
N_b=12
T_b=24
S_b0=10
I_b0=50
m_k=6
n_k=22
T_k=24
tempo_T_b2=250
T_b2=48
tempo_T_k2=250
T_k2=12
```

## Plotagem dos dados

### Chamada automática
Logo após o cálculo da simulação, o próprio programa irá executar o script Python de plotagem. O script por sua vez, verifica se você tem a biblioteca necessária instalada, se não a tiver, instala usando o parâmetro `-q` para que não haja um despejo de informações desnecessárias no seu terminal.

A chamada do script Python é feita da seguinte forma:

```
system("python plot.py [arquivodesaida]\n");
```

Onde `arquivodesaida` é o nome do arquivo passado inicialmente como parâmetro (nos nossos exemplos, `output.csv`).

Em resumo, você não precisa fazer nada além de rodar o programa compilado e passar o nome do arquivo de entrada, o de saída e a quantidade de horas simuladas, o programa irá chamar os demais scripts necessários de forma completamente automática.

### Chamada manual
No entanto, caso queira gerar a partir de um `.csv` diferente, você pode chamar o script manualmente usando

```
python plot.py [seuarquivo].csv
````

Lembre-se de que `seuarquivo.csv` deve ter o seguinte cabeçalho:

```
Cenario 0 S(t),Cenario 0 I(t),Cenario 0 R(t),Cenario 0 D(t),Cenario 1 S(t),Cenario 1 I(t),Cenario 1 R(t), Cenario 1 D(t),Cenario 2 S(t),Cenario 2 I(t),Cenario 2 R(t),Cenario 2 D(t),tempo(t)

```
