# Resumo do projeto

Este projeto implementa o controle de um **servo motor** utilizando **PWM** no Raspberry Pi Pico. O código movimenta o motor para posições fixas de **0°, 90° e 180°**, aguardando 5 segundos entre cada movimento. Em seguida, o servo oscila continuamente entre **0° e 180°** de forma suave, criando um movimento periódico.

# Instruções de uso

Para utilizar o software, siga os seguintes passos:

- **1°:** Clone o repositório para o seu computador.

    - Ao abrir o projeto com o **VSCode**, a extensão do **CMake** irá criar a pasta ``build`` automaticamente com os arquivos de compilação.

    - Caso a pasta não seja gerada, crie uma pasta com nome `build` e execute o seguinte comando dentro da pasta criada:
        
        ``cmake ..``

        O comando acima irá criar os arquivos de compilação.

- **2°:** Compile o firmware utilizando a extensão do ***Raspberry Pi Pico*** no ***VSCode***.

A partir daqui, o firmware já estará pronto para uso.

## Execução no ambiente de simulação Wokwi
(Para a parte simulada que usa o servomotor tenha certeza que o valor de '#define PIN_MOTOR' é 22) 

Para utilizar o ***firmware*** no ambiente de simulação, basta ter a extensão do **Wokwi** instalada no seu ***VSCode***, além de ter configurado a sua licença.

Suprindo os requisitos citados acima, basta clicar no arquivo ``diagram.json``, e a simulação já abrirá com o esquemático pronto.

***Clique no botão de play, no canto superior esquerdo e simule!***

## Execução no *Raspberry Pi Pico*
## (Esta parte é somente caso o valor de '#define PIN_MOTOR' seja 12 assim usando o led ao inves do servomotor na bitdoglab como é pedido)

- **1°:** Coloque o seu ***Raspberry Pi Pico*** em modo ***BOOTSEL***, segurando o botão BOOTSEL enquanto conecta a placa ao computador.

- **2°:** Copie o arquivo `.uf2` gerado na pasta `build` para a unidade do ***Raspberry Pi Pico*** (ele aparecerá como um dispositivo de armazenamento externo chamado `RPI-RP2`).

    - Após isso, o código iniciará automaticamente.

- **3°:** O LED irá acender conforme programado: inicialmente brilhando mais forte e a cada 5 segundos diminui o brilho, após a terceira vez que isso acontece, entrará no modo de oscilação indo do brilho minimo ao maximo de forma suave.

## Funcionalidades do projeto

- Controle de **servo motor** via **PWM**.
- Movimento para **posições fixas (0°, 90°, 180°)**.
- Oscilação contínua entre **0° e 180°**.
- Configuração automática do **PWM** para o controle preciso do servo.

## Vídeo demonstração

Clique em ***[link do vídeo](https://youtu.be/l9MTWGbMeLg)*** para visualizar o projeto em execução.

