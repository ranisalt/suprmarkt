Como usar o Suprmarkt
=====================

Entrando com os dados
---------------------

- Execute o aplicativo.
- Siga as instruções que serão pedidas.
- O aplicativo **exige informações válidas** e não aceita informações fora dos requisitos.
- Ao final, o resultado será mostrado.

Usando arquivo de configuração
------------------------------

- Execute o aplicativo passando como **argumento** `-f nome_do_arquivo` (por exemplo, `suprmarkt -f mercado.dat`)
- Caso haja informações inválidas, o aplicativo indicará onde está o erro.
- O arquivo deve seguir o padrão:

```
# comentarios quaisquer ate o fim da linha 
# mais um comentario. 
# ======================================= 
Nome do Supermercado Inclusive Brancos 
tempo_de_simulacao_em_horas 
tempo_medio_de_chegada_de_cliente_em_segundos 
numero de caixas 
id_caixa1_sem_brancos eficiencia1 salario1 
id_caixa2_sem_brancos eficiencia2 salario2 
- - - 
id_caixaN_sem_brancos eficienciaN salarioN
```
    
- Caso sejam informados mais caixas do que no valor que significa a quantidade, os caixas extras serão **ignorados**.
